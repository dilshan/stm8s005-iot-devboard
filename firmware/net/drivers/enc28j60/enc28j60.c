//----------------------------------------------------------------------------
// ENC28J60 Eathernet driver for STM8 series MCUs.
// Copyright (C) 2021 Dilshan Jayakody.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//----------------------------------------------------------------------------
// Update log:
// [23/01/2021] - Initial version - Dilshan Jayakody.
// [02/02/2021] - Add conditional logs - Dilshan Jayakody.
//----------------------------------------------------------------------------

#include "enc28j60.h"

#include "../../../include/stm8.h"
#include "../../../include/stm8-util.h"

#if defined(DEBUG_MSG) && defined(ENC28J60_LOG_MSG)
#include "../../../include/stm8-dbglog.h"
#endif

#include "../ethernet.h"

#if ETHERCARD_SEND_PIPELINING
    #define BREAKORCONTINUE retry=0; continue;
#else
    #define BREAKORCONTINUE break;
#endif

struct transmit_status_vector 
{
    unsigned char bytes[7];
};

static unsigned char Enc28j60Bank;
unsigned char enc28j60_broadcast_enabled = 0;

// Mute ``conditional flow changed by optimizer`` warning issued by SDCC.
#pragma disable_warning 110

void enc28j60InitSPI() 
{
    SPI_CR1 = 0;
    SPI_CR2 = 0;

    // Initialize CS as output with logic high.
    PC_DDR |= (1 << ENC28J60_CS_PIN);
    PC_CR1 |= (1 << ENC28J60_CS_PIN);
    PC_CR2 |= (1 << ENC28J60_CS_PIN);
    PC_ODR |= (1 << ENC28J60_CS_PIN);

    // Initialize MOSI as output with logic high.
    PC_DDR |= (1 << ENC28J60_MOSI_PIN);
    PC_CR1 |= (1 << ENC28J60_MOSI_PIN);
    PC_CR2 |= (1 << ENC28J60_MOSI_PIN);

    // Initialize MISO as input with pullup.
    PC_DDR &= ~(1 << ENC28J60_MISO_PIN);
    PC_CR1 |= (1 << ENC28J60_MISO_PIN);
    PC_CR2 &= ~(1 << ENC28J60_MISO_PIN);

    // Initialize SCK as output with logic high.
    PC_DDR |= (1 << ENC28J60_SCK_PIN);
    PC_CR1 |= (1 << ENC28J60_SCK_PIN);
    PC_CR2 |= (1 << ENC28J60_SCK_PIN);

    // Initialize SPI interface in master mode.
    SPI_CR2 = SPI_CR2_SSM | SPI_CR2_SSI;
    SPI_CR1 = SPI_CR1_MSTR | SPI_CR1_SPE;
}

unsigned char spiTransfer(unsigned char data) 
{
    SPI_DR = data;
    while ((SPI_SR & SPI_SR_RXNE) == 0);

    unsigned char  val = SPI_DR;
    while ((SPI_SR & SPI_SR_TXE) == 0);

    // Wait if SPI bus is busy. (to fix the lost of last bits at high speed clock rates.)
    while (SPI_SR & SPI_SR_BSY);  
    return val;
}

static void enableChip() 
{
    PC_ODR &= ~(1 << ENC28J60_CS_PIN);
}

static void disableChip() 
{
    while ((SPI_SR & SPI_SR_BSY));
    PC_ODR |= (1 << ENC28J60_CS_PIN);  
}

static unsigned char readOp(unsigned char op, unsigned char address) 
{
    enableChip();

    spiTransfer(op | (address & ADDR_MASK));

    if (address & 0x80)        
        spiTransfer(0x00);

    unsigned char result = spiTransfer(0x00);

    disableChip();
    return result;
}

static void writeOp(unsigned char op, unsigned char address, unsigned char data) 
{
    enableChip();
    spiTransfer(op | (address & ADDR_MASK));
    spiTransfer(data);
    disableChip();
}

static void readBuf(unsigned short len, unsigned char* data) 
{
    enableChip();

    if (len != 0) 
    {
        spiTransfer(ENC28J60_READ_BUF_MEM);

        while(len)
        {
            len--;
            *data = spiTransfer(0x00);              
            data++;
        }
    }

    disableChip();
}

static void writeBuf(unsigned short len, const unsigned char* data) 
{
    enableChip();

    if (len != 0) 
    {
        spiTransfer(ENC28J60_WRITE_BUF_MEM);

        while(len)
        {
            len--;
            spiTransfer(*data);
            data++;
        }
    }

    disableChip();
}

static void setBank(unsigned char address) 
{
    if ((address & BANK_MASK) != Enc28j60Bank) 
    {
        writeOp(ENC28J60_BIT_FIELD_CLR, ECON1, ECON1_BSEL1|ECON1_BSEL0);
        Enc28j60Bank = address & BANK_MASK;
        writeOp(ENC28J60_BIT_FIELD_SET, ECON1, Enc28j60Bank>>5);
    }
}

static unsigned char readRegByte(unsigned char address) 
{
    setBank(address);
    return readOp(ENC28J60_READ_CTRL_REG, address);
}

static unsigned short readReg(unsigned char address) 
{
    return readRegByte(address) + (readRegByte(address+1) << 8);
}

static void writeRegByte(unsigned char address, unsigned char data) 
{
    setBank(address);
    writeOp(ENC28J60_WRITE_CTRL_REG, address, data);
}

static void writeReg(unsigned char address, unsigned short data) 
{
    writeRegByte(address, data);
    writeRegByte(address + 1, data >> 8);
}

static unsigned short readPhyByte(unsigned char address) 
{
    writeRegByte(MIREGADR, address);
    writeRegByte(MICMD, MICMD_MIIRD);
    while (readRegByte(MISTAT) & MISTAT_BUSY);
    writeRegByte(MICMD, 0x00);
    return readRegByte((unsigned char)(MIRD+1));
}

static void writePhy(unsigned char address, unsigned short data) 
{
    writeRegByte(MIREGADR, address);
    writeReg(MIWR, data);
    while (readRegByte(MISTAT) & MISTAT_BUSY);
}

unsigned char enc28j60Init(const unsigned char* macaddr) 
{
    enc28j60InitSPI();
    disableChip();

    writeOp(ENC28J60_SOFT_RESET, 0, ENC28J60_SOFT_RESET);
    delay_ms(2);

    while (!(readOp(ENC28J60_READ_CTRL_REG, ESTAT) & ESTAT_CLKRDY));

    writeReg(ERXST, RXSTART_INIT);
    writeReg(ERXRDPT, RXSTART_INIT);
    writeReg(ERXND, RXSTOP_INIT);
    writeReg(ETXST, TXSTART_INIT);
    writeReg(ETXND, TXSTOP_INIT);

    writePhy(PHLCON, 0x476);

    writeRegByte(ERXFCON, ERXFCON_UCEN|ERXFCON_CRCEN|ERXFCON_PMEN|ERXFCON_BCEN);
    writeReg(EPMM0, 0x303f);
    writeReg(EPMCS, 0xf7f9);
    writeRegByte(MACON1, MACON1_MARXEN);
    writeOp(ENC28J60_BIT_FIELD_SET, MACON3, MACON3_PADCFG0|MACON3_TXCRCEN|MACON3_FRMLNEN);
    writeReg(MAIPG, 0x0C12);
    writeRegByte(MABBIPG, 0x12);
    writeReg(MAMXFL, MAX_FRAMELEN);
    writeRegByte(MAADR5, macaddr[0]);
    writeRegByte(MAADR4, macaddr[1]);
    writeRegByte(MAADR3, macaddr[2]);
    writeRegByte(MAADR2, macaddr[3]);
    writeRegByte(MAADR1, macaddr[4]);
    writeRegByte(MAADR0, macaddr[5]);
    writePhy(PHCON2, PHCON2_HDLDIS);

    setBank(ECON1);
    writeOp(ENC28J60_BIT_FIELD_SET, EIE, EIE_INTIE|EIE_PKTIE);
    writeOp(ENC28J60_BIT_FIELD_SET, ECON1, ECON1_RXEN);

    unsigned char rev = readRegByte(EREVID);
    // Microchip forgot to step the number on the silicon when they
    // released the revision B7. 6 is now rev B7. We still have
    // to see what they do when they release B8. At the moment
    // there is no B8 out yet.
    if (rev > 5) ++rev;
    return rev;
}

unsigned char enc28j60IsLinkUp() 
{
    return (readPhyByte(PHSTAT2) >> 2) & 1;
}

void enc28j60PacketSend(unsigned short len) 
{
    unsigned char retry = 0;

#if ETHERCARD_SEND_PIPELINING
    goto resume_last_transmission;
#endif

#if defined(DEBUG_MSG) && defined(ENC28J60_LOG_MSG)

    debugPrintNewLine();
    debugPrintLn("------- Packet --------");

    unsigned char logPos = 0;
    for(logPos = 0; logPos < len; logPos++)
    {
        debugPrintNum(ethernet_buffer[logPos]);
        debugPrint(" ");
        if((logPos > 0) && ((logPos % 8) == 0))
        {
            debugPrintNewLine();
        }
    }

    debugPrintNewLine();
    debugPrintLn("-----------------------");
    debugPrintNewLine();

#endif

    while (1) 
    {
        unsigned short count = 0;
        
        writeOp(ENC28J60_BIT_FIELD_SET, ECON1, ECON1_TXRST);
        writeOp(ENC28J60_BIT_FIELD_CLR, ECON1, ECON1_TXRST);
        writeOp(ENC28J60_BIT_FIELD_CLR, EIR, EIR_TXERIF|EIR_TXIF);

        // Prepare new transmission.

        // Possible warning (110) from SDCC based on the state of the ETHERCARD_SEND_PIPELINING.
        if (retry == 0) 
        {
            writeReg(EWRPT, TXSTART_INIT);
            writeReg(ETXND, TXSTART_INIT+len);
            writeOp(ENC28J60_WRITE_BUF_MEM, 0, 0x00);
            writeBuf(len, ethernet_buffer);
        }

        // Initiate transmission.
        writeOp(ENC28J60_BIT_FIELD_SET, ECON1, ECON1_TXRTS);
        #if ETHERCARD_SEND_PIPELINING
            if (retry == 0) return;
        #endif

resume_last_transmission:

        // Wait until transmission has finished.  
        while ((readRegByte(EIR) & (EIR_TXIF | EIR_TXERIF)) == 0 && ++count < 1000U);

        if (!(readRegByte(EIR) & EIR_TXERIF) && count < 1000U) 
        {
            // No error; start new transmission.
#if defined(DEBUG_MSG) && defined(ENC28J60_LOG_MSG)            
            debugPrintLn("enc28j60PacketSend : No error");
#endif
            BREAKORCONTINUE
        }

        // Cancel previous transmission if stuck.
        writeOp(ENC28J60_BIT_FIELD_CLR, ECON1, ECON1_TXRTS);
#if defined(DEBUG_MSG) && defined(ENC28J60_LOG_MSG)        
        debugPrintLn("enc28j60PacketSend : Cancel transmission");
#endif

#if ETHERCARD_RETRY_LATECOLLISIONS == 0
        BREAKORCONTINUE
#else
        struct transmit_status_vector tsv;
        unsigned short etxnd = readReg(ETXND);
        writeReg(ERDPT, etxnd+1);        
        readBuf(sizeof(struct transmit_status_vector), (unsigned char*) &tsv);

        if (!((readRegByte(EIR) & EIR_TXERIF) && (tsv.bytes[3] & 1<<5) /*tsv.transmitLateCollision*/) || retry > 16U) 
        {
            // There was some error but no LATECOL so we do not repeat.
            BREAKORCONTINUE
        }

        retry++;
#endif
    }
}

unsigned short enc28j60PacketReceive() 
{
    static unsigned short gNextPacketPtr = RXSTART_INIT;
    static unsigned char unreleasedPacket = 0;
    unsigned short len = 0;

    if (unreleasedPacket) 
    {
        if (gNextPacketPtr == 0)
            writeReg(ERXRDPT, RXSTOP_INIT);
        else
            writeReg(ERXRDPT, gNextPacketPtr - 1);
        unreleasedPacket = 0;
    }

    unsigned char dil = readRegByte(EPKTCNT);
    if (dil > 0) 
    {
        writeReg(ERDPT, gNextPacketPtr);

        struct {
            unsigned short nextPacket;
            unsigned short byteCount;
            unsigned short status;
        } header;

        // Handle endiness issue in SDCC compiler.
        unsigned char tempBuffer[6];
        readBuf(6, tempBuffer);

        header.nextPacket = tempBuffer[0] | tempBuffer[1] << 8;
        header.byteCount = tempBuffer[2] | tempBuffer[3] << 8;
        header.status = tempBuffer[4] | tempBuffer[5] << 8;

        gNextPacketPtr  = header.nextPacket;

        len = header.byteCount - 4;
        if (len>ethernet_bufferSize-1)
            len=ethernet_bufferSize-1;
        if ((header.status & 0x80)==0)
            len = 0;
        else
            readBuf(len, ethernet_buffer);

        ethernet_buffer[len] = 0;
        unreleasedPacket = 1;

        writeOp(ENC28J60_BIT_FIELD_SET, ECON2, ECON2_PKTDEC);
    }
    return len;
}

void enc28j60EnableBroadcast(unsigned char temporary) 
{
    writeRegByte(ERXFCON, readRegByte(ERXFCON) | ERXFCON_BCEN);

    if(!temporary)
        enc28j60_broadcast_enabled = 1;
}

void enc28j60DisableBroadcast(unsigned char temporary) 
{
    if(!temporary)
        enc28j60_broadcast_enabled = 0;

    if(!enc28j60_broadcast_enabled)
        writeRegByte(ERXFCON, readRegByte(ERXFCON) & ~ERXFCON_BCEN);
}
//----------------------------------------------------------------------------
// STM8S003F3, STM8S003K3 SPI definitions for SDCC.
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
// [04/12/2020] - Initial version - Dilshan Jayakody.
//----------------------------------------------------------------------------

#ifndef STM8S003_SPI_DEF_H
#define STM8S003_SPI_DEF_H

#define SPI_CR1_RESET_VALUE     ((unsigned char)0x00)   // Control register 1 reset value.
#define SPI_CR2_RESET_VALUE     ((unsigned char)0x00)   // Control register 2 reset value.
#define SPI_ICR_RESET_VALUE     ((unsigned char)0x00)   // Interrupt control register reset value.
#define SPI_SR_RESET_VALUE      ((unsigned char)0x02)   // Status register reset value.
#define SPI_DR_RESET_VALUE      ((unsigned char)0x00)   // Data register reset value.
#define SPI_CRCPR_RESET_VALUE   ((unsigned char)0x07)   // Polynomial register reset value.
#define SPI_RXCRCR_RESET_VALUE  ((unsigned char)0x00)   // RX CRC register reset value.
#define SPI_TXCRCR_RESET_VALUE  ((unsigned char)0x00)   // TX CRC register reset value.

#define SPI_CR1_LSBFIRST    ((unsigned char)0x80)   // Frame format mask.
#define SPI_CR1_SPE         ((unsigned char)0x40)   // Enable bits mask.
#define SPI_CR1_BR          ((unsigned char)0x38)   // Baud rate control mask.
#define SPI_CR1_MSTR        ((unsigned char)0x04)   // Master Selection mask.
#define SPI_CR1_CPOL        ((unsigned char)0x02)   // Clock Polarity mask.
#define SPI_CR1_CPHA        ((unsigned char)0x01)   // Clock Phase mask.

#define SPI_CR2_BDM         ((unsigned char)0x80)   // Bi-directional data mode enable mask.
#define SPI_CR2_BDOE        ((unsigned char)0x40)   // Output enable in bi-directional mode mask.
#define SPI_CR2_CRCEN       ((unsigned char)0x20)   // Hardware CRC calculation enable mask.
#define SPI_CR2_CRCNEXT     ((unsigned char)0x10)   // Transmit CRC next mask.
#define SPI_CR2_RXONLY      ((unsigned char)0x04)   // Receive only mask.
#define SPI_CR2_SSM         ((unsigned char)0x02)   // Software slave management mask.
#define SPI_CR2_SSI         ((unsigned char)0x01)   // Internal slave select mask.
 
#define SPI_ICR_TXEI    ((unsigned char)0x80)   // Tx buffer empty interrupt enable mask.
#define SPI_ICR_RXEI    ((unsigned char)0x40)   // Rx buffer empty interrupt enable mask.
#define SPI_ICR_ERRIE   ((unsigned char)0x20)   // Error interrupt enable mask.
#define SPI_ICR_WKIE    ((unsigned char)0x10)   // Wake-up interrupt enable mask.
 
#define SPI_SR_BSY      ((unsigned char)0x80)   // Busy flag.
#define SPI_SR_OVR      ((unsigned char)0x40)   // Overrun flag.
#define SPI_SR_MODF     ((unsigned char)0x20)   // Mode fault.
#define SPI_SR_CRCERR   ((unsigned char)0x10)   // CRC error flag.
#define SPI_SR_WKUP     ((unsigned char)0x08)   // Wake-Up flag.
#define SPI_SR_TXE      ((unsigned char)0x02)   // Transmit buffer empty.
#define SPI_SR_RXNE     ((unsigned char)0x01)   // Receive buffer not empty.

#endif /* STM8S003_SPI_DEF_H */
//----------------------------------------------------------------------------
// STM8S I2C library for standard mode communication.
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
// [09/10/2020] - Initial version - Dilshan Jayakody.
//----------------------------------------------------------------------------

#include "../include/stm8-i2c.h"

#ifndef F_CPU
#warning "F_CPU not defined, using 2MHz as default CPU clock frequency"
#define F_CPU 2000000UL
#endif

inline void i2cInit()
{
    // CPU clocking frequency.
    I2C_FREQR = F_CPU / 1000000; 

    // I2C frequency. Default (0x000A) is set to 100kHz.
    I2C_CCRH = 0x00;
    I2C_CCRL = 0x50;

    // 7-bit addressing mode.
    I2C_OARH = I2C_OARH_ADDMODE;

    // Enable I2C.
    I2C_CR1 = I2C_CR1_PE;
}

void i2cStart()
{
    I2C_CR2 |= I2C_CR2_START;
    while (!(I2C_SR1 & I2C_SR1_SB));
}

void i2cStop()
{
    I2C_CR2 |= I2C_CR2_STOP;
    while (I2C_SR3 & I2C_SR3_MSL);
}

void i2cWriteAddr(unsigned char addr)
{
    I2C_DR = addr;
    while (!(I2C_SR1 & I2C_SR1_ADDR));

    (void) I2C_SR3;
    I2C_CR2 |= I2C_CR2_ACK;
}

void i2cWrite(unsigned char data)
{
    I2C_DR = data;
    while (!(I2C_SR1 & I2C_SR1_TXE));
}

unsigned char i2cRead(unsigned char ack)
{
    I2C_CR2 = (ack) ? (I2C_CR2 | I2C_CR2_ACK) : (I2C_CR2 & (~(I2C_CR2_ACK)));
    while (!(I2C_SR1 & (I2C_SR1_RXNE)));

    return I2C_DR;
}
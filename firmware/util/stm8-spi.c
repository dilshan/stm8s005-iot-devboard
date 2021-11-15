//----------------------------------------------------------------------------
// STM8S SPI library for master mode communication.
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
// [22/01/2021] - Initial version - Dilshan Jayakody.
//----------------------------------------------------------------------------

#include "../include/stm8.h"
#include "../include/stm8-spi.h"

void spiInit()
{
    // Configure chip select pin as output pin.
    PC_DDR |= (1 << SPI_DEVICE_SELECT_PIN);
    PC_CR1 |= (1 << SPI_DEVICE_SELECT_PIN);
    PC_ODR |= (1 << SPI_DEVICE_SELECT_PIN);
    
    // Select slave management configuration.
    SPI_CR2 = SPI_CR2_SSM | SPI_CR2_SSI;

    // Enable SPI with 500kHz clock (on 2MHz master clock).
    SPI_CR1 = SPI_CR1_MSTR | SPI_CR1_SPE | SPI_CR1_BR0;
}

void spiSelectSlave()
{
    PC_ODR &= ~(1 << SPI_DEVICE_SELECT_PIN);
}

void spiReleaseSlave()
{
    while ((SPI_SR & SPI_SR_BSY));
    PC_ODR |= (1 << SPI_DEVICE_SELECT_PIN);
}

void spiWrite(unsigned char data)
{
    SPI_DR = data;
    while (!(SPI_SR & SPI_SR_TXE));
}

unsigned char spiRead()
{
    // Perform dummy write.
    SPI_DR = 0xFF;
    while (!(SPI_SR & SPI_SR_TXE));

    // Read data from buffer.
    while (!(SPI_SR & SPI_SR_RXNE));
    return SPI_DR;
}
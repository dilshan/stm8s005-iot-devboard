//----------------------------------------------------------------------------
// STM8S UART library for serial communication.
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
// [02/11/2020] - Initial version - Dilshan Jayakody.
//----------------------------------------------------------------------------

#include "../include/stm8-uart.h"

void uartInit()
{
    // Set Baud rate with relative to master clock frequency.
    UART_BRR2 = BAUD_RATE2;
    UART_BRR1 = BAUD_RATE1;

    UART_CR2 = UART_CR2_TEN | UART_CR2_REN;
}

void uartWrite(unsigned char data)
{
    UART_DR = data;

    // Wait until data is transfered to host terminal.
    while (!(UART_SR & UART_SR_TC));
}

unsigned char uartRead()
{
    // Wait for incoming data from host terminal.
    while (!(UART_SR & UART_SR_RXNE));

    return UART_DR;
}
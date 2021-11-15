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
// [24/01/2021] - Add UART2 support - Dilshan Jayakody.
//----------------------------------------------------------------------------

#ifndef HARDWARE_UART1_H
#define HARDWARE_UART1_H

#include "stm8-common.h"
#include "../include/stm8.h"

// UART module number to use with this library. Set 1 for UART1 or 2 for UART2.
// DO NOT provide UART3 and above support for this library because those UART
// units are assigned for special functions in firmware.
#define UART_MODULE 2

#ifndef UART_MODULE
#warning "UART module ID is not specified. Use UART1 for serial communication library."
#define UART_MODULE 1
#endif

#if(UART_MODULE == 1)
#define UART_SR         UART1_SR
#define UART_SR_RXNE    UART1_SR_RXNE
#define UART_BRR2       UART1_BRR2
#define UART_BRR1       UART1_BRR1
#define UART_CR2        UART1_CR2
#define UART_CR2_TEN    UART1_CR2_TEN
#define UART_CR2_REN    UART1_CR2_REN
#define UART_DR         UART1_DR
#define UART_SR_TC      UART1_SR_TC
#else
#define UART_SR         UART2_SR
#define UART_SR_RXNE    UART2_SR_RXNE
#define UART_BRR2       UART2_BRR2
#define UART_BRR1       UART2_BRR1
#define UART_CR2        UART2_CR2
#define UART_CR2_TEN    UART2_CR2_TEN
#define UART_CR2_REN    UART2_CR2_REN
#define UART_DR         UART2_DR
#define UART_SR_TC      UART2_SR_TC
#endif

// BAUD rate need to define in project source or at makefile(s).
#ifndef BAUD_RATE1  
#warning "BAUD rate 1 is not defined. Use standard BAUD rate 9600 (CLK = 2MHz)."
#define BAUD_RATE1 0x0D
#endif

#ifndef BAUD_RATE2  
#warning "BAUD rate 2 is not defined. Use standard BAUD rate 9600 (CLK = 2MHz)."
#define BAUD_RATE2 0x01
#endif

void uartInit();
void uartWrite(unsigned char data);
unsigned char uartRead();

#define uartGetByte() (UART1_DR)

static inline unsigned char uartDataAvailable()
{
    return (UART_SR & UART_SR_RXNE);
}

#endif /* HARDWARE_UART1_H */
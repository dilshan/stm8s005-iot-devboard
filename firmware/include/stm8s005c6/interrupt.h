//----------------------------------------------------------------------------
// STM8S005C6, STM8S005K6 IRQ mapping header file for SDCC.
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
// [21/01/2021] - Initial version - Dilshan Jayakody.
//----------------------------------------------------------------------------

#ifndef STM8S005_INTERRUPT_MAP_H
#define STM8S005_INTERRUPT_MAP_H

#define EXTERNAL_TOP_LEVEL_IRQ      0       // External top level interrupt.
#define AUTO_WAKE_HALT_IRQ          1       // Auto wake up from halt.

#define CLK_IRQ                     2       // Clock controller.

#define PORTA_IRQ                   3       // Port A external interrupts.
#define PORTB_IRQ                   4       // Port B external interrupts.
#define PORTC_IRQ                   5       // Port C external interrupts.
#define PORTD_IRQ                   6       // Port D external interrupts.
#define PORTE_IRQ                   7       // Port E external interrupts.

#define SPI_END_TRANSFER_IRQ        10      // SPI end of transfer.

#define TIMER1_TRIGGER_IRQ          11      // TIMER1 update/overflow/underflow/trigger/break.
#define TIMER1_COMPARE_IRQ          12      // TIMER1 capture/compare.

#define TIMER2_TRIGGER_IRQ          13      // TIMER2 update /overflow.
#define TIMER2_COMPARE_IRQ          14      // TIMER2 capture/compare.

#define TIMER3_TRIGGER_IRQ          15      // TIMER3 update /overflow.
#define TIMER3_COMPARE_IRQ          16      // TIMER3 capture/compare.

#define IIC_IRQ                     19      // I2C interrupt.

#define UART2_TX_IRQ                17      // UART2 TX (send) complete.
#define UART2_RX_IRQ                18      // UART2 RX (receive) register is full.

#define ADC1_COMPLETE_IRQ           22      // ADC1 end of conversion/analog watchdog interrupt.

#define TIMER4_TRIGGET_IRQ          23      // TIMER4 update/overflow.

#define FLASH_IRQ                   24      // Flash memory end of operation / WR_PG_DIS.

#endif /* STM8S005_INTERRUPT_MAP_H */
//----------------------------------------------------------------------------
// STM8S001J3 I2C definitions for SDCC.
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
// [01/11/2020] - Initial version - Dilshan Jayakody.
//----------------------------------------------------------------------------

#ifndef STM8S001_I2C_DEF_H
#define STM8S001_I2C_DEF_H

#define I2C_CR1_RESET_VALUE     ((unsigned char)0x00)   // CR1 reset value.
#define I2C_CR2_RESET_VALUE     ((unsigned char)0x00)   // CR2 reset value. 
#define I2C_FREQR_RESET_VALUE   ((unsigned char)0x00)   // FREQR reset value.
#define I2C_OARL_RESET_VALUE    ((unsigned char)0x00)   // OARL reset value.
#define I2C_OARH_RESET_VALUE    ((unsigned char)0x00)   // OARH reset value.
#define I2C_DR_RESET_VALUE      ((unsigned char)0x00)   // DR reset value.
#define I2C_SR1_RESET_VALUE     ((unsigned char)0x00)   // SR1 reset value.
#define I2C_SR2_RESET_VALUE     ((unsigned char)0x00)   // SR2 reset value.
#define I2C_SR3_RESET_VALUE     ((unsigned char)0x00)   // SR3 reset value.
#define I2C_ITR_RESET_VALUE     ((unsigned char)0x00)   // ITR reset value.
#define I2C_CCRL_RESET_VALUE    ((unsigned char)0x00)   // CCRL reset value.
#define I2C_CCRH_RESET_VALUE    ((unsigned char)0x00)   // CCRH reset value.
#define I2C_TRISER_RESET_VALUE  ((unsigned char)0x02)   // TRISER reset value.

#define I2C_CR1_NOSTRETCH   ((unsigned char)0x80)   // Clock Stretching Disable (Slave mode).
#define I2C_CR1_ENGC        ((unsigned char)0x40)   // General Call Enable.
#define I2C_CR1_PE          ((unsigned char)0x01)   // Peripheral Enable.
 
#define I2C_CR2_SWRST       ((unsigned char)0x80)   // Software Reset.
#define I2C_CR2_POS         ((unsigned char)0x08)   // Acknowledge.
#define I2C_CR2_ACK         ((unsigned char)0x04)   // Acknowledge Enable.
#define I2C_CR2_STOP        ((unsigned char)0x02)   // Stop Generation.
#define I2C_CR2_START       ((unsigned char)0x01)   // Start Generation.
 
#define I2C_FREQR_FREQ      ((unsigned char)0x3F)   // Peripheral Clock Frequency.
 
#define I2C_OARL_ADD        ((unsigned char)0xFE)   // Interface Address bits [7..1].
#define I2C_OARL_ADD0       ((unsigned char)0x01)   // Interface Address bit0.
 
#define I2C_OARH_ADDMODE    ((unsigned char)0x80)   // Addressing Mode (Slave mode).
#define I2C_OARH_ADDCONF    ((unsigned char)0x40)   // Address Mode Configuration.
#define I2C_OARH_ADD        ((unsigned char)0x06)   // Interface Address bits [9..8].

#define I2C_SR1_TXE     ((unsigned char)0x80)   // Data Register Empty (transmitters).
#define I2C_SR1_RXNE    ((unsigned char)0x40)   // Data Register not Empty (receivers).
#define I2C_SR1_STOPF   ((unsigned char)0x10)   // Stop detection (Slave mode).
#define I2C_SR1_ADD10   ((unsigned char)0x08)   // 10-bit header sent (Master mode).
#define I2C_SR1_BTF     ((unsigned char)0x04)   // Byte Transfer Finished.
#define I2C_SR1_ADDR    ((unsigned char)0x02)   // Address sent (master mode)/matched (slave mode).
#define I2C_SR1_SB      ((unsigned char)0x01)   // Start Bit (Master mode).
 
#define I2C_SR2_WUFH    ((unsigned char)0x20)   // Wake-up from Halt.
#define I2C_SR2_OVR     ((unsigned char)0x08)   // Overrun/Underrun.
#define I2C_SR2_AF      ((unsigned char)0x04)   // Acknowledge Failure.
#define I2C_SR2_ARLO    ((unsigned char)0x02)   // Arbitration Lost (master mode).
#define I2C_SR2_BERR    ((unsigned char)0x01)   // Bus Error.
 
#define I2C_SR3_GENCALL ((unsigned char)0x10)   // General Call Header (Slave mode).
#define I2C_SR3_TRA     ((unsigned char)0x04)   // Transmitter/Receiver.
#define I2C_SR3_BUSY    ((unsigned char)0x02)   // Bus Busy.
#define I2C_SR3_MSL     ((unsigned char)0x01)   // Master/Slave.
 
#define I2C_ITR_ITBUFEN     ((unsigned char)0x04)   // Buffer Interrupt Enable.
#define I2C_ITR_ITEVTEN     ((unsigned char)0x02)   // Event Interrupt Enable.
#define I2C_ITR_ITERREN     ((unsigned char)0x01)   // Error Interrupt Enable.

#define I2C_CCRH_FS     ((unsigned char)0x80)   // Master Mode Selection.
#define I2C_CCRH_DUTY   ((unsigned char)0x40)   // Fast Mode Duty Cycle.
#define I2C_CCRH_CCR    ((unsigned char)0x0F)   // Clock Control Register in Fast/Standard mode (Master mode) bits [11..8].

#define I2C_TRISER_TRISE    ((unsigned char)0x3F)   // Maximum Rise Time in Fast/Standard mode (Master mode).

#endif /* STM8S001_I2C_DEF_H */
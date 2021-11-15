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

#ifndef HARDWARE_I2C_H
#define HARDWARE_I2C_H

#include "stm8-common.h"
#include "../include/stm8.h"

void i2cInit();

void i2cStart();
void i2cStop();

void i2cWriteAddr(unsigned char addr);
void i2cWrite(unsigned char data);

unsigned char i2cRead(unsigned char ack);

#endif /* HARDWARE_I2C_H */
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

#ifndef HARDWARE_SPI_H
#define HARDWARE_SPI_H

#include "stm8-common.h"
#include "../include/stm8.h"

// SPI chip select pin (on PORT C).
#define SPI_DEVICE_SELECT_PIN   4

void spiInit();
void spiSelectSlave();
void spiReleaseSlave();

void spiWrite(unsigned char data);
unsigned char spiRead();

#endif /* HARDWARE_SPI_H */
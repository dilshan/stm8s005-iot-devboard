//----------------------------------------------------------------------------
// STM8S001J3 header file.
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
// [15/11/2020] - Add EEPROM support - Dilshan Jayakody.
//----------------------------------------------------------------------------

#ifndef STM8S001_MAIN_H
#define STM8S001_MAIN_H

#include "stm8s001.h"
#include "interrupt.h"

#include "adc1def.h"
#include "i2cdef.h"
#include "spidef.h"
#include "uart1def.h"

#include "timer1def.h"
#include "timer2def.h"
#include "timer4def.h"

#include "flash.h"

// EEPROM start and end addresses.
#define EEPROM_START_ADDR       0x4000
#define EEPROM_END_ADDR         0x407F

// MASS keys for FLASH_DUKR register to disable the DATA area write protection.
#define FLASH_DUKR_KEY1     0xAE
#define FLASH_DUKR_KEY2     0x56

#endif /* STM8S001_MAIN_H */
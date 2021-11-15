//----------------------------------------------------------------------------
// STM8S EEPROM library for standard mode communication.
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
// [24/10/2020] - Initial version - Dilshan Jayakody.
//----------------------------------------------------------------------------

#include "../include/stm8-eeprom.h"

void eepromWrite(unsigned short addr, unsigned char value)
{
    // Unlock EEPROM.
    FLASH_DUKR = FLASH_DUKR_KEY1;
    FLASH_DUKR = FLASH_DUKR_KEY2;
    while (!(FLASH_IAPSR & FLASH_IAPSR_DUL));

    // Writing data into specified address.
    GLOBAL_MEM(addr) = value;
    while (!(FLASH_IAPSR & FLASH_IAPSR_EOP));

    // Lock EEPROM.
    FLASH_IAPSR &= ~(FLASH_IAPSR_DUL);
}
//----------------------------------------------------------------------------
// STM8S003F3, STM8S003K3 flash / EEPROM definitions for SDCC.
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
// [24/12/2020] - Initial version - Dilshan Jayakody.
//----------------------------------------------------------------------------

#ifndef STM8S003_FLASH_DEF_H
#define STM8S003_FLASH_DEF_H

#define FLASH_CR1_RESET_VALUE       ((unsigned char)0x00)       // CR1 reset value.
#define FLASH_CR2_RESET_VALUE       ((unsigned char)0x00)       // CR2 reset value.
#define FLASH_NCR2_RESET_VALUE      ((unsigned char)0xFF)       // NCR2 reset value.
#define FLASH_IAPSR_RESET_VALUE     ((unsigned char)0x40)       // IAPSR reset value.
#define FLASH_PUKR_RESET_VALUE      ((unsigned char)0x00)       // PUKR reset value.
#define FLASH_DUKR_RESET_VALUE      ((unsigned char)0x00)       // DUKR reset value.

#define FLASH_CR1_HALT              ((unsigned char)0x08)       // Standby in Halt mode mask.
#define FLASH_CR1_AHALT             ((unsigned char)0x04)       // Standby in Active Halt mode mask.
#define FLASH_CR1_IE                ((unsigned char)0x02)       // Flash Interrupt enable mask.
#define FLASH_CR1_FIX               ((unsigned char)0x01)       // Fix programming time mask.

#define FLASH_CR2_OPT               ((unsigned char)0x80)       // Select option byte mask.
#define FLASH_CR2_WPRG              ((unsigned char)0x40)       // Word Programming mask.
#define FLASH_CR2_ERASE             ((unsigned char)0x20)       // Erase block mask.
#define FLASH_CR2_FPRG              ((unsigned char)0x10)       // Fast programming mode mask.
#define FLASH_CR2_PRG               ((unsigned char)0x01)       // Program block mask.
 
#define FLASH_NCR2_NOPT             ((unsigned char)0x80)       // Select option byte mask.
#define FLASH_NCR2_NWPRG            ((unsigned char)0x40)       // Word Programming mask.
#define FLASH_NCR2_NERASE           ((unsigned char)0x20)       // Erase block mask.
#define FLASH_NCR2_NFPRG            ((unsigned char)0x10)       // Fast programming mode mask.
#define FLASH_NCR2_NPRG             ((unsigned char)0x01)       // Program block mask.

#define FLASH_IAPSR_HVOFF           ((unsigned char)0x40)       // End of high voltage flag mask.
#define FLASH_IAPSR_DUL             ((unsigned char)0x08)       // Data EEPROM unlocked flag mask.
#define FLASH_IAPSR_EOP             ((unsigned char)0x04)       // End of operation flag mask.
#define FLASH_IAPSR_PUL             ((unsigned char)0x02)       // Flash Program memory unlocked flag mask.
#define FLASH_IAPSR_WR_PG_DIS       ((unsigned char)0x01)       // Write attempted to protected page mask.

#endif /* STM8S003_FLASH_DEF_H */
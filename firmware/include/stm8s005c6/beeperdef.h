//----------------------------------------------------------------------------
// STM8S005C6, STM8S005K6 Beeper definitions.
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

#ifndef STM8S005_BEEPER_DEF_H
#define STM8S005_BEEPER_DEF_H

#define BEEP_CSR_RESET_VALUE    ((unsigned char)0x1F)   // CSR reset value.

#define BEEP_CSR_BEEPSEL    ((unsigned char)0xC0)   // Beeper frequency selection mask.
#define BEEP_CSR_BEEPEN     ((unsigned char)0x20)   // Beeper enable mask.
#define BEEP_CSR_BEEPDIV    ((unsigned char)0x1F)   // Beeper Divider prescalar mask.

#endif /* STM8S005_BEEPER_DEF_H */
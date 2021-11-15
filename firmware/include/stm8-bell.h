//----------------------------------------------------------------------------
// STM8S Bell frequency definitions.
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
// [03/02/2021] - Initial version - Dilshan Jayakody.
// [04/02/2021] - Add BELL_FREQ - Dilshan Jayakody.
//----------------------------------------------------------------------------

#ifndef HARDWARE_BELL_H
#define HARDWARE_BELL_H

#include "stm8-common.h"
#include "../include/stm8.h"

// Required option byte configuration: OPT2[AFR7] = 1
// Above configuration is required to activate BEEP as Port D4 alternate function.

// Required option byte configuration: OPT4[CKAWUSEL] = 0
// Frequency configuration are based on LSI clock source (fLS = 128kHz).

// Recommended option byte configuration:
// 00 00 FF 80 7F 00 FF 00 FF 00 FF 00 FF 00 FF 00 FF

#define STM8_BELL_OFF   (BEEP_CSR = 0x00)

#ifndef BELL_FREQ
#warning "BELL_FREQ is not defined and default bell frequency (1KHz) is used for bell functions."
#define STM8_BELL_ON    STM8_BELL_1KHZ
#else
#if BELL_FREQ == 1
#define STM8_BELL_ON    STM8_BELL_1KHZ
#elif BELL_FREQ == 2
#define STM8_BELL_ON    STM8_BELL_2KHZ
#else
#define STM8_BELL_ON    STM8_BELL_4KHZ
#endif
#endif

#define STM8_BELL_1KHZ  (BEEP_CSR = 0x2E)
#define STM8_BELL_2KHZ  (BEEP_CSR = 0x6E)
#define STM8_BELL_4KHZ  (BEEP_CSR = 0xAE)

#endif /* HARDWARE_BELL_H */
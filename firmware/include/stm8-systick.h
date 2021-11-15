//----------------------------------------------------------------------------
// STM8S System tick definitions to provide standard 
// library compliance (SysTick_Config).
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
// [24/01/2021] - Initial version - Dilshan Jayakody.
//----------------------------------------------------------------------------

#ifndef SYSCPU_TICK_H
#define SYSCPU_TICK_H

#include "stm8-common.h"

void initSysTick();
unsigned long sysClkTicks();
extern void sysTickDelayMS(unsigned long ms);
extern void sysTickDelayUS(unsigned long us);

#define cyclesPerMicrosecond()		(F_CPU / 1000000UL)
#define millis()					(sysClkTicks() / (F_CPU / 1000))
#define micros()					(sysClkTicks() / (F_CPU / 1000000UL))

#endif /* SYSCPU_TICK_H */
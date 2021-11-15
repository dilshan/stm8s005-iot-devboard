//----------------------------------------------------------------------------
// STM8S103F2, STM8S103F3, STM8S103K3 instruction mapping 
// header file for SDCC. 
// Based on STM8S103 datasheet DocID15441 Rev 14.
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
// [05/10/2020] - Initial version - Dilshan Jayakody.
//----------------------------------------------------------------------------

#ifndef STM8S103_INST_H
#define STM8S103_INST_H

// Interrupts related instruction mappings.

#define sei()   {__asm__("rim\n");}     // Enable interrupts.
#define cli()   {__asm__("sim\n");}     // Disable interrupts.
#define wfi()   {__asm__("wfi\n");}     // Wait for interrupt.

// CPU related instruction mappings.

#define nop()   {__asm__("nop\n");}     // No operation.
#define trap()  {__asm__("trap\n");}    // Trap.
#define halt()  {__asm__("halt\n");}    // Halt.

#endif /* STM8S103_INST_H */
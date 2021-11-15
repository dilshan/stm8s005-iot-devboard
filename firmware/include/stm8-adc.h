//----------------------------------------------------------------------------
// STM8S Analog to digital conversion library.
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
// [04/02/2021] - Initial version - Dilshan Jayakody.
//----------------------------------------------------------------------------

#ifndef HARDWARE_ADCLIB_H
#define HARDWARE_ADCLIB_H

#include "stm8-common.h"

#define adcSetChannel(c) (ADC_CSR = (c & 0x0F))
#define adcBusy() (!(ADC_CSR & ADC1_CSR_EOC))

void adcInit(unsigned char initChannel);
unsigned short adcRead();

#endif /* HARDWARE_ADCLIB_H */
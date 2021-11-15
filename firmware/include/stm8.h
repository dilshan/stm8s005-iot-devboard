//----------------------------------------------------------------------------
// STM8S base header file.
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
// [07/10/2020] - Initial version - Dilshan Jayakody.
// [01/11/2020] - Add support for STM8S001J3 MCU.
// [04/12/2020] - Add support for STM8S003F3 MCU.
// [21/01/2021] - Add support for STM8S005C6 MCU.
//----------------------------------------------------------------------------

#ifndef STM8S_MAIN_H
#define STM8S_MAIN_H

#include "stm8-common.h"
#include "inst.h"

#if defined(STM8S103F2) || defined(STM8S103F3) || defined(STM8S103K3)
#include "stm8s103f3/stm8.h"
#endif

#if defined(STM8S003F3) || defined(STM8S003K3)
#include "stm8s003f3/stm8.h"
#endif

#if defined(STM8S001J3)
#include "stm8s001j3/stm8.h"
#endif

#if defined(STM8S005C6) || defined(STM8S005K6)
#include "stm8s005c6/stm8.h"
#endif

#endif /* STM8S_MAIN_H */
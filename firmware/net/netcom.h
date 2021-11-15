//----------------------------------------------------------------------------
// Common library for ENC28J60 related network functions.
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
// [30/01/2021] - Initial version - Dilshan Jayakody.
//----------------------------------------------------------------------------

#ifndef STM8_NET_COMMON_H
#define STM8_NET_COMMON_H

#include "include/stm8.h"
#include "include/stm8-util.h"
#include "include/stm8-systick.h"

#include "net/drivers/ethernet.h"
#include "net/ethutil.h"
#include "net/drivers/ipstack.h"
#include "net/drivers/enc28j60/enc28j60.h"

#include "net/drivers/dhcp.h"

#endif /* STM8_NET_COMMON_H */
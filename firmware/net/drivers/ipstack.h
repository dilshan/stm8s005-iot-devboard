//----------------------------------------------------------------------------
// Ethernet packet, IP, ICMP and custom message processer for 
// STM8 series MCUs.
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
// [29/01/2021] - Initial version - Dilshan Jayakody.
//----------------------------------------------------------------------------

#ifndef STM8_IP_STACK_H
#define STM8_IP_STACK_H

#include "../net.h"

void networkSetGwIp(const unsigned char *gwipaddr);
void networkUpdateBroadcastAddress();
unsigned char networkClientWaitingGw();
static unsigned char networkIsLan(const unsigned char source[IP_LEN], const unsigned char destination[IP_LEN]);

unsigned short networkPacketLoop(unsigned short plen);

void networkUdpPrepare(unsigned short sport, const unsigned char *dip, unsigned short dport);
void networkUdpTransmit(unsigned short datalen);

#endif /* STM8_IP_STACK_H */
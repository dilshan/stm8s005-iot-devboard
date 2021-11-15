//----------------------------------------------------------------------------
// STM8S UART based debugging routines.
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

#include "../include/stm8.h"
#include "../include/stm8-uart.h"
#include "../include/stm8-dbglog.h"
#include "../net/net.h"

#ifdef DEBUG_MSG

// Print only the specified string.
void debugPrint(const unsigned char* msg)
{
    unsigned char msgPos = 0;
    
    while((msg[msgPos] != 0) && (msgPos < 0xFE))
    {
        uartWrite(msg[msgPos++]);        
    }
}

// Print specified string and move to new line.
void debugPrintLn(const unsigned char* msg)
{
    debugPrint(msg);

    // Move to new line after the message print.
    uartWrite(0x0A);
    uartWrite(0x0D);
}

// Print unsigned short number specified in the parameters.
void debugPrintNum(unsigned short val)
{
    unsigned char str[6] = {0,0,0,0,0,0};
    unsigned char pos = 0;

    do
    {
        str[pos] = (val % 10) + 0x30;
        val = val / 10;
        pos++;
    }
    while(val > 0);

    for(pos = 6; pos != 0xFF; pos--)
    {
        if(str[pos] != 0)
        {
            uartWrite(str[pos]);
        }
    }
}

void debugPrintIPAddress(const unsigned char *ip)
{
    unsigned char pos = 0;
    for(pos = 0; pos < IP_LEN; pos++)
    {
        debugPrintNum(ip[pos]);
        
        if(pos != (IP_LEN - 1))        
            uartWrite('.');
    }
}

void debugPrintMACAddress(const unsigned char *mac)
{
    unsigned char pos = 0;
    for(pos = 0; pos < ETH_LEN; pos++)
    {
        debugPrintNum(mac[pos]);

        if(pos != (ETH_LEN - 1))
            uartWrite(':');
    }
}

void debugPrintNewLine()
{
    uartWrite(0x0A);
    uartWrite(0x0D);
}

#else

// Debug logging is turn-off. Set DEBUG_MSG to turn on the debug logging.

void debugPrint(const unsigned char* msg){}
void debugPrintLn(const unsigned char* msg){}
void debugPrintNum(unsigned short num){}
void debugPrintNewLine(){}

void debugPrintIPAddress(const unsigned char *ip){}
void debugPrintMACAddress(const unsigned char *mac){}

#endif
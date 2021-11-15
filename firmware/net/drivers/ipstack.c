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
// [02/02/2021] - Add conditional logs - Dilshan Jayakody.
//----------------------------------------------------------------------------

#include "ipstack.h"
#include "ethernet.h"
#include "../ethutil.h"
#include "enc28j60/enc28j60.h"

#if defined(DEBUG_MSG) && defined(IP_STACK_LOG_MSG)
#include "../../include/stm8-dbglog.h"
#endif

#include "dhcp.h"

#include <string.h>

// Reference to eathernet data buffer.
#define gPB ethernet_buffer

// Gateway router ARP statuses.
#define WGW_INITIAL_ARP 1       // First request, no answer yet.
#define WGW_HAVE_GW_MAC 2       // Have gateway router MAC.
#define WGW_REFRESHING 4        // Refreshing but already have gateway MAC.
#define WGW_ACCEPT_ARP_REPLY 8  // Accept an ARP reply.

static unsigned char tcpip_waitgwmac;               
static unsigned char tcpip_waiting_for_dns_mac = 0;   
static unsigned char tcpip_destmacaddr[ETH_LEN]; 
static unsigned char tcpip_gwmacaddr[ETH_LEN];
static unsigned char tcpip_has_dns_mac = 0;
static unsigned char tcpip_has_dest_mac = 0;
static unsigned char tcpip_waiting_for_dest_mac = 0;

// ARP request header.
const unsigned char tcpip_arpreqhdr[] = { 0,1,8,0,6,4,0,1 };

// IP header.
const unsigned char tcpip_iphdr[] = { 0x45,0,0,0x82,0,0,0x40,0,0x20 };  

extern const unsigned char tcpip_allOnes[] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

static void fill_checksum(unsigned char dest, unsigned char off, unsigned short len, unsigned char type) 
{
    const unsigned char* ptr = gPB + off;
    unsigned long sum = type==1 ? IP_PROTO_UDP_V+len-8 : type==2 ? IP_PROTO_TCP_V+len-8 : 0;
                   
    while(len >1) 
    {
        sum += (unsigned short) (((unsigned long)*ptr<<8)|*(ptr+1));
        ptr+=2;
        len-=2;
    }

    if (len)
        sum += ((unsigned long)*ptr)<<8;
    while (sum>>16)
        sum = (unsigned short) sum + (sum >> 16);

    unsigned short ck = ~ (unsigned short) sum;
    gPB[dest] = ck>>8;
    gPB[dest+1] = ck;
}

static void setMACs(const unsigned char *mac) 
{
#if defined(DEBUG_MSG) && defined(IP_STACK_LOG_MSG)
    debugPrint("setMACs : ");
    debugPrintMACAddress(mac);
    debugPrintNewLine();
#endif
    
    netutilCopyMac(gPB + ETH_DST_MAC, mac);
    netutilCopyMac(gPB + ETH_SRC_MAC, ethernet_mymac);
}

static void setMACandIPs(const unsigned char *mac, const unsigned char *dst) 
{
#if defined(DEBUG_MSG) && defined(IP_STACK_LOG_MSG)
    debugPrint("setMACandIPs MAC : ");
    debugPrintMACAddress(mac);
    debugPrintNewLine();

    debugPrint("setMACandIPs dst : ");
    debugPrintIPAddress(dst);
    debugPrintNewLine();    
#endif

    setMACs(mac);
    netutilCopyIp(gPB + IP_DST_P, dst);
    netutilCopyIp(gPB + IP_SRC_P, ethernet_myip);
}

void networkSetGwIp(const unsigned char *gwipaddr) 
{
#if defined(DEBUG_MSG) && defined(IP_STACK_LOG_MSG)
    debugPrint("networkSetGwIp IP : ");
    debugPrintIPAddress(gwipaddr);
    debugPrintNewLine();    
#endif

    network_delaycnt = 0; 
    tcpip_waitgwmac = WGW_INITIAL_ARP;
    netutilCopyIp(ethernet_gwip, gwipaddr);
}

void networkUpdateBroadcastAddress()
{
    for(unsigned char i=0; i<IP_LEN; i++)
        ethernet_broadcastip[i] = ethernet_myip[i] | ~ethernet_netmask[i];
}

unsigned char networkClientWaitingGw() 
{
    return !(tcpip_waitgwmac & WGW_HAVE_GW_MAC);
}

static unsigned char eth_type_is_arp_and_my_ip(unsigned short len) 
{
#if defined(DEBUG_MSG) && defined(IP_STACK_LOG_MSG)
    debugPrintLn("eth_type_is_arp_and_my_ip");   
#endif

    return len >= 41 && gPB[ETH_TYPE_H_P] == ETHTYPE_ARP_H_V &&
           gPB[ETH_TYPE_L_P] == ETHTYPE_ARP_L_V &&
           memcmp(gPB + ETH_ARP_DST_IP_P, ethernet_myip, IP_LEN) == 0;
}

static unsigned char client_store_mac(unsigned char *source_ip, unsigned char *mac) 
{
#if defined(DEBUG_MSG) && defined(IP_STACK_LOG_MSG)
    debugPrint("client_store_mac MAC : ");
    debugPrintMACAddress(mac);
    debugPrintNewLine();

    debugPrint("client_store_mac source_ip : ");
    debugPrintIPAddress(source_ip);
    debugPrintNewLine();    
#endif

    if (memcmp(gPB + ETH_ARP_SRC_IP_P, source_ip, IP_LEN) != 0)
        return 0;

#if defined(DEBUG_MSG) && defined(IP_STACK_LOG_MSG)
    debugPrintLn("client_store_mac netutilCopyMac");
#endif

    netutilCopyMac(mac, gPB + ETH_ARP_SRC_MAC_P);
    return 1;
}

static unsigned char eth_type_is_ip_and_my_ip(unsigned short len) 
{    
    return len >= 42 && gPB[ETH_TYPE_H_P] == ETHTYPE_IP_H_V &&
           gPB[ETH_TYPE_L_P] == ETHTYPE_IP_L_V &&
           gPB[IP_HEADER_LEN_VER_P] == 0x45 &&
           (memcmp(gPB + IP_DST_P, ethernet_myip, IP_LEN) == 0 
            || (memcmp(gPB + IP_DST_P, ethernet_broadcastip, IP_LEN) == 0) 
            || (memcmp(gPB + IP_DST_P, tcpip_allOnes, IP_LEN) == 0));
}

static void make_arp_answer_from_request() 
{
#if defined(DEBUG_MSG) && defined(IP_STACK_LOG_MSG)
    debugPrintLn("make_arp_answer_from_request");
#endif 

    setMACs(gPB + ETH_SRC_MAC);
    gPB[ETH_ARP_OPCODE_H_P] = ETH_ARP_OPCODE_REPLY_H_V;
    gPB[ETH_ARP_OPCODE_L_P] = ETH_ARP_OPCODE_REPLY_L_V;
    netutilCopyMac(gPB + ETH_ARP_DST_MAC_P, gPB + ETH_ARP_SRC_MAC_P);
    netutilCopyMac(gPB + ETH_ARP_SRC_MAC_P, ethernet_mymac);
    netutilCopyIp(gPB + ETH_ARP_DST_IP_P, gPB + ETH_ARP_SRC_IP_P);
    netutilCopyIp(gPB + ETH_ARP_SRC_IP_P, ethernet_myip);
    enc28j60PacketSend(42);
}

static void client_arp_whohas(unsigned  char *ip_we_search) 
{
#if defined(DEBUG_MSG) && defined(IP_STACK_LOG_MSG)
    debugPrint("client_arp_whohas IP : ");
    debugPrintIPAddress(ip_we_search);
    debugPrintNewLine();    
#endif

    setMACs(tcpip_allOnes);
    gPB[ETH_TYPE_H_P] = ETHTYPE_ARP_H_V;
    gPB[ETH_TYPE_L_P] = ETHTYPE_ARP_L_V;
    memcpy(gPB + ETH_ARP_P, tcpip_arpreqhdr, sizeof tcpip_arpreqhdr);
    memset(gPB + ETH_ARP_DST_MAC_P, 0, ETH_LEN);
    netutilCopyMac(gPB + ETH_ARP_SRC_MAC_P, ethernet_mymac);
    netutilCopyIp(gPB + ETH_ARP_DST_IP_P, ip_we_search);
    netutilCopyIp(gPB + ETH_ARP_SRC_IP_P, ethernet_myip);
    enc28j60PacketSend(42);
}

static void fill_ip_hdr_checksum() 
{
    gPB[IP_CHECKSUM_P] = 0;
    gPB[IP_CHECKSUM_P+1] = 0;
    gPB[IP_FLAGS_P] = 0x40; 
    gPB[IP_FLAGS_P+1] = 0; 
    gPB[IP_TTL_P] = 64; 
    fill_checksum(IP_CHECKSUM_P, IP_P, IP_HEADER_LEN,0);
}

static void make_eth_ip() 
{
#if defined(DEBUG_MSG) && defined(IP_STACK_LOG_MSG)
    debugPrintLn("make_eth_ip");
#endif

    setMACs(gPB + ETH_SRC_MAC);
    netutilCopyIp(gPB + IP_DST_P, gPB + IP_SRC_P);
    netutilCopyIp(gPB + IP_SRC_P, ethernet_myip);
    fill_ip_hdr_checksum();
}

static void make_echo_reply_from_request(unsigned short len) 
{
#if defined(DEBUG_MSG) && defined(IP_STACK_LOG_MSG)
    debugPrintLn("make_echo_reply_from_request");
#endif
    
    make_eth_ip();
    gPB[ICMP_TYPE_P] = ICMP_TYPE_ECHOREPLY_V;
    if (gPB[ICMP_CHECKSUM_P] > (0xFF-0x08))
        gPB[ICMP_CHECKSUM_P+1]++;
    gPB[ICMP_CHECKSUM_P] += 0x08;
    enc28j60PacketSend(len);
}

static unsigned char networkIsLan(const unsigned char source[IP_LEN], const unsigned char destination[IP_LEN]) 
{
    if(source[0] == 0 || destination[0] == 0) 
    {
        return 0;
    }

    for(int i = 0; i < IP_LEN; i++)
        if((source[i] & ethernet_netmask[i]) != (destination[i] & ethernet_netmask[i])) 
        {
            return 0;
        }

    return 1;
}

unsigned short networkPacketLoop(unsigned short plen) 
{    
#if ETHLIB_DHCP
    if(network_using_dhcp) 
    {
        ethernetDhcpStateMachine(plen);
    }
#endif

    if (plen == 0) 
    {
        // Packet had no data.
        
        //Check every 65536 (no-packet) cycles whether we need to retry ARP request for gateway.
        if ((tcpip_waitgwmac & WGW_INITIAL_ARP || tcpip_waitgwmac & WGW_REFRESHING) && network_delaycnt==0 && enc28j60IsLinkUp()) 
        {
#if defined(DEBUG_MSG) && defined(IP_STACK_LOG_MSG)
            debugPrintLn("networkPacketLoop WGW_ACCEPT_ARP_REPLY");
#endif
            client_arp_whohas(ethernet_gwip);
            tcpip_waitgwmac |= WGW_ACCEPT_ARP_REPLY;
        }
        network_delaycnt++;
        
        if(networkIsLan(ethernet_myip, ethernet_dnsip) && !tcpip_has_dns_mac && !tcpip_waiting_for_dns_mac) 
        {
#if defined(DEBUG_MSG) && defined(IP_STACK_LOG_MSG)
            debugPrintLn("networkPacketLoop ethernet_dnsip");
#endif                        
            client_arp_whohas(ethernet_dnsip);
            tcpip_waiting_for_dns_mac = 1;
        }

        if(networkIsLan(ethernet_myip, ethernet_hisip) && !tcpip_has_dest_mac && !tcpip_waiting_for_dest_mac) 
        {
#if defined(DEBUG_MSG) && defined(IP_STACK_LOG_MSG)
            debugPrintLn("networkPacketLoop ethernet_hisip");
#endif
            client_arp_whohas(ethernet_hisip);
            tcpip_waiting_for_dest_mac = 1;
        }

        return 0;
    }

    // Packet had data, and check packet content.

    if (eth_type_is_arp_and_my_ip(plen))
    {   
        // Service ARP request.

#if defined(DEBUG_MSG) && defined(IP_STACK_LOG_MSG)
            debugPrintLn("networkPacketLoop ARP");
#endif

        if (gPB[ETH_ARP_OPCODE_L_P]==ETH_ARP_OPCODE_REQ_L_V)
            make_arp_answer_from_request();
        if (tcpip_waitgwmac & WGW_ACCEPT_ARP_REPLY && (gPB[ETH_ARP_OPCODE_L_P]==ETH_ARP_OPCODE_REPLY_L_V) && client_store_mac(ethernet_gwip, tcpip_gwmacaddr))
            tcpip_waitgwmac = WGW_HAVE_GW_MAC;
        if (!tcpip_has_dns_mac && tcpip_waiting_for_dns_mac && client_store_mac(ethernet_dnsip, tcpip_destmacaddr)) 
        {
#if defined(DEBUG_MSG) && defined(IP_STACK_LOG_MSG)
            debugPrintLn("networkPacketLoop ARP tcpip_has_dns_mac");
#endif
            tcpip_has_dns_mac = 1;
            tcpip_waiting_for_dns_mac = 0;
        }
        if (!tcpip_has_dest_mac && tcpip_waiting_for_dest_mac && client_store_mac(ethernet_hisip, tcpip_destmacaddr)) 
        {
#if defined(DEBUG_MSG) && defined(IP_STACK_LOG_MSG)
            debugPrintLn("networkPacketLoop ARP tcpip_has_dest_mac");
#endif
            tcpip_has_dest_mac = 1;
            tcpip_waiting_for_dest_mac = 0;
        }

        return 0;
    }

    if (eth_type_is_ip_and_my_ip(plen)==0)
    {   
        // Not IP so ignoring.
        return 0;
    }

#if ETHLIB_ICMP
    if (gPB[IP_PROTO_P]==IP_PROTO_ICMP_V && gPB[ICMP_TYPE_P]==ICMP_TYPE_ECHOREQUEST_V)
    {   // Service ICMP echo request (ping).
        // TODO: (Optional) Implement ping request handler in here. 
        make_echo_reply_from_request(plen);
        return 0;
    }
#endif

    if (plen<54 || gPB[IP_PROTO_P]!=IP_PROTO_TCP_V )
        return 0; 

    // Return 1 if the packet is not processed by the IP stack.
    return 1;
}

void networkUdpPrepare(unsigned short sport, const unsigned char *dip, unsigned short dport) 
{
    if(networkIsLan(ethernet_myip, dip)) 
    { 
#if defined(DEBUG_MSG) && defined(IP_STACK_LOG_MSG)
        debugPrintLn("networkUdpPrepare tcpip_destmacaddr");
#endif
        setMACandIPs(tcpip_destmacaddr, dip);
    } 
    else 
    {
#if defined(DEBUG_MSG) && defined(IP_STACK_LOG_MSG)
        debugPrintLn("networkUdpPrepare tcpip_gwmacaddr");
#endif
        setMACandIPs(tcpip_gwmacaddr, dip);
    }

    // See http://tldp.org/HOWTO/Multicast-HOWTO-2.html

    if ((dip[0] & 0xF0) == 0xE0 || *((unsigned long*) dip) == 0xFFFFFFFF || !memcmp(ethernet_broadcastip,dip,IP_LEN))
        netutilCopyMac(gPB + ETH_DST_MAC, tcpip_allOnes);
        
    gPB[ETH_TYPE_H_P] = ETHTYPE_IP_H_V;
    gPB[ETH_TYPE_L_P] = ETHTYPE_IP_L_V;
    memcpy(gPB + IP_P,tcpip_iphdr,sizeof tcpip_iphdr);
    gPB[IP_TOTLEN_H_P] = 0;
    gPB[IP_PROTO_P] = IP_PROTO_UDP_V;
    gPB[UDP_DST_PORT_H_P] = (dport>>8);
    gPB[UDP_DST_PORT_L_P] = dport;
    gPB[UDP_SRC_PORT_H_P] = (sport>>8);
    gPB[UDP_SRC_PORT_L_P] = sport;
    gPB[UDP_LEN_H_P] = 0;
    gPB[UDP_CHECKSUM_H_P] = 0;
    gPB[UDP_CHECKSUM_L_P] = 0;
}

void networkUdpTransmit(unsigned short datalen) 
{
    gPB[IP_TOTLEN_H_P] = (IP_HEADER_LEN+UDP_HEADER_LEN+datalen) >> 8;
    gPB[IP_TOTLEN_L_P] = IP_HEADER_LEN+UDP_HEADER_LEN+datalen;
    fill_ip_hdr_checksum();
    gPB[UDP_LEN_H_P] = (UDP_HEADER_LEN+datalen) >>8;
    gPB[UDP_LEN_L_P] = UDP_HEADER_LEN+datalen;
    fill_checksum(UDP_CHECKSUM_H_P, IP_SRC_P, 16 + datalen,1);

#if defined(DEBUG_MSG) && defined(IP_STACK_LOG_MSG)
    debugPrint("networkUdpTransmit len = ");
    debugPrintNum(UDP_HEADER_LEN+IP_HEADER_LEN+ETH_HEADER_LEN+datalen);
    debugPrintNewLine();
#endif

    enc28j60PacketSend(UDP_HEADER_LEN+IP_HEADER_LEN+ETH_HEADER_LEN+datalen);
}
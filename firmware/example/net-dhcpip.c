//----------------------------------------------------------------------------
// Example application to demonstrate establishing network connection using a 
// DHCP server. This application is designed to work using the STM8S005 IoT 
// development board/firmware library. 
//----------------------------------------------------------------------------

#include "include/stm8.h"
#include "include/stm8-uart.h"
#include "include/stm8-util.h"
#include "include/stm8-dbglog.h"
#include "include/stm8-systick.h"

#include "net/drivers/dhcp.h"
#include "net/drivers/ethernet.h"
#include "net/drivers/ipstack.h"
#include "net/drivers/enc28j60/enc28j60.h"

// Used for stm8-systick libaray to drive time related functions.
void TIMER4_OVR_ISR() __interrupt(TIMER4_TRIGGET_IRQ);

void main()
{
    // Set mac address as 74:69:69:2d:30:31.
    static unsigned char mymac[] = { 0x74,0x69,0x69,0x2D,0x30,0x31 };

    // Activate the interrupts.
    cli();
    sei();

    // Initialize SysTick related timer and variables.
    initSysTick();

    // Initialize UART as debug log terminal.
    uartInit();

    debugPrintLn("DHCP ETH TEST");

    // Initialize ENC28J60 Ethernet interface.
    unsigned char status = networkInit(mymac);
    if(status == 0)
    {
        debugPrintLn("INIT FAIL");
        while(1);
    }

    // Create and send DHCP request.
    debugPrintLn("START DHCP");
    if(!networkDhcpSetup(0))
    {
        debugPrintLn("FAIL DHCP!");
    }

    debugPrintLn("IP RESOLVED");
    
    // Print IP configuration received from the DHCP server.
    // Print IPv4 address received from the DHCP server.
    debugPrintNum(ethernet_myip[0]);
    debugPrint(".");
    debugPrintNum(ethernet_myip[1]);
    debugPrint(".");
    debugPrintNum(ethernet_myip[2]);
    debugPrint(".");
    debugPrintNum(ethernet_myip[3]);
    debugPrintLn(".");

    // Print subnet mask.
    debugPrintNum(ethernet_netmask[0]);
    debugPrint(".");
    debugPrintNum(ethernet_netmask[1]);
    debugPrint(".");
    debugPrintNum(ethernet_netmask[2]);
    debugPrint(".");
    debugPrintNum(ethernet_netmask[3]);
    debugPrintLn(".");

    // Print gateway IP address.
    debugPrintNum(ethernet_gwip[0]);
    debugPrint(".");
    debugPrintNum(ethernet_gwip[1]);
    debugPrint(".");
    debugPrintNum(ethernet_gwip[2]);
    debugPrint(".");
    debugPrintNum(ethernet_gwip[3]);
    debugPrintLn(".");

    // Print DNS IP address.
    debugPrintNum(ethernet_dnsip[0]);
    debugPrint(".");
    debugPrintNum(ethernet_dnsip[1]);
    debugPrint(".");
    debugPrintNum(ethernet_dnsip[2]);
    debugPrint(".");
    debugPrintNum(ethernet_dnsip[3]);
    debugPrintLn(".");

    // Service loop to process incoming network data packets.
    while(1)
    {
        networkPacketLoop(enc28j60PacketReceive());
    }
}
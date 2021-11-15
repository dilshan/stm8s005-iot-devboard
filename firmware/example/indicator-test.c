//----------------------------------------------------------------------------
// Example application to test the onboard LED indicators attached to PORT D0 
// and D1 of the STM8S005C6T6 MCU.
//
// Note: Before testing this application, make sure to close both JP201 and 
// JP203 jumpers.
//----------------------------------------------------------------------------

#include "include/stm8.h"
#include "include/stm8-uart.h"
#include "include/stm8-util.h"
#include "include/stm8-dbglog.h"
#include "include/stm8-systick.h"
#include "include/stm8-bell.h"

// Used for stm8-systick libaray to drive time related functions (optional).
void TIMER4_OVR_ISR() __interrupt(TIMER4_TRIGGET_IRQ);

void main()
{
    // Activate the interrupts.
    cli();
    sei();

    // Initialize SysTick related timer and variables.
    initSysTick();

    // Initialize UART as debug log terminal.
    uartInit();

    // Configure D0 and D1 as output terminals.
    PD_DDR = 0x03;
    PD_CR1 = 0x03;
    PD_CR2 = 0x00;

    debugPrintLn("START LED TEST");

    while (1)
    {
        // Turn on LED A (and turn off LED B).
        PD_ODR = 0x01;
        delay_ms(500);

        // Turn on LED B (and turn off LED A).
        PD_ODR = 0x02;
        delay_ms(500);

        // Turn off both LEDs.
        PD_ODR = 0x00;
        delay_ms(500);
    }    
}
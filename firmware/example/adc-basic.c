//----------------------------------------------------------------------------
// Example application to test the analog to digital conversion (ADC) on 
// STM8S005 IoT development board.
//----------------------------------------------------------------------------

#include "include/stm8.h"
#include "include/stm8-uart.h"
#include "include/stm8-util.h"
#include "include/stm8-dbglog.h"
#include "include/stm8-systick.h"
#include "include/stm8-bell.h"
#include "include/stm8-adc.h"

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

    // Initialize ADC peripherals and select channel 0.
    adcInit(0);

    debugPrintLn("START ADC TEST");

    while (1)
    {
        // Read value of the ADC input 0 (Port B0).
        debugPrintNum(adcRead());
        debugPrint("      ");

        // Read value of the ADC input 1 (Port B1).
        adcSetChannel(1);

        debugPrintNum(adcRead());
        debugPrintNewLine();

        // Reset capture terminal to input 0.
        adcSetChannel(0);

        delay_ms(500);
    }    
}
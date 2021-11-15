#ifndef STM8_GLOBAL_SYSTEM_DEFINITIONS_H
#define STM8_GLOBAL_SYSTEM_DEFINITIONS_H

// NOTE: Use only SDCC supported preprocessors.

// Configuration for BAUD rate of 57600.
#ifndef BAUD_RATE1  
#define BAUD_RATE1 0x02
#endif

#ifndef BAUD_RATE2  
#define BAUD_RATE2 0x03
#endif

// Set default bell frequency to 1KHz.
#ifndef BELL_FREQ
#define BELL_FREQ 1
#endif

#endif /* STM8_GLOBAL_SYSTEM_DEFINITIONS_H */
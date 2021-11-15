//----------------------------------------------------------------------------
// STM8S005C6, STM8S005K6 base header file for SDCC.
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
// [21/01/2021] - Initial version - Dilshan Jayakody.
//----------------------------------------------------------------------------

#ifndef STM8S005_BASE_H
#define STM8S005_BASE_H

// Register addresses.

// I/O port hardware register map.

// PORTA
#define PA_ODR   *(volatile unsigned char *)0x5000
#define PA_IDR   *(volatile unsigned char *)0x5001
#define PA_DDR   *(volatile unsigned char *)0x5002
#define PA_CR1   *(volatile unsigned char *)0x5003
#define PA_CR2   *(volatile unsigned char *)0x5004

// PORTB
#define PB_ODR   *(volatile unsigned char *)0x5005
#define PB_IDR   *(volatile unsigned char *)0x5006
#define PB_DDR   *(volatile unsigned char *)0x5007
#define PB_CR1   *(volatile unsigned char *)0x5008
#define PB_CR2   *(volatile unsigned char *)0x5009

// PORTC
#define PC_ODR   *(volatile unsigned char *)0x500A
#define PC_IDR   *(volatile unsigned char *)0x500B
#define PC_DDR   *(volatile unsigned char *)0x500C
#define PC_CR1   *(volatile unsigned char *)0x500D
#define PC_CR2   *(volatile unsigned char *)0x500E

// PORTD
#define PD_ODR   *(volatile unsigned char *)0x500F
#define PD_IDR   *(volatile unsigned char *)0x5010
#define PD_DDR   *(volatile unsigned char *)0x5011
#define PD_CR1   *(volatile unsigned char *)0x5012
#define PD_CR2   *(volatile unsigned char *)0x5013

// PORTE
#define PE_ODR   *(volatile unsigned char *)0x5014
#define PE_IDR   *(volatile unsigned char *)0x5015
#define PE_DDR   *(volatile unsigned char *)0x5016
#define PE_CR1   *(volatile unsigned char *)0x5017
#define PE_CR2   *(volatile unsigned char *)0x5018

// PORTF
#define PF_ODR   *(volatile unsigned char *)0x5019
#define PF_IDR   *(volatile unsigned char *)0x501A
#define PF_DDR   *(volatile unsigned char *)0x501B
#define PF_CR1   *(volatile unsigned char *)0x501C
#define PF_CR2   *(volatile unsigned char *)0x501D

// PORTG
#define PG_ODR   *(volatile unsigned char *)0x501E
#define PG_IDR   *(volatile unsigned char *)0x501F
#define PG_DDR   *(volatile unsigned char *)0x5020
#define PG_CR1   *(volatile unsigned char *)0x5021
#define PG_CR2   *(volatile unsigned char *)0x5022

// PORTH
#define PH_ODR   *(volatile unsigned char *)0x5023
#define PH_IDR   *(volatile unsigned char *)0x5024
#define PH_DDR   *(volatile unsigned char *)0x5025
#define PH_CR1   *(volatile unsigned char *)0x5026
#define PH_CR2   *(volatile unsigned char *)0x5027

// PORTI
#define PI_ODR   *(volatile unsigned char *)0x5028
#define PI_IDR   *(volatile unsigned char *)0x5029
#define PI_DDR   *(volatile unsigned char *)0x502A
#define PI_CR1   *(volatile unsigned char *)0x502B
#define PI_CR2   *(volatile unsigned char *)0x502C

// General hardware register map.

// Flash

#define FLASH_CR1       *(volatile unsigned char *)0x505A
#define FLASH_CR2       *(volatile unsigned char *)0x505B
#define FLASH_NCR2      *(volatile unsigned char *)0x505C
#define FLASH_FPR       *(volatile unsigned char *)0x505D
#define FLASH_NFPR      *(volatile unsigned char *)0x505E
#define FLASH_IAPSR     *(volatile unsigned char *)0x505F

#define FLASH_PUKR      *(volatile unsigned char *)0x5062
#define FLASH_DUKR      *(volatile unsigned char *)0x5064

// External interrupt

#define EXTI_CR1    *(volatile unsigned char *)0x50A0
#define EXTI_CR2    *(volatile unsigned char *)0x50A1

// Reset

#define RST_SR  *(volatile unsigned char *)0x50B3

// Clock

#define CLK_ICKR    *(volatile unsigned char *)0x50C0
#define CLK_ECKR    *(volatile unsigned char *)0x50C1

#define CLK_SWR         *(volatile unsigned char *)0x50C4
#define CLK_SWCR        *(volatile unsigned char *)0x50C5
#define CLK_CKDIVR      *(volatile unsigned char *)0x50C6
#define CLK_PCKENR1     *(volatile unsigned char *)0x50C7
#define CLK_CSSR        *(volatile unsigned char *)0x50C8
#define CLK_CCOR        *(volatile unsigned char *)0x50C9
#define CLK_PCKENR2     *(volatile unsigned char *)0x50CA

#define CLK_HSITRIMR    *(volatile unsigned char *)0x50CC
#define CLK_SWIMCCR     *(volatile unsigned char *)0x50CD 

// Window watchdog

#define WWDG_CR     *(volatile unsigned char *)0x50D1
#define WWDG_WR     *(volatile unsigned char *)0x50D2

// Watchdog

#define IWDG_KR     *(volatile unsigned char *)0x50E0
#define IWDG_PR     *(volatile unsigned char *)0x50E1
#define IWDG_RLR    *(volatile unsigned char *)0x50E2

// Auto wakeup unit

#define AWU_CSR1    *(volatile unsigned char *)0x50F0
#define AWU_APR     *(volatile unsigned char *)0x50F1
#define AWU_TBR     *(volatile unsigned char *)0x50F2

// Beeper

#define BEEP_CSR    *(volatile unsigned char *)0x50F3

// SPI

#define SPI_CR1     *(volatile unsigned char *)0x5200
#define SPI_CR2     *(volatile unsigned char *)0x5201
#define SPI_ICR     *(volatile unsigned char *)0x5202
#define SPI_SR      *(volatile unsigned char *)0x5203
#define SPI_DR      *(volatile unsigned char *)0x5204
#define SPI_CRCPR   *(volatile unsigned char *)0x5205
#define SPI_RXCRCR  *(volatile unsigned char *)0x5206
#define SPI_TXCRCR  *(volatile unsigned char *)0x5207

// IIC

#define I2C_CR1     *(volatile unsigned char *)0x5210
#define I2C_CR2     *(volatile unsigned char *)0x5211
#define I2C_FREQR   *(volatile unsigned char *)0x5212
#define I2C_OARL    *(volatile unsigned char *)0x5213
#define I2C_OARH    *(volatile unsigned char *)0x5214
#define I2C_DR      *(volatile unsigned char *)0x5216
#define I2C_SR1     *(volatile unsigned char *)0x5217
#define I2C_SR2     *(volatile unsigned char *)0x5218
#define I2C_SR3     *(volatile unsigned char *)0x5219
#define I2C_ITR     *(volatile unsigned char *)0x521A
#define I2C_CCRL    *(volatile unsigned char *)0x521B
#define I2C_CCRH    *(volatile unsigned char *)0x521C
#define I2C_TRISER  *(volatile unsigned char *)0x521D
#define I2C_PECR    *(volatile unsigned char *)0x521E

// UART 2

#define UART2_SR    *(volatile unsigned char *)0x5240
#define UART2_DR    *(volatile unsigned char *)0x5241
#define UART2_BRR1  *(volatile unsigned char *)0x5242
#define UART2_BRR2  *(volatile unsigned char *)0x5243
#define UART2_CR1   *(volatile unsigned char *)0x5244
#define UART2_CR2   *(volatile unsigned char *)0x5245
#define UART2_CR3   *(volatile unsigned char *)0x5246
#define UART2_CR4   *(volatile unsigned char *)0x5247
#define UART2_CR5   *(volatile unsigned char *)0x5248
#define UART2_CR6   *(volatile unsigned char *)0x5249
#define UART2_GTR   *(volatile unsigned char *)0x524A
#define UART2_PSCR  *(volatile unsigned char *)0x524B

// Timer 1

#define TIM1_CR1    *(volatile unsigned char *)0x5250
#define TIM1_CR2    *(volatile unsigned char *)0x5251
#define TIM1_SMCR   *(volatile unsigned char *)0x5252
#define TIM1_ETR    *(volatile unsigned char *)0x5253
#define TIM1_IER    *(volatile unsigned char *)0x5254
#define TIM1_SR1    *(volatile unsigned char *)0x5255
#define TIM1_SR2    *(volatile unsigned char *)0x5256
#define TIM1_EGR    *(volatile unsigned char *)0x5257
#define TIM1_CCMR1  *(volatile unsigned char *)0x5258
#define TIM1_CCMR2  *(volatile unsigned char *)0x5259
#define TIM1_CCMR3  *(volatile unsigned char *)0x525A
#define TIM1_CCMR4  *(volatile unsigned char *)0x525B
#define TIM1_CCER1  *(volatile unsigned char *)0x525C
#define TIM1_CCER2  *(volatile unsigned char *)0x525D
#define TIM1_CNTRH  *(volatile unsigned char *)0x525E
#define TIM1_CNTRL  *(volatile unsigned char *)0x525F
#define TIM1_PSCRH  *(volatile unsigned char *)0x5260
#define TIM1_PSCRL  *(volatile unsigned char *)0x5261
#define TIM1_ARRH   *(volatile unsigned char *)0x5262
#define TIM1_ARRL   *(volatile unsigned char *)0x5263
#define TIM1_RCR    *(volatile unsigned char *)0x5264
#define TIM1_CCR1H  *(volatile unsigned char *)0x5265
#define TIM1_CCR1L  *(volatile unsigned char *)0x5266
#define TIM1_CCR2H  *(volatile unsigned char *)0x5267
#define TIM1_CCR2L  *(volatile unsigned char *)0x5268
#define TIM1_CCR3H  *(volatile unsigned char *)0x5269
#define TIM1_CCR3L  *(volatile unsigned char *)0x526A
#define TIM1_CCR4H  *(volatile unsigned char *)0x526B
#define TIM1_CCR4L  *(volatile unsigned char *)0x526C
#define TIM1_BKR    *(volatile unsigned char *)0x526D
#define TIM1_DTR    *(volatile unsigned char *)0x526E
#define TIM1_OISR   *(volatile unsigned char *)0x526F

// Timer 2

#define TIM2_CR1    *(volatile unsigned char *)0x5300
#define TIM2_IER    *(volatile unsigned char *)0x5301
#define TIM2_SR1    *(volatile unsigned char *)0x5302
#define TIM2_SR2    *(volatile unsigned char *)0x5303
#define TIM2_EGR    *(volatile unsigned char *)0x5304
#define TIM2_CCMR1  *(volatile unsigned char *)0x5305
#define TIM2_CCMR2  *(volatile unsigned char *)0x5306
#define TIM2_CCMR3  *(volatile unsigned char *)0x5307
#define TIM2_CCER1  *(volatile unsigned char *)0x5308
#define TIM2_CCER2  *(volatile unsigned char *)0x5309
#define TIM2_CNTRH  *(volatile unsigned char *)0x530A
#define TIM2_CNTRL  *(volatile unsigned char *)0x530B
#define TIM2_PSCR   *(volatile unsigned char *)0x530C
#define TIM2_ARRH   *(volatile unsigned char *)0x530D
#define TIM2_ARRL   *(volatile unsigned char *)0x530E
#define TIM2_CCR1H  *(volatile unsigned char *)0x530F
#define TIM2_CCR1L  *(volatile unsigned char *)0x5310
#define TIM2_CCR2H  *(volatile unsigned char *)0x5311
#define TIM2_CCR2L  *(volatile unsigned char *)0x5312
#define TIM2_CCR3H  *(volatile unsigned char *)0x5313
#define TIM2_CCR3L  *(volatile unsigned char *)0x5314

// Timer 3

#define TIM3_CR1    *(volatile unsigned char *)0x5320
#define TIM3_IER    *(volatile unsigned char *)0x5321
#define TIM3_SR1    *(volatile unsigned char *)0x5322
#define TIM3_SR2    *(volatile unsigned char *)0x5323
#define TIM3_EGR    *(volatile unsigned char *)0x5324
#define TIM3_CCMR1  *(volatile unsigned char *)0x5325
#define TIM3_CCMR2  *(volatile unsigned char *)0x5326
#define TIM3_CCER1  *(volatile unsigned char *)0x5327
#define TIM3_CNTRH  *(volatile unsigned char *)0x5328
#define TIM3_CNTRL  *(volatile unsigned char *)0x5329
#define TIM3_PSCR   *(volatile unsigned char *)0x532A
#define TIM3_ARRH   *(volatile unsigned char *)0x532B
#define TIM3_ARRL   *(volatile unsigned char *)0x532C
#define TIM3_CCR1H  *(volatile unsigned char *)0x532D
#define TIM3_CCR1L  *(volatile unsigned char *)0x532E
#define TIM3_CCR2H  *(volatile unsigned char *)0x532F
#define TIM3_CCR2L  *(volatile unsigned char *)0x5330

// Timer 4

#define TIM4_CR1    *(volatile unsigned char *)0x5340
#define TIM4_IER    *(volatile unsigned char *)0x5341
#define TIM4_SR     *(volatile unsigned char *)0x5342
#define TIM4_EGR    *(volatile unsigned char *)0x5343
#define TIM4_CNTR   *(volatile unsigned char *)0x5344
#define TIM4_PSCR   *(volatile unsigned char *)0x5345
#define TIM4_ARR    *(volatile unsigned char *)0x5346

// ADC 1 control and status registers

#define ADC_CSR     *(volatile unsigned char *)0x5400
#define ADC_CR1     *(volatile unsigned char *)0x5401
#define ADC_CR2     *(volatile unsigned char *)0x5402
#define ADC_CR3     *(volatile unsigned char *)0x5403
#define ADC_DRH     *(volatile unsigned char *)0x5404
#define ADC_DRL     *(volatile unsigned char *)0x5405
#define ADC_TDRH    *(volatile unsigned char *)0x5406
#define ADC_TDRL    *(volatile unsigned char *)0x5407
#define ADC_HTRH    *(volatile unsigned char *)0x5408
#define ADC_HTRL    *(volatile unsigned char *)0x5409
#define ADC_LTRH    *(volatile unsigned char *)0x540A
#define ADC_LTRL    *(volatile unsigned char *)0x540B
#define ADC_AWSRH   *(volatile unsigned char *)0x540C
#define ADC_AWSRL   *(volatile unsigned char *)0x540D
#define ADC_AWCRH   *(volatile unsigned char *)0x540E
#define ADC_AWCRL   *(volatile unsigned char *)0x540F

// Generic memory mapping

#define GLOBAL_MEM(addr)   (*(volatile unsigned char *)(addr))

#endif /* STM8S005_BASE_H */
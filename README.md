# STM8S005C6T6 Ethernet development board

This is an Ethernet development board based on [STM8S005C6T6](https://www.st.com/resource/en/datasheet/stm8s005c6.pdf), designed specifically for IoT related applications. This development board consists of [ENC28J60](http://ww1.microchip.com/downloads/en/devicedoc/39662c.pdf), 10BASE-T stand-alone Ethernet controller, [CH340G](https://cdn.sparkfun.com/datasheets/Dev/Arduino/Other/CH340DS1.PDF), USB serial interface, 2 LED indicators, and passive buzzer unit.

![STM8S005C6T6 Ethernet development board](https://raw.githubusercontent.com/dilshan/stm8s005-iot-devboard/main/resources/stm8s005-iot-board.jpg)

The firmware framework for this development board has been developed using [SDCC](http://sdcc.sourceforge.net/). To enable IPv4 support, we convert the [EtherCard](https://github.com/njh/EtherCard) driver, which is available for the *Arduino* platform. The current version of this driver supports all other *EtherCard* functions except TCP support.

In the given design, the SPI terminals of the MCU are connected to the ENC28J60 Ethernet controller. All SPI terminals, such as *MISO* / *PC7*, *MOSI* / *PC6*, and *SCK* / *PC5*, are connected directly to the Ethernet controller. In addition, the *PC4* terminal of the MCU is used as ENC28J60, *CHIP-SELECT*. 

The CH340G USB serial interface is connected to the *UART2* terminals of the MCU. In STM8S005C6T6, the *UART2* is mapped to the *PD6* and *PD5* terminals of the MCU. The USB interface of this development board consists of the jack-sense feature. The jack-sense status can access from *PD7*.

The minor peripherals such as LED indicators and buzzer are connected to the *PORTD* of the MCU. The LED indicators are connected to terminals *PD0* and *PD1* and can be activated or deactivated via jumpers. The passive buzzer is connected to *PD4* and can run through the STM8 beep sound generator unit.

All peripherals of this development board are powered by a 3.3V supply. The recommended supply voltage for this development board is  5V to 9V.

In addition to the STM8S005C6T6, this development board supports the following STM8 series, LQFP48 packaged microcontrollers: [STM8S007C8T6](https://www.st.com/resource/en/datasheet/stm8s007c8.pdf), [STM8S207C8T6](https://www.st.com/resource/en/datasheet/stm8s207c8.pdf), and [STM8S105C6T6](https://www.st.com/resource/en/datasheet/stm8s105c6.pdf).

The schematic and PCB design of this project is released under the terms of [CERN-OHL-W Version 2.0](https://ohwr.org/cern_ohl_w_v2.pdf). The firmware framework is released under the terms of the [GNU GPL 2.0](https://github.com/dilshan/stm8s005-iot-devboard/blob/main/LICENSE) license.


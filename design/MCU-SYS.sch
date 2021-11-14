EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 6
Title "STM8S005C6T6 Ethernet development board"
Date "2021-03-01"
Rev "1.0.0"
Comp "Dilshan R Jayakody"
Comment1 "jayakody2000lk@gmail.com"
Comment2 "https://jayakody2000lk.blogspot.com"
Comment3 "https://github.com/dilshan/stm8s005-iot-devboard"
Comment4 "License under CERN-OHL-W Version 2.0"
$EndDescr
Wire Wire Line
	1950 1150 2100 1150
Text Label 1950 1250 2    50   ~ 0
VCAP
$Comp
L power:+3V3 #PWR0109
U 1 1 601C4C23
P 1400 1100
F 0 "#PWR0109" H 1400 950 50  0001 C CNN
F 1 "+3V3" H 1415 1273 50  0000 C CNN
F 2 "" H 1400 1100 50  0001 C CNN
F 3 "" H 1400 1100 50  0001 C CNN
	1    1400 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 1350 1900 1350
Wire Wire Line
	1950 1800 2100 1800
Wire Wire Line
	1950 1900 2100 1900
Wire Wire Line
	1950 2000 2100 2000
Wire Wire Line
	1950 2100 2100 2100
Wire Wire Line
	1950 2200 2100 2200
Wire Wire Line
	1950 2300 2100 2300
Text Label 1950 1800 2    50   ~ 0
PA1
Text Label 1950 1900 2    50   ~ 0
PA2
Text Label 1950 2000 2    50   ~ 0
PA3
Text Label 1950 2100 2    50   ~ 0
PA4
Text Label 1950 2200 2    50   ~ 0
PA5
Text Label 1950 2300 2    50   ~ 0
PA6
Wire Wire Line
	1950 2450 2100 2450
Wire Wire Line
	1950 2550 2100 2550
Wire Wire Line
	1950 2650 2100 2650
Wire Wire Line
	1950 2750 2100 2750
Wire Wire Line
	1950 2850 2100 2850
Wire Wire Line
	1950 2950 2100 2950
Wire Wire Line
	1950 3050 2100 3050
Wire Wire Line
	1950 3150 2100 3150
Text Label 1950 2450 2    50   ~ 0
PB0
Text Label 1950 2550 2    50   ~ 0
PB1
Text Label 1950 2650 2    50   ~ 0
PB2
Text Label 1950 2750 2    50   ~ 0
PB3
Text Label 1950 2850 2    50   ~ 0
PB4
Text Label 1950 2950 2    50   ~ 0
PB5
Text Label 1950 3050 2    50   ~ 0
PB6
Text Label 1950 3150 2    50   ~ 0
PB7
$Comp
L power:GND #PWR0110
U 1 1 601CB908
P 1900 3850
F 0 "#PWR0110" H 1900 3600 50  0001 C CNN
F 1 "GND" H 1905 3677 50  0000 C CNN
F 2 "" H 1900 3850 50  0001 C CNN
F 3 "" H 1900 3850 50  0001 C CNN
	1    1900 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 1150 5300 1150
Wire Wire Line
	5450 1250 5300 1250
Text Label 5450 1150 0    50   ~ 0
PG1
Text Label 5450 1250 0    50   ~ 0
PG0
Wire Wire Line
	5450 1400 5300 1400
Wire Wire Line
	5450 1500 5300 1500
Wire Wire Line
	5450 1600 5300 1600
Wire Wire Line
	5450 1700 5300 1700
Wire Wire Line
	5450 1800 5300 1800
Wire Wire Line
	5450 1900 5300 1900
Wire Wire Line
	5450 2000 5300 2000
Text Label 5450 1400 0    50   ~ 0
PE7
Text Label 5450 1500 0    50   ~ 0
PE6
Text Label 5450 1600 0    50   ~ 0
PE5
Text Label 5450 1700 0    50   ~ 0
PE3
Text Label 5450 1800 0    50   ~ 0
PE2
Text Label 5450 1900 0    50   ~ 0
PE1
Text Label 5450 2000 0    50   ~ 0
PE0
Wire Wire Line
	5450 2450 5300 2450
Wire Wire Line
	5450 2250 5300 2250
Wire Wire Line
	5450 2350 5300 2350
Text Label 5450 2250 0    50   ~ 0
UART-RX
Text Label 5450 2350 0    50   ~ 0
UART-TX
Text Label 5450 2450 0    50   ~ 0
BEEP
Wire Wire Line
	5450 3600 5300 3600
Wire Wire Line
	5450 3500 5300 3500
Wire Wire Line
	5450 3400 5300 3400
Text Label 5450 3600 0    50   ~ 0
PC1
Text Label 5450 3500 0    50   ~ 0
PC2
Text Label 5450 3400 0    50   ~ 0
PC3
Wire Wire Line
	5450 2850 5300 2850
Wire Wire Line
	5450 2750 5300 2750
Wire Wire Line
	5450 2650 5300 2650
Wire Wire Line
	5450 2550 5300 2550
Wire Wire Line
	5450 2150 5300 2150
Text Label 5450 2850 0    50   ~ 0
PD0
Text Label 5450 2750 0    50   ~ 0
PD1
Text Label 5450 2650 0    50   ~ 0
PD2
Text Label 5450 2550 0    50   ~ 0
PD3
Text Label 5450 2150 0    50   ~ 0
PD7
$Comp
L Connector_Generic:Conn_01x02 J201
U 1 1 601C47B0
P 7200 1150
F 0 "J201" H 7280 1142 50  0000 L CNN
F 1 "2.54mm Female Header" H 7280 1051 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 7200 1150 50  0001 C CNN
F 3 "~" H 7200 1150 50  0001 C CNN
	1    7200 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 1150 7000 1150
Wire Wire Line
	6800 1250 7000 1250
Text Label 6800 1150 2    50   ~ 0
PG0
Text Label 6800 1250 2    50   ~ 0
PG1
$Comp
L Connector_Generic:Conn_01x07 J202
U 1 1 601C8150
P 7200 2150
F 0 "J202" H 7280 2192 50  0000 L CNN
F 1 "2.54mm Female Header" H 7280 2101 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x07_P2.54mm_Vertical" H 7200 2150 50  0001 C CNN
F 3 "~" H 7200 2150 50  0001 C CNN
	1    7200 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 1850 7000 1850
Wire Wire Line
	6800 1950 7000 1950
Wire Wire Line
	6800 2050 7000 2050
Wire Wire Line
	6800 2150 7000 2150
Wire Wire Line
	6800 2250 7000 2250
Wire Wire Line
	6800 2350 7000 2350
Wire Wire Line
	6800 2450 7000 2450
Text Label 6800 1850 2    50   ~ 0
PE0
Text Label 6800 1950 2    50   ~ 0
PE1
Text Label 6800 2050 2    50   ~ 0
PE2
Text Label 6800 2150 2    50   ~ 0
PE3
Text Label 6800 2250 2    50   ~ 0
PE5
Text Label 6800 2350 2    50   ~ 0
PE6
Text Label 6800 2450 2    50   ~ 0
PE7
$Comp
L Connector_Generic:Conn_01x08 J203
U 1 1 601D32E2
P 7200 3300
F 0 "J203" H 7280 3292 50  0000 L CNN
F 1 "2.54mm Female Header" H 7280 3201 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 7200 3300 50  0001 C CNN
F 3 "~" H 7200 3300 50  0001 C CNN
	1    7200 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 3000 7000 3000
Wire Wire Line
	6800 3100 7000 3100
Wire Wire Line
	6800 3200 7000 3200
Wire Wire Line
	6800 3300 7000 3300
Wire Wire Line
	6800 3400 7000 3400
Wire Wire Line
	6800 3500 7000 3500
Wire Wire Line
	6800 3600 7000 3600
Wire Wire Line
	6800 3700 7000 3700
Text Label 6800 3000 2    50   ~ 0
PB0
Text Label 6800 3100 2    50   ~ 0
PB1
Text Label 6800 3200 2    50   ~ 0
PB2
Text Label 6800 3300 2    50   ~ 0
PB3
Text Label 6800 3400 2    50   ~ 0
PB4
Text Label 6800 3500 2    50   ~ 0
PB5
Text Label 6800 3600 2    50   ~ 0
PB6
Text Label 6800 3700 2    50   ~ 0
PB7
$Comp
L Connector_Generic:Conn_01x06 J204
U 1 1 601E35D1
P 9900 1350
F 0 "J204" H 9980 1342 50  0000 L CNN
F 1 "2.54mm Female Header" H 9980 1251 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 9900 1350 50  0001 C CNN
F 3 "~" H 9900 1350 50  0001 C CNN
	1    9900 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 1150 9700 1150
Wire Wire Line
	9500 1250 9700 1250
Wire Wire Line
	9500 1350 9700 1350
Wire Wire Line
	9500 1450 9700 1450
Wire Wire Line
	9500 1550 9700 1550
Wire Wire Line
	9500 1650 9700 1650
Text Label 9500 1150 2    50   ~ 0
PA1
Text Label 9500 1250 2    50   ~ 0
PA2
Text Label 9500 1350 2    50   ~ 0
PA3
Text Label 9500 1450 2    50   ~ 0
PA4
Text Label 9500 1550 2    50   ~ 0
PA5
Text Label 9500 1650 2    50   ~ 0
PA6
$Comp
L Connector_Generic:Conn_01x03 J205
U 1 1 601FAD99
P 9900 2350
F 0 "J205" H 9980 2392 50  0000 L CNN
F 1 "2.54mm Female Header" H 9980 2301 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 9900 2350 50  0001 C CNN
F 3 "~" H 9900 2350 50  0001 C CNN
	1    9900 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 2250 9700 2250
Wire Wire Line
	9500 2350 9700 2350
Wire Wire Line
	9500 2450 9700 2450
Text Label 9500 2250 2    50   ~ 0
PC1
Text Label 9500 2350 2    50   ~ 0
PC2
Text Label 9500 2450 2    50   ~ 0
PC3
$Comp
L Connector_Generic:Conn_01x05 J206
U 1 1 60202DA2
P 9900 3250
F 0 "J206" H 9980 3292 50  0000 L CNN
F 1 "2.54mm Female Header" H 9980 3201 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 9900 3250 50  0001 C CNN
F 3 "~" H 9900 3250 50  0001 C CNN
	1    9900 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 3050 9700 3050
Wire Wire Line
	9500 3150 9700 3150
Wire Wire Line
	9500 3250 9700 3250
Wire Wire Line
	9500 3350 9700 3350
Wire Wire Line
	9500 3450 9700 3450
Text Label 9500 3050 2    50   ~ 0
PD0
Text Label 9500 3150 2    50   ~ 0
PD1
Text Label 9500 3250 2    50   ~ 0
PD2
Text Label 9500 3350 2    50   ~ 0
PD3
Text Label 9500 3450 2    50   ~ 0
PD7
$Comp
L power:GND #PWR0111
U 1 1 60219355
P 4650 6700
F 0 "#PWR0111" H 4650 6450 50  0001 C CNN
F 1 "GND" H 4655 6527 50  0000 C CNN
F 2 "" H 4650 6700 50  0001 C CNN
F 3 "" H 4650 6700 50  0001 C CNN
	1    4650 6700
	1    0    0    -1  
$EndComp
Text Label 4300 5750 2    50   ~ 0
VCAP
$Comp
L Device:CP1 C202
U 1 1 60215FDD
P 4650 6150
F 0 "C202" H 4765 6196 50  0000 L CNN
F 1 "1MFD / 10V" H 4765 6105 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 4650 6150 50  0001 C CNN
F 3 "~" H 4650 6150 50  0001 C CNN
	1    4650 6150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 5750 4650 5750
Wire Wire Line
	4650 5750 4650 6000
Wire Wire Line
	4650 6300 4650 6700
Wire Wire Line
	1950 1250 2100 1250
Text Label 1950 1150 2    50   ~ 0
SYS-RESET
Text GLabel 1250 6500 0    50   Input ~ 0
RESET
$Comp
L Device:R R201
U 1 1 6028F232
P 1500 6100
F 0 "R201" H 1570 6146 50  0000 L CNN
F 1 "10K" H 1570 6055 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 1430 6100 50  0001 C CNN
F 3 "~" H 1500 6100 50  0001 C CNN
	1    1500 6100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C201
U 1 1 6029170E
P 1500 6900
F 0 "C201" H 1615 6946 50  0000 L CNN
F 1 "0.1MFD" H 1615 6855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 1538 6750 50  0001 C CNN
F 3 "~" H 1500 6900 50  0001 C CNN
	1    1500 6900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0112
U 1 1 602993D5
P 1500 7200
F 0 "#PWR0112" H 1500 6950 50  0001 C CNN
F 1 "GND" H 1505 7027 50  0000 C CNN
F 2 "" H 1500 7200 50  0001 C CNN
F 3 "" H 1500 7200 50  0001 C CNN
	1    1500 7200
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0113
U 1 1 6029A159
P 1500 5800
F 0 "#PWR0113" H 1500 5650 50  0001 C CNN
F 1 "+3V3" H 1515 5973 50  0000 C CNN
F 2 "" H 1500 5800 50  0001 C CNN
F 3 "" H 1500 5800 50  0001 C CNN
	1    1500 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 5800 1500 5950
Wire Wire Line
	1500 6250 1500 6500
Wire Wire Line
	1500 7200 1500 7050
Wire Wire Line
	1250 6500 1500 6500
Connection ~ 1500 6500
Wire Wire Line
	1500 6500 1500 6750
$Comp
L Switch:SW_Push SW201
U 1 1 602AB626
P 2150 6850
F 0 "SW201" V 2104 6998 50  0000 L CNN
F 1 "6x6 TACT" V 2195 6998 50  0000 L CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 2150 7050 50  0001 C CNN
F 3 "~" H 2150 7050 50  0001 C CNN
	1    2150 6850
	0    1    1    0   
$EndComp
Wire Wire Line
	1500 6500 2150 6500
Wire Wire Line
	2150 6500 2150 6650
$Comp
L power:GND #PWR0114
U 1 1 602B047F
P 2150 7200
F 0 "#PWR0114" H 2150 6950 50  0001 C CNN
F 1 "GND" H 2155 7027 50  0000 C CNN
F 2 "" H 2150 7200 50  0001 C CNN
F 3 "" H 2150 7200 50  0001 C CNN
	1    2150 7200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 7050 2150 7200
Text Label 3400 6500 0    50   ~ 0
SYS-RESET
$Comp
L Device:Jumper JP202
U 1 1 602F5662
P 2750 6500
F 0 "JP202" H 2750 6764 50  0000 C CNN
F 1 "2.54mm Header" H 2750 6673 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 2750 6500 50  0001 C CNN
F 3 "~" H 2750 6500 50  0001 C CNN
	1    2750 6500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 6500 2450 6500
Connection ~ 2150 6500
Wire Wire Line
	3400 6500 3050 6500
$Comp
L Connector_Generic:Conn_01x04 J207
U 1 1 602FFA4F
P 9900 4500
F 0 "J207" H 9980 4492 50  0000 L CNN
F 1 "2.54mm Male Header" H 9980 4401 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 9900 4500 50  0001 C CNN
F 3 "~" H 9900 4500 50  0001 C CNN
	1    9900 4500
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0115
U 1 1 60306C69
P 8900 4150
F 0 "#PWR0115" H 8900 4000 50  0001 C CNN
F 1 "+3V3" H 8915 4323 50  0000 C CNN
F 2 "" H 8900 4150 50  0001 C CNN
F 3 "" H 8900 4150 50  0001 C CNN
	1    8900 4150
	1    0    0    -1  
$EndComp
$Comp
L Device:Polyfuse F201
U 1 1 60308702
P 9300 4400
F 0 "F201" V 9075 4400 50  0000 C CNN
F 1 "100mA" V 9166 4400 50  0000 C CNN
F 2 "Fuse:Fuse_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 9350 4200 50  0001 L CNN
F 3 "~" H 9300 4400 50  0001 C CNN
	1    9300 4400
	0    1    1    0   
$EndComp
Wire Wire Line
	9700 4400 9450 4400
Wire Wire Line
	9150 4400 8900 4400
Wire Wire Line
	8900 4400 8900 4150
$Comp
L power:GND #PWR0116
U 1 1 6031549E
P 9550 4900
F 0 "#PWR0116" H 9550 4650 50  0001 C CNN
F 1 "GND" H 9555 4727 50  0000 C CNN
F 2 "" H 9550 4900 50  0001 C CNN
F 3 "" H 9550 4900 50  0001 C CNN
	1    9550 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	8650 4500 9700 4500
Wire Wire Line
	9700 4600 9550 4600
Wire Wire Line
	9550 4600 9550 4900
Wire Wire Line
	8650 4700 9700 4700
Text Label 8650 4700 2    50   ~ 0
SYS-RESET
Text Label 8650 4500 2    50   ~ 0
PD1
Wire Wire Line
	2100 1550 1900 1550
Wire Wire Line
	1900 1550 1900 1450
Wire Wire Line
	2100 1450 1900 1450
Connection ~ 1900 1450
Wire Wire Line
	1900 1450 1900 1350
$Comp
L power:GNDA #PWR0117
U 1 1 6020EFD3
P 1400 3850
F 0 "#PWR0117" H 1400 3600 50  0001 C CNN
F 1 "GNDA" H 1405 3677 50  0000 C CNN
F 2 "" H 1400 3850 50  0001 C CNN
F 3 "" H 1400 3850 50  0001 C CNN
	1    1400 3850
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3VA #PWR0118
U 1 1 6021E8A5
P 950 1100
F 0 "#PWR0118" H 950 950 50  0001 C CNN
F 1 "+3.3VA" H 965 1273 50  0000 C CNN
F 2 "" H 950 1100 50  0001 C CNN
F 3 "" H 950 1100 50  0001 C CNN
	1    950  1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	950  1650 950  1100
Wire Wire Line
	950  1650 2100 1650
Text Label 3850 4950 2    50   ~ 0
PD1
Wire Wire Line
	3850 4950 4100 4950
$Comp
L Device:Jumper JP203
U 1 1 603C5CE2
P 4400 4950
F 0 "JP203" H 4400 5214 50  0000 C CNN
F 1 "2.54mm Header" H 4400 5123 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 4400 4950 50  0001 C CNN
F 3 "~" H 4400 4950 50  0001 C CNN
	1    4400 4950
	1    0    0    -1  
$EndComp
Text Label 1600 4950 2    50   ~ 0
PD0
Wire Wire Line
	1600 4950 1850 4950
$Comp
L Device:Jumper JP201
U 1 1 603B77B0
P 2150 4950
F 0 "JP201" H 2150 5214 50  0000 C CNN
F 1 "2.54mm Header" H 2150 5123 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 2150 4950 50  0001 C CNN
F 3 "~" H 2150 4950 50  0001 C CNN
	1    2150 4950
	1    0    0    -1  
$EndComp
Text GLabel 2900 4950 2    50   Output ~ 0
IND-A
Text GLabel 5150 4950 2    50   Output ~ 0
IND-B
Wire Wire Line
	2450 4950 2900 4950
Wire Wire Line
	5150 4950 4700 4950
Text GLabel 6850 4950 2    50   Output ~ 0
BEEP-SPK
Wire Wire Line
	6300 4950 6850 4950
Text Label 6300 4950 2    50   ~ 0
BEEP
Wire Wire Line
	1900 1450 1400 1450
Wire Wire Line
	1400 1450 1400 1100
Wire Wire Line
	6300 5450 6850 5450
Text Label 6300 5450 2    50   ~ 0
BEEP
$Comp
L Connector:TestPoint TP201
U 1 1 602AFA1A
P 6850 5450
F 0 "TP201" V 6804 5638 50  0000 L CNN
F 1 "FREQ-TP" V 6895 5638 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 7050 5450 50  0001 C CNN
F 3 "~" H 7050 5450 50  0001 C CNN
	1    6850 5450
	0    1    1    0   
$EndComp
Text Notes 7050 1000 0    50   ~ 0
PORT-G
Text Notes 7050 1700 0    50   ~ 0
PORT-E
Text Notes 7050 2850 0    50   ~ 0
PORT-B
Text Notes 9750 1000 0    50   ~ 0
PORT-A
Text Notes 9750 2100 0    50   ~ 0
PORT-C
Text Notes 9750 2900 0    50   ~ 0
PORT-D
Text Notes 9800 4250 0    50   ~ 0
ICP
Text Notes 2050 5150 0    50   ~ 0
LED-A
Text Notes 4300 5150 0    50   ~ 0
LED-B
Text Notes 2550 6100 0    50   ~ 0
MCU - RESET
Wire Wire Line
	1400 3300 1400 3850
Wire Wire Line
	1400 3300 2100 3300
Wire Wire Line
	1900 3850 1900 3600
Wire Wire Line
	1900 3400 2100 3400
Wire Wire Line
	2100 3600 1900 3600
Connection ~ 1900 3600
Wire Wire Line
	1900 3600 1900 3500
Wire Wire Line
	2100 3500 1900 3500
Connection ~ 1900 3500
Wire Wire Line
	1900 3500 1900 3400
Text GLabel 9450 5650 2    50   Output ~ 0
MCU-TX
Text GLabel 9450 6000 2    50   Input ~ 0
MCU-RX
Wire Wire Line
	8900 5650 9450 5650
Wire Wire Line
	8900 6000 9450 6000
Text Label 8900 5650 2    50   ~ 0
UART-TX
Text Label 8900 6000 2    50   ~ 0
UART-RX
Text GLabel 9450 6350 2    50   Input ~ 0
USB-DET
Wire Wire Line
	8900 6350 9450 6350
Text Label 8900 6350 2    50   ~ 0
PD7
Text GLabel 5800 3000 2    50   Input ~ 0
MISO
Text GLabel 5800 3100 2    50   Input ~ 0
MOSI
Text GLabel 5800 3200 2    50   Input ~ 0
SCK
Text GLabel 5800 3300 2    50   Input ~ 0
SPI-CS
Wire Wire Line
	5300 3000 5800 3000
Wire Wire Line
	5300 3100 5800 3100
Wire Wire Line
	5300 3200 5800 3200
Wire Wire Line
	5300 3300 5800 3300
$Comp
L sensor-dev-kit:STM8S005C6 U201
U 1 1 6029C909
P 3550 1750
F 0 "U201" H 3700 2615 50  0000 C CNN
F 1 "STM8S005C6" H 3700 2524 50  0000 C CNN
F 2 "Package_QFP:LQFP-48_7x7mm_P0.5mm" H 3700 -350 50  0001 C CNN
F 3 "https://www.st.com/en/microcontrollers-microprocessors/stm8s005c6.html" H 3550 1750 50  0001 C CNN
	1    3550 1750
	1    0    0    -1  
$EndComp
Text Notes 5200 4100 2    50   ~ 0
SUPPORTED MCU: STM8S005C6T6\nSTM8S007C8T6\nSTM8S207C8T6\nSTM8S105C6T6
$EndSCHEMATC

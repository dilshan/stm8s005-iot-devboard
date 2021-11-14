EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 6
Title "STM8S005C6T6 Ethernet development board"
Date "2021-03-01"
Rev "1.0.0"
Comp "Dilshan R Jayakody"
Comment1 "jayakody2000lk@gmail.com"
Comment2 "https://jayakody2000lk.blogspot.com"
Comment3 "https://github.com/dilshan/stm8s005-iot-devboard"
Comment4 "License under CERN-OHL-W Version 2.0"
$EndDescr
$Sheet
S 8550 900  2100 1000
U 601BF9BF
F0 "MCU-SYS" 50
F1 "MCU-SYS.sch" 50
$EndSheet
$Sheet
S 8550 2300 2100 1000
U 603E4B37
F0 "UART-USB" 50
F1 "UART-USB.sch" 50
$EndSheet
$Sheet
S 8550 3700 2100 1000
U 601E05B7
F0 "ETH-PHY" 50
F1 "ETH-PHY.sch" 50
$EndSheet
$Sheet
S 8550 5150 2100 1000
U 6030D73A
F0 "EXT-CNTRL" 50
F1 "EXT-CNTRL.sch" 50
$EndSheet
$Sheet
S 5950 900  2100 1000
U 60233DFB
F0 "PSU" 50
F1 "PSU.sch" 50
$EndSheet
Text Notes 750  950  0    50   ~ 0
NOTES:
Text Notes 850  1100 0    50   ~ 0
- All resistors and capacitors should be 0805 SMD packages unless otherwise noted.
Text Notes 850  1250 0    50   ~ 0
- The recommended power supply is 5V - 9V with a minimum of 1A output. 
$Comp
L Mechanical:MountingHole_Pad H101
U 1 1 602BA674
P 1600 5850
F 0 "H101" H 1700 5899 50  0000 L CNN
F 1 "M3" H 1700 5808 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 1600 5850 50  0001 C CNN
F 3 "~" H 1600 5850 50  0001 C CNN
	1    1600 5850
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H102
U 1 1 602BB064
P 2050 5850
F 0 "H102" H 2150 5899 50  0000 L CNN
F 1 "M3" H 2150 5808 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 2050 5850 50  0001 C CNN
F 3 "~" H 2050 5850 50  0001 C CNN
	1    2050 5850
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H103
U 1 1 602BB213
P 2500 5850
F 0 "H103" H 2600 5899 50  0000 L CNN
F 1 "M3" H 2600 5808 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 2500 5850 50  0001 C CNN
F 3 "~" H 2500 5850 50  0001 C CNN
	1    2500 5850
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H104
U 1 1 602BB3CC
P 2950 5850
F 0 "H104" H 3050 5899 50  0000 L CNN
F 1 "M3" H 3050 5808 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 2950 5850 50  0001 C CNN
F 3 "~" H 2950 5850 50  0001 C CNN
	1    2950 5850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 602BCD7C
P 1600 6200
F 0 "#PWR0103" H 1600 5950 50  0001 C CNN
F 1 "GND" H 1605 6027 50  0000 C CNN
F 2 "" H 1600 6200 50  0001 C CNN
F 3 "" H 1600 6200 50  0001 C CNN
	1    1600 6200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 602BD160
P 2050 6200
F 0 "#PWR0104" H 2050 5950 50  0001 C CNN
F 1 "GND" H 2055 6027 50  0000 C CNN
F 2 "" H 2050 6200 50  0001 C CNN
F 3 "" H 2050 6200 50  0001 C CNN
	1    2050 6200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 602BD340
P 2500 6200
F 0 "#PWR0105" H 2500 5950 50  0001 C CNN
F 1 "GND" H 2505 6027 50  0000 C CNN
F 2 "" H 2500 6200 50  0001 C CNN
F 3 "" H 2500 6200 50  0001 C CNN
	1    2500 6200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 602BD4A5
P 2950 6200
F 0 "#PWR0106" H 2950 5950 50  0001 C CNN
F 1 "GND" H 2955 6027 50  0000 C CNN
F 2 "" H 2950 6200 50  0001 C CNN
F 3 "" H 2950 6200 50  0001 C CNN
	1    2950 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 5950 1600 6200
Wire Wire Line
	2050 5950 2050 6200
Wire Wire Line
	2500 5950 2500 6200
Wire Wire Line
	2950 5950 2950 6200
Text Notes 4150 1800 2    50   ~ 0
STM8S005C6T6\nSTM8S007C8T6\nSTM8S207C8T6\nSTM8S105C6T6
Text Notes 850  1400 0    50   ~ 0
- This development board support following STM8 series LQFP48 package base MCUs
Text Notes 1550 5600 0    50   ~ 0
MOUNTING HOLES
$EndSCHEMATC

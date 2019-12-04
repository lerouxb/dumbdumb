EESchema Schematic File Version 4
LIBS:fiftyseven-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text GLabel 650  5550 0    50   Input ~ 0
R1
$Comp
L Device:D D2
U 1 1 5D339370
P 800 5550
F 0 "D2" H 800 5426 50  0000 C CNN
F 1 "D" H 800 5425 50  0001 C CNN
F 2 "Diodes_SMD:D_SOD-323_HandSoldering" H 800 5550 50  0001 C CNN
F 3 "~" H 800 5550 50  0001 C CNN
	1    800  5550
	-1   0    0    1   
$EndComp
Text GLabel 650  6050 0    50   Input ~ 0
R2
$Comp
L Device:D D3
U 1 1 5D339C5C
P 800 6050
F 0 "D3" H 800 5926 50  0000 C CNN
F 1 "D" H 800 5925 50  0001 C CNN
F 2 "Diodes_SMD:D_SOD-323_HandSoldering" H 800 6050 50  0001 C CNN
F 3 "~" H 800 6050 50  0001 C CNN
	1    800  6050
	-1   0    0    1   
$EndComp
Text GLabel 650  6550 0    50   Input ~ 0
R3
$Comp
L Device:D D4
U 1 1 5D33A4E6
P 800 6550
F 0 "D4" H 800 6426 50  0000 C CNN
F 1 "D" H 800 6425 50  0001 C CNN
F 2 "Diodes_SMD:D_SOD-323_HandSoldering" H 800 6550 50  0001 C CNN
F 3 "~" H 800 6550 50  0001 C CNN
	1    800  6550
	-1   0    0    1   
$EndComp
Text GLabel 650  7050 0    50   Input ~ 0
R4
$Comp
L Device:R R11
U 1 1 5D5A73B0
P 6350 1900
F 0 "R11" H 6420 1946 50  0000 L CNN
F 1 "4.7k" H 6420 1855 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6280 1900 50  0001 C CNN
F 3 "~" H 6350 1900 50  0001 C CNN
	1    6350 1900
	1    0    0    -1  
$EndComp
Text GLabel 6050 2050 3    50   BiDi ~ 0
SCL
Text GLabel 6350 2050 3    50   BiDi ~ 0
SDA
Text GLabel 5300 7600 3    50   Output ~ 0
C12
Text GLabel 4900 7600 3    50   Output ~ 0
C11
Text GLabel 4500 7600 3    50   Output ~ 0
C10
Text GLabel 4150 7600 3    50   Output ~ 0
C9
$Comp
L Switch:SW_Push SW3:9
U 1 1 5D3C496A
P 4200 6750
F 0 "SW3:9" V 4200 6898 50  0000 L CNN
F 1 "SW_Push" V 4245 6898 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 4200 6950 50  0001 C CNN
F 3 "~" H 4200 6950 50  0001 C CNN
	1    4200 6750
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW2:9
U 1 1 5D3C4964
P 4200 6250
F 0 "SW2:9" V 4200 6398 50  0000 L CNN
F 1 "SW_Push" V 4245 6398 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 4200 6450 50  0001 C CNN
F 3 "~" H 4200 6450 50  0001 C CNN
	1    4200 6250
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW1:9
U 1 1 5D3C495E
P 4200 5750
F 0 "SW1:9" V 4200 5898 50  0000 L CNN
F 1 "SW_Push" V 4245 5898 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 4200 5950 50  0001 C CNN
F 3 "~" H 4200 5950 50  0001 C CNN
	1    4200 5750
	0    1    1    0   
$EndComp
Text GLabel 3800 7600 3    50   Output ~ 0
C8
$Comp
L Switch:SW_Push SW3:8
U 1 1 5D3BEB38
P 3850 6750
F 0 "SW3:8" V 3850 6898 50  0000 L CNN
F 1 "SW_Push" V 3895 6898 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 3850 6950 50  0001 C CNN
F 3 "~" H 3850 6950 50  0001 C CNN
	1    3850 6750
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW2:8
U 1 1 5D3BEB32
P 3850 6250
F 0 "SW2:8" V 3850 6398 50  0000 L CNN
F 1 "SW_Push" V 3895 6398 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 3850 6450 50  0001 C CNN
F 3 "~" H 3850 6450 50  0001 C CNN
	1    3850 6250
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW1:8
U 1 1 5D3BEB2C
P 3850 5750
F 0 "SW1:8" V 3850 5898 50  0000 L CNN
F 1 "SW_Push" V 3895 5898 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 3850 5950 50  0001 C CNN
F 3 "~" H 3850 5950 50  0001 C CNN
	1    3850 5750
	0    1    1    0   
$EndComp
Text GLabel 3450 7600 3    50   Output ~ 0
C7
$Comp
L Switch:SW_Push SW3:7
U 1 1 5D3B96D0
P 3500 6750
F 0 "SW3:7" V 3500 6898 50  0000 L CNN
F 1 "SW_Push" V 3545 6898 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 3500 6950 50  0001 C CNN
F 3 "~" H 3500 6950 50  0001 C CNN
	1    3500 6750
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW2:7
U 1 1 5D3B96CA
P 3500 6250
F 0 "SW2:7" V 3500 6398 50  0000 L CNN
F 1 "SW_Push" V 3545 6398 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 3500 6450 50  0001 C CNN
F 3 "~" H 3500 6450 50  0001 C CNN
	1    3500 6250
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW1:7
U 1 1 5D3B96C4
P 3500 5750
F 0 "SW1:7" V 3500 5898 50  0000 L CNN
F 1 "SW_Push" V 3545 5898 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 3500 5950 50  0001 C CNN
F 3 "~" H 3500 5950 50  0001 C CNN
	1    3500 5750
	0    1    1    0   
$EndComp
Text GLabel 3100 7600 3    50   Output ~ 0
C6
$Comp
L Switch:SW_Push SW3:6
U 1 1 5D3B5E41
P 3150 6750
F 0 "SW3:6" V 3150 6898 50  0000 L CNN
F 1 "SW_Push" V 3195 6898 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 3150 6950 50  0001 C CNN
F 3 "~" H 3150 6950 50  0001 C CNN
	1    3150 6750
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW2:6
U 1 1 5D3B5E3B
P 3150 6250
F 0 "SW2:6" V 3150 6398 50  0000 L CNN
F 1 "SW_Push" V 3195 6398 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 3150 6450 50  0001 C CNN
F 3 "~" H 3150 6450 50  0001 C CNN
	1    3150 6250
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW1:6
U 1 1 5D3B5E35
P 3150 5750
F 0 "SW1:6" V 3150 5898 50  0000 L CNN
F 1 "SW_Push" V 3195 5898 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 3150 5950 50  0001 C CNN
F 3 "~" H 3150 5950 50  0001 C CNN
	1    3150 5750
	0    1    1    0   
$EndComp
Text GLabel 2750 7600 3    50   Output ~ 0
C5
$Comp
L Switch:SW_Push SW3:5
U 1 1 5D3B2517
P 2800 6750
F 0 "SW3:5" V 2800 6898 50  0000 L CNN
F 1 "SW_Push" V 2845 6898 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 2800 6950 50  0001 C CNN
F 3 "~" H 2800 6950 50  0001 C CNN
	1    2800 6750
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW2:5
U 1 1 5D3B2511
P 2800 6250
F 0 "SW2:5" V 2800 6398 50  0000 L CNN
F 1 "SW_Push" V 2845 6398 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 2800 6450 50  0001 C CNN
F 3 "~" H 2800 6450 50  0001 C CNN
	1    2800 6250
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW1:5
U 1 1 5D3B250B
P 2800 5750
F 0 "SW1:5" V 2800 5898 50  0000 L CNN
F 1 "SW_Push" V 2845 5898 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 2800 5950 50  0001 C CNN
F 3 "~" H 2800 5950 50  0001 C CNN
	1    2800 5750
	0    1    1    0   
$EndComp
Text GLabel 2400 7600 3    50   Output ~ 0
C4
$Comp
L Switch:SW_Push SW4:4
U 1 1 5D3AFCD4
P 2450 7250
F 0 "SW4:4" V 2450 7398 50  0000 L CNN
F 1 "SW_Push" V 2495 7398 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 2450 7450 50  0001 C CNN
F 3 "~" H 2450 7450 50  0001 C CNN
	1    2450 7250
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW3:4
U 1 1 5D3AFCCE
P 2450 6750
F 0 "SW3:4" V 2450 6898 50  0000 L CNN
F 1 "SW_Push" V 2495 6898 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 2450 6950 50  0001 C CNN
F 3 "~" H 2450 6950 50  0001 C CNN
	1    2450 6750
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW2:4
U 1 1 5D3AFCC8
P 2450 6250
F 0 "SW2:4" V 2450 6398 50  0000 L CNN
F 1 "SW_Push" V 2495 6398 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 2450 6450 50  0001 C CNN
F 3 "~" H 2450 6450 50  0001 C CNN
	1    2450 6250
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW1:4
U 1 1 5D3AFCC2
P 2450 5750
F 0 "SW1:4" V 2450 5898 50  0000 L CNN
F 1 "SW_Push" V 2495 5898 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 2450 5950 50  0001 C CNN
F 3 "~" H 2450 5950 50  0001 C CNN
	1    2450 5750
	0    1    1    0   
$EndComp
Text GLabel 2050 7600 3    50   Output ~ 0
C3
$Comp
L Switch:SW_Push SW4:3
U 1 1 5D3ADAC5
P 2100 7250
F 0 "SW4:3" V 2100 7398 50  0000 L CNN
F 1 "SW_Push" V 2145 7398 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 2100 7450 50  0001 C CNN
F 3 "~" H 2100 7450 50  0001 C CNN
	1    2100 7250
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW3:3
U 1 1 5D3ADABF
P 2100 6750
F 0 "SW3:3" V 2100 6898 50  0000 L CNN
F 1 "SW_Push" V 2145 6898 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 2100 6950 50  0001 C CNN
F 3 "~" H 2100 6950 50  0001 C CNN
	1    2100 6750
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW2:3
U 1 1 5D3ADAB9
P 2100 6250
F 0 "SW2:3" V 2100 6398 50  0000 L CNN
F 1 "SW_Push" V 2145 6398 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 2100 6450 50  0001 C CNN
F 3 "~" H 2100 6450 50  0001 C CNN
	1    2100 6250
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW1:3
U 1 1 5D3ADAB3
P 2100 5750
F 0 "SW1:3" V 2100 5898 50  0000 L CNN
F 1 "SW_Push" V 2145 5898 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 2100 5950 50  0001 C CNN
F 3 "~" H 2100 5950 50  0001 C CNN
	1    2100 5750
	0    1    1    0   
$EndComp
Text GLabel 1700 7600 3    50   Output ~ 0
C2
$Comp
L Switch:SW_Push SW4:2
U 1 1 5D3AABAC
P 1750 7250
F 0 "SW4:2" V 1750 7398 50  0000 L CNN
F 1 "SW_Push" V 1795 7398 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 1750 7450 50  0001 C CNN
F 3 "~" H 1750 7450 50  0001 C CNN
	1    1750 7250
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW3:2
U 1 1 5D3AABA6
P 1750 6750
F 0 "SW3:2" V 1750 6898 50  0000 L CNN
F 1 "SW_Push" V 1795 6898 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 1750 6950 50  0001 C CNN
F 3 "~" H 1750 6950 50  0001 C CNN
	1    1750 6750
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW2:2
U 1 1 5D3AABA0
P 1750 6250
F 0 "SW2:2" V 1750 6398 50  0000 L CNN
F 1 "SW_Push" V 1795 6398 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 1750 6450 50  0001 C CNN
F 3 "~" H 1750 6450 50  0001 C CNN
	1    1750 6250
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW1:2
U 1 1 5D3AAB9A
P 1750 5750
F 0 "SW1:2" V 1750 5898 50  0000 L CNN
F 1 "SW_Push" V 1795 5898 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 1750 5950 50  0001 C CNN
F 3 "~" H 1750 5950 50  0001 C CNN
	1    1750 5750
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW4:1
U 1 1 5D3A82BE
P 1400 7250
F 0 "SW4:1" V 1400 7398 50  0000 L CNN
F 1 "SW_Push" V 1445 7398 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 1400 7450 50  0001 C CNN
F 3 "~" H 1400 7450 50  0001 C CNN
	1    1400 7250
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW3:1
U 1 1 5D3A82B8
P 1400 6750
F 0 "SW3:1" V 1400 6898 50  0000 L CNN
F 1 "SW_Push" V 1445 6898 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 1400 6950 50  0001 C CNN
F 3 "~" H 1400 6950 50  0001 C CNN
	1    1400 6750
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW2:1
U 1 1 5D3A82B2
P 1400 6250
F 0 "SW2:1" V 1400 6398 50  0000 L CNN
F 1 "SW_Push" V 1445 6398 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 1400 6450 50  0001 C CNN
F 3 "~" H 1400 6450 50  0001 C CNN
	1    1400 6250
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW1:1
U 1 1 5D3A82AC
P 1400 5750
F 0 "SW1:1" V 1400 5898 50  0000 L CNN
F 1 "SW_Push" V 1445 5898 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 1400 5950 50  0001 C CNN
F 3 "~" H 1400 5950 50  0001 C CNN
	1    1400 5750
	0    1    1    0   
$EndComp
Text GLabel 1000 7600 3    50   Output ~ 0
C0
$Comp
L Switch:SW_Push SW4:0
U 1 1 5D33B0DC
P 1050 7250
F 0 "SW4:0" V 1050 7398 50  0000 L CNN
F 1 "SW_Push" V 1095 7398 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 1050 7450 50  0001 C CNN
F 3 "~" H 1050 7450 50  0001 C CNN
	1    1050 7250
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW3:0
U 1 1 5D33A4E0
P 1050 6750
F 0 "SW3:0" V 1050 6898 50  0000 L CNN
F 1 "SW_Push" V 1095 6898 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 1050 6950 50  0001 C CNN
F 3 "~" H 1050 6950 50  0001 C CNN
	1    1050 6750
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW2:0
U 1 1 5D339C56
P 1050 6250
F 0 "SW2:0" V 1050 6398 50  0000 L CNN
F 1 "SW_Push" V 1095 6398 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 1050 6450 50  0001 C CNN
F 3 "~" H 1050 6450 50  0001 C CNN
	1    1050 6250
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW1:0
U 1 1 5D33936A
P 1050 5750
F 0 "SW1:0" V 1050 5898 50  0000 L CNN
F 1 "SW_Push" V 1095 5898 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 1050 5950 50  0001 C CNN
F 3 "~" H 1050 5950 50  0001 C CNN
	1    1050 5750
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW0:0
U 1 1 5D335FD8
P 1050 5250
F 0 "SW0:0" V 1050 5398 50  0000 L CNN
F 1 "SW_Push" V 1095 5398 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 1050 5450 50  0001 C CNN
F 3 "~" H 1050 5450 50  0001 C CNN
	1    1050 5250
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW0:1
U 1 1 5D3A82D8
P 1400 5250
F 0 "SW0:1" V 1400 5398 50  0000 L CNN
F 1 "SW_Push" V 1445 5398 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 1400 5450 50  0001 C CNN
F 3 "~" H 1400 5450 50  0001 C CNN
	1    1400 5250
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW0:3
U 1 1 5D3ADADF
P 2100 5250
F 0 "SW0:3" V 2100 5398 50  0000 L CNN
F 1 "SW_Push" V 2145 5398 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 2100 5450 50  0001 C CNN
F 3 "~" H 2100 5450 50  0001 C CNN
	1    2100 5250
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW0:4
U 1 1 5D3AFCEE
P 2450 5250
F 0 "SW0:4" V 2450 5398 50  0000 L CNN
F 1 "SW_Push" V 2495 5398 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 2450 5450 50  0001 C CNN
F 3 "~" H 2450 5450 50  0001 C CNN
	1    2450 5250
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW0:5
U 1 1 5D3B2537
P 2800 5250
F 0 "SW0:5" V 2800 5398 50  0000 L CNN
F 1 "SW_Push" V 2845 5398 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 2800 5450 50  0001 C CNN
F 3 "~" H 2800 5450 50  0001 C CNN
	1    2800 5250
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW0:6
U 1 1 5D3B5E61
P 3150 5250
F 0 "SW0:6" V 3150 5398 50  0000 L CNN
F 1 "SW_Push" V 3195 5398 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 3150 5450 50  0001 C CNN
F 3 "~" H 3150 5450 50  0001 C CNN
	1    3150 5250
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW0:7
U 1 1 5D3B96F0
P 3500 5250
F 0 "SW0:7" V 3500 5398 50  0000 L CNN
F 1 "SW_Push" V 3545 5398 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 3500 5450 50  0001 C CNN
F 3 "~" H 3500 5450 50  0001 C CNN
	1    3500 5250
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW0:8
U 1 1 5D3BEB58
P 3850 5250
F 0 "SW0:8" V 3850 5398 50  0000 L CNN
F 1 "SW_Push" V 3895 5398 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 3850 5450 50  0001 C CNN
F 3 "~" H 3850 5450 50  0001 C CNN
	1    3850 5250
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW0:9
U 1 1 5D3C498A
P 4200 5250
F 0 "SW0:9" V 4200 5398 50  0000 L CNN
F 1 "SW_Push" V 4245 5398 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 4200 5450 50  0001 C CNN
F 3 "~" H 4200 5450 50  0001 C CNN
	1    4200 5250
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW0:2
U 1 1 5D3AABC6
P 1750 5250
F 0 "SW0:2" V 1750 5398 50  0000 L CNN
F 1 "SW_Push" V 1795 5398 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 1750 5450 50  0001 C CNN
F 3 "~" H 1750 5450 50  0001 C CNN
	1    1750 5250
	0    1    1    0   
$EndComp
$Comp
L Device:D D1
U 1 1 5D33766A
P 800 5050
F 0 "D1" H 800 4926 50  0000 C CNN
F 1 "D" H 800 4925 50  0001 C CNN
F 2 "Diodes_SMD:D_SOD-323_HandSoldering" H 800 5050 50  0001 C CNN
F 3 "~" H 800 5050 50  0001 C CNN
	1    800  5050
	-1   0    0    1   
$EndComp
$Comp
L Switch:SW_Push SW3:12
U 1 1 5D3DC0E8
P 5350 6750
F 0 "SW3:12" V 5350 6898 50  0000 L CNN
F 1 "SW_Push" V 5395 6898 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 5350 6950 50  0001 C CNN
F 3 "~" H 5350 6950 50  0001 C CNN
	1    5350 6750
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW1:12
U 1 1 5D3DC0DC
P 5350 5750
F 0 "SW1:12" V 5350 5898 50  0000 L CNN
F 1 "SW_Push" V 5395 5898 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 5350 5950 50  0001 C CNN
F 3 "~" H 5350 5950 50  0001 C CNN
	1    5350 5750
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW3:11
U 1 1 5D3D4498
P 4950 6750
F 0 "SW3:11" V 4950 6898 50  0000 L CNN
F 1 "SW_Push" V 4995 6898 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 4950 6950 50  0001 C CNN
F 3 "~" H 4950 6950 50  0001 C CNN
	1    4950 6750
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW2:11
U 1 1 5D3D4492
P 4950 6250
F 0 "SW2:11" V 4950 6398 50  0000 L CNN
F 1 "SW_Push" V 4995 6398 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 4950 6450 50  0001 C CNN
F 3 "~" H 4950 6450 50  0001 C CNN
	1    4950 6250
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW1:11
U 1 1 5D3D448C
P 4950 5750
F 0 "SW1:11" V 4950 5898 50  0000 L CNN
F 1 "SW_Push" V 4995 5898 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 4950 5950 50  0001 C CNN
F 3 "~" H 4950 5950 50  0001 C CNN
	1    4950 5750
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW3:10
U 1 1 5D3CB370
P 4550 6750
F 0 "SW3:10" V 4550 6898 50  0000 L CNN
F 1 "SW_Push" V 4595 6898 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 4550 6950 50  0001 C CNN
F 3 "~" H 4550 6950 50  0001 C CNN
	1    4550 6750
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW2:10
U 1 1 5D3CB36A
P 4550 6250
F 0 "SW2:10" V 4550 6398 50  0000 L CNN
F 1 "SW_Push" V 4595 6398 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 4550 6450 50  0001 C CNN
F 3 "~" H 4550 6450 50  0001 C CNN
	1    4550 6250
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW1:10
U 1 1 5D3CB364
P 4550 5750
F 0 "SW1:10" V 4550 5898 50  0000 L CNN
F 1 "SW_Push" V 4595 5898 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 4550 5950 50  0001 C CNN
F 3 "~" H 4550 5950 50  0001 C CNN
	1    4550 5750
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW0:10
U 1 1 5D3CB390
P 4550 5250
F 0 "SW0:10" V 4550 5398 50  0000 L CNN
F 1 "SW_Push" V 4595 5398 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 4550 5450 50  0001 C CNN
F 3 "~" H 4550 5450 50  0001 C CNN
	1    4550 5250
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW0:11
U 1 1 5D3D44B8
P 4950 5250
F 0 "SW0:11" V 4950 5398 50  0000 L CNN
F 1 "SW_Push" V 4995 5398 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 4950 5450 50  0001 C CNN
F 3 "~" H 4950 5450 50  0001 C CNN
	1    4950 5250
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW0:12
U 1 1 5D3DC108
P 5350 5250
F 0 "SW0:12" V 5350 5398 50  0000 L CNN
F 1 "SW_Push" V 5395 5398 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 5350 5450 50  0001 C CNN
F 3 "~" H 5350 5450 50  0001 C CNN
	1    5350 5250
	0    1    1    0   
$EndComp
Wire Wire Line
	950  5050 1050 5050
Connection ~ 1050 5050
Wire Wire Line
	1050 5050 1400 5050
Connection ~ 1400 5050
Wire Wire Line
	1400 5050 1750 5050
Connection ~ 1750 5050
Wire Wire Line
	1750 5050 2100 5050
Connection ~ 2100 5050
Wire Wire Line
	2100 5050 2450 5050
Connection ~ 2450 5050
Wire Wire Line
	2450 5050 2800 5050
Connection ~ 2800 5050
Wire Wire Line
	2800 5050 3150 5050
Connection ~ 3150 5050
Wire Wire Line
	3150 5050 3500 5050
Connection ~ 3500 5050
Wire Wire Line
	3500 5050 3850 5050
Connection ~ 3850 5050
Wire Wire Line
	3850 5050 4200 5050
Connection ~ 4200 5050
Wire Wire Line
	4200 5050 4550 5050
Connection ~ 4550 5050
Wire Wire Line
	4550 5050 4950 5050
Connection ~ 4950 5050
Wire Wire Line
	4950 5050 5350 5050
Wire Wire Line
	950  5550 1050 5550
Connection ~ 1050 5550
Wire Wire Line
	1050 5550 1400 5550
Connection ~ 1400 5550
Wire Wire Line
	1400 5550 1750 5550
Connection ~ 1750 5550
Wire Wire Line
	1750 5550 2100 5550
Connection ~ 2100 5550
Wire Wire Line
	2100 5550 2450 5550
Connection ~ 2450 5550
Wire Wire Line
	2450 5550 2800 5550
Connection ~ 2800 5550
Wire Wire Line
	2800 5550 3150 5550
Connection ~ 3150 5550
Wire Wire Line
	3150 5550 3500 5550
Connection ~ 3500 5550
Wire Wire Line
	3500 5550 3850 5550
Connection ~ 3850 5550
Wire Wire Line
	3850 5550 4200 5550
Connection ~ 4200 5550
Wire Wire Line
	4200 5550 4550 5550
Connection ~ 4550 5550
Wire Wire Line
	4550 5550 4950 5550
Connection ~ 4950 5550
Wire Wire Line
	4950 5550 5350 5550
Wire Wire Line
	950  6050 1050 6050
Connection ~ 1050 6050
Wire Wire Line
	1050 6050 1400 6050
Connection ~ 1400 6050
Wire Wire Line
	1400 6050 1750 6050
Connection ~ 1750 6050
Wire Wire Line
	1750 6050 2100 6050
Connection ~ 2100 6050
Wire Wire Line
	2100 6050 2450 6050
Connection ~ 2450 6050
Wire Wire Line
	2450 6050 2800 6050
Connection ~ 2800 6050
Wire Wire Line
	2800 6050 3150 6050
Connection ~ 3150 6050
Wire Wire Line
	3150 6050 3500 6050
Connection ~ 3500 6050
Wire Wire Line
	3500 6050 3850 6050
Connection ~ 3850 6050
Wire Wire Line
	3850 6050 4200 6050
Connection ~ 4200 6050
Wire Wire Line
	4200 6050 4550 6050
Connection ~ 4550 6050
Wire Wire Line
	4550 6050 4950 6050
Wire Wire Line
	950  6550 1050 6550
Connection ~ 1050 6550
Wire Wire Line
	1050 6550 1400 6550
Connection ~ 1400 6550
Wire Wire Line
	1400 6550 1750 6550
Connection ~ 1750 6550
Wire Wire Line
	1750 6550 2100 6550
Connection ~ 2100 6550
Wire Wire Line
	2100 6550 2450 6550
Connection ~ 2450 6550
Wire Wire Line
	2450 6550 2800 6550
Connection ~ 2800 6550
Wire Wire Line
	2800 6550 3150 6550
Connection ~ 3150 6550
Wire Wire Line
	3150 6550 3500 6550
Connection ~ 3500 6550
Wire Wire Line
	3500 6550 3850 6550
Connection ~ 3850 6550
Wire Wire Line
	3850 6550 4200 6550
Connection ~ 4200 6550
Wire Wire Line
	4200 6550 4550 6550
Connection ~ 4550 6550
Wire Wire Line
	4550 6550 4950 6550
Connection ~ 4950 6550
Wire Wire Line
	4950 6550 5350 6550
$Comp
L Device:D D5
U 1 1 5EF6B526
P 800 7050
F 0 "D5" H 800 6926 50  0000 C CNN
F 1 "D" H 800 6925 50  0001 C CNN
F 2 "Diodes_SMD:D_SOD-323_HandSoldering" H 800 7050 50  0001 C CNN
F 3 "~" H 800 7050 50  0001 C CNN
	1    800  7050
	-1   0    0    1   
$EndComp
Wire Wire Line
	950  7050 1050 7050
Connection ~ 1050 7050
Wire Wire Line
	1050 7050 1400 7050
Connection ~ 1400 7050
Wire Wire Line
	1400 7050 1750 7050
Connection ~ 1750 7050
Wire Wire Line
	1750 7050 2100 7050
Connection ~ 2100 7050
Wire Wire Line
	2100 7050 2450 7050
Wire Wire Line
	1050 5450 1000 5450
Wire Wire Line
	1000 5450 1000 5950
Wire Wire Line
	1050 5950 1000 5950
Connection ~ 1000 5950
Wire Wire Line
	1000 5950 1000 6450
Wire Wire Line
	1050 6450 1000 6450
Connection ~ 1000 6450
Wire Wire Line
	1000 6450 1000 6950
Wire Wire Line
	1050 6950 1000 6950
Connection ~ 1000 6950
Wire Wire Line
	1000 6950 1000 7450
Wire Wire Line
	1050 7450 1000 7450
Connection ~ 1000 7450
Wire Wire Line
	1000 7450 1000 7600
Wire Wire Line
	1400 5450 1350 5450
Wire Wire Line
	1350 5450 1350 5950
Wire Wire Line
	1400 5950 1350 5950
Connection ~ 1350 5950
Wire Wire Line
	1350 5950 1350 6450
Wire Wire Line
	1400 6450 1350 6450
Connection ~ 1350 6450
Wire Wire Line
	1350 6450 1350 6950
Wire Wire Line
	1400 6950 1350 6950
Connection ~ 1350 6950
Wire Wire Line
	1350 6950 1350 7450
Wire Wire Line
	1400 7450 1350 7450
Connection ~ 1350 7450
Wire Wire Line
	1350 7450 1350 7600
Wire Wire Line
	1750 5450 1700 5450
Wire Wire Line
	1700 5450 1700 5950
Wire Wire Line
	1750 5950 1700 5950
Connection ~ 1700 5950
Wire Wire Line
	1700 5950 1700 6450
Wire Wire Line
	1750 6450 1700 6450
Connection ~ 1700 6450
Wire Wire Line
	1700 6450 1700 6950
Wire Wire Line
	1750 6950 1700 6950
Connection ~ 1700 6950
Wire Wire Line
	1700 6950 1700 7450
Wire Wire Line
	1750 7450 1700 7450
Connection ~ 1700 7450
Wire Wire Line
	1700 7450 1700 7600
Wire Wire Line
	2100 5450 2050 5450
Wire Wire Line
	2050 5450 2050 5950
Wire Wire Line
	2450 5450 2400 5450
Wire Wire Line
	2400 5450 2400 5950
Wire Wire Line
	2800 5450 2750 5450
Wire Wire Line
	2750 5450 2750 5950
Wire Wire Line
	3150 5450 3100 5450
Wire Wire Line
	3100 5450 3100 5950
Wire Wire Line
	2100 5950 2050 5950
Connection ~ 2050 5950
Wire Wire Line
	2050 5950 2050 6450
Wire Wire Line
	2100 6450 2050 6450
Connection ~ 2050 6450
Wire Wire Line
	2050 6450 2050 6950
Wire Wire Line
	2100 6950 2050 6950
Connection ~ 2050 6950
Wire Wire Line
	2050 6950 2050 7450
Wire Wire Line
	2100 7450 2050 7450
Connection ~ 2050 7450
Wire Wire Line
	2050 7450 2050 7600
Wire Wire Line
	2450 5950 2400 5950
Connection ~ 2400 5950
Wire Wire Line
	2400 5950 2400 6450
Wire Wire Line
	2450 6450 2400 6450
Connection ~ 2400 6450
Wire Wire Line
	2400 6450 2400 6950
Wire Wire Line
	2450 6950 2400 6950
Connection ~ 2400 6950
Wire Wire Line
	2450 7450 2400 7450
Wire Wire Line
	2400 6950 2400 7450
Connection ~ 2400 7450
Wire Wire Line
	2400 7450 2400 7600
Wire Wire Line
	2800 5950 2750 5950
Connection ~ 2750 5950
Wire Wire Line
	2750 5950 2750 6450
Wire Wire Line
	2800 6450 2750 6450
Connection ~ 2750 6450
Wire Wire Line
	2750 6450 2750 6950
Wire Wire Line
	2800 6950 2750 6950
Connection ~ 2750 6950
Wire Wire Line
	3150 5950 3100 5950
Connection ~ 3100 5950
Wire Wire Line
	3100 5950 3100 6450
Wire Wire Line
	3150 6450 3100 6450
Connection ~ 3100 6450
Wire Wire Line
	3100 6450 3100 6950
Wire Wire Line
	3150 6950 3100 6950
Connection ~ 3100 6950
Wire Wire Line
	3500 5450 3450 5450
Wire Wire Line
	3450 5450 3450 5950
Wire Wire Line
	3500 5950 3450 5950
Connection ~ 3450 5950
Wire Wire Line
	3450 5950 3450 6450
Wire Wire Line
	3500 6450 3450 6450
Connection ~ 3450 6450
Wire Wire Line
	3450 6450 3450 6950
Wire Wire Line
	3500 6950 3450 6950
Connection ~ 3450 6950
Wire Wire Line
	3850 5450 3800 5450
Wire Wire Line
	3800 5450 3800 5950
Wire Wire Line
	3850 5950 3800 5950
Connection ~ 3800 5950
Wire Wire Line
	3800 5950 3800 6450
Wire Wire Line
	3850 6450 3800 6450
Connection ~ 3800 6450
Wire Wire Line
	3800 6450 3800 6950
Wire Wire Line
	3850 6950 3800 6950
Connection ~ 3800 6950
Wire Wire Line
	4200 5450 4150 5450
Wire Wire Line
	4150 5450 4150 5950
Wire Wire Line
	4200 5950 4150 5950
Connection ~ 4150 5950
Wire Wire Line
	4150 5950 4150 6450
Wire Wire Line
	4200 6450 4150 6450
Connection ~ 4150 6450
Wire Wire Line
	4150 6450 4150 6950
Wire Wire Line
	4200 6950 4150 6950
Connection ~ 4150 6950
Wire Wire Line
	4550 5450 4500 5450
Wire Wire Line
	4500 5450 4500 5950
Wire Wire Line
	4550 5950 4500 5950
Connection ~ 4500 5950
Wire Wire Line
	4500 5950 4500 6450
Wire Wire Line
	4550 6450 4500 6450
Connection ~ 4500 6450
Wire Wire Line
	4500 6450 4500 6950
Wire Wire Line
	4550 6950 4500 6950
Connection ~ 4500 6950
Wire Wire Line
	4950 5450 4900 5450
Wire Wire Line
	4900 5450 4900 5950
Wire Wire Line
	4950 5950 4900 5950
Connection ~ 4900 5950
Wire Wire Line
	4900 5950 4900 6450
Wire Wire Line
	4950 6450 4900 6450
Connection ~ 4900 6450
Wire Wire Line
	4900 6450 4900 6950
Wire Wire Line
	4950 6950 4900 6950
Connection ~ 4900 6950
Wire Wire Line
	5350 5450 5300 5450
Wire Wire Line
	5300 5450 5300 5950
Wire Wire Line
	5350 5950 5300 5950
Connection ~ 5300 5950
Wire Wire Line
	5350 6950 5300 6950
Connection ~ 5300 6950
Text GLabel 650  5050 0    50   Input ~ 0
R0
$Comp
L STM32G071RB:STM32G071RB U1
U 1 1 5D5839E0
P 2950 3250
F 0 "U1" H 2900 4650 50  0000 L CNN
F 1 "STM32G071RB" H 2700 3300 50  0000 L CNN
F 2 "fiftyseven:STM32G0-LQFP-64" H 2050 3450 50  0001 C CNN
F 3 "" H 2050 3450 50  0001 C CNN
	1    2950 3250
	1    0    0    -1  
$EndComp
Text GLabel 4100 3100 2    50   BiDi ~ 0
SDA
Text GLabel 3000 4400 3    50   Output ~ 0
RX
Text GLabel 3100 4400 3    50   Input ~ 0
TX
Wire Wire Line
	1800 3200 1700 3200
Wire Wire Line
	1700 3200 1700 3100
Wire Wire Line
	1700 3000 1800 3000
Wire Wire Line
	1800 3100 1700 3100
Connection ~ 1700 3100
Wire Wire Line
	1700 3100 1700 3000
$Comp
L power:GND #PWR0126
U 1 1 5D6CB3AE
P 700 3400
F 0 "#PWR0126" H 700 3150 50  0001 C CNN
F 1 "GND" H 705 3227 50  0000 C CNN
F 2 "" H 700 3400 50  0001 C CNN
F 3 "" H 700 3400 50  0001 C CNN
	1    700  3400
	1    0    0    -1  
$EndComp
Text GLabel 4100 2800 2    50   BiDi ~ 0
SWDIO
Text GLabel 4100 2700 2    50   BiDi ~ 0
SWDCLK
$Comp
L power:GND #PWR0128
U 1 1 5D7123B9
P 5000 2350
F 0 "#PWR0128" H 5000 2100 50  0001 C CNN
F 1 "GND" H 5005 2177 50  0000 C CNN
F 2 "" H 5000 2350 50  0001 C CNN
F 3 "" H 5000 2350 50  0001 C CNN
	1    5000 2350
	1    0    0    -1  
$EndComp
$Comp
L Device:C C13
U 1 1 5D716888
P 1600 3150
F 0 "C13" H 1600 3250 50  0000 L CNN
F 1 "1uF" H 1600 3050 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 1638 3000 50  0001 C CNN
F 3 "~" H 1600 3150 50  0001 C CNN
	1    1600 3150
	1    0    0    -1  
$EndComp
$Comp
L Device:C C12
U 1 1 5D717F33
P 1300 3150
F 0 "C12" H 1300 3250 50  0000 L CNN
F 1 "100nF" H 1300 3050 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 1338 3000 50  0001 C CNN
F 3 "~" H 1300 3150 50  0001 C CNN
	1    1300 3150
	1    0    0    -1  
$EndComp
$Comp
L Device:C C11
U 1 1 5D718486
P 1000 3150
F 0 "C11" H 1000 3250 50  0000 L CNN
F 1 "4.7uF" H 1000 3050 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 1038 3000 50  0001 C CNN
F 3 "~" H 1000 3150 50  0001 C CNN
	1    1000 3150
	1    0    0    -1  
$EndComp
$Comp
L Device:C C10
U 1 1 5D73ABC6
P 700 3150
F 0 "C10" H 700 3250 50  0000 L CNN
F 1 "100nF" H 700 3050 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 738 3000 50  0001 C CNN
F 3 "~" H 700 3150 50  0001 C CNN
	1    700  3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 3000 1600 3000
Connection ~ 1700 3000
Connection ~ 1000 3000
Connection ~ 1600 3000
Wire Wire Line
	1600 3300 1800 3300
Connection ~ 1300 3000
Wire Wire Line
	1300 3000 1600 3000
Wire Wire Line
	1000 3000 1300 3000
Wire Wire Line
	700  3000 1000 3000
Wire Wire Line
	700  3300 1000 3300
Connection ~ 1600 3300
Connection ~ 1000 3300
Wire Wire Line
	1000 3300 1300 3300
Connection ~ 1300 3300
Wire Wire Line
	1300 3300 1600 3300
Text GLabel 7500 3850 2    50   Input ~ 0
DB0
Text GLabel 7500 3950 2    50   Input ~ 0
DB1
Text GLabel 7500 4050 2    50   Input ~ 0
DB2
Text GLabel 7500 4150 2    50   Input ~ 0
DB3
Text GLabel 7500 4250 2    50   Input ~ 0
DB4
Text GLabel 7500 4350 2    50   Input ~ 0
DB5
Text GLabel 7500 4450 2    50   Input ~ 0
DB6
Text GLabel 7500 4550 2    50   Input ~ 0
DB7
$Comp
L power:GND #PWR0129
U 1 1 5D8815FC
P 6800 5700
F 0 "#PWR0129" H 6800 5450 50  0001 C CNN
F 1 "GND" H 6805 5527 50  0000 C CNN
F 2 "" H 6800 5700 50  0001 C CNN
F 3 "" H 6800 5700 50  0001 C CNN
	1    6800 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 5600 6500 5700
Wire Wire Line
	6500 5700 6600 5700
Wire Wire Line
	6600 5700 6600 5600
Connection ~ 6600 5700
Wire Wire Line
	6600 5700 6700 5700
Wire Wire Line
	6700 5700 6700 5600
Wire Wire Line
	7100 5600 7100 5700
Wire Wire Line
	7100 5700 7000 5700
Connection ~ 6700 5700
Wire Wire Line
	6800 5600 6800 5700
Connection ~ 6800 5700
Wire Wire Line
	6800 5700 6700 5700
Wire Wire Line
	6900 5600 6900 5700
Connection ~ 6900 5700
Wire Wire Line
	6900 5700 6800 5700
Wire Wire Line
	7000 5600 7000 5700
Connection ~ 7000 5700
Wire Wire Line
	7000 5700 6900 5700
Text GLabel 3200 4400 3    50   Output ~ 0
DB0
Text GLabel 3300 4400 3    50   Output ~ 0
DB1
Text GLabel 3400 4400 3    50   Output ~ 0
DB2
Text GLabel 2900 2100 1    50   Output ~ 0
DB3
Text GLabel 2800 2100 1    50   Output ~ 0
DB4
Text GLabel 2700 2100 1    50   Output ~ 0
DB5
Text GLabel 2600 2100 1    50   Output ~ 0
DB6
Text GLabel 2500 2100 1    50   Output ~ 0
DB7
$Comp
L power:GND #PWR0132
U 1 1 5DA74781
P 5750 4400
F 0 "#PWR0132" H 5750 4150 50  0001 C CNN
F 1 "GND" H 5755 4227 50  0000 C CNN
F 2 "" H 5750 4400 50  0001 C CNN
F 3 "" H 5750 4400 50  0001 C CNN
	1    5750 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 4400 6100 4400
Text GLabel 6100 4500 0    50   Input ~ 0
DC
Text GLabel 6000 4600 0    50   Input ~ 0
~WR
Text GLabel 6100 4700 0    50   Input ~ 0
~RD
Text GLabel 6000 4800 0    50   Input ~ 0
~RES
Wire Wire Line
	6000 4800 6100 4800
Wire Wire Line
	6000 4600 6100 4600
Text GLabel 4100 2500 2    50   Output ~ 0
DC
Text GLabel 4100 2600 2    50   Output ~ 0
~WR
Text GLabel 4100 3400 2    50   Output ~ 0
~RD
Wire Wire Line
	5300 5950 5300 6950
Wire Wire Line
	3100 6950 3100 7600
Wire Wire Line
	3450 6950 3450 7600
Wire Wire Line
	3800 6950 3800 7600
Wire Wire Line
	4150 6950 4150 7600
Wire Wire Line
	4500 6950 4500 7600
Wire Wire Line
	4900 6950 4900 7600
Wire Wire Line
	5300 6950 5300 7600
$Comp
L Switch:SW_Push SW:ESC1
U 1 1 5E38BBE4
P 700 4300
F 0 "SW:ESC1" V 700 4448 50  0000 L CNN
F 1 "SW_Push" V 745 4448 50  0001 L CNN
F 2 "fiftyseven:4.5mm-switch" H 700 4500 50  0001 C CNN
F 3 "~" H 700 4500 50  0001 C CNN
	1    700  4300
	0    1    1    0   
$EndComp
Text GLabel 700  4500 3    50   Output ~ 0
ESC
Text GLabel 1800 2500 0    50   Output ~ 0
R0
Text GLabel 1800 2600 0    50   Output ~ 0
R1
Text GLabel 1800 2700 0    50   Output ~ 0
R2
Text GLabel 1800 2800 0    50   Output ~ 0
R3
Text GLabel 1800 2900 0    50   Output ~ 0
R4
Text GLabel 1800 3500 0    50   Input ~ 0
C0
Text GLabel 1350 7600 3    50   Output ~ 0
C1
Text GLabel 1800 3700 0    50   Input ~ 0
C1
Text GLabel 1800 3800 0    50   Input ~ 0
C2
Text GLabel 1800 3900 0    50   Input ~ 0
C3
Text GLabel 1800 4000 0    50   Input ~ 0
C4
Text GLabel 2200 4400 3    50   Input ~ 0
C5
Text GLabel 2300 4400 3    50   Input ~ 0
C6
Text GLabel 2400 4400 3    50   Input ~ 0
C7
Text GLabel 2500 4400 3    50   Input ~ 0
C8
Text GLabel 2600 4400 3    50   Input ~ 0
C9
Text GLabel 2700 4400 3    50   Input ~ 0
C10
Text GLabel 2800 4400 3    50   Input ~ 0
C11
Text GLabel 2900 4400 3    50   Input ~ 0
C12
Text GLabel 1800 3400 0    50   Input ~ 0
ESC
Wire Wire Line
	2750 6950 2750 7600
$Comp
L power:GND #PWR05
U 1 1 5D8A9111
P 5350 2400
F 0 "#PWR05" H 5350 2150 50  0001 C CNN
F 1 "GND" H 5350 2250 50  0000 C CNN
F 2 "" H 5350 2400 50  0001 C CNN
F 3 "" H 5350 2400 50  0001 C CNN
	1    5350 2400
	1    0    0    -1  
$EndComp
Text GLabel 2400 2100 1    50   Output ~ 0
DB8
Text GLabel 2300 2100 1    50   Output ~ 0
DB9
Text GLabel 3500 4400 3    50   Output ~ 0
DB10
Text GLabel 3600 4400 3    50   Output ~ 0
DB11
Text GLabel 3700 4400 3    50   Output ~ 0
DB12
Text GLabel 4100 4000 2    50   Output ~ 0
DB13
Text GLabel 4100 3900 2    50   Output ~ 0
DB14
Text GLabel 4100 3800 2    50   Output ~ 0
DB15
Wire Wire Line
	6700 3600 6700 3500
Wire Wire Line
	6800 3600 6800 3500
Text GLabel 7500 4650 2    50   Input ~ 0
DB8
Text GLabel 7500 4750 2    50   Input ~ 0
DB9
Text GLabel 7500 4850 2    50   Input ~ 0
DB10
Text GLabel 7500 4950 2    50   Input ~ 0
DB11
Text GLabel 7500 5050 2    50   Input ~ 0
DB12
Text GLabel 7500 5150 2    50   Input ~ 0
DB13
Text GLabel 7500 5250 2    50   Input ~ 0
DB14
Text GLabel 7500 5350 2    50   Input ~ 0
DB15
Text GLabel 6100 4900 0    50   Input ~ 0
IM0
Wire Wire Line
	700  2850 700  3000
Connection ~ 700  3000
Wire Wire Line
	700  3300 700  3400
Connection ~ 700  3300
$Comp
L Device:R R12
U 1 1 5D6CD2A9
P 5000 2200
F 0 "R12" H 4800 2150 50  0000 L CNN
F 1 "10k" H 4800 2250 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4930 2200 50  0001 C CNN
F 3 "~" H 5000 2200 50  0001 C CNN
	1    5000 2200
	-1   0    0    1   
$EndComp
$Comp
L Device:R R10
U 1 1 5D5A7892
P 6050 1900
F 0 "R10" H 6120 1946 50  0000 L CNN
F 1 "4.7k" H 6120 1855 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5980 1900 50  0001 C CNN
F 3 "~" H 6050 1900 50  0001 C CNN
	1    6050 1900
	1    0    0    -1  
$EndComp
Text GLabel 4100 3600 2    50   BiDi ~ 0
SCL
Text GLabel 5600 2100 2    50   Output ~ 0
RESET
$Comp
L Device:C C17
U 1 1 5D8A8A7C
P 5350 2250
F 0 "C17" H 5450 2200 50  0000 L CNN
F 1 "100nF" H 5350 2100 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 5388 2100 50  0001 C CNN
F 3 "~" H 5350 2250 50  0001 C CNN
	1    5350 2250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5DAA8E2F
P 5350 1900
F 0 "R1" H 5420 1946 50  0000 L CNN
F 1 "10k" H 5420 1855 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5280 1900 50  0001 C CNN
F 3 "~" H 5350 1900 50  0001 C CNN
	1    5350 1900
	1    0    0    -1  
$EndComp
Text GLabel 1800 3600 0    50   Input ~ 0
RESET
Text GLabel 5000 2050 1    50   BiDi ~ 0
SWDCLK
$Comp
L power:+3V3 #PWR0104
U 1 1 5DA860BF
P 700 2850
F 0 "#PWR0104" H 700 2700 50  0001 C CNN
F 1 "+3V3" H 715 3023 50  0000 C CNN
F 2 "" H 700 2850 50  0001 C CNN
F 3 "" H 700 2850 50  0001 C CNN
	1    700  2850
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0107
U 1 1 5DA87715
P 5350 1750
F 0 "#PWR0107" H 5350 1600 50  0001 C CNN
F 1 "+3V3" H 5365 1923 50  0000 C CNN
F 2 "" H 5350 1750 50  0001 C CNN
F 3 "" H 5350 1750 50  0001 C CNN
	1    5350 1750
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0108
U 1 1 5DA87CD1
P 6050 1750
F 0 "#PWR0108" H 6050 1600 50  0001 C CNN
F 1 "+3V3" H 6065 1923 50  0000 C CNN
F 2 "" H 6050 1750 50  0001 C CNN
F 3 "" H 6050 1750 50  0001 C CNN
	1    6050 1750
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0109
U 1 1 5DA88178
P 6350 1750
F 0 "#PWR0109" H 6350 1600 50  0001 C CNN
F 1 "+3V3" H 6365 1923 50  0000 C CNN
F 2 "" H 6350 1750 50  0001 C CNN
F 3 "" H 6350 1750 50  0001 C CNN
	1    6350 1750
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR0101
U 1 1 5DA7E01B
P 8650 2550
F 0 "#PWR0101" H 8650 2400 50  0001 C CNN
F 1 "+BATT" V 8650 2750 50  0000 C CNN
F 2 "" H 8650 2550 50  0001 C CNN
F 3 "" H 8650 2550 50  0001 C CNN
	1    8650 2550
	0    -1   -1   0   
$EndComp
$Comp
L power:VBUS #PWR0102
U 1 1 5DA7F5A5
P 8650 2350
F 0 "#PWR0102" H 8650 2200 50  0001 C CNN
F 1 "VBUS" V 8650 2550 50  0000 C CNN
F 2 "" H 8650 2350 50  0001 C CNN
F 3 "" H 8650 2350 50  0001 C CNN
	1    8650 2350
	0    -1   -1   0   
$EndComp
Text GLabel 8650 1550 0    50   BiDi ~ 0
SCL
Text GLabel 8650 1450 0    50   BiDi ~ 0
SDA
Text GLabel 8650 2450 0    50   Input ~ 0
EN
Text GLabel 8650 1650 0    50   BiDi ~ 0
D0
Text GLabel 8650 1750 0    50   BiDi ~ 0
D1
Text GLabel 8650 1850 0    50   BiDi ~ 0
D2
Text GLabel 8650 1950 0    50   BiDi ~ 0
D3
Text GLabel 8650 2050 0    50   BiDi ~ 0
D4
Text GLabel 8650 2150 0    50   BiDi ~ 0
D5
Text GLabel 8650 2250 0    50   BiDi ~ 0
D6
Wire Wire Line
	5600 2100 5350 2100
Wire Wire Line
	5350 2100 5350 2050
Connection ~ 5350 2100
$Comp
L Connector:Conn_01x28_Female J1
U 1 1 5DB70253
P 8850 2750
F 0 "J1" H 8878 2726 50  0000 L CNN
F 1 "Feather" H 8878 2635 50  0000 L CNN
F 2 "fiftyseven:FeatherHolderSMD" H 8850 2750 50  0001 C CNN
F 3 "~" H 8850 2750 50  0001 C CNN
	1    8850 2750
	1    0    0    -1  
$EndComp
Text GLabel 8650 3550 0    50   BiDi ~ 0
A5
Text GLabel 8650 3450 0    50   BiDi ~ 0
A4
Text GLabel 8650 3350 0    50   BiDi ~ 0
A3
Text GLabel 8650 3250 0    50   BiDi ~ 0
A2
Text GLabel 8650 3150 0    50   BiDi ~ 0
A1
Text GLabel 8650 3050 0    50   BiDi ~ 0
A0
Text GLabel 8650 4150 0    50   BiDi ~ 0
FREE
Text GLabel 8650 2850 0    50   Input ~ 0
AREF
Text GLabel 8650 2650 0    50   Output ~ 0
RESET
$Comp
L power:+3V3 #PWR0110
U 1 1 5DA859F5
P 8650 2750
F 0 "#PWR0110" H 8650 2600 50  0001 C CNN
F 1 "+3V3" V 8650 3000 50  0000 C CNN
F 2 "" H 8650 2750 50  0001 C CNN
F 3 "" H 8650 2750 50  0001 C CNN
	1    8650 2750
	0    -1   -1   0   
$EndComp
Text GLabel 8650 4050 0    50   Output ~ 0
TX
Text GLabel 8650 3950 0    50   Input ~ 0
RX
Text GLabel 8650 3850 0    50   BiDi ~ 0
MISO
Text GLabel 8650 3750 0    50   BiDi ~ 0
MOSI
Text GLabel 8650 3650 0    50   BiDi ~ 0
SCK
$Comp
L power:GND #PWR0103
U 1 1 5DA801C8
P 8650 2950
F 0 "#PWR0103" H 8650 2700 50  0001 C CNN
F 1 "GND" V 8655 2777 50  0000 C CNN
F 2 "" H 8650 2950 50  0001 C CNN
F 3 "" H 8650 2950 50  0001 C CNN
	1    8650 2950
	0    1    1    0   
$EndComp
Text GLabel 4100 3700 2    50   Output ~ 0
IM0
Text GLabel 4100 3500 2    50   Output ~ 0
~RES
$Comp
L power:+3V3 #PWR0105
U 1 1 5DD7E742
P 700 4100
F 0 "#PWR0105" H 700 3950 50  0001 C CNN
F 1 "+3V3" H 715 4273 50  0000 C CNN
F 2 "" H 700 4100 50  0001 C CNN
F 3 "" H 700 4100 50  0001 C CNN
	1    700  4100
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x05_Male J2
U 1 1 5D80D587
P 5050 3250
F 0 "J2" H 5158 3631 50  0000 C CNN
F 1 "STM32 SWD" H 5158 3540 50  0000 C CNN
F 2 "fiftyseven:SWD_Header" H 5050 3250 50  0001 C CNN
F 3 "~" H 5050 3250 50  0001 C CNN
	1    5050 3250
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0111
U 1 1 5D80DFFD
P 5250 3050
F 0 "#PWR0111" H 5250 2900 50  0001 C CNN
F 1 "+3V3" V 5250 3250 50  0000 C CNN
F 2 "" H 5250 3050 50  0001 C CNN
F 3 "" H 5250 3050 50  0001 C CNN
	1    5250 3050
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0112
U 1 1 5D80E664
P 5250 3150
F 0 "#PWR0112" H 5250 2900 50  0001 C CNN
F 1 "GND" V 5255 2977 50  0000 C CNN
F 2 "" H 5250 3150 50  0001 C CNN
F 3 "" H 5250 3150 50  0001 C CNN
	1    5250 3150
	0    -1   -1   0   
$EndComp
Text GLabel 5250 3250 2    50   BiDi ~ 0
SWDIO
Text GLabel 5250 3350 2    50   BiDi ~ 0
SWDCLK
Text GLabel 5250 3450 2    50   Output ~ 0
RESET
$Comp
L 240x320_16bit:240x320_16bit U6
U 1 1 5D6131E0
P 6800 4600
F 0 "U6" H 6250 5550 50  0000 C CNN
F 1 "240x320_16bit" H 6800 4600 50  0000 C CNN
F 2 "fiftyseven:LCD-320x240" H 6700 4900 50  0001 C CNN
F 3 "" H 6700 4900 50  0001 C CNN
	1    6800 4600
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H1
U 1 1 5D85B0BB
P 9900 2450
F 0 "H1" H 10000 2496 50  0000 L CNN
F 1 "MountingHole" H 10000 2405 50  0000 L CNN
F 2 "Mounting_Holes:MountingHole_5mm" H 9900 2450 50  0001 C CNN
F 3 "~" H 9900 2450 50  0001 C CNN
	1    9900 2450
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPDT SW1
U 1 1 5D85C95E
P 10000 3400
F 0 "SW1" H 10000 3075 50  0000 C CNN
F 1 "SW_SPDT" H 10000 3166 50  0000 C CNN
F 2 "Buttons_Switches_SMD:SW_SPDT_CK-JS102011SAQN" H 10000 3400 50  0001 C CNN
F 3 "~" H 10000 3400 50  0001 C CNN
	1    10000 3400
	1    0    0    1   
$EndComp
NoConn ~ 10200 3300
Text GLabel 9800 3400 0    50   Input ~ 0
EN
$Comp
L power:GND #PWR0113
U 1 1 5D868B31
P 10300 3500
F 0 "#PWR0113" H 10300 3250 50  0001 C CNN
F 1 "GND" H 10305 3327 50  0000 C CNN
F 2 "" H 10300 3500 50  0001 C CNN
F 3 "" H 10300 3500 50  0001 C CNN
	1    10300 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	10200 3500 10300 3500
$Comp
L p-channel:ZXMP6A13FQ Q1
U 1 1 5DEA7C64
P 6450 3100
F 0 "Q1" H 6650 3200 50  0000 L CNN
F 1 "ZXMP6A13FQ" H 6000 3300 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23_Handsoldering" H 6650 3025 50  0001 L CIN
F 3 "http://www.vishay.com/docs/70209/70209.pdf" H 6450 3100 50  0001 L CNN
	1    6450 3100
	1    0    0    1   
$EndComp
$Comp
L p-channel:ZXMP6A13FQ Q2
U 1 1 5DEC2F81
P 7000 3100
F 0 "Q2" H 6850 3200 50  0000 L CNN
F 1 "ZXMP6A13FQ" H 6500 3300 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23_Handsoldering" H 7200 3025 50  0001 L CIN
F 3 "http://www.vishay.com/docs/70209/70209.pdf" H 7000 3100 50  0001 L CNN
	1    7000 3100
	-1   0    0    1   
$EndComp
$Comp
L power:+3V3 #PWR0106
U 1 1 5DEC41D5
P 6750 2300
F 0 "#PWR0106" H 6750 2150 50  0001 C CNN
F 1 "+3V3" H 6765 2473 50  0000 C CNN
F 2 "" H 6750 2300 50  0001 C CNN
F 3 "" H 6750 2300 50  0001 C CNN
	1    6750 2300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5DEC44E9
P 6250 2800
F 0 "R2" H 6320 2846 50  0000 L CNN
F 1 "47k" H 6320 2755 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6180 2800 50  0001 C CNN
F 3 "~" H 6250 2800 50  0001 C CNN
	1    6250 2800
	1    0    0    1   
$EndComp
$Comp
L Device:R R3
U 1 1 5DEC4D92
P 7200 2750
F 0 "R3" H 7270 2796 50  0000 L CNN
F 1 "47k" H 7270 2705 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 7130 2750 50  0001 C CNN
F 3 "~" H 7200 2750 50  0001 C CNN
	1    7200 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 2450 6750 2450
Wire Wire Line
	6900 3300 6900 3600
Connection ~ 6750 2450
Wire Wire Line
	6750 2450 6900 2450
Text GLabel 6150 3100 0    50   Output ~ 0
LCD_POWER
Text GLabel 7300 3100 2    50   Output ~ 0
BACKLIGHT_POWER
Text GLabel 3700 2100 1    50   Output ~ 0
BACKLIGHT_POWER
Text GLabel 3600 2100 1    50   Output ~ 0
LCD_POWER
Wire Wire Line
	6550 2450 6550 2900
Wire Wire Line
	6900 2450 6900 2900
Wire Wire Line
	7200 2600 7200 2450
Wire Wire Line
	7200 2450 6900 2450
Connection ~ 6900 2450
Wire Wire Line
	6550 2450 6250 2450
Wire Wire Line
	6250 2450 6250 2650
Connection ~ 6550 2450
Wire Wire Line
	6250 2950 6250 3100
Wire Wire Line
	6150 3100 6250 3100
Connection ~ 6250 3100
Wire Wire Line
	7200 2900 7200 3100
Wire Wire Line
	7300 3100 7200 3100
Connection ~ 7200 3100
Wire Wire Line
	6750 2300 6750 2450
Wire Wire Line
	6550 3300 6550 3500
Wire Wire Line
	6550 3500 6700 3500
Connection ~ 6700 3500
Wire Wire Line
	6700 3500 6800 3500
$EndSCHEMATC

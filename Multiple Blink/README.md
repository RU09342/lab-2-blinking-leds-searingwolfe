MSP430 Microprocessors (5 boards):
------------------------------------------
MSP430F5529
MSP430FR2311
MSP430FR5994
MSP430FR6989
MSP430G2553
------------------------------------------

Multiple LED Blink

------------------------------------------

The code begins with turning off the on-board watchdog timer control. The next line sets the red LED and green LED (pin names are different for most boards) to be outputs and to produce Vcc for illuminating them. The LED pins themselves are designated as BIT values (i.e. P1OUT = BIT0 for LED with pin name P1.0). If the LEDs have the same P pin value (i.e. P1.0 and P1.1), then they are placed in the same line separated by a + sign (i.e. P1DIR = BIT0 + BIT1). If not, then they are separated into two different lines (i.e. P1DIR = BIT0; P2DIR = BIT0). An infinite while-loop toggles on and off the dual LED illumination with a delay specified as 50000 cycles, or 0.045 second delays. The operation ^= controls the toggling (i.e. P1OUT ^= BIT0).

This code is almost identical for every board, with the exception found in three of them. The MSP430FR boards require one extra line to implement the same code for blinking the LEDs, which disables the GPIO power-on default high-impedance mode for activating the configured In/Out port settings (PM5CTL0 &= ~LOCKLPM5).

------------------------------------------

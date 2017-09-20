MSP430 Microprocessors (5 boards):
------------------------------------------
MSP430F5529
MSP430FR2311
MSP430FR5994
MSP430FR6989
MSP430G2553
------------------------------------------

Off-Board LED Blink

------------------------------------------

The code begins with turning off the on-board watchdog timer control. The next line sets a GPIO output pin (pin name is different for most boards) to be an output and to produce Vcc for sending current through it. The GPIO pin itself is designated as a BIT value (i.e. P2OUT = BIT5 for GPIO pin with pin name P2.5). The code in general is almost identical to the simple LED blink. An infinite while-loop toggles on and off the LED illumination with a delay specified as 50000 cycles, or 0.045 second delays. The operation ^= controls the toggling (i.e. P1OUT ^= BIT0). When hooking up the GND pin and designated GPIO pin to an LED (in series with a resistor) on a breadboard, the LED blinks on and off.

This code is almost identical for every board, with the exception found in three of them. The MSP430FR boards require one extra line to implement the same code for blinking an LED, which disables the GPIO power-on default high-impedance mode for activating the configured In/Out port settings (PM5CTL0 &= ~LOCKLPM5).

------------------------------------------

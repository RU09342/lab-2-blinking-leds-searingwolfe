MSP430 Microprocessors (5 boards):
------------------------------------------
MSP430F5529
MSP430FR2311
MSP430FR5994
MSP430FR6989
MSP430G2553
------------------------------------------

Button LED Blink

------------------------------------------

The code begins with turning off the on-board watchdog timer control. The next line sets the red LED (pin name is different for most boards) to be an output and to produce Vcc for illuminating it. The LED pin itself is designated as a BIT value (i.e. P1OUT = BIT0 for LED with pin name P1.0), along with the push-button pin name. The input pin for a push-button is given a pullup/pulldown resistor for clamping the on-off signals (i.e. P1REN = BIT3). Then this same internal resistor is defined on a new line to connect to Vcc, making it a pullup resistor (i.e. P1OUT = BIT3). An infinite while-loop toggles on and off the LED illumination with a delay specified as 50000 cycles, or 0.045 second delays. The operation ^= controls the toggling (i.e. P1OUT ^= BIT0). However, these operations are found within an if-statement within the while-loop. The if-statement waits for the button-pressed condition to occur before performing any LED toggling (i.e. if((P1IN & BIT3) != BIT3).

This code is almost identical for every board, with the exception found in three of them. The MSP430FR boards require one extra line to implement the same code for blinking an LED with a button-press, which disables the GPIO power-on default high-impedance mode for activating the configured In/Out port settings (PM5CTL0 &= ~LOCKLPM5).

------------------------------------------

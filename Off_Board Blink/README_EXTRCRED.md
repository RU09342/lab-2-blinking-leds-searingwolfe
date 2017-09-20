MSP430 Microprocessors (5 boards):
------------------------------------------
MSP430F5529
MSP430FR2311
MSP430FR5994
MSP430FR6989
MSP430G2553
------------------------------------------

Off-Board LED Blink (Extra Credit)
4 GPIO pins used. 1 button-press implemented.
Pressing button cycles through 4 different delay-cycle speeds.

------------------------------------------

The code begins with turning off the on-board watchdog timer control. The next line sets 4 GPIO output pins (pin names are different for most boards) to be outputs and to produce Vcc for sending current through them. The GPIO pins themselves are designated as BIT values (i.e. P2OUT = BIT5 for GPIO pin with pin name P2.5), along with the push-button pin name. The input pin for a push-button is given a pullup/pulldown resistor for clamping the on-off signals (i.e. P1REN = BIT3). Then this same internal resistor is defined on a new line to connect to Vcc, making it a pullup resistor (i.e. P1OUT = BIT3). An integer variable X is declared, which will increase after a previous button-press was made. Increasing from 0 to 3 in the while-loop and within if-statements, this allows 4 different possible LED blinking speeds to be cycled through using only one button. An infinite while-loop toggles on and off the LED illuminations with a delay specified as 1 of 4 possible cycles (LEDs are not illuminated at first until button is pressed). The operation ^= controls the toggling (i.e. P1OUT ^= BIT0). Two if-statements are used for each of the 4 possible button-press cycles: one that waits for the button-is-pressed condition, which activates the blinking of the LEDs (similar to the Button LED Blink code), and another that waits for the button-is-released condition, which only serves to increment the X variable by 1. Thus, the 4 button-is-pressed conditions for the if-statements activating the 4 different LED blink-rates use an additional AND condition for the value of the X variable (i.e. else if(((P1IN & BIT3)!=BIT3) & x == 1)).

When hooking up the GND pin and designated 4 GPIO pins to 4 LEDs (in series with a resistor) on a breadboard, the LEDs blink on and off at a slow rate after the first button-press. After the second press, the LEDs blink slightly faster. After the third press, the LEDs blink even faster. After the fourth press, the LEDs blink the fastest, and one additional button-press reset the cycle back to the slowest blink-rate.

This code is almost identical for every board, with the exception found in three of them. The MSP430FR boards require one extra line to implement the same code for blinking an LED, which disables the GPIO power-on default high-impedance mode for activating the configured In/Out port settings (PM5CTL0 &= ~LOCKLPM5).

------------------------------------------

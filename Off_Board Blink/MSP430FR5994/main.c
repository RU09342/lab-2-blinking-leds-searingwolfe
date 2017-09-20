#include <msp430fr5994.h>

//Off-Board Blink
void main()
{
    WDTCTL = WDTPW + WDTHOLD; //watchdog timer control, not using
    PM5CTL0 &= ~LOCKLPM5; // Disable the GPIO power-on default high-impedance mode to activate configured port settings
    P2DIR = BIT5; //set BIT5 to be output, P2.5
    P2OUT = BIT5; //turns on P2.5 and produces 3.3V
    
    while(1) //loop indefinitely
    {
        P2OUT ^= BIT5; //set the output of the pins. ^ means toggle
        _delay_cycles(50000); //delay for 50000 cycles.
        //default for one cycle = 0.9 microseconds to execute
        //50000 * 0.9us per cycle = 0.045 second delay
    }
} //attaching the chip to a breadboard, and wiring up Vcc and GND to the launchpad's Vcc and GND pins, an LED was wired in series with a 200 ohm resistor.
// the LED indeed flashes at a rate of 0.045 seconds.
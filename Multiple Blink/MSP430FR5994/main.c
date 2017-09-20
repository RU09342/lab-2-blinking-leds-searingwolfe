#include <msp430fr5994.h> 

//Multiple Blink
void main()
{
    WDTCTL = WDTPW + WDTHOLD; //watchdog timer control, not using
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode to activate configured port settings
    P1DIR = BIT0 + BIT1; //set BIT0 and BIT6 to be output
    P1OUT = BIT1 + BIT0; //turns on P1.6 and produces 3.3V
    
    while(1) //loop indefinitely
    {
        P1OUT ^= BIT0 + BIT1; //set the output of the pins. ^ means toggle
        _delay_cycles(50000); //delay for 50000 cycles.
    }
}
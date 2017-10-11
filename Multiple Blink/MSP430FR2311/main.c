#include <msp430fr2311.h> 

//Multiple Blink
void main()
{
    WDTCTL = WDTPW + WDTHOLD; //watchdog timer control, not using
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode to activate configured port settings
    P1DIR = BIT0; //set BIT0 and BIT6 to be output
    P1OUT = BIT0; //turns on P1.6 and produces 3.6V
    P2DIR = BIT0; //second LED is named P2.0 instead of P1.2
    P2OUT = BIT0;
    
    while(1) //loop indefinitely
    {
        P1OUT ^= BIT0; //set the output of the pins. ^ means toggle
        P2OUT ^= BIT0;
        _delay_cycles(50000); //delay for 50000 cycles.
    }
}
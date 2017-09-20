#include <msp430fr6989.h> 

//Multiple Blink
void main()
{
    WDTCTL = WDTPW + WDTHOLD; //watchdog timer control, not using
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode to activate configured port settings
    P1DIR = BIT0; //set BIT0 and BIT6 to be output
    P1OUT = BIT1; //turns on P1.6 and produces 3.3V
    P9DIR = BIT7; //second LED is named P9.7 instead of P1.2
    P9OUT = BIT7;
    
    while(1) //loop indefinitely
    {
        P1OUT ^= BIT0; //set the output of the pins. ^ means toggle
        P9OUT ^= BIT7;
        _delay_cycles(50000); //delay for 50000 cycles.
    }
}
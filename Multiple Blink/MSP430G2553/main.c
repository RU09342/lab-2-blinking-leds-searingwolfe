#include <msp430g2553.h> 

//Multiple Blink
void main()
{
    WDTCTL = WDTPW + WDTHOLD; //watchdog timer control, not using
    P1DIR = BIT0 + BIT6; //set BIT0 and BIT6 to be output
    P1OUT = BIT0 + BIT6; //turns on P1.6 and produces 3.6V
    
    while(1) //loop indefinitely
    {
        P1OUT ^= BIT0 + BIT6; //set the output of the pins. ^ means toggle
        _delay_cycles(50000); //delay for 50000 cycles.
        //default for one cycle = 0.9 microseconds to execute
        //50000 * 0.9us per cycle = 0.045 second delay
    }
}
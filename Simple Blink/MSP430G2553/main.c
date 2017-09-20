#include <msp430g2553.h> 

//Simple Blink
void main()
{
    WDTCTL = WDTPW + WDTHOLD; //watchdog timer control, not using
    P1DIR = BIT0; //set BIT0 to be output
    P1OUT = BIT0; //turns on P1.0 and produces 3.6V
    
    while(1) //loop indefinitely
    {
        P1OUT ^= BIT0; //set the output of the pins. ^ means toggle
        _delay_cycles(50000); //delay for 50000 cycles.
        //default for one cycle = 0.9 microseconds to execute
        //50000 * 0.9us per cycle = 0.045 second delay
    }
}
#include <msp430f5529.h> 

//Multiple Blink
void main()
{
    WDTCTL = WDTPW + WDTHOLD; //watchdog timer control, not using
    P1DIR = BIT0; //set BIT0 to be output
    P4DIR = BIT7;
    P1OUT = BIT0;
    P4OUT = BIT7; //turns on P4.7 and produces 3.3V
    
    while(1) //loop indefinitely
    {
        P1OUT ^= BIT0; //set the output of the pins. ^ means toggle
        P4OUT ^= BIT7;
        _delay_cycles(50000); //delay for 50000 cycles.
        //default for one cycle = 0.9 microseconds to execute
        //50000 * 0.9us per cycle = 0.045 second delay
    }
}
#include <msp430g2553.h>

 //Button Blink
void main(void)
{
    WDTCTL = WDTPW + WDTHOLD; //watchdog timer control
    P1DIR = BIT0; //make P1.0 the output pin, automatically assigns P1.1, P1.2, etc as inputs
    P1REN = BIT3; //internal resistor is enabled, P1.3 connects to either Vcc (3.6V) or ground
    P1OUT = BIT3; //P1.3 is an input pin; this line defines internal resistor to connect to 3.6V
					//the line above sets the pin as normally high (pull-up resistor)
					//if P1OUT &= ~BIT3, then internal resistor connects to ground (pull-down resistor)
    while(1) //loop indefinitely
    {
		//if button is pressed, then P1IN = 0; it is 1 by default
		
        if((P1IN & BIT3)!=BIT3) //logic AND. P1IN and BIT3 must be 1 for output to be 1
        { //line above means: if result of port 1 input AND P1.3 pin (ONE) is NOT equal to P1.3 (ONE), 
			//then it will execute the codes inside the loop.
            __delay_cycles(50000);
            P1OUT ^= BIT0;     
        }
    }
}
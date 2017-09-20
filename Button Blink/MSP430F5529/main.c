#include <msp430f5529.h>

 //Button Blink
void main(void)
{
    WDTCTL = WDTPW + WDTHOLD; //watchdog timer control
    P1DIR = BIT0; //make P1.0 the output pin, automatically assigns P1.1, P1.2, etc as inputs
    P2REN = BIT1; //internal resistor is enabled, P2.1 connects to either Vcc (3.3V) or ground
    P2OUT = BIT1; //P2.1 is an input pin; this line defines internal resistor to connect to 3.3V
					//the line above sets the pin as normally high (pull-up resistor)
					//if P1OUT &= ~BIT3, then internal resistor connects to ground (pull-down resistor)
    while(1) //loop indefinitely
    {
		//if button is pressed, then P1IN = 0; it is 1 by default
		
        if((P2IN & BIT1)!=BIT1) //logic AND. P2IN and BIT1 must be 1 for output to be 1
        { //line above means: if result of port 1 input AND P2.1 pin (ONE) is NOT equal to P2.1 (ONE), 
			//then it will execute the codes inside the loop.
            __delay_cycles(50000);
            P1OUT ^= BIT0;     
        }
    }
}
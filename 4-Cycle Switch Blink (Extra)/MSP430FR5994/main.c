#include <msp430fr5994.h>

//4-Cycle Switch Blink
void main()
{
    WDTCTL = WDTPW + WDTHOLD; //watchdog timer control, not using
    PM5CTL0 &= ~LOCKLPM5; // Disable the GPIO power-on default high-impedance mode to activate configured port settings
    P2DIR = BIT5 + BIT6; //set 4 pins to be output. The + sign means OR
    P2OUT = BIT5 + BIT6; //turns on 4 pins and produces 3.3V
    P4DIR = BIT3 + BIT2;
    P4OUT = BIT3 + BIT2;
    
    P5REN = BIT6; //internal resistor is enabled, P5.6 connects to either Vcc (3.3V) or ground
    P5OUT = BIT6; //P5.6 is an input pin; this line defines internal resistor to connect to 3.3V
    
    int x = 0; //defines a variable to toggle button between more than two blink-speeds. 4 speeds total.
    
    while(1) //loop indefinitely
    {
        //four different LEDs blinking simultaneously
        //P2OUT ^= BIT5 + BIT4 + BIT2 + BIT0; //set  + the output of the pins. ^ means toggle
        //_delay_cycles(500000); //delay for 500000 cycles. Commenting these out allows the code below to work properly.
        
        //button-press will make the LEDs blink faster.
        if(((P5IN & BIT6)!=BIT6) & x == 0) //logic AND. P5IN and BIT6 must be 1 for output to be 1
        { //line above means: if result of port 1 input AND P5.6 pin (ONE) is NOT equal to P5.6 (ONE), 
			//then it will execute the codes inside the loop.
			P2OUT ^= BIT5 + BIT6; //set  + the output of the pins. ^ means toggle
			P4OUT ^= BIT3 + BIT2;
            _delay_cycles(250000);
            if(((P5IN & BIT6)==BIT6) & x == 0)
            {
                x = 1; //change x variable to continue the cycling of multiple blink-speeds.
            }
        }
        else if(((P5IN & BIT6)!=BIT6) & x == 1)
        { 
			P2OUT ^= BIT5 + BIT6; //set  + the output of the pins. ^ means toggle
			P4OUT ^= BIT3 + BIT2;
            _delay_cycles(100000);
            if(((P5IN & BIT6)==BIT6) & x == 1)
            {
                x = 2; //change x variable to continue the cycling of multiple blink-speeds.
            }
        }
        else if(((P5IN & BIT6)!=BIT6) & x == 2)
        { 
			P2OUT ^= BIT5 + BIT6; //set  + the output of the pins. ^ means toggle
			P4OUT ^= BIT3 + BIT2;
            _delay_cycles(50000);
            if(((P5IN & BIT6)==BIT6) & x == 2)
            {
                x = 3; //change x variable to continue the cycling of multiple blink-speeds.
            }
        }
        else if(((P5IN & BIT6)!=BIT6) & x == 3)
        { 
			P2OUT ^= BIT5 + BIT6; //set  + the output of the pins. ^ means toggle
			P4OUT ^= BIT3 + BIT2;
            _delay_cycles(25000);
            if(((P5IN & BIT6)==BIT6) & x == 3)
            {
                x = 0; //change x variable to continue the cycling of multiple blink-speeds.
            }
        }
    }
} //attaching the chip to a breadboard, and wiring up Vcc and GND to the launchpad's Vcc and GND pins, an LED was wired in series with a 200 ohm resistor.

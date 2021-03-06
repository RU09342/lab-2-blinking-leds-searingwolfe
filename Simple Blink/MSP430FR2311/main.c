#include <msp430fr2311.h> 

//Simple Blink
void main()
{
    WDTCTL = WDTPW + WDTHOLD;               // Stop watchdog timer, can also use | instead of +
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode to activate configured port settings

    // Configure GPIO
    P1DIR = BIT0;                          // Set P1.0 to output direction, difficult to find the pin name of this LED on the board
    P1OUT = BIT0;                         // Clear P1.0 output latch for a defined power-on state
    
    while(1)
    {
        P1OUT ^= BIT0;                      // Toggle LED, also known as exclusive OR
        __delay_cycles(50000);
    }
}

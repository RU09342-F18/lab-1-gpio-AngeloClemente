/*
Angelo Clemente
Rowan University
Intro to Embedded Systems
Section 4
Email: clementea6@students.rowan.edu

Disclaimer: This code was not written by Angelo Clemnete. This is the built in code for blinking an LED on a MSP430G2553
from Code Composer Studio 8. The comments were edited by Angelo Clemente.
This code uses the generic msp430 series header file.
*/
#include <msp430.h>				


/**
 * blink.c
 */
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;		// Stops the watchdog timer from performing a system reset
	P1DIR |= 0x01;					// Sets P1.0 as output (LED)

	volatile unsigned int i;		// Volatile to prevent optimization, declares an unsigned int

	while(1)                        // Infinite loop
	{
		P1OUT ^= 0x01;				// Toggles P1.0 (LED) on/off depending on P1OUT's value
		for(i=50000; i>0; i--);     // For loop that delays by looping 50000 times
	}
}

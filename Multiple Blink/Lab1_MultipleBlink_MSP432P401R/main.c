/*
Angelo Clemente
Rowan University
Intro to Embedded Systems
Section 4
Email: clementea6@students.rowan.edu

Disclaimer: This code was not written by Angelo Clemnete. This is based on the built in code for blinking an LED on a MSP430G2553
from Code Composer Studio 8. The code was edited so that multiple LEDs blink at different rates for the MSP432P401R.
The comments were edited by Angelo Clemente.
This code uses the more generic msp header file since it is not part of the msp430 series.
*/

#include "msp.h"


/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// Stops the watchdog timer from performing a system reset

	P2SEL0 &=~(BIT1|BIT0);                          // Sets P2.0 and P2.1 as input/output pins
	P1SEL0 &=~BIT0;                                 // Sets P1.0 as input/output pin

	P2DIR |= 0x03;                                  // Sets P2.0 and P2.1 as outputs (LED2)
	P1DIR |= 0x01;                                  // Sets P1.0 as output (LED1)

	      for (;;)                                  // Infinite for loop
	      {
	        volatile unsigned int i;                // Volatile to prevent optimization, declares an unsigned int

	        P2OUT ^= 0x01;                          // Toggles P2.0 (LED2 Red) on/off using exclusive-OR


	        for(i = 50000; i>0; i--)                // For loop that iterates 50000 times as i decrements to cause delay
	        {
	            if(i == 50000) P2OUT ^= 0x02;       // The five conditional statements toggle P2.1 (LED2 Green) on/off
	            if(i == 40000) P2OUT ^= 0x02;       // using exclusive-OR
	            if(i == 30000) P2OUT ^= 0x02;       // LED2 Green toggles five times in the time it takes for
	            if(i == 20000) P2OUT ^= 0x02;       // LED2 Red to toggle
	            if(i == 10000) P2OUT ^= 0x02;

	            if(i == 50000) P1OUT ^= 0x01;       // The two conditional statements toggle P1.0 (LED1) on/off
	            if(i == 25000) P1OUT ^= 0x01;       // using exclusive-OR
	                                                // LED1 toggles two times in the time it takes for
	                                                // LED2 Red to toggle
	        }
	      }
}

/*
Angelo Clemente
Rowan University
Intro to Embedded Systems
Section 4
Email: clementea6@students.rowan.edu

Disclaimer: This code was not written by Angelo Clemnete. This is based on the built in code for blinking an LED on a MSP430G2553
from Code Composer Studio 8. The code was edited so that multiple LEDs blink at different rates.
The comments were edited by Angelo Clemente.
This code uses the generic msp430 series header file.
*/

#include <msp430.h>				


/**
 * blink.c
 */
void main(void)
{
    {
      WDTCTL = WDTPW + WDTHOLD;                 // Stops the watchdog timer from performing a system reset
      P1DIR |= 0x41;                            // Set P1.6 and P1.0 as outputs (LEDs)


      for (;;)                                  // Infinite loop
      {
        volatile unsigned int i;                // Volatile to prevent optimization, declares an unsigned int

        P1OUT ^= 0x01;                          // Toggles P1.0 (LED1) using exclusive-OR


        for(i = 50000; i>0; i--)                // For loop iterates 50000 times to cause a delay
        {
            if(i == 50000) P1OUT ^= 0x40;       // These five lines toggle P1.6 (LED2) using exclusive-OR
            if(i == 40000) P1OUT ^= 0x40;       // LED2 toggles five times in the time it takes for
            if(i == 30000) P1OUT ^= 0x40;       // LED1 to toggle
            if(i == 20000) P1OUT ^= 0x40;
            if(i == 10000) P1OUT ^= 0x40;
        }
      }
    }
}

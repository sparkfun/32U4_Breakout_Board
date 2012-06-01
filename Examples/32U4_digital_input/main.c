/* Created 05/22/2012 by Jordan McConnell at Sparkfun Electronics
 * This code is beerware, you know what I'm sayin'?
 *
 * Built on WinXP SP3 and WinAVR-20100110, AVRDUDE 5.10
 *
 * This code is a simple example of digital input for Sparkfun's
 * 32U4 Breakout Board using C and standard AVR libraries.  It
 * teaches you how to read the status of a digital pin to determine
 * whether its current status is HIGH or LOW.
 *
 * Pin PF0 is used as a digital input.  If its status is HIGH,
 * pin PD5 toggles each second, if it's status is LOW, pin PD6
 * toggles each second instead.
 *
 * The user can connect LED's to pins PD5 and PD6 or use a multimeter
 * to verify operation.  If pin PF0 is left unconnected, it's status
 * will be HIGH due to internal pullup resistors, and PD5 toggles.
 * If PF0 is connected to ground, PD6 toggles each second instead.
 */

// Libraries for register names and the delay function
#include <avr/io.h>
#include <util/delay.h>

// Macros to make bit manipulation easier
#define set_bit(address,bit) (address |= (1<<bit))
#define clear_bit(address,bit) (address &= ~(1<<bit))
#define toggle_bit(address,bit) (address ^= (1<<bit))

// This macro is for checking if a certain bit is set in a given register.
// This is useful here for checking the status of individual input pins.
#define check_bit(address,bit) ((address & (1<<bit)) == (1<<bit))

int main(void)
{
    // The following line sets bit 5 HIGH in register DDRD
    set_bit(DDRD,5); // Pin PD5 is now configured as an OUTPUT
    set_bit(DDRD,6); // Pin PD6 is now configured as an OUTPUT

    // The following line sets bit 0 LOW in register DDRF
    clear_bit(DDRF,0); // Pin PF0 is now configured as an INPUT
    set_bit(PORTF,0); // Turn on internal pullups for PF0

    while(1)
    {
        // PINF is the register you have to read to check if a particular
        // pin on port F (PFx) is HIGH or LOW
        if(check_bit(PINF,0))
        {
            // If PF0 is HIGH, toggle pin PD5's output status
            toggle_bit(PORTD,5);
        }
        else
        {
            // If PF0 is LOW, toggle pin PD6's output status
            toggle_bit(PORTD,6);
        }

        _delay_ms(1000); // Delay 1 second before checking PF0 again

    }

    return 0;
}

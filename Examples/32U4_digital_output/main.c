/* Created 05/20/2012 by Jordan McConnell at Sparkfun Electronics
 * This code is beerware, you know what I'm sayin'?
 *
 * Built on WinXP SP3 and WinAVR-20100110, AVRDUDE 5.10
 *
 * This code is a simple example of digital output for Sparkfun's
 * 32U4 Breakout Board using C and standard AVR libraries.  It
 * teaches you how to set a pin high or low or toggle it from one
 * state to the other using pin PD5 as an example.
 *
 * The user can use a multimeter or LED on pin PD5 to verify that
 * the pin is indeed changing state between HIGH and LOW each second.
 */

// Libraries for register names (DDRD, PORTD) and the delay function
#include <avr/io.h>
#include <util/delay.h>

// Macros to make bit manipulation easier
// Macro tutorial found here: http://www.cprogramming.com/tutorial/cpreprocessor.html
// Bit manipulation tutorial found here: http://www.avrfreaks.net/index.php?name=PNphpBB2&file=viewtopic&t=37871
#define set_bit(address,bit) (address |= (1<<bit)) // sets BIT to 1 in the register specified with ADDRESS
#define clear_bit(address,bit) (address &= ~(1<<bit)) // sets BIT to 0 in the register specified with ADDRESS
#define toggle_bit(address,bit) (address ^= (1<<bit)) // sets BIT to the opposite of what it's set to currently in the register specified with ADDRESS

int main(void)
{
    // The following line sets bit 5 high in register DDRD
    set_bit(DDRD,5); // Pin PD5 is now configured as an OUTPUT
    set_bit(PORTD,5); // Pin PD5 is now HIGH

    _delay_ms(1000);  // Delay for 1 second

    // The following line sets bit 5 low in register PORTD
    clear_bit(PORTD,5); // Pin PD5 is now LOW

    while(1)
    {
        _delay_ms(1000);
        toggle_bit(PORTD,5); // PD5 switches from LOW to HIGH or vice versa
    }

    return 0;
}

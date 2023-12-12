#define F_CPU 12000000UL // Define the CPU frequency as 16MHz

#include <avr/io.h>
#include <util/delay.h>

// Wiring: https://learn.sparkfun.com/tutorials/button-and-switch-basics/all
// Using momentary push button
// Input Pin connected to button in parallel with pull-up resistor to VCC
// GND connected to other side of button

#define BUTTON_PIN PA6 // Assuming the Button is connected to Pin PA6
// changed back PA6 to use pin change interrupt 
// each GPIO should have pin change interrupt

#define LED_PIN PC6 // Assuming the LED is connected to Pin PC6

int main(void) {
    // Set PA6 as input pin
    DDRA &= ~(1 << BUTTON_PIN);
    PORTA |= (1 << BUTTON_PIN); // Enable pull-up resistor of 10k Ohm
    

    // Set PC6 as output pin
    DDRC |= (1 << LED_PIN);

    while (1) {
        // Check if the button is pressed, software debounce
        if (!(PINA & (1 << BUTTON_PIN))) {
            // Toggle the LED
            PORTC ^= (1 << LED_PIN);
        }
        _delay_ms(100); // Wait 100ms to debounce, best time is 100ms, shorter is glitchy and longer needs longer button press
    }

    return 0;
}

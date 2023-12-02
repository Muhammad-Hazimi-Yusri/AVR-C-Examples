#define F_CPU 12000000UL // Define the CPU frequency as 16MHz

#include <avr/io.h>
#include <util/delay.h>


#define LED_PIN PC6 // Assuming the LED is connected to Pin PC6

int main(void) {
    // Set PC6 as output pin
    DDRC |= (1 << LED_PIN);

    while (1) {
        // Toggle the LED pin
        PORTC ^= (1 << LED_PIN);

        // Delay for 1 second
        _delay_ms(1000);
    }

    return 0;
}

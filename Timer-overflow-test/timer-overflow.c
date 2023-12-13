#define F_CPU 12000000UL // Define the CPU frequency as 16MHz

#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint16_t overflow_count = 0;

#define NEEDED_OVERFLOWS 9 // To get 3 seconds, we need 9 overflows (3 * 12MHz / 1024)
#define LED_PIN PC6 // Assuming the LED is connected to Pin PC6


// Timer1 initialization for 1-second periodic interrupts at 12MHz
void timer1_init() {
    // Set prescaler to 64 and start Timer1
    TCCR1B |= (1 << CS10) | (1 << CS11);

    // Enable Timer1 overflow interrupt
    TIMSK1 |= (1 << TOIE1);

    // Enable global interrupts
    sei();
}

// ISR for Timer1 overflow
ISR(TIMER1_OVF_vect) {
    overflow_count++;
    if (overflow_count >= NEEDED_OVERFLOWS) {  // Replace NEEDED_OVERFLOWS with the calculated value
        overflow_count = 0;
        PORTC ^= (1 << LED_PIN); // Toggle the LED
    }
}
int main(void) {
    // Initialize Timer1
    timer1_init();

    // Set PC6 as output pin
    DDRC |= (1 << LED_PIN);


    while (1) {
        // Rest of your main code
    }
    // Rest of your main code
}

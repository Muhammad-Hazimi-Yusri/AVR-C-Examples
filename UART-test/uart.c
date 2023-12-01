#include <avr/io.h>
#include <util/delay.h>

// yellow to PD1
// orange to PD0
// black to GND

// LED to PC6
#define LED_PIN PC6

// UART configuration
#define BAUD_RATE 9600
#define F_CPU 12000000UL  // Assuming a 12MHz clock frequency

void initUART() {
    // Set baud rate
    UBRR0 = F_CPU / (16UL * BAUD_RATE) - 1;

    // Enable transmitter and receiver
    UCSR0B = (1 << TXEN0) | (1 << RXEN0);

    // Set frame format: 8 data bits, 1 stop bit, no parity
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void sendUARTByte(uint8_t data) {
    // Wait for the buffer to be empty
    while (!(UCSR0A & (1 << UDRE0)))
        ;

    // Send the data
    UDR0 = data;
}

uint8_t receiveUARTByte() {
    // Wait for data to be received
    while (!(UCSR0A & (1 << RXC0)))
        ;

    // Return received data
    return UDR0;
}

void toggleLED() {
    // Assuming an LED is connected to Pin C6 (adjust as needed)
    PORTC ^= (1 << LED_PIN);
}

int main() {
    // Initialize UART
    initUART();
    
    // Set PC6 as output pin
    DDRC |= (1 << LED_PIN);     //DONT FORGET THIS

    while (1) {
        // Test sending
        sendUARTByte('A');
        // Test receiving
        uint8_t receivedData = receiveUARTByte();

        // Blink an LED based on received data
        if (receivedData == 'A') {
            // Toggle an LED or perform any other action
            toggleLED();
        }

        _delay_ms(1000); // Adjust delay as needed
    }

    return 0;
}

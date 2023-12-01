# Makefile for AVR-C code

# Compiler
CC = avr-gcc

# Compiler flags
CFLAGS = -mmcu=atmega644p -Wall -Os

# Source file
SRC = led.c

# Output file
OUTPUT = led

# Object file
OBJ = $(SRC:.c=.o)

all: $(OUTPUT).hex

$(OUTPUT).hex: $(OUTPUT)
	avr-objcopy -O ihex -R .eeprom $(OUTPUT) $(OUTPUT).hex

$(OUTPUT): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(OUTPUT)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)

flash: $(OUTPUT).hex
	avrdude -c usbasp -p m644p -U flash:w:$(OUTPUT).hex

clean:
	rm -f $(OUTPUT) $(OUTPUT).hex $(OBJ)


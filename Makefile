CC=avr-gcc
BOARD=atmega328p
CFLAGS=-Wall

default: 

flash: $(BUILD)
	sudo avrdude -p $(BOARD) -c dragon_isp =P usb -e -U flash:w:$(BUILD).hex

obj: $(BUILD).c 
	$(CC) $(CFLAGS) -Os -mmcu=$(BOARD) -c -o $(BUILD).o $(BUILD).c

elf: $(BUILD).o
	$(CC) $(CFLAGS) -mmcu=$(BOARD) $(BUILD).o -o $(BUILD).elf

hex: $(BUILD)
	avr-objcopy -O ihex -R .eeprom $(BUILD) $(BUILD).hex

gpio: gpio/gpio.c test/gpiotest.c

gpiotest: gpio/gpio.c test/gpiotest.c
	$(CC) $(CFLAGS) -Os -mmcu=$(BOARD) -o gpiotest.elf gpio/gpio.c test/gpiotest.c
	avr-objcopy -j .text -j .data -O ihex gpiotest.elf gpiotest.hex 
	sudo avrdude -p atmega328p -c dragon_isp -P usb -e -U flash:w:gpiotest.hex

clean: 
	$(RM) *.o *.hex *.elf $(BUILD)

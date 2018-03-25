# ATmega328p

A C library designed for use with the Atmel ATmega328 MCU. This is a lightweight yet powerful microcontroller great for hobbyist projects. 

[The Datasheet for the ATmega328 can be found here](http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-42735-8-bit-AVR-Microcontroller-ATmega328-328P_Datasheet.pdf)

This project is geared toward a UNIX-like environment but much of it can be applied to other operating systems. 

# Required

You will need: 

* An ATmega328p MCU. They can be acquired cheaply [on digikey.](https://www.digikey.com/product-detail/en/microchip-technology/ATMEGA328-PU/ATMEGA328-PU-ND/2271026)
* A way to flash your ATmega. There are tutorials for doing this with an Arduino. I have personally had a lot of luck with the AVR Dragon. They can often be found on ebay for under $30 if you're willing to shop around a bit. 
* With an AVR Dragon I highly recommend you purchase a [ZIF socket](https://www.adafruit.com/product/382?gclid=Cj0KCQjwkd3VBRDzARIsAAdGzMDcqFkFy3UdztMQvXvdBZ2_B7nwR5RmlN8oiXUD0VcNr_sBIRO56bAaAi41EALw_wcB) for attaching your chip to the programmer. 
* A set of discrete components (resistors, caps, LEDs, etc.).
* A 5V power supply. The ATmega328 will operate down to 1.8V but the clock cannot be run as quickly and it is not as reliable.

# Installation

You will need to install:

* `avr-gcc` - compiler 
* `avr-binutils` - assembler, linker
* `arv-libc` - avr specific headers and functions
* `avr-gdb` - debugger
* `avrdude` - tool to flash over USB

See the package manager for your system for installation details.

If you are on a Windows based system, you may wish to look into using [Atmel Studio](https://www.microchip.com/avr-support/atmel-studio-7). A free version is available at the linked URL. 

# Programming

An example for compiling a simple project follows. It assumes you are using an AVR Dragon. You may wish to adapt this to a `Makefile`

```bash
avr-gcc -Wall -mmcu=atmega328p -Os example.c -o example
avr-objcopy -O ihex -R .eeprom example example.hex
sudo avrdude -p atmega328p -c dragon_isp =P usb -e -U flash:w:example.hex
```

These commands will compile your source files and link them into ELF format. `avr-objcopy` then transfers that executable to a flashable .hex format. Finally avrdude will search for an AVR Dragon connected with USB and flash your executable onto your chip. Note that `sudo` is required to access the USB port. 

# TODO

- PWM
- DAC/ADC
- UART
- EEPROM

# In Progress

* GPIO

# Completed
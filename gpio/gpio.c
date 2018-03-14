#include <avr/io.h>
#include "gpio.h"

void set_pin_type(port p, uint8_t pin, pintype t){
  uint8_t ddrVal = (t == INPUT) ? 0 : 1;
  uint8_t portVal = (t == INPUT) ? 1 : 0; 

  //Output LOW by default. 
  //Pullups on by default.
  switch (p){
    case B:
      DDRB |=  ddrVal << pin;
      PORTB |= portVal << pin;
      break;
    case C:
      DDRC |= ddrVal << pin;
      PORTC |= portVal << pin;
      break;
    case D:
      DDRD |= ddrVal << pin;
      PORTD |= portVal << pin;
      break;
  }
}

uint8_t read_pin(port p, uint8_t pin){
  uint8_t pinMask = 1 << pin;

  switch (p){
    case B:
      return PINB & pinMask;
    case C:
      return PINC & pinMask;
    case D:
      return PIND & pinMask;
  }
}

void write_pin(port p, uint8_t pin, pinstate s){
}

#include <avr/io.h>
#include "gpio.h"

void set_pin_type(port p, uint8_t pin, pintype t){
  uint8_t ddrVal = (INPUT == t) ? 0 : 1;
  uint8_t portVal = (INPUT == t) ? 1 : 0; 

  ddrVal = ddrVal << pin;
  portVal = portVal << pin;

  //Output LOW by default. 
  //Pullups on by default.
  switch (p){
    case B:
      DDRB |=  ddrVal;
      PORTB |= portVal;
      break;
    case C:
      DDRC |= ddrVal;
      PORTC |= portVal;
      break;
    case D:
      DDRD |= ddrVal;
      PORTD |= portVal;
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
  uint8_t output = (LOW == s) ? 0 : 1;
  output = output << pin;

  switch (p){
    case B: 
      PORTB |= output;
      return;
    case C: 
      PORTC |= output;
      return;
    case D:
      PORTD |= output;
      return;
  } 
}

#include <avr/io.h>
#include "../include/gpio.h"

//Sets the pin type, INPUT or OUTPUT
//Note when setting to output, if the previous state was INPUT with PULLUP 
//an intermediate step of ({DDRxn, PORTxn} = 0b00) is required, as per the ATmega328p datasheet.
//Hence our clearning DDRxn before setting it again if t == OUTPUT.
//
//OUTPUT is LOW by default
//Pullups are on by default when pinmode is INPUT
void set_pin_type(port p, uint8_t pin, pintype t){
  uint8_t setting = 1 << pin;

  if (OUTPUT == t){
    switch (p){
      case B:
        DDRB &= ~setting; 
        PORTB &= ~setting;
        DDRB |= setting;
        break;
      case C:
        DDRC &= ~setting;
        PORTC &= ~setting;
        DDRC |= setting;
        break;
      case D:
        DDRB &= ~setting;
        PORTD &= ~setting;
        DDRD |= setting;
        break;
    }
  }
  else{
    switch (p){
      case B:
        DDRB &= ~setting;
        PORTB |= setting;
        break;
      case C:
        DDRC &= ~setting;
        PORTC |= setting;
        break;
      case D:
        DDRD &= ~setting;
        PORTD |= setting;
        break;
    }
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
    default:
      return 0;
  }
}

void write_pin(port p, uint8_t pin, pinstate s){
  uint8_t output = 1 << pin;

  if (HIGH == s){
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
  else{
    switch (p){
      case B: 
        PORTB &= ~output;
        return;
      case C: 
        PORTC &= ~output;
        return;
      case D:
        PORTD &= ~output;
        return;
    }
  }
}

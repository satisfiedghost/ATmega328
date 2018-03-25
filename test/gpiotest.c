#define F_CPU 1000000UL

#include "../include/gpio.h"
#include <util/delay.h>
#include <stdint.h>
#include <avr/io.h>

#define DELAY_MS 20


//Assumes all pins are connected to LEDs with limiting resistors
int main(void){
  //Set pins to output
  for (uint8_t i = 0; i < 7; i++){
   set_pin_type(B, i, OUTPUT); 
  }

  for (uint8_t i = 0; i < 6; i++){
    set_pin_type(C, i, OUTPUT);
  }

  for(uint8_t i = 0; i < 7; i++){
    set_pin_type(D, i, OUTPUT);
  }

  while (1){
    for (uint8_t i = 0; i < 7; i++){
      write_pin(B, i, HIGH);
      _delay_ms(DELAY_MS);
      write_pin(B, i, LOW);
    }

    for (uint8_t i = 0; i < 6; i++){
       write_pin(C, i, HIGH);
      _delay_ms(DELAY_MS);
      write_pin(C, i, LOW);
    }

    for(uint8_t i = 0; i < 7; i++){
       write_pin(D, i, HIGH);
      _delay_ms(DELAY_MS);
      write_pin(D, i, LOW);
    }
  }
}

  




#include <avr/io.h>

void set_pin_type(port p, uint8_t pin, pintype t){
  uint8_t portVal = (t == INPUT) ? 0 : 1;

  switch (p){
    case A:

    case B:

    case C:

    case D:
  }
}

uint8_t read_pin(port p, uint8_t pin){

}

void write_pin(port p, uint8_t pin, pinstate s){
}

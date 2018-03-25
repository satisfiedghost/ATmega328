#include <stdint.h>

typedef enum pintype{INPUT=0, OUTPUT}pintype;
typedef enum pinstate{LOW=0, HIGH}pinstate;
typedef enum port{B=0, C, D}port;

void set_pin_type(port p, uint8_t pin, pintype t);

uint8_t read_pin(port p, uint8_t pin);

void write_pin(port p, uint8_t pin, pinstate s);

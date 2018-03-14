typedef enum pintype{INPUT=0, OUTPUT};
typedef enum pinstate{LOW=0, HIGH};
typedef enum port{A=0, B, C, D};

void set_pin_type(port p, uint8_t pin, pintype t);

uint8_t read_pin(port p, uint8_t pin);

void write_pin(port p, uint8_t pin, pinstate s);

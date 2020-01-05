#include "twi.h"

float sclf;

float TWISetup(){
    // Fscl = 333kHz  (max400kHz)  Fcpu = 16MHz //
    // Set I2C Bit Rate Register (16 bits) //
    TWBR |= 0b00010000;
    TWCR |= (1<<TWEN);

    sclf = (float) CPU_F / (float) (16 + (2*TWBR));
    return sclf;
}

void TWIStart() {

  TWCR |= (1<<TWEN)|(1<<TWSTA)|(1<<TWINT);
  while (!(TWCR & (1<<TWINT)));
  
}

void TWIWrite(uint8_t reg){

    TWDR = reg;
    TWCR = (1<<TWINT)|(1<<TWEN);

    while (!(TWCR & (1<<TWINT)));
}

uint8_t TWIRead() {

    TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
    while (!(TWCR & (1<<TWINT)));
    
    return TWDR;
}

void TWIStop(){
    TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}
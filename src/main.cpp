#include <Arduino.h>

#define SDA 4 
#define SCL 5
#define SLA_W 0b1010010
#define SLA_R 0b1010011

void TWISetup(){
    
    Serial.begin(9600);
    Serial.println("Serial connection set!");

    // Fscl = 333kHz  (max400kHz)  Fcpu = 16MHz //
    // Set I2C Bit Rate Register (16 bits) //
    TWBR |= 0b00010000;
    TWCR |= (1<<TWEN);

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

void setup() {

  TWISetup();
  TWIStart();
  TWIWrite(SLA_R);
  Serial.println("----------------------");
  Serial.println("Status Code: ");
  Serial.println(TWSR);
  Serial.println("----------------------");
  TWIStart();
  TWIRead();
  Serial.println("----------------------");
  Serial.println("Status Code: ");
  Serial.println(TWSR);
  Serial.println("----------------------");
  /*Serial.println("TWI Read Value: ");
  Serial.println(TWIRead());
  Serial.println("----------------------");*/
  
  TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

void loop() {


}
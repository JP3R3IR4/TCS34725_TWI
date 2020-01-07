#include "twi.h"
#include <Arduino.h>

float TWISetup(){

    float sclf;
    // Fscl = 333kHz  (max400kHz)  Fcpu = 16MHz //
    // Set I2C Bit Rate Register (16 bits) //
    TWBR = 0b00010000;
    TWCR = (1<<TWEN);

    sclf = (float) CPU_F / (float) (16 + (2*TWBR));
    return sclf;

}

uint8_t TWIStart() {

    TWCR = 0;

    /* Enable and start TWI */
    TWCR = (1<<TWEN)|(1<<TWSTA)|(1<<TWINT);
    while (!(TWCR & (1<<TWINT)));

    /* Check if Status code Errors */
    if ((TWSR == BUS_ERROR) ||
        (TWSR == ARBILOST)) {

            #ifdef DEBUG 
                Serial.print("Status code for TWISTART: ");
                Serial.println(TWSR);
            #endif

            return ERROR;
        }
        
    return TWSR;
}

uint8_t TWIWrite(uint8_t reg){

    TWDR = reg;
    TWCR = (1<<TWINT)|(1<<TWEN); 
    while (!(TWCR & (1<<TWINT)));

    if ((TWSR == BUS_ERROR) || 
        (TWSR == ARBILOST) ||  
        (TWSR == SLAW_T_NACK) ||  
        (TWSR == SLAR_T_NACK) ||
        (TWSR == DATA_T_NACK)) {

            #ifdef DEBUG 
                Serial.print("Status code for TWIWrite: ");
                Serial.println(TWSR);
            #endif

            return ERROR;
        }
        
    return TWSR;
}

uint8_t TWIRead_ACK() {

    TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
    while (!(TWCR & (1<<TWINT)));

    if ((TWSR == BUS_ERROR) || 
        (TWSR == ARBILOST) ||
        (TWSR == DATA_R_NACK)) {

            #ifdef DEBUG 
                Serial.print("Status code for TWIRead: ");
                Serial.println(TWSR);
            #endif

            return ERROR;
        }
        
    return TWDR;
}

uint8_t TWIRead_NACK() {

    TWCR = (1<<TWINT)|(1<<TWEN);
    while (!(TWCR & (1<<TWINT)));

    if ((TWSR == BUS_ERROR) || 
        (TWSR == ARBILOST)) {

            #ifdef DEBUG 
                Serial.print("Status code for TWIRead: ");
                Serial.println(TWSR);
            #endif

            return ERROR;
        }
        
    return TWDR;
}

void TWIStop(){
    TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}
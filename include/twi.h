#ifndef TWI_H_  /* Include guard */
#define TWI_H_

#include <Arduino.h>

#define SDA 4 
#define SCL 5
#define SLA_W 0b1010010
#define SLA_R 0b1010011
#define CPU_F 16000000

float TWISetup();
void TWIStart();
void TWIWrite(uint8_t reg);
uint8_t TWIRead();
void TWIStop();

#endif
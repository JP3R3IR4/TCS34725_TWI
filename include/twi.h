#ifndef TWI_H_  /* Include guard */
#define TWI_H_

#include <Arduino.h>

#define SLA_W 0b1010010
#define SLA_R 0b1010011
#define CPU_F 16000000

#define ERROR 0xFF
#define BUS_ERROR 0x00

/* Status Code TWSR MASTER TRANSMITTER */
#define START_T 0x08
#define START_RP_T 0x10
#define SLAW_T_ACK 0x18
#define SLAW_T_NACK 0x20
#define DATA_T_ACK 0x28
#define DATA_T_NACK 0x30
#define ARBILOST 0x38
/* Status Code TWSR MASTER RECEIVER */
#define SLAR_T_ACK 0x40
#define SLAR_T_NACK 0x48
#define DATA_R_ACK 0x50
#define DATA_R_NACK 0x58

/* ENABLE/DISABLE TWI DEBUG */
#define DEBUG 

float TWISetup();
uint8_t TWIStart();
uint8_t TWIWrite(uint8_t reg);
uint8_t TWIRead_ACK();
uint8_t TWIRead_NACK();
void TWIStop();

#endif
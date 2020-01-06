/**
 * @file twi.cpp
 * 
 * @brief in this file are the main Two Wire Interfaces functions based 
 * on the atmega328p datasheet and on the I2C protocol guide, required 
 * to establish connection between the Arduino and the TCS34725 sensor
 * 
 * @author Nuno Nogueira, 2020
 * */

#ifndef TWI_H_
#define TWI_H_

#include <Arduino.h>

/* TCS34725 ADDRESS + R/W bit */
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

/**
 * Sets SCL Frequency and enables TWI.
 * returns: SCL Frequency 
 * */
float TWISetup();

/**
 * Sends a Start Condition 
 * */
uint8_t TWIStart();

/**
 * Sends DATA and waits for ACK from slave.
 * @param reg is stored in TWDR
 * returns: TWSR (Status Code) or ERROR in case of error
 * */
uint8_t TWIWrite(uint8_t reg);

/**
 * Receives data and sends ACK to slave-transmitter.
 * */
uint8_t TWIRead_ACK();

/**
 * Receives data but does not send ACK to slave. It is used when it is received before ending communtion.
 * */
uint8_t TWIRead_NACK();

/**
 * Sends a STOP condition. Ends communication.
 * */
void TWIStop();

#endif
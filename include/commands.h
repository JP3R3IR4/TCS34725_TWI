#ifndef CMD_H_  /* Include guard */
#define CMD_H_

#include <Arduino.h>
#include "twi.h"
#include "register_set.h"

uint8_t getID();
uint16_t getColor(uint8_t color);
void enableRGBC();
void powerON();
void setGain();
void setTime();
void enableTCS34725();
void getRawColors(uint16_t *c, uint16_t *r, uint16_t *g, uint16_t *b);

#endif
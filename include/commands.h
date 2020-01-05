#ifndef CMD_H_  /* Include guard */
#define CMD_H_

#include <Arduino.h>
#include "twi.h"
#include "register_set.h"

uint8_t get_ID();
uint16_t get_color(uint8_t color);
void enable_RGBC();
void power_ON();
void setGain();
void setTime();
uint8_t getStatus();

#endif
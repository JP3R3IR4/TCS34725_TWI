/**
 * @file commands.h
 * 
 * @brief in this file are the main data registers commands functions,
 * required to access to certain data.
 * 
 * @author Nuno Nogueira, 2020
 * */

#ifndef CMD_H_  /* Include guard */
#define CMD_H_

#include <Arduino.h>
#include "twi.h"
#include "register_set.h"

/**
 * Get device ID (0x44)
 * returns: id
 * */
uint8_t getID();

/**
 * Gets a color 16-bit value 
 * @param color type of color: red, green, blue, clear.
 * returns: color value
 * */
uint16_t getColor(uint8_t color);

/** 
 * Enables RGBC.
 * */
void enableRGBC();

/**
 * Changes state of the sensor to IDLE
 * */
void powerON();

/**
 * Defines gain settings
 * */
void setGain();

/**
 * Defines internal integration time of the RGBC clear 
 * and IR channel ADCs in 2.4-ms increments.
 * */
void setTime();

/**
 * Enables RGBC and waits for integration time.
 * */
void enableTCS34725();

/**
 * Updates inputs with RGB values.
 * @param c clear color
 * @param r red color
 * @param g green color
 * @param b blue color
 * */
void getRawColors(uint16_t *c, uint16_t *r, uint16_t *g, uint16_t *b);

#endif
/**
 * @file main.cpp
 * 
 * @author Nuno Nogueira, 2020
 * */

#include <Arduino.h>
#include "twi.h"
#include "register_set.h"
#include "commands.h"

#define RED 3
#define BLUE 4
#define GREEN 5

const uint8_t gammatable[] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
    2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
    5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
   10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
   17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
   25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
   37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
   51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
   69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
   90, 92, 93, 95, 96, 98, 99,101,102,104,105,107,109,110,112,114,
  115,117,119,120,122,124,126,127,129,131,133,135,137,138,140,142,
  144,146,148,150,152,154,156,158,160,162,164,167,169,171,173,175,
  177,180,182,184,186,189,191,193,196,198,200,203,205,208,210,213,
  215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255 };

uint16_t clear_color, blue_color, green_color, red_color;

void setup() {

	pinMode(OUTPUT, RED);
	pinMode(OUTPUT, BLUE);
	pinMode(OUTPUT, GREEN);

  	Serial.begin(9600);
	Serial.print("|	  SCL Frequency -> "); Serial.print(TWISetup()); Serial.println(" Hz");
	Serial.println("+--------------------------------------+");	
	
	/* Check if the device is connected */
  	while (getID() != NUMBER_IDENTIFICATION) {
  		Serial.println("Device is not connected!");
		/* Force boot */
		powerON();
		delay(1000);
  	} 

	Serial.println("+--------------------------------------+");
    Serial.println("|	Device is connected!");
    Serial.println("+--------------------------------------+");
	
	setGain();
	Serial.println("+--------------------------------------+");
    Serial.print("|	GAIN: ");
	Serial.println("1X");
    Serial.println("+--------------------------------------+");

	setTime();
	Serial.println("+--------------------------------------+");
    Serial.print("|	Integration time: ");
	Serial.println(INTEGRATION_DELAY);
    Serial.println("+--------------------------------------+");
			
	enableTCS34725();

}

void loop() {

	getRawColors(&clear_color, &red_color, &green_color, &blue_color);

	uint32_t sum = clear_color;
  	float r, g, b;
  	r = red_color; r /= sum;
  	g = green_color; g /= sum;
  	b = blue_color; b /= sum;
  	r *= 256; g *= 256; b *= 256;

	analogWrite(RED, gammatable[(int)r]);
	analogWrite(GREEN, gammatable[(int)g]);
	analogWrite(BLUE, gammatable[(int)b]);

	#ifdef DEBUG
		Serial.print("[ "); Serial.print(sum); Serial.print(" ], ");
		Serial.print("[ "); Serial.print(gammatable[(int)r]); Serial.print(" ], ");
		Serial.print("[ "); Serial.print(gammatable[(int)g]); Serial.print(" ], ");
		Serial.print("[ "); Serial.print(gammatable[(int)b]); Serial.println(" ] ");
	#endif

}
#include <Arduino.h>
#include "twi.h"
#include "register_set.h"
#include "commands.h"

#define RED 3
#define BLUE 4
#define GREEN 5

uint16_t clear_color, blue_color, green_color, red_color;

void setup() {

	pinMode(OUTPUT, RED);
	pinMode(OUTPUT, BLUE);
	pinMode(OUTPUT, GREEN);

  	Serial.begin(9600);
	Serial.print("SCL Frequency -> "); Serial.print(TWISetup()); Serial.println(" Hz");
	Serial.println("---------------------------------");	

	setGain();
	setTime();

	/* Check if the device is connected */
  	if (get_ID() != NUMBER_IDENTIFICATION) {
  		Serial.println("Device is not connected!");
  	} 
	else {
			
		Serial.println("Device is connected!");
		power_ON();
		enable_RGBC();
	}

}

void loop() {

	clear_color = getColor(CDATA);
	red_color = getColor(RDATA);
	green_color = getColor(GDATA);
	blue_color = getColor(BDATA);

	delay(154);

	analogWrite(RED, red_color>>8);
	analogWrite(GREEN, green_color>>8);
	analogWrite(BLUE, blue_color>>8);

}
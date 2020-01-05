#include <Arduino.h>
#include "twi.h"
#include "register_set.h"
#include "commands.h"

void setup() {

  Serial.begin(9600);

  TWISetup();

	setGain();
	setTime();
  
}

void loop() {

	/* Power On Sensor - From Sleep to Idle state */
	power_ON();

  /* Check if the device is connected */
  if (get_ID() != NUMBER_IDENTIFICATION) {
  		Serial.println("Device is not connected!");
  } 
	else {
			Serial.println("Device is connected!");

			enable_RGBC();
			
			Serial.println(getStatus());
  }
}
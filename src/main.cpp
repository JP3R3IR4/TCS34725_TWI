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
	Serial.print("|	  SCL Frequency -> "); Serial.print(TWISetup()); Serial.println(" Hz");
	Serial.println("+--------------------------------------+");	

	/* Force boot */
	//powerON();

	getID();
	
	/* Check if the device is connected */
  	/*while (getID() != NUMBER_IDENTIFICATION) {
  		Serial.println("Device is not connected!");
		delay(1000);
  	} */

	Serial.println("+--------------------------------------+");
    Serial.println("|	Device is connected!");
    Serial.println("+--------------------------------------+");
	
	//setGain();
	Serial.println("+--------------------------------------+");
    Serial.print("|	GAIN: ");
	Serial.println("1X");
    Serial.println("+--------------------------------------+");

	//setTime();
	Serial.println("+--------------------------------------+");
    Serial.print("|	Integration time: ");
	Serial.println(INTEGRATION_DELAY);
    Serial.println("+--------------------------------------+");
			
	enableTCS34725();

}

void loop() {

	/*getRawColors(&clear_color, &red_color, &green_color, &blue_color);

	Serial.print("[ "); Serial.print(clear_color>>8); Serial.print(" ], ");
	Serial.print("[ "); Serial.print(red_color>>8); Serial.print(" ], ");
	Serial.print("[ "); Serial.print(green_color>>8); Serial.print(" ], ");
	Serial.print("[ "); Serial.print(blue_color>>8); Serial.println(" ] ");*/

	//delay(1000);

	/*analogWrite(RED, red_color>>8);
	analogWrite(GREEN, green_color>>8);
	analogWrite(BLUE, blue_color>>8);*/

}
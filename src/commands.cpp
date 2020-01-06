#include "commands.h"

/* REGISTER FUNCTION: READ ONLY */
uint8_t getID() {

    uint8_t id = 0;

    TWIStart();
    TWIWrite(SLA_W);
    TWIWrite(COMMAND_BIT|ID);
    TWIStart();
    TWIWrite(SLA_R);
    id = TWIRead_NACK();
    TWIStop();

    return id;

}

uint16_t getColor(uint8_t color) {

    uint16_t x = 0; 

    TWIStart();
    TWIWrite(SLA_W);
    TWIWrite(COMMAND_BIT | color);
    TWIStart();
    TWIWrite(SLA_R);
    /*x = (TWIRead() << 8);
    x |= TWIRead();*/
    TWIStop();

    return x;
}

void enableRGBC() {

    /* A minimum interval of 2.4ms must pass after PON is asserterd before RGBC can be initialized */
    delay(3);

    TWIStart();
    TWIWrite(SLA_W);
    TWIWrite(COMMAND_BIT | ENABLE_REGISTER);
    TWIWrite(AEN|PON);
    TWIStop();

}

void powerON() {

    TWIStart();
    TWIWrite(SLA_W);
    TWIWrite(COMMAND_BIT | ENABLE_REGISTER);
    TWIWrite(PON);
    TWIStop();

}

void setGain() {

    TWIStart();
    TWIWrite(SLA_W);
    TWIWrite(COMMAND_BIT | CONTROL_REGISTER);
    TWIWrite(AGAIN);
    TWIStop();

}

void setTime() {

    TWIStart();
    TWIWrite(SLA_W);
    TWIWrite(COMMAND_BIT | TIMING_REGISTER);
    TWIWrite(ATIME);
    TWIStop();

}

void enableTCS34725() {
    //powerON();
    enableRGBC();
    delay(INTEGRATION_DELAY);
}

void getRawColors(uint16_t *c, uint16_t *r, uint16_t *g, uint16_t *b) {

    *c = getColor(CDATA);
	*r = getColor(RDATA);
	*g = getColor(GDATA);
	*b = getColor(BDATA);

    delay(INTEGRATION_DELAY);

}
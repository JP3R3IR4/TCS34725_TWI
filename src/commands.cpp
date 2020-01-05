#include "commands.h"

uint16_t x = 0;

/* REGISTER FUNCTION: READ ONLY */
uint8_t get_ID() {

    TWIStart();
    TWIWrite(SLA_W);
    TWIWrite(COMMAND_BIT | ID);
    TWIStart();
    TWIWrite(SLA_R);
    return TWIRead();

}

uint16_t getColor(uint8_t color) {

    TWIStart();
    TWIWrite(SLA_W);
    TWIWrite(COMMAND_BIT | color);
    TWIStart();
    TWIWrite(SLA_R);
    x = (TWIRead() << 8);
    x |= TWIRead();

    return x;
}

void enable_RGBC() {

    /* A minimum interval of 2.4ms must pass after PON is asserterd before RGBC can be initialized */
    delay(3);

    TWIStart();
    TWIWrite(SLA_W);
    TWIWrite(COMMAND_BIT | ENABLE_REGISTER);
    TWIStart();
    TWIWrite(SLA_W);
    TWIWrite(AEN);

}

void power_ON() {

    TWIStart();
    TWIWrite(SLA_W);
    TWIWrite(COMMAND_BIT | ENABLE_REGISTER);
    TWIStart();
    TWIWrite(SLA_W);
    TWIWrite(PON);

}

void setGain() {

    TWIStart();
    TWIWrite(SLA_W);
    TWIWrite(COMMAND_BIT | CONTROL_REGISTER);
    TWIStart();
    TWIWrite(SLA_W);
    TWIWrite(AGAIN);

}

void setTime() {

    TWIStart();
    TWIWrite(SLA_W);
    TWIWrite(COMMAND_BIT | TIMING_REGISTER);
    TWIStart();
    TWIWrite(SLA_W);
    TWIWrite(ATIME);

}

uint8_t getStatus() {

    TWIStart();
    TWIWrite(SLA_W);
    TWIWrite(COMMAND_BIT | STATUS);
    TWIStart();
    TWIWrite(SLA_R);
    return TWIRead();
}

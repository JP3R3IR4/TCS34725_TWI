# TCS34725_TWI

TCS34725_TWI is a project aiming to implement TWI protocol to comunicate between an Arduino Nano and a [TCS34725](https://cdn-shop.adafruit.com/datasheets/TCS34725.pdf) RGB sensor.

## Contents

### System Concept


### I2C and Two Wire Interface Fundamentals

#### Background

I2C is a serial communication protocol used to communicate between masters and slaves using a two-wire interface. Two Wire Interface was created by Atmel to avoid any legal troubles by using this communication protocol created by Philips.

Since this project uses a microcontroller from Atmel(atmega328p from an Arduino Nano), it should be implemented in using TWI.

#### Functionality

Frame | start | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | stopbit 
--- | --- | --- | --- |--- |--- |--- |--- |--- |--- |--- |--- 
Bit | LOW | X | X | X | X | X | X | X | X | X | HIGH 


### TWI Implementation

### System Functions

### Graphical User Interface

A GUI was created in Python (based on [PyQt5](https://riverbankcomputing.com/software/pyqt/intro)) to simulate a RGB LED behavior.
The program receives RGB values from serial port, prints it and converts it into a color.
To open the GUI, run:

```
python3 guy.py
```


### PCB

#### Schematic

#### PCB Design

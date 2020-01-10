# TCS34725_TWI

TCS34725_TWI is a project aiming to implement TWI protocol to comunicate between an Arduino Nano and a [TCS34725](https://cdn-shop.adafruit.com/datasheets/TCS34725.pdf) RGB sensor.

## Contents

### System Concept

### I2C and Two Wire Interface Fundamentals

#### Background

I2C is a serial communication protocol used to communicate between masters and slaves using a two-wire interface. Two Wire Interface was created by Atmel to avoid any legal troubles using this communication protocol created by Philips.

Since this project uses a microcontroller from Atmel(atmega328p from an Arduino Nano), it should be implemented using **TWI**.

#### TWI Functionality

The two wire interface is defined by two wires: **SDA** (serial data) and **SCL** (serial clock) connected with a pull-up resistor to +Vdd. This allows to communicate between many devices, with their unique address, with only two wires.

In a normal state both lines are high.
To start a communication, a master creates a **start condition** (SDA line low)  and to end communication the master sends a **stop condition** (SDA line high). Between these conditions the data is sent.

After sending a **start condition** the master must send the **7-bit slave address** he wants to establish connection followed by **read/write bit** (where read is 1 and write is 0). 
If the slave is on the bus, it answers with an ACK. If not, with NACK.

If the slave answers with ACK, the master should now become a master transmittter or a master receiver, depending on the **read/write bit**.
###### Note: In this project both modes are used.
To transmit, a master transmitter should send the command and then send a **stop condition** to end communication.

<img width="1064" alt="Captura de ecrã 2020-01-10, às 15 37 44" src="https://user-images.githubusercontent.com/38976366/72165309-2756ee00-33bf-11ea-9b57-9023e6a3c2a9.png">

To receive, a master should after receiving the data send ACK or NACK: sends NACK when it is the last packed received before a **stop condition**.

<img width="1216" alt="Captura de ecrã 2020-01-10, às 15 39 24" src="https://user-images.githubusercontent.com/38976366/72165427-62592180-33bf-11ea-94a9-5eb5ff75a2e3.png">



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

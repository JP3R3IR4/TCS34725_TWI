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
To transmit, a master transmitter should send the command, the desired data packets and then send a **stop condition** to end communication:

<img width="1064" alt="Captura de ecrã 2020-01-10, às 15 37 44" src="https://user-images.githubusercontent.com/38976366/72165309-2756ee00-33bf-11ea-9b57-9023e6a3c2a9.png">

To receive, a master should after receiving the data send ACK or NACK: sends NACK when it is the last packed received before a **stop condition**. 

In this example it is also notable that to change from master transmitter to master receiver, the master must send a **repeated start condition** and send the proper **slave address + R/W bit**: 

<img width="1216" alt="Captura de ecrã 2020-01-10, às 15 39 24" src="https://user-images.githubusercontent.com/38976366/72165427-62592180-33bf-11ea-94a9-5eb5ff75a2e3.png">

###### [Source](http://www.ti.com/lit/an/slva704/slva704.pdf)

### TWI Implementation

A lib folder was created with the TWI protocol implemented in C.

#### Setup

To setup TWI it is necessary to set SCL frequency. Since the maximum rate is 400kHz and the TCS34725 works up to 400kHz, the SCL frequency is set a bit lower than the maximum values, **333kHz**:

- Arduino Frequency: 16MHz
- Prescaler: 16
- TWEN set to 1 to enable TWI operation

#### Start Condition

A start condition is created by:

- Set TWSTA and TWINT to 1.

TWSTA is written to 1 to check if the bus is free and generates a **start condition** on the bus if it is free.
TWINT is set by hardware when the TWI has finished its current task.

- Wait for TWINT to be set.

#### Write

To write to the bus the TWI Data Register (TWDR) should be written with the data desired to send. Enable TWI operation and wait for it to end.

#### Read

To read, the master waits reception, reads on TWDR and sends ACK to the slave by enable the TWI Enable Acknowledge Bit (TWEA).

In case of reception of the last packet before the stop condition, a NACK must be sent by set TWEA to 0.

#### Stop Condition

A stop condition is created by setting TWI STOP Condition Bit (TWSTO) to 1.

### TCS34725 States



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

# Solar Tracking System Using LDR Sensors

## Overview

This project implements a solar tracking system using an Arduino Uno, two LDR sensors, and a servo motor. The system detects the direction of the strongest light source and automatically adjusts the servo motor to follow it.

## Components Used

| Component | Description |
|-----------|-------------|
| Arduino Uno | The microcontroller that runs the program and controls the circuit |
| Servo Motor | Used to create controlled rotational movement based on the Arduino signal |
| 2 × 1kΩ Resistors | Used to limit current and stabilize the signal in the circuit |
| 2 × Potentiometers (Variable Resistors) | Allow adjustment of input values that control the servo behaviour |
| Breadboard / PCB | Used to assemble and hold the circuit components |
| Jumper Wires | Used to connect the Arduino, servo, and other components together |

## Functionality

* When the system starts, the Arduino reads the light intensity from two LDR sensors.
* When one sensor detects more light than the other, the Arduino moves the servo motor toward that direction.
* When the light intensity changes, the servo motor adjusts its position to face the strongest light source.

## Code Explanation

This Arduino program controls a **servo motor using two sensors** connected to the Arduino.

The program uses **one digital pin to control the servo motor** and **two analog input pins to read the sensor values**. The sensors measure input levels and the Arduino compares their values to determine which direction the servo should move.

### Pin Setup

The **servo motor is connected to digital pin D3**, which sends the control signal from the Arduino to move the servo.  
Two sensors are used to provide input to the system. The **left sensor is connected to analog pin A0**, and the **right sensor is connected to analog pin A1**. These sensors send their analog readings to the Arduino so it can compare the values and determine how the servo should move.

### Behaviour

The servo motor starts at a **center position of 90 degrees**.

The Arduino continuously reads the values from both sensors and calculates the **difference between them**.

- If the **left sensor detects a higher value**, the servo moves slightly toward the left.
- If the **right sensor detects a higher value**, the servo moves slightly toward the right.

A **threshold value** is used to ignore very small differences between the sensors, preventing unnecessary movement.

### Loop Cycle

The servo position is adjusted **one degree at a time** to create smooth movement.  
A short **20 millisecond delay** is added between updates, and the process repeats continuously so the servo keeps adjusting based on the sensor readings.

## Simulation

Created and tested using Autodesk [Tinkercad Circuits](https://www.tinkercad.com/circuits).


## License

This project is licensed under the [MIT License](https://github.com/AndreasFragkop/Arduino-Tinkercad-Projects/blob/main/LICENSE).

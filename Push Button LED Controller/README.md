# Push Button LED Controller

## Overview
This project implements a simple LED control system using an Arduino Uno, a push button, and resistors. The system allows a user to control the state of an LED using a button input. When the button is pressed, the LED turns on, and when the button is released, the LED turns off.

## Components Used

| Component | Description |
|-----------|-------------|
| Arduino Uno | The microcontroller that runs the program and controls the circuit |
| Red LED | Used as the visual output indicator |
| 520Ω Resistor | Limits the current flowing through the LED to protect it |
| 10kΩ Resistor | Acts as a pull-down resistor to stabilize the button input signal |
| Push Button Switch | Provides manual input to control the LED |
| Breadboard | Used to assemble and hold the circuit components |
| Jumper Wires | Used to connect the Arduino and electronic components together |

## Functionality

* When the system starts, the Arduino waits for input from the push button.
* When the button is pressed, the Arduino detects a HIGH signal on the input pin and turns the LED on.
* When the button is released, the input signal becomes LOW and the Arduino turns the LED off.
* This allows the user to directly control the LED using the push button.

## Code Explanation

This Arduino program controls an LED using a push button connected to the Arduino.
The program uses one digital pin as an output to control the LED and another digital pin as an input to read the button state.

### Pin Setup

The LED is connected to digital pin **D5**, which sends the signal from the Arduino to turn the LED on or off.
The push button is connected to digital pin **D2**, which sends its signal to the Arduino when the button is pressed.

### Behaviour

When the button is pressed, the Arduino reads a HIGH signal from the button pin. The Arduino then sends a HIGH signal to the LED pin, causing the LED to turn on. When the button is released, the Arduino reads a LOW signal and turns the LED off.

### Idle State

When the system is powered on and the button is not pressed, the LED remains turned off.  
The Arduino continuously waits for the user to press the button and activates the LED only when the input signal changes.

## Simulation

Created and tested using Autodesk [Tinkercad Circuits](https://www.tinkercad.com).

## License

This project is licensed under the [MIT License](https://github.com/AndreasFragkop/Arduino-Tinkercad-Projects/blob/main/LICENSE).

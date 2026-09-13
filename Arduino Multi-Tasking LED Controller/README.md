# Arduino Multi-Tasking LED Controller

## Overview

This project implements a simple LED control system using an Arduino Uno, two LEDs, a push button, and resistors. The blue LED blinks automatically, while the green LED turns on when the button is pressed and off when it is released. The program uses the `millis()` function to control the blinking without pausing button input, allowing both tasks to run independently.

## Components Used

| Component | Description |
|-----------|-------------|
| Arduino Uno | The microcontroller that runs the program and controls the LEDs |
| Blue LED | Used as the output that blinks automatically |
| Green LED | Turns on when the push button is pressed |
| 250Ω Resistor | Limits the current flowing through an LED to protect it |
| 220Ω Resistor | Limits the current flowing through an LED to protect it |
| 10kΩ Resistor | Acts as a pull-down resistor to stabilize the button input signal |
| Push Button Switch | Provides manual input to control the green LED |
| Breadboard / PCB | Used to assemble and hold the circuit components |
| Jumper Wires | Used to connect the Arduino, LEDs, resistors, and button |

## Functionality

* The blue LED turns on for 0.5 seconds and off for 0.5 seconds, repeating continuously.
* When the push button is pressed, the green LED turns on.
* When the button is released, the green LED turns off.
* The blue LED continues blinking while the button controls the green LED.
* The program uses `millis()` instead of `delay()`, allowing it to check the button continuously while timing the blue LED.

## Code Explanation

This Arduino program controls two LEDs using a push button and a timer. The `digitalRead()` function checks the button state, and `digitalWrite()` turns the green LED on when the button is pressed and off when it is released. The program uses `millis()` to measure the time since the blue LED last changed state. Every **500 milliseconds**, it switches the blue LED on or off and updates the timer. Because the program does not use `delay()`, it continues checking the button while the blue LED blinks.

### Pin Setup

The blue LED is connected to digital pin **D5**, and the green LED is connected to digital pin **D6**. These pins are configured as outputs, allowing the Arduino to turn each LED on or off. The push button is connected to digital pin **D2**, which is configured as an input. A **10kΩ pull-down resistor** keeps the button input LOW when the button is not pressed. The LEDs use **250Ω and 220Ω resistors** to limit the current and protect them, and the circuit shares a common ground connected to the Arduino’s **GND** pin.

### Behaviour

When the system starts, the blue LED remains off for **0.5 seconds**, then turns on. It continues switching on and off every **0.5 seconds**. When the push button is pressed, the Arduino turns the green LED on, and when the button is released, it turns the green LED off. The blue LED continues blinking throughout, allowing the circuit to respond to button input without interrupting the blinking sequence.

## Simulation

Created and tested using Autodesk [Tinkercad Circuits](https://www.tinkercad.com/circuits).

## License

This project is licensed under the [MIT License](../LICENSE).

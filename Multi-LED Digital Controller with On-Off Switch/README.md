# Multi-LED Digital Controller with On-Off Switch

## Overview

This project implements a multi-LED digital controller using an Arduino Uno.
Sixteen LEDs are arranged on a breadboard and controlled through a switch input. When the switch is activated, the LEDs perform a scanning sequence from left to right and then reverse from right to left, creating a continuous back-and-forth lighting effect.

## Components Used

| Component | Description |
|-----------|-------------|
| Arduino Uno | The microcontroller that runs the program and controls the LEDs |
| 16 × LEDs (Red, Green, Blue, Orange) | Used to create the LED scanner light effect |
| 16 × 220Ω Resistors | Limit the current flowing through each LED to protect the LEDs and Arduino |
| Push Button (S1) | Used to activate the LED scanning sequence |
| Breadboard / PCB | Used to assemble and hold the circuit components |
| Jumper Wires | Used to connect the Arduino pins to the LEDs, resistors, and button |

## Functionality

* When the switch is **ON**, the LEDs light sequentially from left to right.
* After reaching the final LED, the sequence reverses from right to left.
* When the switch is **OFF**, all LEDs remain turned off.

## Code Explanation

This Arduino program controls a LED scanner effect using a switch.

The program uses **8 Arduino output pins** stored in an array to control the LEDs.  
Although the circuit contains **16 LEDs**, they are arranged in pairs so that **each Arduino pin controls two LEDs simultaneously**.

A switch connected to **pin 10** activates the LED sequence. The switch uses the **internal pull-up resistor**, meaning the pin reads **LOW when the switch is pressed**.

### Pin Setup

The Arduino uses digital pins **D2 to D9** to control the LEDs. Each of these pins is connected to two LEDs in the circuit, meaning the same signal from the Arduino powers a pair of LEDs. This results in a total of **16 LEDs being controlled by 8 output pins**.

For example, pin **D2** controls LED 1 and LED 9, pin **D3** controls LED 2 and LED 10, and this pattern continues up to pin **D9**, which controls LED 8 and LED 16.
The **switch is connected to pin D10**, which is configured as an input using the Arduino’s internal pull-up resistor.

Each LED is connected through a **220Ω resistor** to limit current.

### Behaviour

- When the **switch is pressed**, the LEDs light up one at a time from the first LED pair to the last.
- The sequence then **reverses direction**, creating a **back-and-forth scanner effect**.
- Each step lasts **200 ms**.

### Idle State

When the **switch is not pressed**, all LEDs remain **off**.

## Simulation

Created and tested using Autodesk [Tinkercad Circuits](https://www.tinkercad.com).

## License

This project is licensed under the [MIT License](https://github.com/AndreasFragkop/Arduino-Tinkercad-Projects/blob/main/LICENSE).

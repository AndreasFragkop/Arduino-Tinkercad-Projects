# Arduino Traffic Light Simulator

## Overview

This project implements a simple traffic light control system using an Arduino Uno, three LEDs, and resistors. The red, green, and yellow LEDs represent the signals of a traffic light. The system turns each LED on in sequence for a set duration, repeating the cycle continuously to simulate the operation of a traffic light.

## Components Used

| Component | Quantity | Description |
|-----------|----------|-------------|
| Arduino Uno R3 | 1 | Runs the program and controls the traffic lights |
| Small Breadboard | 1 | Holds the components and their circuit connections |
| Red LED | 1 | Represents the stop signal |
| Green LED | 1 | Represents the go signal |
| Yellow LED | 1 | Represents the caution signal |
| 220 Ω Resistor | 3 | Limits the current through each LED to protect it |
| Jumper Wires | As needed | Connect the Arduino, breadboard, and LEDs |

## Functionality

* When the system starts, the red LED turns on for 5 seconds while the other LEDs remain off.
* The red LED then turns off, and the green LED turns on for 5 seconds.
* The green LED then turns off, and the yellow LED turns on for 2 seconds.
* After the yellow LED turns off, the cycle starts again with the red LED.
* This sequence repeats continuously, with only one LED on at a time.

## Code Explanation

This Arduino program controls three LEDs to simulate a traffic light. Each LED is connected to a digital pin, which is configured as an output using the `pinMode()` function in `setup()`. The program uses `digitalWrite()` to turn the LEDs on and off, while `delay()` controls how long each light stays on. The instructions inside `loop()` repeat continuously, keeping the red LED on for 5 seconds, the green LED on for 5 seconds, and the yellow LED on for 2 seconds.

### Pin Setup

The red LED is connected to digital pin **D12**, the yellow LED to digital pin **D11**, and the green LED to digital pin **D10**. These pins are configured as outputs, allowing the Arduino to turn each LED on or off. Each LED uses a **220Ω resistor** to limit the current and protect it. The circuit shares a common ground connected to the Arduino’s **GND** pin.

### Behaviour

When the system starts, the Arduino turns on the red LED for **5 seconds**, while the green and yellow LEDs remain off. The red LED then turns off, and the green LED turns on for **5 seconds**. Next, the green LED turns off, and the yellow LED turns on for **2 seconds**. After this, the sequence returns to the red LED and repeats continuously, allowing the circuit to simulate a traffic light.

## Simulation

To be added: the Tinkercad simulation link and circuit screenshots.

## License

This project is licensed under the [MIT License](../LICENSE).

# 3-LED Control System

## Overview

This project implements a simple traffic light controller using an Arduino Uno and three LEDs (red, orange, and green). The LEDs are arranged on a breadboard and controlled through Arduino digital output pins. The system simulates the behavior of a real traffic signal by lighting the LEDs in a timed sequence.

## Components Used

- [ ] **Arduino Uno** – The microcontroller that runs the program and controls the LEDs.  
- [ ] **Red LED** – Represents the red traffic light signal.  
- [ ] **Orange LED** – Represents the orange (yellow) traffic light signal.  
- [ ] **Green LED** – Represents the green traffic light signal.  
- [ ] **3 × 250Ω Resistors** – Limit the current flowing through each LED to protect them from damage.  
- [ ] **Breadboard or PCB** – Used to assemble and hold the circuit components.  
- [ ] **Jumper Wires** – Used to connect the Arduino pins to the LEDs and resistors.

## Functionality

* The **Red LED** turns on to indicate stop.
* After a delay, the **Green LED** turns on to indicate go.
* The **Orange LED** then turns on to signal caution before the cycle repeats.
* The sequence runs continuously to simulate a basic traffic light system.

## Code Explanation

This Arduino program simulates a **traffic light system** using three LEDs.

The program uses **three Arduino output pins** to control the LEDs.  
Each LED represents a traffic light colour: **red, orange, and green**.

### Pin Setup

The LEDs are connected to three digital pins on the Arduino. The **red LED is connected to pin D11**, the **orange LED is connected to pin D10**, and the **green LED is connected to pin D9**. Each LED is connected through a **250Ω resistor** to limit the current and protect the components.

### Behaviour

The program runs a continuous traffic light cycle:

- The **red LED turns on for 5 seconds**, while the other LEDs remain off.
- After this, the **green LED turns on for 5 seconds**, indicating it is safe to go.
- Finally, the **orange LED turns on for 2 seconds**, signalling that the light will soon change.

### Loop Cycle

After the orange light turns off, the program **restarts the sequence from the red light**, repeating the traffic light cycle indefinitely.

## Simulation

Created and tested using Autodesk [Tinkercad Circuits](https://www.tinkercad.com/circuits).

## License

This project is licensed under the [MIT License](https://github.com/AndreasFragkop/Arduino-Tinkercad-Projects/blob/main/LICENSE).

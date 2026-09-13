# Arduino 16x2 LCD Interface

![Difficulty: Intermediate](https://img.shields.io/badge/Difficulty-Intermediate-orange)

## Overview

This project implements a scrolling text display using an Arduino Uno, a 16x2 LCD, a potentiometer, and a resistor. The LCD displays the message “Loading Data”, which moves across the first row and repeats continuously. The potentiometer allows the user to adjust the display contrast, making the text easier to read.

## Components Used

| Component | Description |
|-----------|-------------|
| Arduino Uno | The microcontroller that runs the program and controls the LCD |
| 16x2 LCD | Displays the scrolling “Loading Data” message |
| 250kΩ Potentiometer | Used to adjust the contrast of the LCD |
| 1kΩ Resistor | Limits the current flowing through the LCD backlight |
| Breadboard / PCB | Used to assemble and hold the circuit components |
| Jumper Wires | Used to connect the Arduino, LCD, potentiometer, and resistor |

## Functionality

* When the system starts, the Arduino initializes the LCD with 16 columns and 2 rows.
* The message “Loading Data” scrolls from left to right across the first row.
* The display updates every 300 milliseconds to move the text one position at a time.
* Once the message moves off the display, the scrolling sequence starts again.
* The potentiometer allows the user to adjust the LCD contrast, while the second row remains blank.

## Code Explanation

This Arduino program uses the `LiquidCrystal` library to control a 16x2 LCD. The message “Loading Data” is stored in a character array with spaces before and after the text. The program displays 16 characters at a time on the first row, then decreases the starting position to move the message from left to right. When the starting position becomes negative, it resets to repeat the scrolling sequence. The `delay()` function pauses the program for **300 milliseconds** between updates to control the scrolling speed.

### Pin Setup

The LCD’s **RS pin is connected to Arduino pin D12**, and its **Enable pin to D11**. The LCD data pins **D4, D5, D6, and D7** are connected to Arduino digital pins **D5, D4, D3, and D2**, respectively. These connections allow the Arduino to send commands and text to the display. The **250kΩ potentiometer** adjusts the contrast through the LCD’s **VO pin**, while a **1kΩ resistor** limits the current through the backlight. The LCD is powered by the Arduino’s **5V** and **GND** connections, with its **RW pin connected to GND**.

### Behaviour

When the system starts, the LCD is briefly blank before the message “Loading Data” enters from the left side of the first row. The text moves one position to the right every **300 milliseconds** until it leaves the display. The scrolling sequence then starts again and repeats continuously, while the second row remains blank. Turning the potentiometer changes the display contrast without affecting the scrolling speed.

## Simulation

Created and tested using Autodesk [Tinkercad Circuits](https://www.tinkercad.com/circuits).

## License

This project is licensed under the [MIT License](../LICENSE).

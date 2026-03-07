# Push Button LED Controller

## Overview

This project uses a push button to control an LED with an Arduino.  
When the button is pressed, the LED turns on. When released, the LED turns off.

## Pin Configuration

- LED pin: `5`
- Button pin: `2`

## Components

- Arduino Uno (or compatible)
- 1 LED
- 1 push button
- 1 resistor (220 ohm for LED)
- 1 resistor (10k ohm for button pull-down, if needed)
- Breadboard and jumper wires

## Behavior

- If `digitalRead(buttonPin)` is `HIGH`, the LED is turned `HIGH`.
- Otherwise, the LED is turned `LOW`.

## File

- `code.ino`

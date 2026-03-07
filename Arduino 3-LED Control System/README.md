# Arduino 3-LED Control System

This project controls three LEDs (red, orange, green) in a repeating traffic-light style sequence.

## LED Sequence

1. Red ON for 5 seconds
2. Green ON for 5 seconds
3. Orange ON for 2 seconds
4. Repeat

## Pin Configuration

- Red LED: pin 11
- Orange LED: pin 10
- Green LED: pin 9

## Components Needed

- 1x Arduino Uno (or compatible board)
- 3x LEDs (red, orange/yellow, green)
- 3x 220 ohm resistors
- Breadboard
- Jumper wires

## Wiring

- Connect Arduino pin 11 to the red LED anode (+) through a 220 ohm resistor.
- Connect Arduino pin 10 to the orange LED anode (+) through a 220 ohm resistor.
- Connect Arduino pin 9 to the green LED anode (+) through a 220 ohm resistor.
- Connect all LED cathodes (-) to GND.

## File

- `Arduino 3-LED Control System.ino`

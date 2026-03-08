# Arduino 8-Button Piano

## Overview

This project creates a simple Arduino piano using 8 push buttons and a buzzer.  
Each button plays one musical note, forming a one-octave scale from C to high C.

## Pin Configuration

- Buzzer pin: `10`
- Button pins: `2, 3, 4, 5, 6, 7, 8, 9`

## Notes

- C: 262 Hz
- D: 294 Hz
- E: 330 Hz
- F: 349 Hz
- G: 392 Hz
- A: 440 Hz
- B: 494 Hz
- High C: 523 Hz

## Components

- Arduino Uno (or compatible)
- 8 push buttons
- 1 piezo buzzer
- Resistors for button wiring (e.g., 10k ohm pull-downs, if needed)
- Breadboard and jumper wires

## Behavior

- The sketch continuously checks all 8 button inputs.
- When a button is pressed, the buzzer plays the mapped note using `tone()`.
- If no button is pressed, the buzzer is silenced with `noTone()`.
- The first detected pressed button in the scan order is played.

## File

- `code.ino`

# Arduino Digital Piano with Push Buttons

## Overview
This project implements a simple digital piano using an Arduino Uno. Eight push buttons are arranged on a breadboard and act as piano keys. When a button is pressed, the Arduino generates a musical tone through a buzzer. Each button corresponds to a different musical note, allowing the user to play simple melodies.

## Components Used

| Component | Description |
|-----------|-------------|
| Arduino Uno | The microcontroller that processes button inputs and generates sound |
| 8 × Push Buttons | Used as piano keys to trigger different musical notes |
| 8 × 10kΩ Resistors | Used as pull-down resistors to stabilize button input signals |
| Piezo Buzzer / Speaker | Produces sound corresponding to the selected musical note |
| Breadboard / PCB | Used to assemble and hold the circuit components |
| Jumper Wires | Used to connect the Arduino pins to the buttons and buzzer |

## Functionality
When a button is pressed, the Arduino reads the corresponding digital input pin and generates a specific frequency using the buzzer.

Each button corresponds to a musical note, allowing the user to play a simple octave of notes similar to a piano.

Only one tone is played at a time. When no buttons are pressed, the buzzer remains silent.

## Code Explanation
This Arduino program reads the state of eight push buttons and generates musical tones using the `tone()` function.

An array stores the Arduino input pins connected to the buttons, while another array stores the frequencies of the musical notes.

The program continuously checks each button. If a button is pressed, the Arduino sends the corresponding frequency to the buzzer.

If no buttons are pressed, the `noTone()` function stops any sound output.

## Pin Setup
The Arduino uses digital pins **D2 to D9** as inputs for the push buttons.

Each button is connected to one digital pin and uses a **10kΩ pull-down resistor** to ensure the pin reads LOW when the button is not pressed.

The buzzer is connected to **digital pin D10**, which is configured as an output. The Arduino sends frequency signals through this pin to produce sound.

## Behaviour
When a button is pressed, the buzzer plays the corresponding musical note.

| Button | Note | Frequency |
|------|------|------|
| Button 1 | C | 262 Hz |
| Button 2 | D | 294 Hz |
| Button 3 | E | 330 Hz |
| Button 4 | F | 349 Hz |
| Button 5 | G | 392 Hz |
| Button 6 | A | 440 Hz |
| Button 7 | B | 494 Hz |
| Button 8 | High C | 523 Hz |

This allows the device to function like a small digital piano.

## Idle State
When no buttons are pressed, the Arduino stops generating sound and the buzzer remains silent.




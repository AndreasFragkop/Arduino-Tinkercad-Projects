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

When a button is pressed, the Arduino reads the corresponding digital input pin and generates a specific frequency using the buzzer. Each button corresponds to a musical note, allowing the user to play a simple octave of notes similar to a piano. Only one tone is played at a time. When no buttons are pressed, the buzzer remains silent.

## Code Explanation

This Arduino program reads the state of eight push buttons and generates musical tones using the `tone()` function. An array stores the Arduino input pins connected to the buttons, while another array stores the frequencies of the musical notes. The program continuously checks each button. If a button is pressed, the Arduino sends the corresponding frequency to the buzzer. If no buttons are pressed, the `noTone()` function stops any sound output.

### Pin Setup

The Arduino uses digital pins **D2 to D9** as inputs for the push buttons. Each button is connected to one digital pin and uses a **10kΩ pull-down resistor** to ensure the pin reads LOW when the button is not pressed. The buzzer is connected to **digital pin D10**, which is configured as an output. The Arduino sends frequency signals through this pin to produce sound.

### Behaviour

When a button is pressed, the Arduino detects the input and sends a specific frequency signal to the buzzer. Each button corresponds to a different musical note, allowing the user to play a small octave similar to a piano keyboard. For example, pressing **Button 1** plays the note **C (262 Hz)**, while **Button 2** plays **D (294 Hz)** and **Button 3** plays **E (330 Hz)**. The sequence continues with **F (349 Hz)**, **G (392 Hz)**, **A (440 Hz)**, and **B (494 Hz)**. The final button plays **High C (523 Hz)**, completing the octave. Because each button produces a different tone, the user can press different buttons to create simple melodies, allowing the circuit to function like a small digital piano.

### Idle State
When no buttons are pressed, the Arduino stops generating sound and the buzzer remains silent.

## Simulation

Created and tested using Autodesk [Tinkercad Circuits](https://www.tinkercad.com).

## License

This project is licensed under the [MIT License](https://github.com/AndreasFragkop/Arduino-Tinkercad-Projects/blob/main/LICENSE).

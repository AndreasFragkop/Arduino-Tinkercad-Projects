# Multi-LED Digital Controller with On-Off Switch

A simple Arduino LED chaser controlled by a digital on-off switch.

## Overview
- Controls 8 LEDs connected to Arduino digital pins `2` to `9`.
- Uses a switch on pin `10` with `INPUT_PULLUP`.
- When the switch is ON (`LOW` on pin 10), LEDs run a forward-and-back chase pattern.
- When the switch is OFF (`HIGH` on pin 10), all LEDs are turned off.

## Files
- `code.ino`: Arduino sketch
- `circuit.png`: Circuit image
- `Arduino Multi-LED Digital Controller.pdf`: Circuit/notes export
- `components.csv`: Components list
- `Arduino Multi-LED Digital Controller.brd`: Board design file

## Pin Mapping
- `LED 1` -> `D2`
- `LED 2` -> `D3`
- `LED 3` -> `D4`
- `LED 4` -> `D5`
- `LED 5` -> `D6`
- `LED 6` -> `D7`
- `LED 7` -> `D8`
- `LED 8` -> `D9`
- `Switch` -> `D10` (configured as `INPUT_PULLUP`)

## How It Works
1. In `setup()`, all LED pins are set as outputs and initialized to `LOW`.
2. The switch pin is configured with internal pull-up (`INPUT_PULLUP`).
3. In `loop()`:
   - If switch reads `LOW`, LEDs animate from first to last and then back toward the first.
   - If switch reads `HIGH`, all LEDs remain off.

## Build and Run (Arduino IDE)
1. Open `code.ino` in Arduino IDE.
2. Select your board (for example, **Arduino Uno**) and serial port.
3. Click **Verify** to compile.
4. Click **Upload** to flash the board.

## Tinkercad Usage
1. Recreate/import the circuit based on `circuit.png` or your saved project.
2. Paste `code.ino` into the code editor.
3. Start simulation and toggle the switch to control the LED sequence.

## Notes
- With `INPUT_PULLUP`, switch logic is inverted: pressed/ON often reads `LOW`.
- The current code uses `delay(200)`, so switch-off response is not immediate during a running sequence.

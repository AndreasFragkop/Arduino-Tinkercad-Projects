# Digital Safe with Keypad

![Difficulty: Advanced](https://img.shields.io/badge/Difficulty-Advanced-red)

## Overview

This project implements a digital safe security system using an Arduino Uno, a 4x4 keypad, an I2C 16x2 LCD, a servo motor, two LEDs, and a piezo buzzer. The user enters a four-digit PIN using the keypad, and the LCD hides each entered digit with an asterisk. A correct PIN unlocks the safe temporarily, while an incorrect PIN activates a warning. After three incorrect attempts, the system sounds an alarm and blocks further input for five seconds.

## Components Used

| Component | Description |
|-----------|-------------|
| Arduino Uno | The microcontroller that processes the PIN and controls the security system |
| 4x4 Keypad | Allows the user to enter, clear, and submit the PIN |
| I2C 16x2 LCD | Displays instructions, masked PIN input, and access messages |
| Positional Micro Servo | Moves the safe latch between its locked and unlocked positions |
| Piezo Buzzer | Produces keypress, success, warning, and alarm sounds |
| Red LED | Indicates an incorrect PIN or active alarm |
| Green LED | Indicates that access has been granted |
| 2 × 220Ω Resistors | Limit the current flowing through the LEDs to protect them |
| Breadboard / PCB | Used to assemble and hold the circuit components |
| Jumper Wires | Used to connect the Arduino, keypad, LCD, servo, LEDs, and buzzer |

## Functionality

* When the system starts, the servo moves to the locked position and the LCD asks for a PIN.
* Number keys enter a four-digit PIN, with each digit displayed as an asterisk.
* The **# key** submits the entered PIN, while the **\* key** clears it.
* Entering the correct PIN **1234** turns on the green LED, plays a success sound, and unlocks the safe for 4 seconds.
* Entering an incorrect PIN turns on the red LED, sounds the buzzer, and displays a warning.
* After three incorrect attempts, the red LED remains on while an alternating alarm sounds for 5 seconds.
* The safe automatically locks again and returns to the PIN entry screen after each completed sequence.

## Code Explanation

This Arduino program uses the `Keypad` library to read the 4x4 keypad, the `Servo` library to control the locking mechanism, and the `LiquidCrystal_I2C` library to display messages. Entered number keys are stored in a `String` until four digits have been entered. Pressing **#** compares the entered value with the stored PIN, while pressing **\*** clears the current entry. The program controls the LEDs, servo, LCD, and buzzer according to whether access is granted or denied. A counter records incorrect attempts and starts the alarm sequence after the third failure.

### Pin Setup

The keypad row pins **R1, R2, R3, and R4** are connected to Arduino digital pins **D2, D3, D4, and D5**. The keypad column pins **C1, C2, C3, and C4** are connected to **D6, D7, D8, and A1**. The servo signal is connected to **D9**, the green LED to **D10**, the red LED to **D11**, and the piezo buzzer to **D12**. The I2C LCD uses address **0x27**, with **SDA connected to A4** and **SCL connected to A5**. The LEDs use **220Ω resistors**, and the circuit shares the Arduino’s **5V** and **GND** connections.

### Behaviour

When the system starts, the LCD displays “DIGITAL SAFE” and waits for a PIN. Each number pressed produces a short sound and appears as an asterisk on the LCD. If the correct PIN is submitted, the green LED turns on, the LCD displays “ACCESS GRANTED,” and the servo moves from **0° to 90°** to unlock the safe. After **4 seconds**, the servo returns to 0° and the system locks again. If the PIN is incorrect, the red LED and warning sound activate before the system requests another attempt. Three consecutive incorrect PINs trigger a 5-second alternating alarm, after which the attempt counter resets.

## Simulation

Created and tested using Autodesk [Tinkercad Circuits](https://www.tinkercad.com/circuits).

## License

This project is licensed under the [MIT License](../LICENSE).

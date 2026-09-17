// Arduino 12-Key Piano

// 12 musical note frequencies: C4 to B4
const int notes[12] = {
  262, 277, 294, 311,
  330, 349, 370, 392,
  415, 440, 466, 494
};

// Buttons connected to D2 through D13
const int buttonPins[12] = {
  2, 3, 4, 5, 6, 7,
  8, 9, 10, 11, 12, 13
};

// Buzzer + connected to A0
const int buzzerPin = A0;

void setup() {

  // Set all buttons as inputs
  for (int i = 0; i < 12; i++) {
    pinMode(buttonPins[i], INPUT);
  }

  // Buzzer output
  pinMode(buzzerPin, OUTPUT);
}

void loop() {

  bool notePlaying = false;

  // Check all 12 buttons
  for (int i = 0; i < 12; i++) {

    if (digitalRead(buttonPins[i]) == HIGH) {

      // Play the corresponding note
      tone(buzzerPin, notes[i]);

      notePlaying = true;

      // Stop checking after finding pressed button
      break;
    }
  }

  // If no button is pressed, stop sound
  if (!notePlaying) {
    noTone(buzzerPin);
  }
}
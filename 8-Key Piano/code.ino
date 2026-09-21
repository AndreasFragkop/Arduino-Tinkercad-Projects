// Arduino 8-button Piano

const int buzzerPin = 10;

// Button pins (pressed = HIGH)
const int buttonPins[8] = {2,3,4,5,6,7,8,9};

// Note frequencies in Hz (C major scale)
int notes[8] = {
  262, // C
  294, // D
  330, // E
  349, // F
  392, // G
  440, // A
  494, // B
  523  // High C
};

void setup() {
  // Set up all button pins as inputs
  for(int i = 0; i < 8; i++){
    pinMode(buttonPins[i], INPUT);
  }

  pinMode(buzzerPin, OUTPUT);
}

void loop() {

  bool buttonPressed = false;

  // Check each button; the first one pressed plays its note
  for(int i = 0; i < 8; i++) {
    if(digitalRead(buttonPins[i]) == HIGH) {
      tone(buzzerPin, notes[i]);
      buttonPressed = true;
      break;   // Only one note at a time
    }
  }

  // Silence the buzzer when no button is pressed
  if(!buttonPressed) {
    noTone(buzzerPin);
  }
}
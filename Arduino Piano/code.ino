// Arduino 8-button Piano

const int buzzerPin = 10;

// Button pins
const int buttonPins[8] = {2,3,4,5,6,7,8,9};

// Musical notes (frequencies in Hz)
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
  for(int i = 0; i < 8; i++){
    pinMode(buttonPins[i], INPUT);
  }

  pinMode(buzzerPin, OUTPUT);
}

void loop() {

  bool buttonPressed = false;

  for(int i = 0; i < 8; i++) {
    if(digitalRead(buttonPins[i]) == HIGH) {
      tone(buzzerPin, notes[i]);
      buttonPressed = true;
      break;
    }
  }

  if(!buttonPressed) {
    noTone(buzzerPin);
  }
}

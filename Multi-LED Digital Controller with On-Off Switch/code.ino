
const int leds[] = {2,3,4,5,6,7,8,9};
const int totalLeds = 8;

const int switchPin = 10;

void setup() {

  pinMode(switchPin, INPUT_PULLUP);

  for (int i = 0; i < totalLeds; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }

}

void loop() {

  if (digitalRead(switchPin) == LOW) {

    for (int i = 0; i < totalLeds; i++) {
      digitalWrite(leds[i], HIGH);
      delay(200);
      digitalWrite(leds[i], LOW);
    }

    for (int i = totalLeds - 2; i > 0; i--) {
      digitalWrite(leds[i], HIGH);
      delay(200);
      digitalWrite(leds[i], LOW);
    }

  } 
  else {

    for (int i = 0; i < totalLeds; i++) {
      digitalWrite(leds[i], LOW);
    }

  }

}
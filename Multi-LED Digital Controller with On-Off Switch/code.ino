// LED pins for the 8-LED chase (Knight Rider style)
const int leds[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int totalLeds = 8;

const int switchPin = 10;   // Switch input (ON = LOW, using internal pull-up)

void setup() {
  pinMode(switchPin, INPUT_PULLUP);

  // Set all LED pins as outputs and start with them off
  for (int i = 0; i < totalLeds; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }
}

void loop() {

  // Switch is ON: run the back-and-forth animation
  if (digitalRead(switchPin) == LOW) {

    // Sweep forward, first LED to last
    for (int i = 0; i < totalLeds; i++) {
      digitalWrite(leds[i], HIGH);
      delay(200);
      digitalWrite(leds[i], LOW);
    }

    // Sweep back, skipping the end LEDs so they aren't lit twice in a row
    for (int i = totalLeds - 2; i > 0; i--) {
      digitalWrite(leds[i], HIGH);
      delay(200);
      digitalWrite(leds[i], LOW);
    }

  }
  // Switch is OFF: keep all LEDs off
  else {

    for (int i = 0; i < totalLeds; i++) {
      digitalWrite(leds[i], LOW);
    }

  }

}
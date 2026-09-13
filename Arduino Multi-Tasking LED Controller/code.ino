const int BLUE_LED   = 5;
const int GREEN_LED  = 6;
const int BUTTON_PIN = 2;

unsigned long previousMillis = 0;
const long blinkInterval = 500; // Blink every 0.5 seconds
int blueState = LOW;

void setup() {
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  // 1. Instant Button Check (Runs continuously without delay)
  if (digitalRead(BUTTON_PIN) == HIGH) {
    digitalWrite(GREEN_LED, HIGH);
  } else {
    digitalWrite(GREEN_LED, LOW);
  }

  // 2. Non-blocking Blue LED Blink Timer
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= blinkInterval) {
    previousMillis = currentMillis;

    // Toggle the blue LED state
    if (blueState == LOW) {
      blueState = HIGH;
    } else {
      blueState = LOW;
    }
    digitalWrite(BLUE_LED, blueState);
  }
}
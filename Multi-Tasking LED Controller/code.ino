const int BLUE_LED   = 5;   // Blinks on its own
const int GREEN_LED  = 6;   // Follows the button
const int BUTTON_PIN = 2;   // Button input (pressed = HIGH)

unsigned long previousMillis = 0;
const long blinkInterval = 500;   // Blink every 0.5 seconds
int blueState = LOW;

void setup() {
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  // Green LED is on only while the button is held
  if (digitalRead(BUTTON_PIN) == HIGH) {
    digitalWrite(GREEN_LED, HIGH);
  } else {
    digitalWrite(GREEN_LED, LOW);
  }

  // Blue LED blinks using millis() instead of delay(),
  // so the button is still checked instantly
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= blinkInterval) {
    previousMillis = currentMillis;

    // Toggle the blue LED
    if (blueState == LOW) {
      blueState = HIGH;
    } else {
      blueState = LOW;
    }
    digitalWrite(BLUE_LED, blueState);
  }
}
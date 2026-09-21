// Pin 13 has an LED connected on most Arduino boards.
const int LED_PIN = 13;

void setup() {
  // Initialize digital pin 13 as an output.
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);   // Turn the LED ON
  delay(1000);                   // Wait for 1 second (1000 milliseconds)
  digitalWrite(LED_PIN, LOW);    // Turn the LED OFF
  delay(1000);                   // Wait for 1 second
}
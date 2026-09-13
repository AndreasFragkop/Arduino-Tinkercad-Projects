const int LDR_PIN = A0;      // Photoresistor voltage signal
const int LED_PIN = 9;       // LED control pin
const int THRESHOLD = 500;   // Trigger point for dark vs light

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);        // Opens Serial Monitor
}

void loop() {
  int sensorValue = analogRead(LDR_PIN);  // Read raw light level (0-1023)

  Serial.print("Light Level: ");
  Serial.println(sensorValue);

  // If it gets dark (value drops below threshold), turn LED ON
  if (sensorValue < THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(100);
}
const int ledRed = 11;
const int ledOrange = 10;
const int ledGreen = 9;

void setup() {
  pinMode(ledRed, OUTPUT);
  pinMode(ledOrange, OUTPUT);
  pinMode(ledGreen, OUTPUT);
}

void loop() {

  // RED light - 5 seconds
  digitalWrite(ledRed, HIGH);
  digitalWrite(ledOrange, LOW);
  digitalWrite(ledGreen, LOW);
  delay(5000);

  // GREEN light - 5 seconds
  digitalWrite(ledRed, LOW);
  digitalWrite(ledOrange, LOW);
  digitalWrite(ledGreen, HIGH);
  delay(5000);

  // ORANGE light - 2 seconds
  digitalWrite(ledRed, LOW);
  digitalWrite(ledOrange, HIGH);
  digitalWrite(ledGreen, LOW);
  delay(2000);
}

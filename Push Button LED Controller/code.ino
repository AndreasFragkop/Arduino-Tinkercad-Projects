const int ledPin = 5;
const int buttonPin = 2;

void setup() 
{
  pinMode(ledPin, OUTPUT);   // LED output
  pinMode(buttonPin, INPUT); // Button input
}

void loop() 
{
  if (digitalRead(buttonPin) == HIGH) { 
    digitalWrite(ledPin, HIGH); // Turn LED ON
  } 
  else { 
    digitalWrite(ledPin, LOW);  // Turn LED OFF
  }
}

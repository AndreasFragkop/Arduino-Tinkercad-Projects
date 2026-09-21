const int redLED = 11;
const int yellowLED = 10;
const int greenLED = 9;

const int sensorPin = 7;   // 3-pin ultrasonic sensor (one pin for trigger and echo)
const int buzzerPin = 6;


// Returns distance in cm, or -1 if nothing detected
long getDistanceCM() {

  // Send trigger pulse
  pinMode(sensorPin, OUTPUT);

  digitalWrite(sensorPin, LOW);
  delayMicroseconds(2);

  digitalWrite(sensorPin, HIGH);
  delayMicroseconds(5);

  digitalWrite(sensorPin, LOW);

  // Listen for the echo on the same pin
  pinMode(sensorPin, INPUT);

  long duration = pulseIn(sensorPin, HIGH, 30000);

  // Timed out, no object detected
  if (duration == 0) {
    return -1;
  }

  // Convert echo time to cm
  return duration / 58;
}


void setup() {

  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
}


void loop() {

  long distance = getDistanceCM();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Turn everything off first
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);

  noTone(buzzerPin);


  // No object detected
  if (distance <= 0) {

    delay(100);
  }


  // Red: 30 cm or closer
  else if (distance <= 30) {

    digitalWrite(redLED, HIGH);

    // Continuous sound
    tone(buzzerPin, 800);

    delay(50);
  }


  // Yellow: 31 - 79 cm
  else if (distance < 80) {

    digitalWrite(yellowLED, HIGH);

    // Faster beep
    tone(buzzerPin, 800);
    delay(120);

    noTone(buzzerPin);
    delay(250);
  }


  // Green: 80 - 150 cm
  else if (distance <= 150) {

    digitalWrite(greenLED, HIGH);

    // Slow beep
    tone(buzzerPin, 800);
    delay(120);

    noTone(buzzerPin);
    delay(650);
  }


  // More than 150 cm: everything stays off
  else {

    noTone(buzzerPin);

    delay(100);
  }
}
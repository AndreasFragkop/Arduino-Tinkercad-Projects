#include <Servo.h>

Servo servo;

const int servoPin = 3;
const int leftSensorPin = A0;    // Left light sensor
const int rightSensorPin = A1;   // Right light sensor

int servoPos = 90;         // Start centered
const int threshold = 20;  // Ignore small differences

void setup()
{
  servo.attach(servoPin);
  servo.write(servoPos);
}

void loop()
{
  // Read both light sensors
  int leftSensor  = analogRead(leftSensorPin);
  int rightSensor = analogRead(rightSensorPin);

  int diff = leftSensor - rightSensor;

  // Only move if the difference is big enough
  if (abs(diff) > threshold)
  {
    // Turn one step toward the brighter side, within 0-180 degrees
    if (diff > 0 && servoPos < 180)
    {
      servoPos++;
    }
    else if (diff < 0 && servoPos > 0)
    {
      servoPos--;
    }

    servo.write(servoPos);
  }

  delay(20);   // Small delay for smooth, slow movement
}
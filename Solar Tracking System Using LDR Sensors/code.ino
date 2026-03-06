#include <Servo.h>

Servo servo;

const int servoPin = 3;
const int leftSensorPin = A0;
const int rightSensorPin = A1;

int servoPos = 90;      // start centered
const int threshold = 20; // ignore small differences

void setup()
{
  servo.attach(servoPin);
  servo.write(servoPos);
}

void loop()
{
  int leftSensor  = analogRead(leftSensorPin);
  int rightSensor = analogRead(rightSensorPin);

  int diff = leftSensor - rightSensor;

  if (abs(diff) > threshold)
  {
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

  delay(20);
}

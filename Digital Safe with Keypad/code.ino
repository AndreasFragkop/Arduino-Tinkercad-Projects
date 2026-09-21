#include <Keypad.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// I2C LCD (address 0x27, 16x2)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Servo that moves the safe latch
Servo safeLatch;

const int SERVO_PIN = 9;
const int LOCKED_POS = 0;
const int UNLOCKED_POS = 90;

// Status LEDs and buzzer
const int GREEN_LED = 10;
const int RED_LED = 11;
const int BUZZER = 12;

// 4x4 keypad layout
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Keypad wiring: rows on D2-D5, columns on D6, D7, D8, A1
byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, A1};

Keypad keypad = Keypad(
  makeKeymap(keys),
  rowPins,
  colPins,
  ROWS,
  COLS
);

const String CORRECT_PIN = "1234";

String enteredPIN = "";   // PIN typed so far
int wrongAttempts = 0;    // Counts consecutive wrong entries

void setup() {

  // Start the LCD
  lcd.init();
  lcd.backlight();

  // LEDs and buzzer start off
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);

  // Start with the safe locked
  safeLatch.attach(SERVO_PIN);
  safeLatch.write(LOCKED_POS);

  showHomeScreen();
}

void loop() {

  char key = keypad.getKey();

  if (key) {

    // Short beep on every key press
    tone(BUZZER, 1000, 50);

    // # = enter
    if (key == '#') {
      checkPIN();
    }

    // * = clear
    else if (key == '*') {
      enteredPIN = "";
      showHomeScreen();
    }

    // Digits only, up to 4 characters
    else if (key >= '0' && key <= '9') {

      if (enteredPIN.length() < 4) {

        enteredPIN += key;

        // Show a * for each digit entered
        lcd.setCursor(5 + enteredPIN.length() - 1, 1);
        lcd.print("*");
      }
    }
  }
}


// Draw the default screen
void showHomeScreen() {

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print(" DIGITAL SAFE ");

  lcd.setCursor(0, 1);
  lcd.print("PIN: ");
}


// Check the entered PIN and react
void checkPIN() {

  // Correct PIN: unlock the safe
  if (enteredPIN == CORRECT_PIN) {

    wrongAttempts = 0;

    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ACCESS GRANTED");

    lcd.setCursor(0, 1);
    lcd.print("UNLOCKING...");

    // Success sound
    tone(BUZZER, 1500, 150);
    delay(200);

    tone(BUZZER, 2000, 200);

    // Open the latch and keep it open for 4 seconds
    safeLatch.write(UNLOCKED_POS);

    delay(4000);

    // Lock again
    safeLatch.write(LOCKED_POS);

    digitalWrite(GREEN_LED, LOW);

    enteredPIN = "";

    showHomeScreen();
  }

  // Wrong PIN
  else {

    wrongAttempts++;

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("WRONG PIN!");

    lcd.setCursor(0, 1);
    lcd.print("TRY AGAIN");

    // Low error tone
    tone(BUZZER, 400, 500);

    delay(1500);

    digitalWrite(RED_LED, LOW);

    enteredPIN = "";

    // After 3 wrong attempts, sound the alarm and lock out for 5 seconds
    if (wrongAttempts >= 3) {

      lcd.clear();

      lcd.setCursor(0, 0);
      lcd.print("ALARM!");

      lcd.setCursor(0, 1);
      lcd.print("WAIT 5 SEC");

      digitalWrite(RED_LED, HIGH);

      // Alternating siren tones, 1 second per loop
      for (int i = 0; i < 5; i++) {

        tone(BUZZER, 700, 400);
        delay(500);

        tone(BUZZER, 1200, 400);
        delay(500);
      }

      digitalWrite(RED_LED, LOW);

      wrongAttempts = 0;
    }

    showHomeScreen();
  }
}
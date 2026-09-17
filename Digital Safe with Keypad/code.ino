#include <Keypad.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// ---------------- LCD ----------------
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ---------------- SERVO ----------------
Servo safeLatch;

const int SERVO_PIN = 9;
const int LOCKED_POS = 0;
const int UNLOCKED_POS = 90;

// ---------------- LEDs + BUZZER ----------------
const int GREEN_LED = 10;
const int RED_LED = 11;
const int BUZZER = 12;

// ---------------- KEYPAD ----------------
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Keypad:
// R1 = D2
// R2 = D3
// R3 = D4
// R4 = D5
// C1 = D6
// C2 = D7
// C3 = D8
// C4 = A1

byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, A1};

Keypad keypad = Keypad(
  makeKeymap(keys),
  rowPins,
  colPins,
  ROWS,
  COLS
);

// ---------------- PASSWORD ----------------
const String CORRECT_PIN = "1234";

String enteredPIN = "";
int wrongAttempts = 0;

void setup() {

  // LCD
  lcd.init();
  lcd.backlight();

  // LEDs and buzzer
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);

  // Servo
  safeLatch.attach(SERVO_PIN);
  safeLatch.write(LOCKED_POS);

  showHomeScreen();
}

void loop() {

  char key = keypad.getKey();

  if (key) {

    // Small sound when a key is pressed
    tone(BUZZER, 1000, 50);

    // # = ENTER
    if (key == '#') {
      checkPIN();
    }

    // * = CLEAR
    else if (key == '*') {
      enteredPIN = "";
      showHomeScreen();
    }

    // Only allow numbers
    else if (key >= '0' && key <= '9') {

      if (enteredPIN.length() < 4) {

        enteredPIN += key;

        lcd.setCursor(5 + enteredPIN.length() - 1, 1);
        lcd.print("*");
      }
    }
  }
}

// ------------------------------------------------

void showHomeScreen() {

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print(" DIGITAL SAFE ");

  lcd.setCursor(0, 1);
  lcd.print("PIN: ");
}

// ------------------------------------------------

void checkPIN() {

  // CORRECT PASSWORD
  if (enteredPIN == CORRECT_PIN) {

    wrongAttempts = 0;

    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ACCESS GRANTED");

    lcd.setCursor(0, 1);
    lcd.print("UNLOCKING...");

    // Success sounds
    tone(BUZZER, 1500, 150);
    delay(200);

    tone(BUZZER, 2000, 200);

    // Open vault
    safeLatch.write(UNLOCKED_POS);

    delay(4000);

    // Lock again
    safeLatch.write(LOCKED_POS);

    digitalWrite(GREEN_LED, LOW);

    enteredPIN = "";

    showHomeScreen();
  }

  // WRONG PASSWORD
  else {

    wrongAttempts++;

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("WRONG PIN!");

    lcd.setCursor(0, 1);
    lcd.print("TRY AGAIN");

    tone(BUZZER, 400, 500);

    delay(1500);

    digitalWrite(RED_LED, LOW);

    enteredPIN = "";

    // Alarm after 3 wrong attempts
    if (wrongAttempts >= 3) {

      lcd.clear();

      lcd.setCursor(0, 0);
      lcd.print("ALARM!");

      lcd.setCursor(0, 1);
      lcd.print("WAIT 5 SEC");

      digitalWrite(RED_LED, HIGH);

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
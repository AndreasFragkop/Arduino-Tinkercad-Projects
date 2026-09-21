#include <LiquidCrystal.h>

// LCD pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

// Buttons (active HIGH, using external pull-down resistors)
const int SET_BUTTON  = 8;
const int UP_BUTTON   = 9;
const int DOWN_BUTTON = 10;

// Time and date
int h = 0;
int m = 0;
int s = 0;
int day = 1;
int month = 1;

// 0 = run, 1 = set hours, 2 = set minutes, 3 = set day, 4 = set month
int mode = 0;

int daysInMonth[13] = {
  0,
  31, 28, 31, 30, 31, 30,
  31, 31, 30, 31, 30, 31
};

// Single-character month display (Oct = O, Nov = N, Dec = D)
char monthCharacter[13] = {
  ' ',
  '1', '2', '3', '4', '5', '6',
  '7', '8', '9', 'O', 'N', 'D'
};

// Previous button states, used to detect a new press
bool lastSet  = LOW;
bool lastUp   = LOW;
bool lastDown = LOW;

unsigned long previousMillis = 0;
bool colonState = true;   // Toggles every 500 ms to blink the colon


// Custom characters used to build the big digits
byte bar1[8] = {
  B11100,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11100
};

byte bar2[8] = {
  B00111,
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
  B00111
};

byte bar3[8] = {
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111
};

byte bar4[8] = {
  B11110,
  B11100,
  B00000,
  B00000,
  B00000,
  B00000,
  B11000,
  B11100
};

byte bar5[8] = {
  B01111,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00011,
  B00111
};

byte bar6[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111
};

byte bar7[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00111,
  B01111
};

byte bar8[8] = {
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};


void setup() {

  lcd.begin(16, 2);

  // Load custom characters into LCD memory
  lcd.createChar(1, bar1);
  lcd.createChar(2, bar2);
  lcd.createChar(3, bar3);
  lcd.createChar(4, bar4);
  lcd.createChar(5, bar5);
  lcd.createChar(6, bar6);
  lcd.createChar(7, bar7);
  lcd.createChar(0, bar8);   // Slot 0 is used for bar8

  pinMode(SET_BUTTON, INPUT);
  pinMode(UP_BUTTON, INPUT);
  pinMode(DOWN_BUTTON, INPUT);

  // Start at 00:00:00, 1 Jan, in run mode
  mode = 0;
  h = 0;
  m = 0;
  s = 0;
  day = 1;
  month = 1;
  colonState = true;

  lcd.clear();
  delay(300);

  // Read starting button states
  lastSet  = digitalRead(SET_BUTTON);
  lastUp   = digitalRead(UP_BUTTON);
  lastDown = digitalRead(DOWN_BUTTON);

  previousMillis = millis();
}


// Big digits: each is 3 columns wide and 2 rows tall
void custom0(int col) {

  lcd.setCursor(col, 0);
  lcd.write(byte(2));
  lcd.write(byte(0));
  lcd.write(byte(1));

  lcd.setCursor(col, 1);
  lcd.write(byte(2));
  lcd.write(byte(6));
  lcd.write(byte(1));
}

void custom1(int col) {

  lcd.setCursor(col, 0);
  lcd.print("  ");
  lcd.write(byte(1));

  lcd.setCursor(col, 1);
  lcd.print("  ");
  lcd.write(byte(1));
}

void custom2(int col) {

  lcd.setCursor(col, 0);
  lcd.write(byte(5));
  lcd.write(byte(3));
  lcd.write(byte(1));

  lcd.setCursor(col, 1);
  lcd.write(byte(2));
  lcd.write(byte(6));
  lcd.write(byte(6));
}

void custom3(int col) {

  lcd.setCursor(col, 0);
  lcd.write(byte(5));
  lcd.write(byte(3));
  lcd.write(byte(1));

  lcd.setCursor(col, 1);
  lcd.write(byte(7));
  lcd.write(byte(6));
  lcd.write(byte(1));
}

void custom4(int col) {

  lcd.setCursor(col, 0);
  lcd.write(byte(2));
  lcd.write(byte(6));
  lcd.write(byte(1));

  lcd.setCursor(col, 1);
  lcd.print("  ");
  lcd.write(byte(1));
}

void custom5(int col) {

  lcd.setCursor(col, 0);
  lcd.write(byte(2));
  lcd.write(byte(3));
  lcd.write(byte(4));

  lcd.setCursor(col, 1);
  lcd.write(byte(7));
  lcd.write(byte(6));
  lcd.write(byte(1));
}

void custom6(int col) {

  lcd.setCursor(col, 0);
  lcd.write(byte(2));
  lcd.write(byte(3));
  lcd.write(byte(4));

  lcd.setCursor(col, 1);
  lcd.write(byte(2));
  lcd.write(byte(6));
  lcd.write(byte(1));
}

void custom7(int col) {

  lcd.setCursor(col, 0);
  lcd.write(byte(0));
  lcd.write(byte(0));
  lcd.write(byte(1));

  lcd.setCursor(col, 1);
  lcd.print("  ");
  lcd.write(byte(1));
}

void custom8(int col) {

  lcd.setCursor(col, 0);
  lcd.write(byte(2));
  lcd.write(byte(3));
  lcd.write(byte(1));

  lcd.setCursor(col, 1);
  lcd.write(byte(2));
  lcd.write(byte(6));
  lcd.write(byte(1));
}

void custom9(int col) {

  lcd.setCursor(col, 0);
  lcd.write(byte(2));
  lcd.write(byte(3));
  lcd.write(byte(1));

  lcd.setCursor(col, 1);
  lcd.write(byte(7));
  lcd.write(byte(6));
  lcd.write(byte(1));
}


// Draw a single big digit (0-9) starting at the given column
void printNumber(int value, int col) {

  switch (value) {

    case 0:
      custom0(col);
      break;

    case 1:
      custom1(col);
      break;

    case 2:
      custom2(col);
      break;

    case 3:
      custom3(col);
      break;

    case 4:
      custom4(col);
      break;

    case 5:
      custom5(col);
      break;

    case 6:
      custom6(col);
      break;

    case 7:
      custom7(col);
      break;

    case 8:
      custom8(col);
      break;

    case 9:
      custom9(col);
      break;
  }
}


// Read buttons and handle mode changes and value adjustments
void checkButtons() {

  bool setNow  = digitalRead(SET_BUTTON);
  bool upNow   = digitalRead(UP_BUTTON);
  bool downNow = digitalRead(DOWN_BUTTON);


  // SET: cycle through modes
  if (setNow == HIGH && lastSet == LOW) {

    mode++;

    if (mode > 4) {

      mode = 0;

      // Resume the clock cleanly
      previousMillis = millis();
    }

    delay(100);   // Simple debounce
  }


  // UP: increase the selected value
  if (upNow == HIGH && lastUp == LOW) {

    if (mode == 1) {          // Hours
      h = h + 1;

      if (h > 23) {
        h = 0;
      }
    }

    else if (mode == 2) {     // Minutes
      m = m + 1;

      if (m > 59) {
        m = 0;
      }
    }

    else if (mode == 3) {     // Day
      day = day + 1;

      if (day > daysInMonth[month]) {
        day = 1;
      }
    }

    else if (mode == 4) {     // Month
      month = month + 1;

      if (month > 12) {
        month = 1;
      }

      // Keep the day valid for the new month
      if (day > daysInMonth[month]) {
        day = daysInMonth[month];
      }
    }

    delay(100);
  }


  // DOWN: decrease the selected value
  if (downNow == HIGH && lastDown == LOW) {

    if (mode == 1) {          // Hours
      h = h - 1;

      if (h < 0) {
        h = 23;
      }
    }

    else if (mode == 2) {     // Minutes
      m = m - 1;

      if (m < 0) {
        m = 59;
      }
    }

    else if (mode == 3) {     // Day
      day = day - 1;

      if (day < 1) {
        day = daysInMonth[month];
      }
    }

    else if (mode == 4) {     // Month
      month = month - 1;

      if (month < 1) {
        month = 12;
      }

      // Keep the day valid for the new month
      if (day > daysInMonth[month]) {
        day = daysInMonth[month];
      }
    }

    delay(100);
  }


  // Remember button states for the next loop
  lastSet  = setNow;
  lastUp   = upNow;
  lastDown = downNow;
}


// Keep time: every 500 ms the colon toggles, and each full blink adds 1 second
void updateClock() {

  unsigned long currentMillis = millis();

  // Run mode: clock is counting
  if (mode == 0) {

    if (currentMillis - previousMillis >= 500) {

      previousMillis = currentMillis;

      colonState = !colonState;

      // Count a second each time the colon turns on
      if (colonState == true) {

        s++;

        if (s >= 60) {

          s = 0;
          m++;

          if (m >= 60) {

            m = 0;
            h++;

            if (h >= 24) {

              h = 0;
              day++;

              if (day > daysInMonth[month]) {

                day = 1;
                month++;

                if (month > 12) {
                  month = 1;
                }
              }
            }
          }
        }
      }
    }
  }

  // Setting modes: clock is paused, colon stays on
  else {

    colonState = true;
    previousMillis = currentMillis;
  }
}


// Draw time, seconds and date on the LCD
void displayClock() {

  // Hours
  printNumber(h / 10, 0);
  printNumber(h % 10, 3);

  // Minutes
  printNumber(m / 10, 7);
  printNumber(m % 10, 10);

  // Blinking dots between hours and minutes
  if (colonState) {

    lcd.setCursor(6, 0);
    lcd.print(".");

    lcd.setCursor(6, 1);
    lcd.print(".");
  }

  else {

    lcd.setCursor(6, 0);
    lcd.print(" ");

    lcd.setCursor(6, 1);
    lcd.print(" ");
  }

  // Blinking colon before seconds
  lcd.setCursor(13, 0);

  if (colonState) {
    lcd.print(":");
  }
  else {
    lcd.print(" ");
  }

  // Seconds
  lcd.setCursor(14, 0);
  lcd.print(s / 10);
  lcd.print(s % 10);

  // Date: month character followed by two-digit day
  lcd.setCursor(13, 1);
  lcd.print(monthCharacter[month]);
  lcd.print(day / 10);
  lcd.print(day % 10);
}


void loop() {

  checkButtons();
  updateClock();
  displayClock();
}
#include <LiquidCrystal.h>
#include <string.h>

// LCD pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Padded with spaces so the text scrolls in and out of view
char text[] = "                Loading Data                ";
int scrollIndex;   // Start position of the 16-character window

void setup() {

  lcd.begin(16, 2);

  // Start the window at the end of the text
  scrollIndex = strlen(text) - 16;
}

void loop() {

  lcd.setCursor(0, 0);

  // Print the current 16-character window
  for (int i = 0; i < 16; i++) {
    lcd.print(text[scrollIndex + i]);
  }

  // Move the window left, so the text appears to scroll right
  scrollIndex--;

  // Wrap around to the end when we reach the start
  if (scrollIndex < 0) {
    scrollIndex = strlen(text) - 16;
  }

  delay(300);   // Scroll speed
}
#include <LiquidCrystal.h>
#include <string.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

char text[] = "                Loading Data                ";
int index;

void setup() {

  lcd.begin(16, 2);

  index = strlen(text) - 16;
}

void loop() {

  lcd.setCursor(0, 0);

  for (int i = 0; i < 16; i++) {
    lcd.print(text[index + i]);
  }

  index--;

  if (index < 0) {
    index = strlen(text) - 16;
  }

  delay(300);
}
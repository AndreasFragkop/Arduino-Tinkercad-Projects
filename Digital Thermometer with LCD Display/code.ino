#include <LiquidCrystal.h>

// Initialize LCD pins (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Custom degree symbol pixel pattern (5x8 grid)
byte degreeSymbol[8] = {
  B00110,
  B01001,
  B01001,
  B00110,
  B00000,
  B00000,
  B00000,
  B00000
};

int rawADC;
double tempC;

void setup() {
  lcd.begin(16, 2);

  // Create custom degree character at slot 0
  lcd.createChar(0, degreeSymbol);

  // Line 0: Display phrase
  lcd.setCursor(0, 0);
  lcd.print("Current Temp:");
}

void loop() {
  // Read sensor on pin A0
  rawADC = analogRead(A0);

  // Convert ADC reading to Celsius (TMP36 formula)
  tempC = (((double)rawADC / 1024.0) * 5.0 - 0.5) * 100.0;

  // Line 1: Display temperature reading
  lcd.setCursor(0, 1);
  lcd.print(tempC, 1);   // Displays temperature with 1 decimal place
  lcd.write(byte(0));    // Custom degree symbol °
  lcd.print("C   ");      // Clear trailing digits

  delay(500); // Prevents display flickering
}

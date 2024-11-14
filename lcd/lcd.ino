#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Line 1: Hello,");
  lcd.setCursor(0, 1);
  lcd.print("Line 2: World!");

  delay(2000); // Display for 2 seconds

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scrolling Line:");
  
  for (int i = 0; i < 20; i++) {
    lcd.setCursor(0, 1);
    lcd.print("This is a long text");
    lcd.scrollDisplayLeft();
    delay(300); // Scroll speed
  }
}

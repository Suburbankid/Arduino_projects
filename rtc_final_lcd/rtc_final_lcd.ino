#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
    lcd.begin(16, 2);
  Serial.begin(9600);
  while (!Serial) ; // wait for serial
  delay(200);
  Serial.println("DS1307RTC Read Test");
  Serial.println("-------------------");
}

void loop() {
  tmElements_t tm;

  if (RTC.read(tm)) {
    Serial.print("Time = ");
    
    
    print2digits(tm.Hour);
    Serial.write(':');
    print2digits(tm.Minute);
    Serial.write(':');
    print2digits(tm.Second);
    Serial.print(", Date (D/M/Y) = ");
    Serial.print(tm.Day);
    Serial.write('/');
    Serial.print(tm.Month);
    Serial.write('/');
    Serial.print(tmYearToCalendar(tm.Year));
    Serial.println();
    char dateBuffer[20];
  char timeBuffer[20];

  // Format the date string
  sprintf(dateBuffer, "Date: %02d/%02d/%04d", tm.Day, tm.Month, tmYearToCalendar(tm.Year));

  // Format the time string
  sprintf(timeBuffer, "Time: %02d:%02d:%02d", tm.Hour, tm.Minute, tm.Second);

  // Clear the LCD
  lcd.clear();

  // Set the cursor to column 0, line 0
  lcd.setCursor(0, 0);
  lcd.print(dateBuffer);

  // Set the cursor to column 0, line 1
  lcd.setCursor(0, 1);
  lcd.print(timeBuffer);

   // Update every second
  } else {
    if (RTC.chipPresent()) {
      Serial.println("The DS1307 is stopped.  Please run the SetTime");
      Serial.println("example to initialize the time and begin running.");
      Serial.println();
    } else {
      Serial.println("DS1307 read error!  Please check the circuitry.");
      Serial.println();
    }
    delay(9000);
  }
  delay(1000);
}

void print2digits(int number) {
  if (number >= 0 && number < 10) {
    Serial.write('0');
  }
  Serial.print(number);
}

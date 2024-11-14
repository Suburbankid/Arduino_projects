#include <Wire.h>
#include <DS1307RTC.h>
#include <TimeLib.h>

void setup() {
  Serial.begin(9600);
  while (!Serial) ; // wait for serial
  delay(200);
}

void loop() {
  tmElements_t tm;
  RTC.read(tm);

  // Print the date
  Serial.print("Date: ");
  Serial.print(tm.Day);
  Serial.print("/");
  Serial.print(tm.Month);
  Serial.print("/");
  Serial.println(tmYearToCalendar(tm.Year));

  // Print the time
  Serial.print("Time: ");
  print2digits(tm.Hour);
  Serial.print(":");
  print2digits(tm.Minute);
  Serial.print(":");
  print2digits(tm.Second);
  Serial.println();

  delay(1000); // Update every second
}

void print2digits(int number) {
  if (number >= 0 && number < 10) {
    Serial.print('0');
  }
  Serial.print(number);
}

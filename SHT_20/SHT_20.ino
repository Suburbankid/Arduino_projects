#include <DFRobot_SHT20.h>
#include <Wire.h>

// Define the I2C address of the SHT20 sensor
#define SHT20_I2C_ADDR 0x40

// Create an instance of the DFRobot_SHT20 class
DFRobot_SHT20 sht20(&Wire, SHT20_I2C_ADDR);

void setup() {
  // Initialize serial communication at 115200 baud rate
  Serial.begin(115200);
  
  // Initialize the I2C interface
  Wire.begin();
  
  // Initialize the SHT20 sensor
  sht20.initSHT20();
  delay(100);
  Serial.println("Sensor init finish!");
  
  // Check the current status information of SHT20
  sht20.checkSHT20();
}

void loop() {
  // Read the measured humidity data
  float humd = sht20.readHumidity();
  
  // Read the measured temperature data
  float temp = sht20.readTemperature();
  
  // Print the system time, temperature, and humidity to the serial monitor
  Serial.print("Time: ");
  Serial.print(millis());
  Serial.print(" Temperature: ");
  Serial.print(temp, 1); // Print temperature with one decimal place
  Serial.print("°C Humidity: ");
  Serial.print(humd, 1); // Print humidity with one decimal place
  Serial.println("%");
  
  // Delay for 1 second before taking the next reading
  delay(1000);
}

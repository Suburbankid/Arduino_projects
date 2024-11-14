#include <Servo.h>

int pos = 0, inp = 2;  // Change inp to pin 2 (supports interrupts)
bool pinAState = false;  // Track the direction of the servo
Servo servo_9;

// Function to move servo to 180 degrees
void ri() {
  for (pos = 0; pos <= 180; pos += 1) {
    Serial.println("Moving right");
    servo_9.write(pos);
    delay(15);  // Wait for 15 millisecond(s)
  }
}

// Function to move servo back to 0 degrees
void anti() {
  for (pos = 180; pos >= 0; pos -= 1) {
    Serial.println("Moving left");
    servo_9.write(pos);
    delay(15);  // Wait for 15 millisecond(s)
  }
}

// Interrupt Service Routine (ISR) to toggle the direction
void toggleDirection() {
  pinAState = !pinAState;  // Toggle the direction state
}

void setup() {
  Serial.begin(9600);

  // Set input pin for the button
  pinMode(inp, INPUT);  // Button pin is now pin 2

  // Attach the servo to pin 22
  servo_9.attach(22, 500, 5000);

  // Attach interrupt to the button pin (2) for changing direction
  attachInterrupt(digitalPinToInterrupt(inp), toggleDirection, RISING);  // Trigger on rising edge (button press)
}

void loop() {
  delay(3000);  // 3 seconds delay between movements

  // Move the servo based on the current direction
  if (pinAState) {
    ri();  // Move servo to 180 degrees
  } else {
    anti();  // Move servo back to 0 degrees
  }
}

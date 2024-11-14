void setup() {
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop()
{
  
  int v = digitalRead(2);
  if (v==0)
  {  
    Serial.print("HIGH READING IS ");
    Serial.println(v);
  }
  
  else if  (v==1)
  
  {
    Serial.print("LOW READING IS ");
    Serial.println(v);
  }
  
  delay(100); // Optional: Add a delay to reduce serial output frequency
  }

const int k[]={33,35,37,39,41,43,45,47};

void blinkall()
  {for(int i=0;i<8;i++)
  { digitalWrite(k[i],HIGH);
   delay(250);}
   for(int i=0;i<8;i++)
   {
   digitalWrite(k[i],LOW);
   delay(250);
  }}
void altblink()
{
   for (int i = 0; i < 8; i += 2) {
digitalWrite(k[i], HIGH);
delay(250);
digitalWrite(k[i], LOW);
}
delay(500);
for (int i = 1; i < 8; i += 2) {
digitalWrite(k[i], HIGH);
delay(250);
digitalWrite(k[i], LOW);
}
delay(500);
}
void setup()
{for(int i=3;i<10;i++)
{
  pinMode(i,OUTPUT);
}
}
void loop()
{
  blinkall();
delay(2000);
  altblink();
  delay(2000);
}

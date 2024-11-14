int pinOut = 49;
int pinA = 41;
int pinB = 37;
void setup()
{
pinMode(pinOut, OUTPUT);
pinMode(pinA, INPUT);
pinMode(pinB, INPUT);
}
void loop()
{
boolean pinAState = digitalRead(pinA);
boolean pinBState = digitalRead(pinB);
boolean pinOutState;
// and
pinOutState =pinAState & pinBState;
digitalWrite(pinOut, pinOutState);
}

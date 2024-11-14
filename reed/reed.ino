int reedSwitch = 53,LED=51;
void isr1(){
digitalWrite(LED,HIGH);
}
void isr2(){
digitalWrite(LED,LOW);
}
void setup() {
pinMode(reedSwitch,INPUT);
pinMode(LED,OUTPUT);
}
void loop() {
int s = digitalRead(reedSwitch);
attachInterrupt(s,isr1,FALLING);
attachInterrupt(s,isr2,RISING);
}

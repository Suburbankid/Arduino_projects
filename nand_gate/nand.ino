int b1=49,b2=47,val1=0,val2=0;
int led1=33,led2=31,led3=22;
bool s1=false,s2=false,result=false;
bool nand(bool input1, bool input2) {
return !(input1 && input2);
}
void setup() {
pinMode(b1,INPUT);
pinMode(b2,INPUT);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
}
void loop() {
val1 = digitalRead(b1);
delay(150);
if(val1==0)
{
s1 = !s1;
}
val2 = digitalRead(b2);
delay(150);
if(val2==0)
{
s2 = !s2;
}
if(s1)
{
digitalWrite(led1,HIGH);
}
else
{
digitalWrite(led1,LOW);
}
if(s2)
{
digitalWrite(led2,HIGH);
}
else
{
digitalWrite(led2,LOW);
}
result = nand(s1,s2);
if(result)
{
digitalWrite(led3,HIGH);
}
else
{
digitalWrite(led3,LOW);
}
}

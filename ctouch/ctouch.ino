int a=7,b=6,c=5,d=4;
int l=30,m=31,n=32,o=33;
void setup() {
Serial.begin(9600);
pinMode(a,INPUT);
pinMode(b,INPUT);
pinMode(c,INPUT);
pinMode(d,INPUT);
pinMode(l,OUTPUT);
pinMode(m,OUTPUT);
pinMode(n,OUTPUT);
pinMode(o,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(a)==HIGH)
{digitalWrite(l,HIGH);
}
else digitalWrite(l,LOW);
if(digitalRead(b)==HIGH)
{digitalWrite(m,HIGH);
}
else digitalWrite(m,LOW);
if(digitalRead(c)==HIGH)
{digitalWrite(n,HIGH);
}
else digitalWrite(n,LOW);
if(digitalRead(d)==HIGH)
{digitalWrite(o,HIGH);
}
else digitalWrite(o,LOW);
}

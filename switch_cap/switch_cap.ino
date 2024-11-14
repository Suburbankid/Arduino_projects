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
int k[]={a,b,c,d};
int t[]={l,m,n,o};
for(int i=0;i<4;i++)
{switch(digitalRead(k[i]))
{
  case 1:digitalWrite(t[i],HIGH);
break;
  case 0:digitalWrite(t[i],LOW);
break;
default: digitalWrite(t[i],LOW);
}}}

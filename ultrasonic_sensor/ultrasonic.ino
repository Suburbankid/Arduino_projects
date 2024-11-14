
void setup()
{
  Serial.begin(9600);
  pinMode(6,OUTPUT);
  pinMode(5,INPUT);
  pinMode(4,OUTPUT);
  Serial.begin(9600);
  
  
}

void loop()
{
  digitalWrite(6,HIGH);
  delayMicroseconds(10);
  digitalWrite(6,LOW);
  delayMicroseconds(10);
  float dur=pulseIn(5,HIGH);
  float dis=dur*0.017;
  Serial.println(dis);
  if(dis<50)
  {digitalWrite(4,HIGH);
  }
  else if(dis>50)
  {digitalWrite(4,LOW);
  }
}

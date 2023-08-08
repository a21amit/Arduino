//circuit link: https://www.tinkercad.com/things/3BHwouMvs0C
int buzzPin=8;
int potPin=A3;
int potVal;
int dt=500;
void setup() {
  // put your setup code here, to run once:
pinMode(buzzPin,OUTPUT);
pinMode(potPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal=analogRead(potPin);
  Serial.println(potVal);
  if(potVal>1000){
    digitalWrite(buzzPin,HIGH);
    delay(dt);
    digitalWrite(buzzPin,LOW);
  }
}

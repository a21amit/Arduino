int pin2=2;
int pin3=3;
int pin5=5;
int pin4=4;
void setup() {
  // put your setup code here, to run once:
pinMode(pin2,OUTPUT);
pinMode(pin3,OUTPUT);
pinMode(pin4,OUTPUT);
pinMode(pin5,OUTPUT);
}

void loop() {
//0
digitalWrite(pin2,LOW);
digitalWrite(pin3,LOW);
digitalWrite(pin4,LOW);
digitalWrite(pin5,LOW);
delay(450);
//1
digitalWrite(pin2,LOW);
digitalWrite(pin3,LOW);
digitalWrite(pin4,LOW);
digitalWrite(pin5,HIGH);
delay(450);
//2
digitalWrite(pin2,LOW);
digitalWrite(pin3,LOW);
digitalWrite(pin4,HIGH);
digitalWrite(pin5,LOW);
delay(450);
//3
digitalWrite(pin2,LOW);
digitalWrite(pin3,LOW);
digitalWrite(pin4,HIGH);
digitalWrite(pin5,HIGH);
delay(450);
//4
digitalWrite(pin2,LOW);
digitalWrite(pin3,HIGH);
digitalWrite(pin4,LOW);
digitalWrite(pin5,LOW);
delay(450);
//5
digitalWrite(pin2,LOW);
digitalWrite(pin3,HIGH);
digitalWrite(pin4,LOW);
digitalWrite(pin5,HIGH);
delay(450);
//6
digitalWrite(pin2,LOW);
digitalWrite(pin3,HIGH);
digitalWrite(pin4,HIGH);
digitalWrite(pin5,LOW);
delay(450);
//7
digitalWrite(pin2,LOW);
digitalWrite(pin3,HIGH);
digitalWrite(pin4,HIGH);
digitalWrite(pin5,HIGH);
delay(450);
//8
digitalWrite(pin2,HIGH);
digitalWrite(pin3,LOW);
digitalWrite(pin4,LOW);
digitalWrite(pin5,LOW);
delay(450);
//9
digitalWrite(pin2,HIGH);
digitalWrite(pin3,LOW);
digitalWrite(pin4,LOW);
digitalWrite(pin5,HIGH);
delay(450);
}

//ciruit link : https://www.tinkercad.com/things/lnq3unecgFN
int buzzPin=13;
int myNUm;
String msg="input your number: ";
int dt=500;
void setup() {
  // put your setup code here, to run once:
pinMode(buzzPin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(msg);
while(Serial.avialable()==0){

}
myNum=Serial.parseInt();
if(myNum > 10){
  digitalWrite(buzzPin,High);
  delay(dt);
  digitalWrite(buzzPin,LOW);
  delay(dt);
}
}

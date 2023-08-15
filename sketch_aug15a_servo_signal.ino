// C++ code
//circuit design link: https://www.tinkercad.com/things/3Grq3svfuMd

#include<Servo.h>
int servoPin=12;
int myserv, light, angle;
int lightPin=A5;
int dt=250;
Servo myServo;
void setup()
{
  pinMode(lightPin, INPUT);
  pinMode(servoPin, OUTPUT);
  Serial.begin(9600);
  myServo.attach(servoPin);
}

void loop()
{
  light=analogRead(lightPin);
  Serial.println(light);
  delay(dt);
  angle=-(16./63.)*(light-780.);
  myServo.write(angle);
  delay(dt); 
}
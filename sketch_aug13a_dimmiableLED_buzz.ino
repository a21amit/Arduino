// C++ code
int button1=12;
int button2=11;
int buzz=2;
int LEDpin=8;
int buttonVal1, buttonVal2, LED;
int dt=250;

void setup()
{
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(LEDpin, OUTPUT);
  pinMode(buzz, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  LED=digitalRead(LEDpin);
  buttonVal1=digitalRead(button1);
  Serial.print("Button 1= ");
  Serial.print(buttonVal1);
  Serial.print(", ");
  buttonVal2=digitalRead(button2);
  Serial.print("Button 2= ");
  Serial.print(buttonVal2);
  Serial.println();
  delay(dt);
  if (buttonVal1==0){
    LED=LED+5;
  }
  if (buttonVal2==0){
    LED=LED-5;
  }
  Serial.println(LED);
  if (LED>255){
    LED=255;
    digitalWrite(buzz, HIGH);
    delay(dt);
    digitalWrite(buzz, LOW);
  }
  if (LED<0){
    LED=0;
    digitalWrite(buzz, HIGH);
    delay(dt);
    digitalWrite(buzz, LOW);
  }
  analogWrite(LEDpin, LED);
}
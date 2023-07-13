void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(8,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly
  digitalWrite(13,HIGH);
  delay(50);
  digitalWrite(13,LOW);
  delay(50);

  digitalWrite(10,HIGH);
  delay(150);
  digitalWrite(10,LOW);
  delay(150);

  digitalWrite(8,HIGH);
  delay(100);
  digitalWrite(8,LOW);
  delay(100);
}

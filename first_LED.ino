
void setup()
{
  pinMode(12, OUTPUT);
}

void loop()
{
  digitalWrite(12, HIGH);
  delay(500); // Wait for 1000 millisecond(s)
  digitalWrite(12, LOW);
  delay(500); // Wait for 1000 millisecond(s)
}
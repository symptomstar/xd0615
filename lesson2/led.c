int i=0;
void setup()
{
  for(i=0;i<8;i++)
  {
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  for(i=0;i<8;i++)
  {
    if(i<6)
    {
      digitalWrite(i, HIGH);
      delay(100); // Wait for 1000 millisecond(s)
      digitalWrite(i, LOW);
      delay(100); // Wait for 1000 millisecond(s)
      digitalWrite(i+2, HIGH);
      delay(100); // Wait for 1000 millisecond(s)
      digitalWrite(i+2, LOW);
      delay(100); // Wait for 1000 millisecond(s)
    }
  }
  
  delay(500);
  
  
  for(i=0;i<5;i++)
  {
      digitalWrite(i, HIGH);
      delay(1000); // Wait for 1000 millisecond(s)
      digitalWrite(i, LOW);
      delay(1000); // Wait for 1000 millisecond(s)
  }
  
  for(i=0;i<2;i++)
  {
      digitalWrite(i, HIGH);
      delay(1000); // Wait for 1000 millisecond(s)
      digitalWrite(i, LOW);
      delay(1000); // Wait for 1000 millisecond(s)
  }
  
  digitalWrite(0, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(0, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}
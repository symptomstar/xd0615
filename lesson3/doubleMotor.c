char ch=' ';
void setup()
{
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  
  Serial.begin(9600);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  Serial.println("ok!");
}

/*
预定
’f‘表示前进，都正
’b‘表示后退，都反
’r‘表示右转，左轮正转右轮反转
’l‘表示左转，左反右正
’s‘表示停止，全LOW
*/

void loop()
{
  if(Serial.available()>0)
  {
    ch=Serial.read();
    switch(ch)
    {
      case'f':
       digitalWrite(6,HIGH);
       digitalWrite(7,LOW);
       digitalWrite(8,HIGH);
       digitalWrite(9,LOW);
       digitalWrite(2, HIGH);
       digitalWrite(3, LOW);
       digitalWrite(4, LOW);
       digitalWrite(5, LOW);
       break;
      
      case'b':
       digitalWrite(7,HIGH);
       digitalWrite(6,LOW);
       digitalWrite(9,HIGH);
       digitalWrite(8,LOW);
       digitalWrite(3, HIGH);
       digitalWrite(2, LOW);
       digitalWrite(4, LOW);
       digitalWrite(5, LOW);
       break;
      
      case'r':
       digitalWrite(7,HIGH);
       digitalWrite(6,LOW);
       digitalWrite(8,HIGH);
       digitalWrite(9,LOW);
       digitalWrite(4, HIGH);
       digitalWrite(3, LOW);
       digitalWrite(2, LOW);
       digitalWrite(5, LOW);
       break;
      
      case'l':
       digitalWrite(6,HIGH);
       digitalWrite(7,LOW);
       digitalWrite(9,HIGH);
       digitalWrite(8,LOW);
       digitalWrite(5, HIGH);
       digitalWrite(3, LOW);
       digitalWrite(4, LOW);
       digitalWrite(2, LOW);
       break;
      
      case's':
       digitalWrite(6,LOW);
       digitalWrite(7,LOW);
       digitalWrite(8,LOW);
       digitalWrite(9,LOW);
       break;
      
      default:
       break;
    }
  }
}
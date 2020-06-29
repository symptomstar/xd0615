#define IN1 3
#define IN2 4
#define IN3 5
#define IN4 6

#define LT 7
#define BT 8
#define S 9

int pinInterrupt=2;
int tick = 0; //计数值
int state=0;

//中断服务程序
void myfunc()
{
  tick=-1;
  Serial.println(tick);
}
 
void setup()
{
  pinMode(IN1, OUTPUT);//输入1
  pinMode(IN2, OUTPUT);//输入2
  pinMode(IN3, OUTPUT);//输入3
  pinMode(IN4, OUTPUT);//输入4
  
  pinMode(S, OUTPUT);
  pinMode(LT, OUTPUT);
  pinMode(BT, OUTPUT);
  
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH);
  digitalWrite(S,HIGH);

  Serial.begin(9600); //初始化串口
  pinMode(13,OUTPUT);
  
  attachInterrupt( digitalPinToInterrupt(pinInterrupt), myfunc, CHANGE);
}
 
byte income=0;
void loop()
{
  Serial.println(tick++);
  if(tick==10) tick=0;
  income=tick-'0';
  digitalWrite(S,LOW);
  digitalWrite(IN1,income&0x1);
  digitalWrite(IN2,(income>>1)&0x1);
  digitalWrite(IN3,(income>>2)&0x1);
  digitalWrite(IN4,(income>>3)&0x1);
  digitalWrite(S,HIGH);
  
  state=~state;
  digitalWrite(13,state);
  delay(1000);
  
}


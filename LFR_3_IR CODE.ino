int ile,ifo,ire;
int in1=11;
int in2=12;
int in3=3;
int in4=4;
int x=1;  //black              x=0,y=1(black line follower)
int y=0;  //white              x=1,y=0(white line follower)

void setup() {
  // put your setup code here, to run once:
  pinMode(7,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);        //in1=right forward
  pinMode(in4,OUTPUT);        //in2=right backward
  Serial.begin(9600);         //in3=left backward
                              //in4=left forward
}


void forward()
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in4,HIGH);
  digitalWrite(in3,LOW);
}

void right()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in4,HIGH);
  digitalWrite(in3,LOW);
}

void left()
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(in3,LOW);
}

void reverseleft()
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(in3,HIGH);
}

void reverseright()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in4,HIGH);
  digitalWrite(in3,LOW);
}

void stoplfr()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(in3,LOW);
}

void reverse()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in4,LOW);
  digitalWrite(in3,HIGH);
}


void loop() {
  // put your main code here, to run repeatedly:
 ile=digitalRead(7);
 ifo=digitalRead(5);
 ire=digitalRead(6);

 if(ile==y && ifo==x && ire==y)  {
 forward();
 }

  if(ile==x && ifo==y && ire==y)  {
 left();
 }

  if(ile==y && ifo==y && ire==x)  {
 right();
 }

  if(ile==x && ifo==x && ire==y)  {
 reverseleft();
 }

  if(ile==y && ifo==x && ire==x)  {
 reverseright();
 }

  if(ile==x && ifo==y && ire==x)  {
 right();
 }

 /* if(ile==y && ifo==y && ire==y)  {
 delay(0);
 }*/

 }

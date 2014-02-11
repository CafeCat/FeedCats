#include <Servo.h> 

Servo hasbi;
Servo bugi;
int hasbiPos = 10;
int bugiPos = 10;

void setup()
{
  hasbi.attach(8);
  bugi.attach(9);
  hasbi.write(hasbiPos);
  bugi.write(bugiPos);
  Serial.begin(19200);
}

void loop(){
  while(Serial.available())
  {
    char inChar = (char)Serial.read();
    Serial.println(inChar);
    switch(inChar)
    {
      case 'h':
        controlHasbi('open');
        delay(100);
        break;
      case 'o':
        controlHasbi('close');
        delay(100);
        break;
    }  
  }
}
void controlHasbi(char state)
{
  int i=0;
  switch(state)
  {
    case 'open':
      for(i=hasbiPos; i<170; i+=5)
      {
        hasbi.write(i);
      }
      break;
    case 'close':
      for(i=hasbiPos; i>=10; i-=5)
      {
        hasbi.write(i);
      }
      break;
  }
  hasbiPos = i;
}

void controlBugi(char state)
{
  int i = 0;
  switch(state)
  {
    case 'open':
      for(i=bugiPos; i<170; i+=5)
      {
        bugi.write(i);
      }
      break;
    case 'close':
      for(i=bugiPos; i>=10; i-=5)
      {
        bugi.write(i);
      }
      break;
  }
  bugiPos = i;
}

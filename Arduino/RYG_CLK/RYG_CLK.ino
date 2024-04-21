#include <Arduino.h>
#include <TM1637Display.h>

#define CLK 9
#define DIO 8
#define RED 7
#define GRN 5
#define YLW 6

TM1637Display display(CLK, DIO);

void setup()
{
  pinMode(RED,OUTPUT);
  pinMode(GRN,OUTPUT);
  pinMode(YLW,OUTPUT);
}

void loop()
{
  display.setBrightness(0x0f);
  display.clear();
  for(int i = 15; i > -1 ; --i)
  {
    if(i > 11)
    {
      display.showNumberDec(i - 11, false,1,2 );
      digitalWrite(RED,HIGH);
      delay(1000);
    }
    else if(i > 8)
    {
    display.showNumberDec(i - 8, false,1,2 );
    digitalWrite(YLW,HIGH);
    delay(1000);
    }
    
    else
    {
      digitalWrite(RED,LOW);
      digitalWrite(YLW,LOW);
      display.showNumberDec(i , false,1,2 );
      digitalWrite(GRN,HIGH);
      delay(1000);
    }
  }

  digitalWrite(RED,LOW);
  digitalWrite(YLW,LOW);
  digitalWrite(GRN,LOW);
  delay(6000);

}
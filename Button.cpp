#in#include <Arduino.h>

int button = 25;
int led = 2;
int hightime = 400;
int lowtime = 100;
void setup()
{
  pinMode(button,INPUT);
  pinMode(led,OUTPUT);
}

void loop()
{
  digitalWrite(led, HIGH);
  if (digitalRead(button)==HIGH)
  {
    delay(lowtime);
    digitalWrite(led,LOW);
    delay(lowtime);

  }
  else
  {
    delay(hightime);
    digitalWrite(led,LOW);
    delay(hightime);
  }
}

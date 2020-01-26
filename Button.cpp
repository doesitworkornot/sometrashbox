#include <Arduino.h>

int button = 25;
int led = 2;
void setup()
{
  pinMode(button,INPUT);
  pinMode(led,OUTPUT);
}

void loop()
{
  if (digitalRead(button)==HIGH)
  {
    digitalWrite(led, HIGH);
  }
  else()
  {
    digitalWrite(led,LOW);
  }
}

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
  digitalWrite(led, HIGH);
  if (digitalRead(button)==HIGH)
  {
    delay(200);
    digitalWrite(led,LOW);
    delay(200);

  }
  else
  {
    delay(800);
    digitalWrite(led,LOW);
    delay(800);
  }
}

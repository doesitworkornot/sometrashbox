#include <Arduino.h>

int val = 0;  // cтартовое значение
int led = 2;  // пин лампочки

void setup()
{
  Serial.begin(9600);
  pinMode(led,OUTPUT);

}

void loop()
 {
  if (Serial.available()>0)
  {
    val = Serial.read();
    Serial.println(val);
    digitalWrite(led,HIGH);
    delay(400);
    digitalWrite(led,LOW);
    Serial.flush();  //очистка памяти после завершения цикла
  }
 }

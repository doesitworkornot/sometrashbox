#include <Arduino.h>

int led = 2;   // пин для лампочки
int waittime = 100;  //частота мерцания лампочки
int val = 0; //полученное с ввода значение

void setup()
{
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}
 void loop()
 {
   int count = 0;
   if (Serial.available()>0)
   {
     val = Serial.read();
     Serial.println(val);
     while (count <= val)
     {
       digitalWrite(led,HIGH);
       delay(waittime);
       digitalWrite(led,LOW);
       delay(waittime);
       count++;
     }
   }
 }

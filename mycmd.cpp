#include <Arduino.h>

String username = "";
String inputstr = "";
bool usernamecomplete = true;
bool stringComplete = false;
int commandMaxLen = 20;
void serialEvent();
void cmdProc(String);
int led(25);

void setup()
 {
	Serial.begin(9600);
  Serial.println("It's workin'");
  Serial.println("How do u want to be called");
  pinMode(led, OUTPUT);

}

void loop()
 {
   if (Serial.available())
    {
     serialEvent();
    }
   if (stringComplete)
    {
  		cmdProc(inputstr);
  		inputstr = "";
  		stringComplete = false;
    }
 }

void serialEvent()
 {
 	while (Serial.available())
   {
 		char inChar = (char)Serial.read();
 		Serial.print(inChar);
 		if (inChar == '\n')
     {
 			stringComplete = true;
 		 }
    else
     {
 			if (inputstr.length() < commandMaxLen)
       {
 				inputstr += inChar;
 			 }
      else
       {
         stringComplete = true;
       }
 		 }
 	}
}

void cmdProc(String cmd) {
	cmd.trim();
	if(usernamecomplete)
   {
    Serial.print("Hello ");
    Serial.println(inputstr);
    Serial.println("What do u want from me?");
    usernamecomplete=false;
    stringComplete=false;
    inputstr = "";
   }
  else if(inputstr=="Light on"){
    digitalWrite(led, HIGH);
  }
  else if(inputstr=="Light off"){
    digitalWrite(led, LOW);
  }

  else
  {
    Serial.println("Incorrect command");
  }
}

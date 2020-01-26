#include <Arduino.h>

void setup() {
	pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

	  digitalWrite(LED_BUILTIN, HIGH);

	  delay(1338);

	  digitalWrite(LED_BUILTIN, LOW);

	  delay(1337);
	}

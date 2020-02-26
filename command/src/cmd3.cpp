#include <Arduino.h>
#define SENSOR_PIN 25   // select the input pin for the potentiometer
#define LED_BUILTIN 2

String inputString = "";         // Буфер(объект типа "строка") для приема символов из посл. порта
bool stringComplete = false;     // флаг окончания ввода строки
bool terminateAllSignal = false;     // флаг завершения всех комманд
bool sens1 = false;     // флаг разрешения аналогового чтения из порта
int commandMaxLen = 20; //иаксимальная длина команды
int sensorValue = 0;  // variable to store the value coming from the sensor

const long interval = 100;           // interval at which to do smth (milliseconds)
unsigned long previousMillis = 0;        // will store last time when do smth
unsigned long currentMillis = 0;

void cmdProc(String);
void cmdProc_led(String);
void serialEvent();

void setup() {
	pinMode(LED_BUILTIN, OUTPUT);
	Serial.begin(57200);
	Serial.println("Устройство #231");
	cmdProc("");
	cmdProc_led("on");
	delay(650);
	cmdProc_led("off");
}

void loop() {
	if (Serial.available()) {
		serialEvent();
	};

	// Ниже сбособ выполнять определенные действия через заданные промежутки времени без остановки всей программы (как это делает команда delay())
	currentMillis = millis();
	if (currentMillis - previousMillis >= interval) {
		previousMillis = currentMillis;
		if (sens1){
			sensorValue = analogRead(SENSOR_PIN);
			Serial.println(sensorValue);
		}
	}

	// выполнить команду при получении /n:
	if (stringComplete) {
		cmdProc(inputString);
		inputString = "";
		stringComplete = false;
	}

	if (terminateAllSignal) {
		sens1 = false;
		terminateAllSignal = false;
	}
}

void cmdProc(String cmd) {
	cmd.trim();
	if (cmd == "") {
		//Пустая команда, а заодно завершает все процессы.
		terminateAllSignal = true;

	} else if (cmd == "test") {
		Serial.println("Вы прислали команду test");

	} else if (cmd.substring(0, 3) == "led") {
		cmdProc_led(cmd.substring(3));

	} else if (cmd == "s") {
		sens1 = true;

	} else {
		Serial.println("Неизвестная команда.");
	}
	Serial.println("\nOk");
}

void cmdProc_led(String cmd) {
	cmd.trim();
	if (cmd == "off") {
		digitalWrite(LED_BUILTIN, LOW);
		Serial.println("Светодиод на 13 порту выключен!");
	} else if (cmd == "on") {
		digitalWrite(LED_BUILTIN, HIGH);
		Serial.println("Светодиод на 13 порту включен!");
	} else {
		Serial.println("Ошибка. Правильный формат:");
		Serial.println("led on - включить светодиод");
		Serial.println("led off - выключить светодиод");
	}
}

void serialEvent() {
	while (Serial.available()) {
		char inChar = (char)Serial.read();
		Serial.print(inChar);
		if (inChar == '\n') {
			stringComplete = true;
		} else {
			if (inputString.length() < commandMaxLen) {
				inputString += inChar;
			}
		}
	}
}

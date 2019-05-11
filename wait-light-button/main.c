// -I/usr/local/include -L/usr/local/lib -lwiringPi
#include <wiringPi.h>
#include <stdio.h>
const int lightPin = 6; // gpio25

void lightOn () {
	digitalWrite(lightPin, true);
}
void lightOff () {
	digitalWrite(lightPin, false);
}
bool lightStatus () {
	return digitalRead(lightPin);
}

void handleInterrupt () {
	lightStatus() ? lightOff() : lightOn();
}

int main () {
	const int pin = 0; // gpio17
	//piHiPri(90);
	wiringPiSetup();
	pinMode(pin, INPUT);
	pullUpDnControl(pin, PUD_DOWN);
	wiringPiISR(pin, INT_EDGE_RISING, &handleInterrupt);
	printf("ver: %d", piBoardRev());
	while(true);
}

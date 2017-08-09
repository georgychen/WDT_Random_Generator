#include <WDT_Random_Generator.h>

/*
This example creates 8 random numbers(bytes) upon program startup. 
Note that it is very unlikely to have same initial numbers created between arduino resets.
Under default setting, it takes around 382ms to generate one byte.
*/

void setup()
{
	Serial.begin(115200);
	Serial.println("Program started.");
	Serial.println("Creating 8 random numbers(byte):");
	uint8_t r;
	for (uint16_t i = 0; i < 8; i++)
	{
		r = getWdtRandom();
		Serial.print(r,10);
		Serial.print(" ");
	}
	Serial.println();
	Serial.println("Program ended.");
}

void loop()
{
	
}

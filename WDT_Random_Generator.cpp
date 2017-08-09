/*
 Name:		WDT_Random_Generator.cpp
 Created:	8/8/2017 5:14:56 PM
 Author:	georgychen
 Editor:	http://www.visualmicro.com
*/

#include "WDT_Random_Generator.h"

volatile bool _wdt_hasInterrupt = false;

/*The main function to get a wdt based uint8_t (8-bit) random number*/
uint8_t getWdtRandom()
{
	uint8_t ret;
	uint8_t timerValue;
	_wdtStart();//enable wdt interrupt
	uint8_t counter = DEFAULT_ITERATION;
	while (counter)
	{
		if (_wdt_hasInterrupt == true)
		{
			_wdt_hasInterrupt = false;
			timerValue = TCNT0; //read timer 0 value
			ret = (ret << 1) | (ret >> 7); //rotate the ret bits
			ret ^= timerValue;	//XOR operation, preserves the randomness
			counter--;
		}
	}
	_wdtEnd();//disable wdt interrupt
	return ret;
}

/*Sub-function used to enable watch dog timer interrupt mode*/
void _wdtStart()
{
	cli(); //disable all interrupts
	MCUSR = 0; //reset the MCU Status Register
	WDTCSR = _BV(WDCE) | _BV(WDE); //set the Watchdog Change Enable 
	WDTCSR = _BV(WDIE); //enable interrupt mode and/or set interval
	sei(); //enable all interrupts
}

/*Sub-function used to disable watch dog timer interrupt mode*/
void _wdtEnd()
{
	WDTCSR = 0; //disable WDT
}

/*ISR to handle WDT interrupt*/
ISR(WDT_vect)
{
	_wdt_hasInterrupt = true;
}
/*
 Name:		WDT_Random_Generator.h
 Created:	8/8/2017 5:14:56 PM
 Author:	georgychen
 Editor:	http://www.visualmicro.com
*/

#ifndef _WDT_Random_Generator_h
#define _WDT_Random_Generator_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif



#define DEFAULT_ITERATION 24

uint8_t getWdtRandom();
void _wdtStart();
void _wdtEnd();

#endif //_WDT_Random_Generator_h


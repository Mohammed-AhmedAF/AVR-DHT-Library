#ifndef DHT_H_INCLUDED
#define DHT_H_INCLUDED
/*
||
||  Filename:	 		DHT.h
||  Title: 			    DHTxx Driver
||  Author: 			Efthymios Koktsidis
||	Email:				efthymios.ks@gmail.com
||  Compiler:		 	AVR-GCC
||	Description:
||	This library can drive DHT11 and DHT22 sensors.
||
*/

//------ Headers ------//
#include <util/delay.h>
#include <avr/io.h> 
#include "IO_macros.h"
#include "DHT_CONFIG.h"
//----------------------//

//----- Auxiliary data -------------------//
#define DHT11						 1
#define DHT22						 2

#define DHT_DELAY_SETUP				2000

enum DHT_STATUS
{
	FALSE_HUMIDITY = -4,
	FALSE_TEMPERATURE = -3,
	CHECKSUM = -2,
	TIMEOUT = -1,
	OK = 1
};
//-----------------------------------------//

//----- Prototypes---------------------------//
void DHT_setup(void);
int8_t DHT_readRaw(uint8_t arr[4]);
int8_t DHT_readTemp(double *temp);
int8_t DHT_readHum(double *hum);
int8_t DHT_read(double *temp, double *hum);
double DHT_convertToFahrenheit(double temp);
double DHT_convertToKelvin(double temp);
//-------------------------------------------//
#endif
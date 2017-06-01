//Headers
#include <util/delay.h>
#include "DHT.h"

int main(void)
{
	//Variables
	double temp[1], hum[1];		//Return values of sensor - Must be pointers or more preferably size-one arrays
	temp[0] = hum[0] = 0;

	//Setup
	DHT_setup();
	
	//Loop
	while (1)
	{
		//Read from sensor
		DHT_read(temp, hum);
		
		//Check status
		switch (DHT_STATUS)
		{
			case (DHT_OK):
				//Print temperature
				//print(temp[0]);
	
				//Print humidity
				//print(hum[0]);	
				break;
			case (DHT_ERROR_CHECKSUM):
				//Do something
				break;
			case (DHT_ERROR_TIMEOUT):
				//Do something else
				break;
		}
				
		//Sensor needs 1-2s to stabilize its readings
		_delay_ms(1000);
	}
	
	return 0;
}


//Headers
#include <util/delay.h>
#include "DHT.h"

int main(void)
{
	//Variables
	uint8_t status = DHT_OK;	//Return status of sensor
	double temp[1], hum[1];		//Return values of sensor - Must be pointers or more preferably size-one arrays
	temp[0] = hum[0] = 0;

	//Setup
	DHT_setup();
	
	//Loop
	while (1)
	{
		//Read from sensor
		DHT_read(temp, hum);
		//Get the status of the last performed reading
		status = DHT_status();
		
		//Check status
		if (status == DHT_OK)
		{
			//Print temperature
			//print(temp[0]);
	
			//Print humidity
			//print(hum[0]);
		}
		else if (status == DHT_ERROR_CHECKSUM)
		{
			//Do something
		}
		else if (status == DHT_ERROR_TIMEOUT)
		{
			//Do something else
		}
				
		//Sensor needs 1-2s to stabilize its readings
		_delay_ms(1000);
	}
	
	return 0;
}


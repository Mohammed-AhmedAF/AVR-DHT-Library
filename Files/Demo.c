//Headers
#include "DHT.h"

int main(void)
{
	//Variables
	enum DHT_STATUS status =OK;	//Return status of sensor
	double temp[1], hum[1];		//Return values of sensor - Must be pointers or more preferably size-one arrays
	temp[0] = hum[0] = 0;

	//Setup
	DHT_setup();
	
	//Loop
	while(1)
	{
		//Read from sensor
		status = DHT_read(temp, hum);
	
		//Check status
		if (status == OK)
		{
			//Print temperature
			//print(temp[0]);
	
			//Print humidity
			//print(hum[0]);
		}
		else if (status == CHECKSUM)
		{
			//Do something
		}
		else if (status == TIMEOUT)
		{
			//Do something else
		}
				
		//Sensor needs 1-2s to stabilize its readings
		_delay_ms(1000);
	}
	
	return 0;
}


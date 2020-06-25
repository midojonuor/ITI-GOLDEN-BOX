#include <stdio.h>
#include <stdint.h>
#include "wiringPi.h"

#include "wiringPiSPI.h"

#define NUM_OF_CHANNELS			8

uint8_t ADC_DataArr[NUM_OF_CHANNELS] = {0};
void ADC_AllChannelsRead(uint8_t *pData_arr, uint8_t data_size);

int main (void)
{
	int SPI_fd;
	SPI_fd = wiringPiSPISetupMode(0,500000,1);
	uint32_t iterator = 0;

	while(1)
	{
		ADC_AllChannelsRead(ADC_DataArr, NUM_OF_CHANNELS);

		for(iterator = 0; iterator < NUM_OF_CHANNELS; ++iterator)
		{
			
		printf("Channel Number %d = %d\n", iterator, ADC_DataArr[iterator]);
		printf(".............................................\n");
		}
		delay(1000);
	}
}




void ADC_AllChannelsRead(uint8_t *pData_arr, uint8_t data_size)
{
	uint32_t indx = 0;
	uint8_t recData = 0xAA;			// CMD to get all channels value

	wiringPiSPIDataRW(0, &recData, 1);
	
	if(recData == 0xAA)
	{
		wiringPiSPIDataRW(0, pData_arr, data_size);
	}
}

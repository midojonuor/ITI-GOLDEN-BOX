#include <stdio.h>
#include "wiringPi.h"

#include "wiringPiSPI.h"

int main (void)
{
	//char ReceivedByte[10] = {1};
	char ReceivedByte;
	int SPI_fd;
	//SPI_fd = wiringPiSPISetup(0,);
	SPI_fd=wiringPiSPISetupMode(0,500000,1);
	//printf("%d\n",SPI_fd);
	while(1)
	{
		wiringPiSPIDataRW(0,&ReceivedByte,1);
		//for (int i=0; i<10 ; i++)
		//{
	//	fflush(stdout);
			printf("%d\n",ReceivedByte);
			delay(1000);
		//}
		
	}
}

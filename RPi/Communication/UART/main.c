#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

#include "UART_Interface.h"
#include <wiringPi.h>
#include <wiringSerial.h>


int main (void)
{
	uint8_t SendData[6]="amira";
	uint8_t ReceivedData[10];
	uint16_t ReceivedLength;
	UART_Init(9600);
	while (1)
	{
		UART_SendData(SendData,6);
		UART_ReceiveData(ReceivedData,&ReceivedLength);
	}
	return 0;
}

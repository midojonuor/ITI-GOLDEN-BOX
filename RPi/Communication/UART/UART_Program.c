#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

#include <wiringPi.h>
#include <wiringSerial.h>
#include "UART_Interface.h"

static uint16_t serial_port;

uint8_t UART_Init(uint32_t BaudRate)
{
    uint8_t DeviceName[20] = "/dev/ttyS0";
    if ((serial_port = serialOpen (DeviceName, BaudRate)) < 0)	/* open serial port */
    {
        fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
        return 1;
    }
    if (wiringPiSetup () == -1)					/* initializes wiringPi setup */
    {
        fprintf (stdout, "Unable to start wiringPi: %s\n", strerror (errno)) ;
        return 1 ;
    }
}

void UART_SendData (uint8_t *Data, uint8_t DataLength)
{
    uint32_t indx;
    for (indx =0 ; indx < DataLength ; indx++)
    {
	serialPutchar(serial_port, Data[indx]);	/* transmit character serially on port */
    }
}

void UART_ReceiveData (uint8_t *ReceivedData, uint16_t *ReceivedLength)
{
    uint16_t indx = 0;
    while(serialDataAvail (serial_port)<0 || indx < 1024)
    { 
	ReceivedData[indx] = serialGetchar (serial_port);	/* receive character serially*/	
	printf ("%s\n", ReceivedData[indx]) ;
	fflush (stdout) ;
	indx++;
    }
    *ReceivedLength = indx;
}

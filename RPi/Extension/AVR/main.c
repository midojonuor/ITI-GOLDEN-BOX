/*
 * main.c
 *
 *  Created on: Jun 25, 2020
 *      Author: midoj
 */


#include "stdint.h"
#include "avr/io.h"
//#include "util/delay.h"

#include "SPI.h"
#include "ADC.h"

#define NUM_OF_CHANNELS		8

uint8_t ADC_ChannelDataArr[NUM_OF_CHANNELS] = {0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80};


void ADC_ChannelsDataSend(uint8_t *dataArr, uint8_t dataSize);

int
main(void)
{
	ADC_Init();
	SPI_SlaveInit();

	DDRC = 0xFF;
	DDRA = 0x00;

	while(1)
	{
		ADC_ChannelsDataSend(ADC_ChannelDataArr, NUM_OF_CHANNELS);
	}
	return 0;
}


void ADC_ChannelsDataSend(uint8_t *dataArr, uint8_t dataSize)
{
	uint8_t indx = 0;
	uint8_t recData = 0;
	SPI_SlaveRW(0xBB, &recData);
	if (recData == 0xAA)
	{
		for(indx=0;indx < dataSize;indx++)
		{
			ADC_Start(indx, ADC_ChannelDataArr + indx);
			SPI_SlaveRW(dataArr[indx], &recData);
		}
	}
	//PORTC = indx;
}





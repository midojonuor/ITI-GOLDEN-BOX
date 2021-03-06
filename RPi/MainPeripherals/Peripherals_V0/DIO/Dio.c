/*
 * Dio.h
 *
 *  Created on: June 2, 2020
 *      Author: Amira Zaher
 *      Microcontroller: Raspberry Pi 3 B+
 */

#include <stdio.h>
#include "stdint.h"
#include "stdlib.h"

// #include <wiringPi.h>

#include "Dio.h"

#define GPIO_17   0U
#define GPIO_27   2U
#define GPIO_22   3U
#define GPIO_05   21U
#define GPIO_06   22U
#define GPIO_13   23U
#define GPIO_19   24U
#define GPIO_26   25U

#define GPIO_18   1U
#define GPIO_23   4U
#define GPIO_24   5U
#define GPIO_25   6U
#define GPIO_12   26U
#define GPIO_16   27U
#define GPIO_20   28U
#define GPIO_21   29U


#define HIGH				1
#define LOW					0

enum Digital_Input_Channels
{
	Digital_IN_CH_01,
	Digital_IN_CH_02,
	Digital_IN_CH_03,
	Digital_IN_CH_04,
	Digital_IN_CH_05,
	Digital_IN_CH_06,
	Digital_IN_CH_07,
	Digital_IN_CH_08,
};

enum Digital_Output_Channels
{
	Digital_OUT_CH_01,
	Digital_OUT_CH_02,
	Digital_OUT_CH_03,
	Digital_OUT_CH_04,
	Digital_OUT_CH_05,
	Digital_OUT_CH_06,
	Digital_OUT_CH_07,
	Digital_OUT_CH_08,
};

#define IN_CHANNELS_NUM  		8u
#define OUT_CHANNELS_NUM  		8u

static uint8_t InputChannelTable[IN_CHANNELS_NUM] = {
	GPIO_17,
	GPIO_27,
	GPIO_22,
	GPIO_05,
	GPIO_06,
	GPIO_13,
	GPIO_19,
	GPIO_26,
};

static uint8_t OutputChannelTable[OUT_CHANNELS_NUM] = {
	GPIO_18,
	GPIO_23,
	GPIO_24,
	GPIO_25,
	GPIO_12,
	GPIO_16,
	GPIO_20,
	GPIO_21
};



/*
 * Description:
 * 		This function shall set high on a given channel
 *
 * Parameters:
 * 		- digital_channel
 *
 * Return:
 * 		Channel state 
 */

uint8_t DO_CH_SET(uint8_t digital_channel)
{
	printf("Digital output channel %d set to high\n", digital_channel);
	// digitalWrite(OutputChannelTable[digital_channel], HIGH);
	return HIGH;
}


/*
 * Description:
 * 		This function shall set low on a given channel
 *
 * Parameters:
 * 		- digital_channel
 *
 * Return:
 * 		Channel state 
 */
uint8_t DO_CH_RESET(uint8_t digital_channel)
{
	printf("Digital output channel %d set to low\n", digital_channel);
	// digitalWrite(OutputChannelTable[digital_channel], LOW);
	return LOW;
}

/*
 * Description:
 * 		This function shall read given channel
 *
 * Parameters:
 * 		- digital_channel
 * 		- pValue *
 *
 * Return:
 * 		Channel state
 */
uint8_t DI_CH_GET(uint8_t digital_channel, uint8_t *pValue)
{
	*pValue = 1;
	printf("Digital input channel %d value is %d\n", digital_channel, *pValue);
	// *pValue = digitalRead(InputChannelTable[digital_channel]);
	return *pValue;
}
















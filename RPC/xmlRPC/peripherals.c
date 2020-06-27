/*
 * 	peripherals.c
 *
 *  Created on: June 2, 2020
 *      Author: Mido
 */

#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"

#include "peripherals.h"
#include "goldenbox_config.h"

#if RPI_HOST
#include "wiringPi.h"
#include "wiringPiSPI.h"
#endif


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


#define HIGH						1
#define LOW							0


#define DIGITAL_IN_CHANNELS_NUM  				8u
#define DIGITAL_OUT_CHANNELS_NUM  				8u

#define PWM_IN_CHANNELS_NUM						2u
#define PWM_OUT_CHANNELS_NUM					2u


#define CMD_SPI_ADC_REQUEST						0xAA
#define CMD_SPI_ADC_REPLAY						0xBB

#define PWM_MAX_FREQ							19200000u

static uint8_t DigitalInputChannelTable[DIGITAL_IN_CHANNELS_NUM] = {
	GPIO_17,
	GPIO_27,
	GPIO_22,
	GPIO_05,
	GPIO_06,
	GPIO_13,
	GPIO_19,
	GPIO_26,
};

static uint8_t DigitalOutputChannelTable[DIGITAL_OUT_CHANNELS_NUM] = {
	GPIO_18,
	GPIO_23,
	GPIO_24,
	GPIO_25,
	GPIO_12,
	GPIO_16,
	GPIO_20,
	GPIO_21
};

static uint8_t PWMOutputChannelTable[PWM_OUT_CHANNELS_NUM] = {
	1,
	26
};

static uint8_t PWMInputChannelTable[PWM_IN_CHANNELS_NUM] = {
	11,
	31
};


static uint32_t SPI_Speed = 0;
static uint8_t SPI_Mode = 0;


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
#if RPI_HOST
	//printf("Digital output channel %d set to high\n", digital_channel);
	digitalWrite(DigitalOutputChannelTable[digital_channel], HIGH);
#endif
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
#if RPI_HOST
	//printf("Digital output channel %d set to low\n", digital_channel);
	digitalWrite(DigitalOutputChannelTable[digital_channel], LOW);
#endif
	return LOW;
}

/*
 * Description:
 * 		This function shall read given input channel
 *
 * Parameters:
 * 		- digital_channel
 * 		- Value 
 *
 * Return:
 * 		Channel state
 */
uint8_t DI_CH_GET(uint8_t digital_channel)
{
	uint8_t result = 0;

#if RPI_HOST
	result = digitalRead(DigitalInputChannelTable[digital_channel]);
#endif

	return result;
}


/*
 * Description:
 * 		This function shall read given output channel
 *
 * Parameters:
 * 		- digital_channel
 * 		- Value 
 *
 * Return:
 * 		Channel state
 */
uint8_t DO_CH_GET(uint8_t digital_channel)
{
	uint8_t result = 0;
#if RPI_HOST
	result = digitalRead(DigitalOutputChannelTable[digital_channel]);
#endif
	return result;
}


/*
 * Description:
 * 		This function shall initialize all digital I/O channels
 *
 * Parameters:
 * 		- digital_channel
 * 		- pValue *
 *
 * Return:
 * 		- none
 */
void DIO_Init(void)
{
#if RPI_HOST
	int indx;
	
	/* using WiringPi numbering */ 
	wiringPiSetup();
	
	for(indx = 0; indx < DIGITAL_IN_CHANNELS_NUM ; ++indx)
	{
		pinMode(DigitalInputChannelTable[indx],INPUT);
		pullUpDnControl (DigitalInputChannelTable[indx],PUD_DOWN);
		pinMode(DigitalOutputChannelTable[indx],OUTPUT);
	}
#endif
}


/*
 * Description:
 * 		This function shall initialize SPI connection to extention
 *
 * Parameters:
 * 		- speed	: specify the SPI connection speed
 * 		- mode	: can be one of the following
 * 					- SPI_MODE_0	(Sample First	, clock idle stat low)
 * 					- SPI_MODE_1	(Setup First	, clock idle stat low)
 * 					- SPI_MODE_2	(Sample First	, clock idle stat high)
 * 					- SPI_MODE_3	(Setup First	, clock idle stat high)
 *
 * Return:
 * 		- none
 */
void SPI_Init(uint32_t speed, uint8_t mode)
{
	int SPI_fd;
#if RPI_HOST
	SPI_Mode = mode;
	SPI_Speed = speed;
	SPI_fd = wiringPiSPISetupMode(0, speed, mode);
#endif
}


/*
 * Description:
 * 		- This function shall read all ADC channel from extention
 * 		- Prerequest for this function is SPI_Init
 *
 * Parameters:
 * 		- pData_arr: pointer to uint8_t to return values
 * 		- data_size: number of channels that should be read
 *
 * Return:
 * 		- none
 */
void ADC_AllChannelsRead(uint8_t *pData_arr, uint8_t data_size)
{
	uint32_t indx = 0;
	uint8_t recData = CMD_SPI_ADC_REQUEST;			// CMD to get all channels value
	int SPI_fd;


#if RPI_HOST
	wiringPiSPIDataRW(0, &recData, 1);
	delay(1);

	if(recData == CMD_SPI_ADC_REPLAY)
	{
		wiringPiSPIDataRW(0, pData_arr, 8);
		// for (indx = 0 ; indx < data_size ; indx++)
		// {
		// 	wiringPiSPIDataRW(0, (pData_arr + indx), 1);
		// }
	}
#endif
}	


/*
 * Description:
 * 		- This function shall PWM initialize and select frequency
 *
 * Parameters:
 * 		- pwm_freq: desired pwm
 *
 * Return:
 * 		- none
 */
void PWM_Init(uint32_t pwm_freq)
{
	uint32_t pwm_div = 0;
	uint8_t indx = 0;

#if RPI_HOST
	/* Initialize pwm channels */
	for(indx = 0; indx < PWM_OUT_CHANNELS_NUM; ++indx)
	{
		pinMode(PWMOutputChannelTable[indx], PWM_OUTPUT);
	}

	pwmSetMode(PWM_MODE_MS);

	/*
		PWM frequency can be obtained by the following equation:
			Freq = 19.2MHz/(PWM_DIV * PWM_RANGE)
	*/
	pwm_div = (PWM_RANGE * pwm_freq);
	if(pwm_div > 0)
	{
		pwm_div = (PWM_MAX_FREQ/pwm_div);
	}
	else
	{
		pwm_div = 1;
	}
	
    pwmSetRange(PWM_RANGE);
    pwmSetClock(pwm_div);

#endif
}



/*
 * Description:
 * 		- This function shall write passed duty cycle to selected channel
 *
 * Parameters:
 * 		- pwm_channel	: Channel number
 * 		- duty			: value of duty cycle (0 to 100)
 *
 * Return:
 * 		- none
 */
void PWM_Write(uint8_t pwm_channel, uint8_t duty)
{
	uint16_t range = 0;
#if RPI_HOST
	range = (duty/100) * PWM_RANGE;
	pwmWrite(pwm_channel, range);
#endif
}





















/*
 * GPIO_Interface.h
 *
 *  Created on: May 30, 2020
 *      Author: Salma Amr
 *      Microcontroller: Raspberry Pi 3 B+
 */

#include <stdio.h>
#include <stdint.h>
#include <wiringPi.h>

/*
 * Description:
 * 		This function shall set high or low on a given pin
 *
 * Parameters:
 * 		- Channel Number (DI_CH_x)
 * 		- Bit Value (Bit_SET or Bit_RESET)
 *
 * Return:
 * 		Error state, it will be OK if function executed correctly otherwise the return will be NOK
 */ 

Error_t DIO_SetPinValue(DIO_Channels_t DIO_Channel ,BitStatus_t pinStatus)
{
	Error_t Func_Status = PASSED;
	wiringPiSetupGpio();
	
	pinMode(Channel_LookUp[DIO_Channel],OUTPUT);
	if(pinStatus == BIT_SET)
	{
		digitalWrite(Channel_LookUp[DIO_Channel],HIGH);
	}
	else if(pinStatus == BIT_RESET)
	{
		digitalWrite(Channel_LookUp[DIO_Channel],LOW);
	}		
	else
	{
		Func_Status = FAILED;
	}
	return Func_Status;

}

/*
 * Description:
 * 		This function shall read given pin
 *
 * Parameters:
 * 		- Channel number (DO_CH_x)
 * 		- Bit status (Bit_SET or Bit_RESET)
 *
 * Return:
 * 		Error state, it will be OK if function executed correctly otherwise the return will be NOK
 */

Error_t GPIO_GetPinValue(DIO_Channels_t DIO_Channel, BitStatus_t *pinStatus)
{
	Error_t Func_Status = PASSED;
	wiringPiSetupGpio();
	
	if (digitalRead(Channel_LookUp[DIO_Channel]) == HIGH) 
	{
		pinStatus = BIT_SET;
	}
	else if (digitalRead(Channel_LookUp[DIO_Channel]) == LOW) 
	{
		pinStatus = BIT_RESET;
	}
	else
	{
		Func_Status = FAILED;
	}
		
	return Func_Status;
}
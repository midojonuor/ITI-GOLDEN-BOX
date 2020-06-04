/*
 * GPIO_Interface.h
 *
 *  Created on: June 2, 2020
 *      Author: Amira Zaher
 *      Microcontroller: Raspberry Pi 3 B+
 */

/* #include <stdio.h> */
#include <rpc/rpc.h>
#include <time.h>
#include <wiringPi.h>
#include "rpcGen.h"
#include "DIO_Interface.h"


uint8_t Channel_LookUp[CHANNELS_NUM]= {GPIO_17,GPIO_27,
GPIO_22,GPIO_05,GPIO_06,GPIO_13,GPIO_19,GPIO_26,
GPIO_18,GPIO_23,GPIO_24,GPIO_25,GPIO_12,GPIO_16,
GPIO_20,GPIO_21};

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

Error_t * dio_setpinvalue_1_svc(param * DIO, struct svc_req * request)
{
	static Error_t Func_Status = PASSED;
	wiringPiSetupGpio();
	
	pinMode(Channel_LookUp[DIO->DIO_Channel],OUTPUT);
	if(DIO->pinStatus == BIT_SET)
	{
		digitalWrite(Channel_LookUp[DIO->DIO_Channel],HIGH);
	}
	else if(DIO->pinStatus == BIT_RESET)
	{
		digitalWrite(Channel_LookUp[DIO->DIO_Channel],LOW);
	}		
	else
	{
		Func_Status = FAILED;
	}
	return &Func_Status;

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

Error_t DIO_GetPinValue(DIO_Channels_t DIO_Channel, BitStatus_t *pinStatus)
{
	Error_t Func_Status = PASSED;
	wiringPiSetupGpio();
	
	if (digitalRead(Channel_LookUp[DIO_Channel]) == HIGH) 
	{
		*pinStatus = BIT_SET;
	}
	else if (digitalRead(Channel_LookUp[DIO_Channel]) == LOW) 
	{
		*pinStatus = BIT_RESET;
	}
	else
	{
		Func_Status = FAILED;
	}
		
	return Func_Status;
}

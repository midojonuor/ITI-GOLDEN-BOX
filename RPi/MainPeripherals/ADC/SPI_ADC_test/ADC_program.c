/*
 * ADC_program.c
 *
 *  Created on: Feb 26, 2020
 *      Author: Amira Zaher
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_register.h"
#include "ADC_interface.h"


void ADC_voidInit(void)
{
	/*8-bits mode , a Vcc ref voltage, Polling(not interrupt)*/
	/*A vcc ref voltage */

	CLR_BIT(ADMUX,7);
	CLR_BIT(ADMUX,6);

	/*Active left adjuster mode*/

	SET_BIT(ADMUX,5);

	/*ADC enable*/
	SET_BIT(ADCSRA,7);

	/*Prescaler divion by 128*/
	SET_BIT(ADCSRA,2);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,0);
}

u8 ADC_u8GetChannelReading(u8 Copy_u8Channel)
{
	/*Set channel in ADMUX*/
	ADMUX &= 0b11100000;
	ADMUX |= Copy_u8Channel;

	/*Start conversion*/
	SET_BIT(ADCSRA,6);

	/*Polling on the conversion complete flag*/
	while ((GET_BIT(ADCSRA,4))==0);
	/*Clear the flag*/
	SET_BIT(ADCSRA,4);
	/*Get the result*/
	return ADCH;
}

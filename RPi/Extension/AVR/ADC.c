/*
 * ADC.c
 *
 *  Created on: Jun 25, 2020
 *      Author: midoj
 */


#include "stdint.h"
#include "avr/io.h"

#include "ADC.h"



void ADC_Init(void)
{
	/* Reference Voltage and Left adjust disable (Read ADCL only) */
	ADMUX &= ~(1 << REFS1);
	ADMUX |= (1 << REFS0);
	ADMUX |= (1 << ADLAR);   // Enable Adjust Left

	/* Prescaler divisor by 32 */
	ADCSRA = 0 ;
	ADCSRA |= (1 << ADPS2) |(1<<ADPS0) | (1<<ADPS1);

	/* Enable Interrupt */
//	ADCSRA |= (1 << ADIE);

	/* Enable ADC */
	ADCSRA |= (1 << ADEN);

}

void ADC_Start(uint8_t channel_num, uint8_t *rData)
{
	/* select channel number to read */
	channel_num &= 0x07;
	ADMUX &= 0xF8;
	ADMUX |= channel_num;


	/* Start conversion */
	ADCSRA |= (1 << ADSC);

	/* wait to conversion finish */
	while(!(ADCSRA & (1 << ADIF)));

	/* Clear ADIF flag when conversion finished */
	ADCSRA |= (1 << ADIF);

	*rData = ADCL;
	*rData = ADCH;
}
























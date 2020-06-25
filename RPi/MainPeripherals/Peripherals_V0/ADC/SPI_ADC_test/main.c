#include "STD_TYPES.h"
#include "BIT_MATH.h"
//#include <util/delay.h>

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "SPI_interface.h"
//#include "ADC_interface.h"
#include <avr/io.h>

//#define SREG  *((volatile u8*)0x5F)

unsigned int ADC_read(unsigned char chnl);

int main(void)
{
	u8 Result;
	u8 AnalogVal;
	u8 Ch;
	PORTInitialize();

	/* Set Pull up resistor for SS */
	SetPinValue('B',4,1);

	/* Enable Global Int */
	SET_BIT(SREG,7);
	SPI_voidInit();

	//ADC_voidInit();

	PORTC = 0xFF;         //make PORTC as output to connect 8 leds
	ADMUX=(1<<REFS0);      // Selecting internal reference voltage
	ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);     // Enable ADC also set Prescaler as 128

	while (1)
	{
		Ch=SPI_u8SendDataByteSynch(Result);
		Result = ADC_read(Ch);   //save adc read value in integer
		//AnalogVal = (Result * 5000UL)/1024;
		
	}
}



unsigned int ADC_read(unsigned char chnl)
{
	chnl= chnl & 0b00000111; // select adc channel between 0 to 7
	ADMUX = 0x40;        //channel A0 selected
	ADCSRA|=(1<<ADSC);   // start conversion
	while(!(ADCSRA & (1<<ADIF)));   // wait for ADIF conversion complete return
	ADCSRA|=(1<<ADIF);   // clear ADIF when conversion complete by writing 1
	return (ADC); //return calculated ADC value
}


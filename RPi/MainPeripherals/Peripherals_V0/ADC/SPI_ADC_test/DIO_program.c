#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_register.h"
#include "DIO_config.h"

void SetPinValue(u8 Port,u8 Pin,u8 Val)
{
	switch (Port)
	{
	case 'A':
		if (Val == 0)
		{
			CLR_BIT(PORTA,Pin);
		}

		else
		{
			SET_BIT(PORTA,Pin);
		}
		break;
	case 'B':
		if (Val == 0)
		{
			CLR_BIT(PORTB,Pin);
		}

		else
		{
			SET_BIT(PORTB,Pin);
		}
		break;
	case 'C':
		if (Val == 0)
		{
			CLR_BIT(PORTC,Pin);
		}

		else
		{
			SET_BIT(PORTC,Pin);
		}
		break;
	case 'D':
		if (Val == 0)
		{
			CLR_BIT(PORTD,Pin);
		}

		else
		{
			SET_BIT(PORTD,Pin);
		}
		break;
	}

}

u8 GetPinValue(u8 Port,u8 Pin)
{
	u8 Result;
	switch (Port)
	{
	case 'A': Result=GET_BIT(PINA,Pin);	break;
	case 'B': Result=GET_BIT(PINB,Pin);	break;
	case 'C': Result=GET_BIT(PINC,Pin);	break;
	case 'D': Result=GET_BIT(PIND,Pin);	break;
	}
	return Result;

}

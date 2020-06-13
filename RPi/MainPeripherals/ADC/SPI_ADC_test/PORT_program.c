#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PORT_interface.h"
#include "PORT_REG.h"
/*note that the private file uses the configuration file , so include configuration first*/

#include "PORT_confg.h"
#include "PORT_private.h"

void PORTInitialize(void)
{
	DDRA=PORTA_DIR;
	DDRB=PORTB_DIR;
	DDRC=PORTC_DIR;
	DDRD=PORTD_DIR;
	
}

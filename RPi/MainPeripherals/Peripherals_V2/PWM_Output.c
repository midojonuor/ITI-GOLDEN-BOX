#include "stdio.h"
#include "wiringPi.h"
#include "stdlib.h"


#define PWM_RANGE			200
#define PWM_DIV				48			// PWM_Freq = (19.2MHz / (PWM_DIV * PWM_RANGE))

int main(void)
{
	int iter;
	printf("Pulse Width Modulation Output Program\n");

	/* Set wiringPi numbering for pins */
	if(wiringPiSetup() == -1)
	{
		exit(1);
	}

	/* Set pin 1 to PWM */
	pinMode(1, PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);

	// Desired PWM frequency is 400Hz
    pwmSetRange(PWM_RANGE);
    pwmSetClock(PWM_DIV);
//	pwmWrite(1,95);
	while(1)
	{
		
		/* Loop to increment duty cycle from 0 to PWM_RANGE */
		for(iter = 0; iter < PWM_RANGE -10; iter+=10)
		{
			pwmWrite(1, iter);
			delay(1000);
		}
		

		/* Loop to decrement duty cycle from PWM_RANGE to 0 */
/*		for(iter = PWM_RANGE-2; iter >= 0; --iter)
		{
			pwmWrite(1, iter);
			delay(10);
		}
		delay(1000);
*/	}

	return 0;
}

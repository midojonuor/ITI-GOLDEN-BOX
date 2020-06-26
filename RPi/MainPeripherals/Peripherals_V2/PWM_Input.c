#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "unistd.h"
#include <stdint.h>

#include <wiringPi.h>

/* Pin Number 11 according to wiringPi numbering */
#define PWM_IN 		0



static volatile unsigned long startTime 		= 0;
static volatile unsigned long stopTime  		= 0;
static volatile unsigned long prevStart 		= 0;
static volatile unsigned long prevStop  		= 0;

uint8_t Waiting_Flag = 0;
struct timeval tv;

void changeState(void);
void pulseRising(void);
void pulseFalling(void);


int
main(void)
{
	double Frequency;
    double DutyCycle;

    double T_Cycle = 0;
    double T_On = 0;


    /* Use wiringPi pin numbering */
    if (wiringPiSetup () == -1)
    {
    	exit (1) ;
    }


	/* Set PWM_IN to Input */
	pinMode (PWM_IN, INPUT) ;

    /* 
    	Listen to interrupt events on PWM_IN pin on any change 
    	and set changeState as a callback for IRQ 
    */
    wiringPiISR(PWM_IN, INT_EDGE_BOTH, &changeState);


	while(1)
	{
        if(startTime < stopTime)
        {
            Waiting_Flag = 0;

            T_Cycle   = startTime - prevStart;
            T_On      = stopTime - startTime;
            Frequency = 1000000.0 / T_Cycle;
            DutyCycle = (((double)T_On ) / ((double) T_Cycle)) * 100.0;
        }
        
        Waiting_Flag = 1;
        
        printf("Frequency = %lf  Hz , DutyCycle = %lf  %\n", Frequency, DutyCycle);

        delay(300);
	}
	return 0;
}


void changeState()
{
    if(Waiting_Flag == 1)
    {
        if (digitalRead(PWM_IN) != 0)
        {
            gettimeofday(&tv, NULL);
            prevStart=startTime;
            startTime = (1000000 * tv.tv_sec ) + tv.tv_usec;
        }
        else if (digitalRead(PWM_IN) == 0)
        {
            gettimeofday(&tv, NULL);
            prevStop = startTime;
            stopTime = (1000000 * tv.tv_sec ) + tv.tv_usec;
        }
    }
}

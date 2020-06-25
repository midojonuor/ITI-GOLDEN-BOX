#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "unistd.h"
#include <stdint.h>
#include <wiringPi.h>

#define Input_pin 0

#define PWM_pin  23   /* GPIO 1 as per WiringPi, GPIO18 as per BCM */

static volatile unsigned long startTime = 0;
static volatile unsigned long stopTime  = 0;
static volatile unsigned long PrevStart = 0;
static volatile unsigned long PrevStop  = 0;
static uint8_t Waiting_Flag=0;
void changeState();
void pulseRising();
void pulseFalling();

int main()
{

    float Frequency;
    float DutyCycle;

    float T_Cycle;
     float T_On;
    
    wiringPiSetup();

    wiringPiISR(Input_pin,INT_EDGE_BOTH,&changeState);
    
    //if (wiringPiSetup () == -1)
    //exit (1) ;
    
    pinMode (PWM_pin, PWM_OUTPUT) ; /* set PWM pin as output */
    
    pwmSetMode(PWM_MODE_MS);
    
    pinMode (Input_pin,INPUT) ;

     // Desired PWM frequency is 500Hz
    pwmSetRange(256);
    pwmSetClock(150);
    
    while (1)   
    {
        // Duty cycle of 50% ( 128/256) 
       if(Waiting_Flag==1)
       {
        pwmWrite(PWM_pin,128);
    
        T_Cycle   = startTime - PrevStart;
        T_On      = stopTime - PrevStart;
        Frequency = 1000000 / T_Cycle;
        DutyCycle = (((float)T_On )/((float) T_Cycle))*100;
        }
        printf("Frequency = %lf  Hz , DutyCycle = %lf  %\n",Frequency,DutyCycle);
        delay(100);
        //printf("------------\n");
        //printf("Start= %lu, Stop=  %lu \n",startTime, stopTime);
    }
    return 0;

}

void changeState()
{
    if (digitalRead(Input_pin) != 0)
    {
        pulseRising();
    }
    else
    {
        pulseFalling();
    }
}

void pulseRising()
{
    Waiting_Flag=1;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    PrevStart=startTime;
    startTime = (1000000 * tv.tv_sec )+ tv.tv_usec;
    
}

void pulseFalling()
{
     Waiting_Flag=0;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    PrevStop=startTime;
    stopTime = (1000000 * tv.tv_sec )+ tv.tv_usec;
}

#include <wiringPi.h>

#include <stdio.h>
#include <stdlib.h>

const int PWM_pin = 1;   /* GPIO 1 as per WiringPi, GPIO18 as per BCM */

int main (void)
{
  int intensity ;            

  if (wiringPiSetup () == -1)
    exit (1) ;

  pinMode (PWM_pin, PWM_OUTPUT) ; /* set PWM pin as output */
  pwmSetMode(PWM_MODE_MS);
  // Desired PWM frequency is 500kHz
  pwmSetRange(1024);
  pwmSetClock(4);
  // Desired PWM Frequency is 10Mhz
  //pwmSetRange(1024);
  //pwmSetClock(1875);
  while (1)
  {
	// Duty cycle of 50% ( 512/1024) 
	pwmWrite(PWM_pin,512);
   // delay(1);
  }
}

/*
 * main.c
 *
 *  Created on: Jun 5, 2020
 *      Author: midoj
 */

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "FDX_Server.h"




int
main()
{
	FdxServer_Init("192.168.1.55", 22);

#if DEBUG_START
	printf("########################################################\n");
	printf("start of new connection\n");
	printf("########################################################\n");
#endif
	FdxServer_StartForever();
	return 0;
}





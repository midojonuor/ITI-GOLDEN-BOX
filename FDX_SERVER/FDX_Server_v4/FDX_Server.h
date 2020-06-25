/*
 * FdxUdpServer.h
 *
 *  Created on: Jun 5, 2020
 *      Author: midoj
 */

#ifndef FDX_SERVER_H_
#define FDX_SERVER_H_



#define RPI_HOST				1
#define DEBUG_START				1

#define SPI_SPEED				500000UL
#define SPI_MODE				1

extern void FdxServer_Init(char * ip, uint16_t port);

extern void FdxServer_StartForever(void);



#endif /* FDX_SERVER_H_ */

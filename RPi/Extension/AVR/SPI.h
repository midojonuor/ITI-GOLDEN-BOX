/*
 * SPI.h
 *
 *  Created on: Jun 25, 2020
 *      Author: midoj
 */

#ifndef SPI_H_
#define SPI_H_


#define DDR_SPI			DDRB
#define PORT_SPI		PORTB

#define SS				4
#define MOSI			5
#define MISO			6
#define SCK				7


void SPI_MasterInit(void);
void SPI_MasterRW(uint8_t CS, uint8_t tData, uint8_t *rData);

void SPI_SlaveInit(void);
void SPI_SlaveRW(uint8_t tData, uint8_t *rData);

#endif /* SPI_H_ */

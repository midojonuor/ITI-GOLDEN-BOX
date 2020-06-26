/*
 * SPI.c
 *
 *  Created on: Jun 25, 2020
 *      Author: midoj
 */


#include "stdint.h"
#include "avr/io.h"

#include "SPI.h"


void SPI_MasterInit(void)
{
	uint8_t temp = 0;

	/* Set MOSI, SCK and SS output, all others input */
	DDR_SPI |= (1 << MOSI) | (1 << SCK) | (1 << SS);

	/* Enable SPI, Master, set clock rate FCK/16 */
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0) | (1 << CPHA);

	temp = SPSR;
}


void SPI_MasterRW(uint8_t CS, uint8_t tData, uint8_t *rData)
{
	/* Activate slave by writing low to SS pin*/
	PORT_SPI &= ~(1 << CS);

	/* Start transmission */
	SPDR = tData;

	/* Wait for transmission complete */
	while(!(SPSR & (1 << SPIF)));

	/* Read received data */
	*rData = SPDR;

	/* Deactivate slave by writing high to SS pin*/
	PORT_SPI |= (1 << CS);
}

void SPI_SlaveInit(void)
{
	/* Set MISO output, all others input */
	DDR_SPI |= (1 << MISO);

	/* Enable SPI */
	SPCR = (1<<SPE) | (1 << CPHA);
}


void SPI_SlaveRW(uint8_t tData, uint8_t *rData)
{
	/* Set data to be transmitted */
	SPDR = tData;

	/* Wait for reception complete */
	while(!(SPSR & (1<<SPIF)));

	/* Return data register */
	*rData = SPDR;
}





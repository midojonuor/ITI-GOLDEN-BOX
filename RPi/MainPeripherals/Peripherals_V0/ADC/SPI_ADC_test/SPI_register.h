/*
 * SPI_register.h
 *
 *  Created on: Apr 22, 2020
 *      Author: KAPOO
 */

#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_

#define SPCR      *((volatile u8 *)0x2D)
#define SPSR      *((volatile u8 *)0x2E)
#define SPDR      *((volatile u8 *)0x2F)


#endif /* SPI_REGISTER_H_ */

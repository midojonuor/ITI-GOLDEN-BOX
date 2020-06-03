/*
 * Std_Types.h
 *
 *  Created on: May 18, 2020
 *      Author: Family
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_


typedef signed char 			int8_t;
typedef signed short 			int16_t;
typedef signed long 			int32_t;
typedef signed long long int 	int64_t;

typedef unsigned char 			uint8_t;
typedef unsigned short 			uint16_t;
typedef unsigned long 			uint32_t;
typedef unsigned long long int 	uint64_t;

typedef float float32;
typedef double float64;

typedef uint8_t Std_ReturnType;

#define E_OK			0x00u
#define E_NOT_OK		0x01u

#define STD_HIGH		0x01u
#define STD_LOW			0x00u

#define STD_ACTIVE		0x01u
#define STD_IDLE		0x00u

#define STD_ON			0x01u
#define STD_OFF			0x00u

#define NULL			((void *)0)

#endif /* STD_TYPES_H_ */





















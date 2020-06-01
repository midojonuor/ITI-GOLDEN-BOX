/*
 * GPIO_Interface.h
 *
 *  Created on: May 30, 2020
 *      Author: Amira Zaher
 *      Microcontroller: Raspberry Pi 3 B+
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#define GPIO_17   0U
#define GPIO_27   2U
#define GPIO_22   3U
#define GPIO_05   21U
#define GPIO_06   22U
#define GPIO_13   23U
#define GPIO_19   24U
#define GPIO_26   25U

#define GPIO_18   1U
#define GPIO_23   4U
#define GPIO_24   5U
#define GPIO_25   6U
#define GPIO_12   26U
#define GPIO_16   27U
#define GPIO_20   28U
#define GPIO_21   29U

#define CHANNELS_NUM  16U

typedef enum
{
	DI_CH_00,
	DI_CH_01,
	DI_CH_02,
	DI_CH_03,
	DI_CH_04,
	DI_CH_05,
	DI_CH_06,
	DI_CH_07,
	D0_CH_08,
	D0_CH_09,
	D0_CH_10,
	D0_CH_11,
	D0_CH_12,
	D0_CH_13,
	D0_CH_14,
	D0_CH_15
}DIO_Channels_t;

uint8_t Channel_LookUp[CHANNELS_NUM]= {GPIO_17,GPIO_27,
GPIO_22,GPIO_05,GPIO_06,GPIO_13,GPIO_19,GPIO_26,
GPIO_18,GPIO_23,GPIO_24,GPIO_25,GPIO_12,GPIO_16,
GPIO_20,GPIO_21};
 
typedef uint8_t BitStatus_t;
#define BIT_RESET 			0U
#define BIT_SET				1U 
 
typedef uint8_t Error_t;
#define PASSED		(0U)
#define FAILED		(1U)

/*
 * Description:
 * 		This function shall set high or low on a given pin
 *
 * Parameters:
 * 		- Channel Number (DI_CH_x)
 * 		- Bit Value (Bit_SET or Bit_RESET)
 *
 * Return:
 * 		Error state, it will be OK if function executed correctly otherwise the return will be NOK
 */ 
extern Error_t DIO_SetPinValue(DIO_Channels_t DIO_Channel ,BitStatus_t pinStatus);

/*
 * Description:
 * 		This function shall read given pin
 *
 * Parameters:
 * 		- Channel number (DO_CH_x)
 * 		- Bit status (Bit_SET or Bit_RESET)
 *
 * Return:
 * 		Error state, it will be OK if function executed correctly otherwise the return will be NOK
 */
extern Error_t GPIO_GetPinValue(DIO_Channels_t DIO_Channel, BitStatus_t *pinStatus);
   
#endif
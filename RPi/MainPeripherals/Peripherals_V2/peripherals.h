#ifndef _PERIPHERALS_H_
#define _PERIPHERALS_H_


#define SPI_MODE_0					0
#define SPI_MODE_1					1
#define SPI_MODE_2					2
#define SPI_MODE_3					3

#define PWM_RANGE					192


enum Digital_Input_Channels
{
	Digital_IN_CH_01,
	Digital_IN_CH_02,
	Digital_IN_CH_03,
	Digital_IN_CH_04,
	Digital_IN_CH_05,
	Digital_IN_CH_06,
	Digital_IN_CH_07,
	Digital_IN_CH_08,
};

enum Digital_Output_Channels
{
	Digital_OUT_CH_01,
	Digital_OUT_CH_02,
	Digital_OUT_CH_03,
	Digital_OUT_CH_04,
	Digital_OUT_CH_05,
	Digital_OUT_CH_06,
	Digital_OUT_CH_07,
	Digital_OUT_CH_08,
};

enum PWM_Output_Channels
{
	PWM_OUT_CH_01,
	PWM_OUT_CH_02,
};

enum PWM_Input_Channels
{
	PWM_IN_CH_01,
	PWM_IN_CH_02,
};

extern uint8_t DO_CH_SET(uint8_t digital_channel);

extern uint8_t DO_CH_RESET(uint8_t digital_channel);

extern uint8_t DI_CH_GET(uint8_t digital_channel);

extern uint8_t DO_CH_GET(uint8_t digital_channel);

extern void DIO_Init(void);

extern void SPI_Init(uint32_t speed, uint8_t mode);

extern void ADC_AllChannelsRead(uint8_t *pData_arr, uint8_t data_size);

extern void PWM_Init(uint32_t pwm_div, uint32_t pwm_range);

extern void PWM_Write(uint8_t pwm_channel, uint8_t duty);

#endif /* !_PERIPHERALS_H_ */

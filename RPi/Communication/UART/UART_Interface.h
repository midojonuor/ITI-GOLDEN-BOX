#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

extern uint8_t UART_Init(uint32_t BaudRate);

extern void UART_SendData (uint8_t *Data, uint8_t DataLength);

extern void UART_ReceiveData (uint8_t *ReceivedData, uint16_t *ReceivedLength);

#endif

/*
 * API_uart.h
 *
 *  Created on: Apr 2, 2022
 *      Author: renato
 */

#ifndef API_INC_API_UART_H_
#define API_INC_API_UART_H_

#include "main.h"

/*********************User defines*****************/
#define BAUDRATE 9600	//UART peripheral's baudrate
#define UARTx USART3	//UART peripheral to use

/*************Public functions*********************/
bool_t uartinit();
void uartsendString(uint8_t * pstring);
void uartReceiveStringSize(uint8_t * pstring, uint16_t size);

#endif /* API_INC_API_UART_H_ */

/*
 * Consola_API.h
 *
 *  Created on: Apr 22, 2022
 *      Author: renato
 */

#ifndef USERAPI_INC_CONSOLA_API_H_
#define USERAPI_INC_CONSOLA_API_H_

#include "main.h"
#include "API_uart.h"
#include "RTC_API.h"

void Consola_updateScreen_RTC();
void Consola_print_WelcomeMessage();
void Consola_read_CMD(); //parse cmd comming from serial console
void Consola_print_options();

#endif /* USERAPI_INC_CONSOLA_API_H_ */

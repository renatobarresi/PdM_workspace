/*
 * API_debounce.h
 *
 *  Created on: Mar 27, 2022
 *      Author: renato
 */

#ifndef API_INC_API_DEBOUNCE_H_
#define API_INC_API_DEBOUNCE_H_

#include "main.h"
#include "API_delay.h"

#define DEBOUNCE_TIME 40

void debounceFSM_init();        // debe cargar el estado inicial
void debounceFSM_update();    // debe leer las entradas, resolver la lógica de transición de estados y actualizar las salidas

void buttonPressed();            // debe togglear el LED1
void buttonReleased();        // debe togglear el LED3

bool_t readKey();

uint16_t debounceTime;  //tiempo de anti-rebote debe ser de 40 ms, it is defined in debounceFSM_init

#endif /* API_INC_API_DEBOUNCE_H_ */

/*
 * API_debounce.c
 *
 *  Created on: Mar 27, 2022
 *      Author: renato
 */

#include "API_debounce.h"

/*************Private variables*************/

typedef enum{
	BUTTON_UP,
	BUTTON_FALLING,
	BUTTON_DOWN,
	BUTTON_RAISING,
} debounceState_t;

static debounceState_t estadoActual; //current machine state

static bool_t instaKeyStatus; //used to store the value of the button

/*************Public functions*************/
/**
 * @brief This function is executed to initialize the LED and state
 * @params none
 * @retval none
 */
void debounceFSM_init(){
	BSP_PB_Init(BUTTON_USER, BUTTON_MODE_GPIO);
	estadoActual = BUTTON_UP;
	debounceTime = DEBOUNCE_TIME;
}

/**
 * @brief executes the FSM
 * @params none
 * @retval none
 */
void debounceFSM_update(){

	uint8_t buttonState = BSP_PB_GetState(BUTTON_USER);

	switch(buttonState){
		case GPIO_PIN_SET:

			BSP_LED_Off(LED3);

			/*Update machine state*/
			estadoActual = BUTTON_FALLING;

			/*We wait 40ms to be sure the button is not debouncing anymore*/
			if(delayRead(&debounceDelay)){
				estadoActual = BUTTON_DOWN;
			}

			/*If the state is button_down, then we execute button pressed until button gets released*/
			while(BSP_PB_GetState(BUTTON_USER) && estadoActual == BUTTON_DOWN){
				buttonPressed();
			}

			BSP_LED_Off(LED1);

			break;

		case GPIO_PIN_RESET:
			estadoActual = BUTTON_UP;
			buttonReleased();
			break;
	}
}

/**
 * @brief toggles LED1 when the delay time has passed
 * @params none
 * @retval none
 */
void buttonPressed(){
	if(delayRead(&LEDDelay)){
		BSP_LED_Toggle(LED1);
	}
}

/**
 * @brief toggles LED3 when the delay time has passed
 * @params none
 * @retval none
 */
void buttonReleased(){
	if(delayRead(&LED3Delay)){
		BSP_LED_Toggle(LED3);
	}
}

/**
 * @brief Reads the button state, and sets instaKeyStatus it to false if key was pressed
 * @params none
 * @retval true if key was pressed, otherwise false
 */

bool_t readKey(){
	if(instaKeyStatus == true){
		instaKeyStatus = false;
		return true;
	}

	return false;

}

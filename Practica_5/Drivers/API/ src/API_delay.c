/*
 * API_delay.c
 *
 *  Created on: Mar 19, 2022
 *      Author: renato
 */

#include "API_delay.h"

/*
 * Descp: Initializes the delay_t structure, with a running state, and stores the current time
 * Params: delay_t * delay: pointer to the delay_t struct
 * 			tick_t duration: the desired duration time in ms
 * returns: void
 *
*/

void delayInit( delay_t * delay, tick_t duration ){

	if((int)duration < 0) //checks if duration is valid
		duration = 50; //set delay to 50 so the user can know there is an invalid parameter

	delay -> startTime = HAL_GetTick();
	delay -> duration = duration;
	delay -> running = true;
}

/*
 * Descp: Checks if the delay time has passed
 * Params: delay_t * delay: pointer to the delay_t struct
 * returns: true if the delay has passed, otherwise false
 *
*/

bool_t delayRead( delay_t * delay ){

	if(delay -> running == false){
		delay -> startTime = HAL_GetTick();
		delay -> running = true;
	}
	else{
		if(HAL_GetTick() - (delay -> startTime) >= delay -> duration){
			delay -> running = false;	//set running to false, so we can store again the starting time
			return true;
		}
	}

	return false;
}

/*
 * Descp: Initializes the delay_t structure, with a running state, and stores the current time
 * Params: delay_t * delay: pointer to the delay_t struct
 * 			tick_t duration: the desired duration time in ms
 * returns: void
 *
*/
void delayWrite( delay_t * delay, tick_t duration ){

	if((int)duration < 0) //checks if duration is valid
		duration = 50; //set delay to 50 so the user can know there is an invalid parameter

	delay -> duration = duration;
}


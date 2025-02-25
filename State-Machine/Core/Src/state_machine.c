/*
 * state_machine.c
 *
 *  Created on: Feb 6, 2025
 *      Author: leagu
 */

#include "state_machine.h"

extern TIM_HandleTypeDef htim4;
extern volatile uint8_t buttonCounter;
extern int clockCount;
state_Type current_state;
void (*state_table[])(void) = {
	state_machine_init,
	state_LED1_function,
	state_LED2_function,
	state_LED3_function,
	state_LED4_function,
};

void state_machine_init(void) {
	current_state = STATE_LED1;
	CDC_Transmit_FS((uint8_t*) "Init State\n", 11);
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 0);
}

void state_LED1_function(void) {
	CDC_Transmit_FS((uint8_t*) "State-1\n", 8);
	HAL_Delay(200);
	if (buttonCounter % 4 == 1) {
		current_state = STATE_LED2;
		__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 125);
	}
}

void state_LED2_function(void) {
	CDC_Transmit_FS((uint8_t*) "State-2\n", 8);
	HAL_Delay(200);
	if (buttonCounter % 4 == 2) {
		current_state = STATE_LED3;
		__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 250);
	}
}

void state_LED3_function(void) {
	CDC_Transmit_FS((uint8_t*) "State-3\n", 8);
	HAL_Delay(200);
	if (buttonCounter % 4 == 3) {
		current_state = STATE_LED4;
		__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 375);
	}
}

void state_LED4_function(void) {
	CDC_Transmit_FS((uint8_t*) "State-4\n", 8);
	HAL_Delay(200);
	if (buttonCounter % 4 == 0) {
		current_state = STATE_INIT;
		__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 500);
	}
}

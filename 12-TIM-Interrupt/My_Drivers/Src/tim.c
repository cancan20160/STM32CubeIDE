/*
 * tim.c
 *
 *  Created on: Feb 26, 2025
 *      Author: leagu
 */

#include "tim.h"

TIM_HandleTypeDef htim1;

void TIM1_Init(void) {

	__HAL_RCC_TIM1_CLK_ENABLE();

	TIM_ClockConfigTypeDef sClockConfig = { 0 };
	TIM_MasterConfigTypeDef sMasterConfig = { 0 };

	htim1.Instance = TIM1;
	htim1.Init.Prescaler = 16000 - 1;
	htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim1.Init.Period = 1000 - 1;
	htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim1.Init.RepetitionCounter = 0;
	htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	HAL_TIM_Base_Init(&htim1);

	sClockConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	sClockConfig.ClockPrescaler = TIM_CLOCKPRESCALER_DIV1;
	sClockConfig.ClockFilter = 0;
	HAL_TIM_ConfigClockSource(&htim1, &sClockConfig);

	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig);

}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_0);
}

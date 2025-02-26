/*
 * tim.c
 *
 *  Created on: Feb 26, 2025
 *      Author: leagu
 */

#include "tim.h"

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;

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

	HAL_NVIC_SetPriority(TIM1_UP_TIM16_IRQn, 1, 0);
	HAL_NVIC_EnableIRQ(TIM1_UP_TIM16_IRQn);

}

void TIM2_Init(void) {

	__HAL_RCC_TIM2_CLK_ENABLE();

	TIM_ClockConfigTypeDef sClockConfig = { 0 };
	TIM_MasterConfigTypeDef sMasterConfig = { 0 };

	htim2.Instance = TIM2;
	htim2.Init.Prescaler = 16000 - 1;
	htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim2.Init.Period = 2000 - 1;
	htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim2.Init.RepetitionCounter = 0;
	htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	HAL_TIM_Base_Init(&htim2);

	sClockConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	sClockConfig.ClockPrescaler = TIM_CLOCKPRESCALER_DIV1;
	sClockConfig.ClockFilter = 0;
	HAL_TIM_ConfigClockSource(&htim2, &sClockConfig);

	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig);

	HAL_NVIC_SetPriority(TIM2_IRQn, 2, 0);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);

}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim->Instance == TIM1) {
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_0);
	} else if (htim->Instance == TIM2) {
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_1);
	} else {
		return;
	}
}

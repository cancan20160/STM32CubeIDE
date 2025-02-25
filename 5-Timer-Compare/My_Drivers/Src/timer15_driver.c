#include "stm32g4xx_hal.h"
#include "timer15_driver.h"

void timer15_init(void) {

	GPIO_InitTypeDef GPIO_InitStruct;

	__HAL_RCC_TIM15_CLK_ENABLE();

	GPIO_InitStruct.Pin = GPIO_PIN_14;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
	GPIO_InitStruct.Alternate = GPIO_AF1_TIM15;

	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	TIM15->PSC = 48000 - 1;	// TIM15 Clock = 48 MHz / 48000 = 1000 Hz (1ms period)

	// OUTPUT COMPARE MODE - TOGGLE ON MATCH
	TIM15->CCMR1 |= TIM_CCMR1_OC1M_0;
	TIM15->CCMR1 |= TIM_CCMR1_OC1M_1;
	TIM15->CCMR1 &= ~TIM_CCMR1_OC1M_2;

	// OUTPUT COMPARE
	TIM15->CCMR1 &= ~TIM_CCMR1_CC1S_0;
	TIM15->CCMR1 &= ~TIM_CCMR1_CC1S_1;

	// Enable OC1REF OUTPUT
	TIM15->CCER |= TIM_CCER_CC1E;
}

void timer15_enable(void) {
	TIM15->CR1 |= TIM_CR1_CEN;
}

void timer15_disable(void) {
	TIM15->CR1 &= ~TIM_CR1_CEN;
	while (TIM15->CR1 & TIM_CR1_CEN);

}

void timer15_capture_set_period(uint32_t ms) {

	timer15_disable();
	TIM15->ARR = ms - 1;
	TIM15->CCR1 = ms - 1;
	TIM15->EGR |= TIM_EGR_UG;
	timer15_enable();
}

/*
 * tim.h
 *
 *  Created on: Feb 26, 2025
 *      Author: leagu
 */

#ifndef INC_TIM_H_
#define INC_TIM_H_

#include "main.h"

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;

void TIM1_Init(void);
void TIM2_Init(void);

#endif /* INC_TIM_H_ */

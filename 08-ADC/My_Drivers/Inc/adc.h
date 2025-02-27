/*
 * adc.h
 *
 *  Created on: Feb 22, 2025
 *      Author: leagu
 */

#ifndef INC_ADC_H_
#define INC_ADC_H_

#include "main.h"

extern ADC_HandleTypeDef hadc1;

void ADC1_Init(void);
float map(float adcValue, float max, float min, float conMax, float conMin);

#endif /* INC_ADC_H_ */

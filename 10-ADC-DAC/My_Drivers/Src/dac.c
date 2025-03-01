/*
 * dac.c
 *
 *  Created on: Feb 25, 2025
 *      Author: leagu
 */

#include "dac.h"

DAC_HandleTypeDef hdac1;

void DAC1_Init(void) {

	__HAL_RCC_DAC1_CLK_ENABLE();

	DAC_ChannelConfTypeDef sConfig = { 0 };

	hdac1.Instance = DAC1;
	HAL_DAC_Init(&hdac1);

	sConfig.DAC_HighFrequency = DAC_HIGH_FREQUENCY_INTERFACE_MODE_AUTOMATIC;
	sConfig.DAC_DMADoubleDataMode = DISABLE;
	sConfig.DAC_SignedFormat = DISABLE;
	sConfig.DAC_SampleAndHold = DAC_SAMPLEANDHOLD_DISABLE;
	sConfig.DAC_Trigger = DAC_TRIGGER_NONE;
	sConfig.DAC_Trigger2 = DAC_TRIGGER_NONE;
	sConfig.DAC_OutputBuffer = DAC_OUTPUTBUFFER_ENABLE;
	sConfig.DAC_ConnectOnChipPeripheral = DAC_CHIPCONNECT_EXTERNAL;
	sConfig.DAC_UserTrimming = DAC_TRIMMING_FACTORY;
	HAL_DAC_ConfigChannel(&hdac1, &sConfig, DAC_CHANNEL_1);

}

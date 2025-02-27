/*
 * dac.c
 *
 *  Created on: Feb 25, 2025
 *      Author: leagu
 */

#include "dac.h"

DAC_HandleTypeDef hdac1;

uint16_t sinArray[64] = { 2048, 2248, 2447, 2642, 2831, 3013, 3185, 3346, 3495,
		3630, 3750, 3853, 3939, 4007, 4056, 4085, 4095, 4085, 4056, 4007, 3939,
		3853, 3750, 3630, 3495, 3346, 3185, 3013, 2831, 2642, 2447, 2248, 2048,
		1847, 1648, 1453, 1264, 1082, 910, 749, 600, 465, 345, 242, 156, 88, 39,
		10, 0, 10, 39, 88, 156, 242, 345, 465, 600, 749, 910, 1082, 1264, 1453,
		1648, 1847 };

uint16_t triArray[64] = { 128, 256, 384, 512, 640, 768, 896, 1024, 1152, 1280,
		1408, 1536, 1664, 1792, 1920, 2048, 2175, 2303, 2431, 2559, 2687, 2815,
		2943, 3071, 3199, 3327, 3455, 3583, 3711, 3839, 3967, 4095, 3967, 3839,
		3711, 3583, 3455, 3327, 3199, 3071, 2943, 2815, 2687, 2559, 2431, 2303,
		2175, 2048, 1920, 1792, 1664, 1536, 1408, 1280, 1152, 1024, 896, 768,
		640, 512, 384, 256, 128, 0 };

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
	HAL_DAC_ConfigChannel(&hdac1, &sConfig, DAC_CHANNEL_2);

}

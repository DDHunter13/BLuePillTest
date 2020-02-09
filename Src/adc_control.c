/*
 * adc_control.c
 *
 *  Created on: 9 ����. 2020 �.
 *      Author: �����
 */

#include "adc_control.h"

float adc2_measure()
{
	// Start the adc measure
	HAL_ADC_Start(&hadc2);
	// Waiting for conversion
	HAL_ADC_PollForConversion(&hadc2,100);
	// Get measured value
	float adc_res = (float)HAL_ADC_GetValue(&hadc2);
	// Stop adc
	HAL_ADC_Stop(&hadc2);
	// Calculate the real voltage
	adc_res = adc_res / 4096 * 3.3;
	return adc_res;
}

float adc1_temp_measure()
{
	// Start the adc measure
	HAL_ADC_Start(&hadc1);
	// Waiting for conversion
	HAL_ADC_PollForConversion(&hadc1,100);
	// Get measured value
	float adc_res = (float)HAL_ADC_GetValue(&hadc1);
	// Stop adc
	HAL_ADC_Stop(&hadc1);
	// Calculate the real temperature
	adc_res = adc_res / 4096 * 3.3;
	float sub = adc_res - 1.43;
	sub = sub / 0.0043;
	return 25 + sub;
}

/*
 * adc_control.c
 *
 *  Created on: 9 февр. 2020 г.
 *      Author: Денис
 */

#include "adc_control.h"

float adc2_measure()
{
	HAL_ADC_Start(&hadc2);
	HAL_ADC_PollForConversion(&hadc2,100);
	float adc_res = (float)HAL_ADC_GetValue(&hadc2);
	HAL_ADC_Stop(&hadc2);
	adc_res = adc_res / 4096 * 3.3;
	return adc_res;
}

float adc1_temp_measure()
{
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1,100);
	float adc_res = (float)HAL_ADC_GetValue(&hadc1);
	HAL_ADC_Stop(&hadc1);
	adc_res = adc_res / 4096 * 3.3;
	float sub = adc_res - 1.43;
	sub = sub / 0.0043;
	return 25 + sub;
}

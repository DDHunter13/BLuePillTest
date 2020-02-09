/*
 * adc_control.h
 *
 *  Created on: 9 февр. 2020 г.
 *      Author: Денис
 */

#ifndef ADC_CONTROL_H_
#define ADC_CONTROL_H_

#include "main.h"

extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;


float adc2_measure();
float adc1_temp_measure();

#endif /* ADC_CONTROL_H_ */

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

/** @brief The function to get measure of channel0 of adc2 and calculate the voltage.
 * @retval Measured voltage.
 */
float adc2_measure();

/** @brief The function to get measure of temperature sensor of adcq and calculate the temperature.
 * @retval Measured temperature.
 */
float adc1_temp_measure();

#endif /* ADC_CONTROL_H_ */

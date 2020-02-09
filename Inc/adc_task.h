/*
 * adc_task.h
 *
 *  Created on: 9 февр. 2020 г.
 *      Author: Денис
 */

#ifndef ADC_TASK_H_
#define ADC_TASK_H_

#include "main.h"
#include "adc_control.h"
#include "ledcontrol.h"
#include <cmsis_os.h>

extern uint8_t adc_request;
extern uint8_t usart_tx_request;
extern float adc_tx;


void Adc_Task();

#endif /* ADC_TASK_H_ */

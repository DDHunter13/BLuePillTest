/*
 * usart_task.h
 *
 *  Created on: 9 февр. 2020 г.
 *      Author: Денис
 */

#ifndef USART_TASK_H_
#define USART_TASK_H_

#include "main.h"
#include "cmsis_os.h"
#include "ledcontrol.h"
#include <math.h>
#include <string.h>
#include <stdio.h>

extern uint8_t adc_request;
extern USART_HandleTypeDef husart1;
extern uint8_t usart_tx_request;
extern float temperature_tx;
extern float adc_tx;

/** @brief THe funtion to Usart_task. It controls uart Rx and Tx and operate with flags with adc and temperature tasks.
 *
 */
void Usart_Task();

#endif /* USART_TASK_H_ */

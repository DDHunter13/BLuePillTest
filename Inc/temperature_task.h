/*
 * temperature_task.h
 *
 *  Created on: 9 февр. 2020 г.
 *      Author: Денис
 */

#ifndef TEMPERATURE_TASK_H_
#define TEMPERATURE_TASK_H_

#include "main.h"
#include "cmsis_os.h"
#include "adc_control.h"

extern uint8_t usart_tx_request;
extern float temperature_tx;

/** @brief The function to RTOS task. It controls counter to do periodic temperature measurements.
 *
 */
void Temperature_Task();

#endif /* TEMPERATURE_TASK_H_ */

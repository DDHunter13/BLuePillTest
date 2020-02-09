/*
 * temperature_task.c
 *
 *  Created on: 9 февр. 2020 г.
 *      Author: Денис
 */

#include "temperature_task.h"

void Temperature_Task()
{
	// Init temperature value
	temperature_tx = 0;

	// Infinite loop of RTOS task
	for(;;)
	{
		// Make a measurement
		temperature_tx = adc1_temp_measure();
		// Set a flag for uart
		usart_tx_request = (usart_tx_request > 1)? usart_tx_request : (usart_tx_request + 2);
		// Wait before new  measurement
		osDelay(TEMP_SELF_MEASURE);
	}
}

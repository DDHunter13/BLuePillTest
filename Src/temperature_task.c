/*
 * temperature_task.c
 *
 *  Created on: 9 февр. 2020 г.
 *      Author: Денис
 */

#include "temperature_task.h"

void Temperature_Task()
{

	temperature_tx = 0;

	for(;;)
	{
		temperature_tx = adc1_temp_measure();
		usart_tx_request = (usart_tx_request > 1)? usart_tx_request : (usart_tx_request + 2);
		osDelay(TEMP_SELF_MEASURE);
		// send it via uart
	}
}

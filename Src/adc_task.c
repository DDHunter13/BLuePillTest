/*
 * adc_task.c
 *
 *  Created on: 9 февр. 2020 г.
 *      Author: Денис
 */

#include "adc_task.h"

void Adc_Task()
{
	// Init counter
	int adc_time_check = 0;
	// Init voltage variable
	adc_tx = 0;

	// Infinite loop of RTOS task
	for(;;)
	{
		// Check for counter of request
		if((adc_time_check >= ADC_SELF_MEASURE) || (1 == adc_request))
		{
			/* Need to do measurement */
			// Clean counter
			adc_time_check = 0;
			// Call measurement
			adc_tx = adc2_measure();
			// Increase flag to indicates the end of a voltage measurement
			usart_tx_request = (usart_tx_request > 0)? usart_tx_request : (usart_tx_request + 1);
			// Clear request
			adc_request = 0;
			osDelay(100);
		}
		else
		{
			/* No need to measure */
			// Wait some time before new checking
			adc_time_check += 100;
			osDelay(100);
		}
	}

}

/*
 * adc_task.c
 *
 *  Created on: 9 февр. 2020 г.
 *      Author: Денис
 */

#include "adc_task.h"

void Adc_Task()
{
	int adc_time_check = 0;
	adc_tx = 0;

	for(;;)
	{
		if((adc_time_check >= ADC_SELF_MEASURE) || (1 == adc_request))
		{
			adc_time_check = 0;
			adc_tx = adc2_measure();
			usart_tx_request = (usart_tx_request > 0)? usart_tx_request : (usart_tx_request + 1);
			adc_request = 0;
			osDelay(100);
		}
		else
		{
			adc_time_check += 100;
			osDelay(100);
		}
	}

}

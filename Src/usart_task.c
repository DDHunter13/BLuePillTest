/*
 * usart_task.c
 *
 *  Created on: 9 февр. 2020 г.
 *      Author: Денис
 */


#include "usart_task.h"

static void Usart_Receive();
static void Usart_Transmit();

static void Usart_Transmit()
{
	if(usart_tx_request > 1)
	{
		char buffer[13] = {0};
		float divv = fmod(temperature_tx, (float)1);
		sprintf(buffer, "temp: %d.%d", (int)temperature_tx, (int)(divv*100));
		HAL_StatusTypeDef state = HAL_USART_Transmit(&husart1, (uint8_t *) buffer, 13, 100);
		if(HAL_OK != state)
		{
			// close task for restart;
			Error_Handler();
		}
		usart_tx_request -= 2;
	}

	if(usart_tx_request > 0)
	{
		char buffer[13] = {0};
		float divv = fmod(adc_tx, (float)1);
		sprintf(buffer, "adc: %d.%d", (int)adc_tx, (int)(divv*100));
		HAL_StatusTypeDef state = HAL_USART_Transmit(&husart1, (uint8_t *) buffer, 13, 100);
		if(HAL_OK != state)
		{
			// close task for restart;
			Error_Handler();
		}
		usart_tx_request -= 1;
	}
}

static void Usart_Receive()
{
	uint8_t data_buffer[4] = {0};
	uint8_t * p_data_buffer = &data_buffer[0];
	HAL_StatusTypeDef state = HAL_USART_Receive(&husart1, p_data_buffer, 4, 100);
	if(HAL_TIMEOUT == state)
	{
		return;
	}
	if(HAL_OK != state)
	{
		// close task for restart;
		Error_Handler();
	}

	if(0 == strcmp((const char *)p_data_buffer, "adc"))
	{
		adc_request = 1;
		Led_Blink();
		Led_Blink();
	}
	return;
}

void Usart_Task()
{

	adc_request = 0;
	usart_tx_request = 0;

	for(;;)
	{
		 Usart_Receive();
		 Usart_Transmit();
		 osDelay(200);
	}
}

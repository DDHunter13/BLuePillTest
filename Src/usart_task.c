/*
 * usart_task.c
 *
 *  Created on: 9 февр. 2020 г.
 *      Author: Денис
 */


#include "usart_task.h"

/** @brief THe function to check new data from uart receiver. It process it to indicate a request to voltage measurement.
 *
 */
static void Usart_Receive();

/** @brief The function to check new available data for transmitting.
 *
 */
static void Usart_Transmit();

static void Usart_Transmit()
{
	// Check, if we have a new temperature measurement
	if(usart_tx_request > 1)
	{
		// Combine answer string
		char buffer[13] = {0};
		float divv = fmod(temperature_tx, (float)1);
		sprintf(buffer, "temp: %d.%d", (int)temperature_tx, (int)(divv*100));
		// Send anser via uart
		HAL_StatusTypeDef state = HAL_USART_Transmit(&husart1, (uint8_t *) buffer, 13, 100);
		// Check state of operation
		if(HAL_OK != state)
		{
			// close task for restart;
			Error_Handler();
		}
		// Clear the flag of temperature measurement
		usart_tx_request -= 2;
	}

	// Check, if we have a new voltage measurement
	if(usart_tx_request > 0)
	{
		// Combine answer string
		char buffer[13] = {0};
		float divv = fmod(adc_tx, (float)1);
		sprintf(buffer, "adc: %d.%d", (int)adc_tx, (int)(divv*100));
		// Send anser via uart
		HAL_StatusTypeDef state = HAL_USART_Transmit(&husart1, (uint8_t *) buffer, 13, 100);
		// Check state of operation
		if(HAL_OK != state)
		{
			// close task for restart;
			Error_Handler();
		}
		// Clear the flag of voltage measurement
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
	// Init value of Rx and Tx requests
	adc_request = 0;
	usart_tx_request = 0;

	// Infinite loop of RTOS
	for(;;)
	{
		// Check for receiving data and process it
		Usart_Receive();
		// Check for transmitting flag
		Usart_Transmit();

		osDelay(200);
	}
}

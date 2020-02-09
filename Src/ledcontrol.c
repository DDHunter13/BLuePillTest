/*
 * ledcontrol.c
 *
 *  Created on: 8 февр. 2020 г.
 *      Author: Денис
 */

#include "ledcontrol.h"

void Led_Blink()
{
	uint8_t old_state = led_state;
	HAL_GPIO_WritePin(STATUS_INDICATE_PORT, STATUS_INDICATE_PIN, GPIO_PIN_SET);
	osDelay(LED_BLINK_DELAY);
	HAL_GPIO_WritePin(STATUS_INDICATE_PORT, STATUS_INDICATE_PIN, GPIO_PIN_RESET);
	osDelay(LED_BLINK_DELAY);
	HAL_GPIO_WritePin(STATUS_INDICATE_PORT, STATUS_INDICATE_PIN, GPIO_PIN_SET);
	osDelay(LED_BLINK_DELAY);
	HAL_GPIO_WritePin(STATUS_INDICATE_PORT, STATUS_INDICATE_PIN, old_state);
}

void Led_Switch()
{
	led_state = (1 == led_state)? 0 : 1;
	HAL_GPIO_WritePin(STATUS_INDICATE_PORT, STATUS_INDICATE_PIN, led_state);
}

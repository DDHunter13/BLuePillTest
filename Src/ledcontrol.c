/*
 * ledcontrol.c
 *
 *  Created on: 8 февр. 2020 г.
 *      Author: Денис
 */

#include "ledcontrol.h"

void Led_Blink()
{
	// remember old state to returns to it after blink
	uint8_t old_state = led_state;
	// off
	HAL_GPIO_WritePin(STATUS_INDICATE_PORT, STATUS_INDICATE_PIN, GPIO_PIN_SET);
	osDelay(LED_BLINK_DELAY);
	// on
	HAL_GPIO_WritePin(STATUS_INDICATE_PORT, STATUS_INDICATE_PIN, GPIO_PIN_RESET);
	osDelay(LED_BLINK_DELAY);
	// off
	HAL_GPIO_WritePin(STATUS_INDICATE_PORT, STATUS_INDICATE_PIN, GPIO_PIN_SET);
	osDelay(LED_BLINK_DELAY);
	// return old
	HAL_GPIO_WritePin(STATUS_INDICATE_PORT, STATUS_INDICATE_PIN, old_state);
}

void Led_Switch()
{
	// Switch led_state variable
	led_state = (1 == led_state)? 0 : 1;
	// Switch HW led state
	HAL_GPIO_WritePin(STATUS_INDICATE_PORT, STATUS_INDICATE_PIN, led_state);
}

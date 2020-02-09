/*
 * ledcontrol.h
 *
 *  Created on: 8 ����. 2020 �.
 *      Author: �����
 */

#ifndef LEDCONTROL_H_
#define LEDCONTROL_H_

#include <stm32f1xx_hal.h>
#include <cmsis_os.h>
#include <main.h>

uint8_t led_state; //!< Current Led state. Need to switch by function.

/** @brief The function to provide blink led.
 *
 */
void Led_Blink();

/** @brief The function to switch led state.
 * @note It changes led_state variable.
 */
void Led_Switch();

#endif /* LEDCONTROL_H_ */

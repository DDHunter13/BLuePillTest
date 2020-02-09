/*
 * ledcontrol.h
 *
 *  Created on: 8 февр. 2020 г.
 *      Author: Денис
 */

#ifndef LEDCONTROL_H_
#define LEDCONTROL_H_

#include <stm32f1xx_hal.h>
#include <cmsis_os.h>
#include <main.h>

uint8_t led_state;

void Led_Blink();
void Led_Switch();

#endif /* LEDCONTROL_H_ */

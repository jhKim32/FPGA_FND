/*
 * Button.h
 *
 *  Created on: Oct 9, 2022
 *      Author: jhKim
 */

#ifndef SRC_DRIVER_BUTTON_BUTTON_H_
#define SRC_DRIVER_BUTTON_BUTTON_H_

#include "stm32f4xx_hal.h"

enum {ACTIVE_NO, ACTIVE_PUSH, ACTIVE_RELEASE};
enum {PUSHED, RELEASED};

typedef struct _button
{
	GPIO_TypeDef* GPIOX;
	uint16_t GPIO_Pin;
	int prevState;
}Button;

void Button_GetInstance(Button *btn, GPIO_TypeDef* GPIOx, uint16_t GPIO_pin);
int Button_GetState(Button *btn);

#endif /* SRC_DRIVER_BUTTON_BUTTON_H_ */

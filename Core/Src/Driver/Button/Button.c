/*
 * Button.c
 *
 *  Created on: Oct 9, 2022
 *      Author: jhKim
 */

#include "Button.h"

void Button_GetInstance(Button *btn, GPIO_TypeDef* GPIOx, uint16_t GPIO_pin)
{
	btn->GPIOX = GPIOx;
	btn->GPIO_Pin = GPIO_pin;
	btn->prevState = RELEASED;
}

int Button_GetState(Button *btn)
{
	int curState;
	curState = HAL_GPIO_ReadPin(btn->GPIOX, btn->GPIO_Pin);

	if(btn->prevState == RELEASED && curState == PUSHED)
	{
		btn->prevState = PUSHED;
		return ACTIVE_PUSH;
	}
	else if(btn->prevState == PUSHED && curState == RELEASED)
	{
		btn->prevState = RELEASED;
		return ACTIVE_RELEASE;
	}
	return ACTIVE_NO;
}

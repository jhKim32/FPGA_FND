/*
 * FPGA_FND.c
 *
 *  Created on: Oct 9, 2022
 *      Author: jhKim
 */

#include "FPGA_FND.h"

int gNumber = 0;

void FPGA_FND_SetNumber(int number)
{
	gNumber = number;
}

void FPGA_FND_DispFNDNumber()
{
	FPGA_FND_SetFNDNumber(gNumber);
}

void FPGA_FND_SetFNDNumber(int number)
{
	static int position = 0;
	FPGA_FND_SetDigitPosition(position);
	switch(position)
	{
	case 0:
		FPGA_FND_SetValue(number%10);	// 100msec ~ 1000msec
		break;

	case 1:
		FPGA_FND_SetValue(number/10%10); // 1sec ~ 10sec
		break;

	case 2:
		FPGA_FND_SetValue(number/100%6); // 10sec ~ 60sec
		break;

	case 3:
		FPGA_FND_SetValue(number/600%10); // 1min ~ 10min
		break;
	}
	position = (position + 1) % 4;
}

void FPGA_FND_SetDigitPosition(int position)
{
	if(position >= 4) return;

	int pinState = 0;

	GPIO_TypeDef* gpio[2] = {GPIOB, GPIOB};
	int gpio_pin[2] = {GPIO_PIN_3, GPIO_PIN_5};

	for(int i=0 ; i < 2; i++)
	{
		pinState = (position & (1 << i)) ? 1 : 0;
		HAL_GPIO_WritePin(gpio[i], gpio_pin[i], pinState);
	}
}

void FPGA_FND_SetValue(int number)
{
	if(number >= 10) return;

	int pinState = 0;

	GPIO_TypeDef* gpio[4] = {GPIOC, GPIOC, GPIOC, GPIOB};
	int gpio_pin[4] = {GPIO_PIN_6, GPIO_PIN_8, GPIO_PIN_9, GPIO_PIN_8};

	for(int i=0; i < 4; i++)
	{
		pinState = (number & (1 << i)) ? 1 : 0;
		HAL_GPIO_WritePin(gpio[i], gpio_pin[i], pinState);
	}
}

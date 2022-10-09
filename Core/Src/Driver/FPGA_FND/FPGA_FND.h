/*
 * FPGA_FND.h
 *
 *  Created on: Oct 9, 2022
 *      Author: jhKim
 */

#ifndef SRC_DRIVER_FPGA_FND_FPGA_FND_H_
#define SRC_DRIVER_FPGA_FND_FPGA_FND_H_

#include "stm32f4xx_hal.h"

void FPGA_FND_SetNumber(int number);
void FPGA_FND_DispFNDNumber();
void FPGA_FND_SetFNDNumber(int number);
void FPGA_FND_SetDigitPosition(int position);
void FPGA_FND_SetValue(int number);

#endif /* SRC_DRIVER_FPGA_FND_FPGA_FND_H_ */

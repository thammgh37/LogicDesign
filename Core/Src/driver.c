/*
 * driver.c
 *
 *  Created on: Dec 27, 2023
 *      Author: phongtran
 */
#include "driver.h"

uint16_t pinArr[] = {LED12_Pin,LED1_Pin, LED2_Pin, LED3_Pin, LED4_Pin, LED5_Pin,
                     LED6_Pin, LED7_Pin, LED8_Pin, LED9_Pin, LED10_Pin, LED11_Pin, LED12_Pin};

GPIO_TypeDef *portArr[] = {LED12_GPIO_Port,LED1_GPIO_Port, LED2_GPIO_Port, LED3_GPIO_Port, LED4_GPIO_Port,
                           LED5_GPIO_Port, LED6_GPIO_Port, LED7_GPIO_Port, LED8_GPIO_Port, LED9_GPIO_Port,
                           LED10_GPIO_Port, LED11_GPIO_Port, LED12_GPIO_Port};

void offAllLedMode(){
	HAL_GPIO_WritePin(MODE1_GPIO_Port, MODE1_Pin, 1);
	HAL_GPIO_WritePin(MODE2_GPIO_Port, MODE2_Pin, 1);
	HAL_GPIO_WritePin(MODE3_GPIO_Port, MODE3_Pin, 1);
}
void changeLedMode(){
	switch(currentMode){
	case CHANGE_HOUR:
		HAL_GPIO_WritePin(MODE3_GPIO_Port, MODE3_Pin, 1);
		HAL_GPIO_WritePin(MODE1_GPIO_Port, MODE1_Pin, 0);
		break;
	case CHANGE_MINUTE:
		HAL_GPIO_WritePin(MODE1_GPIO_Port, MODE1_Pin, 1);
		HAL_GPIO_WritePin(MODE2_GPIO_Port, MODE2_Pin, 0);
			break;
	case CHANGE_SECOND:
		HAL_GPIO_WritePin(MODE2_GPIO_Port, MODE2_Pin, 1);
		HAL_GPIO_WritePin(MODE3_GPIO_Port, MODE3_Pin, 0);
			break;
	default:
		break;
	}
}
// ======= LED CLOCK =========
void clearAllCLock()
{
  HAL_GPIO_WritePin(portArr[0], pinArr[0], 1);
  HAL_GPIO_WritePin(portArr[1], pinArr[1], 1);
  HAL_GPIO_WritePin(portArr[2], pinArr[2], 1);
  HAL_GPIO_WritePin(portArr[3], pinArr[3], 1);
  HAL_GPIO_WritePin(portArr[4], pinArr[4], 1);
  HAL_GPIO_WritePin(portArr[5], pinArr[5], 1);
  HAL_GPIO_WritePin(portArr[6], pinArr[6], 1);
  HAL_GPIO_WritePin(portArr[7], pinArr[7], 1);
  HAL_GPIO_WritePin(portArr[8], pinArr[8], 1);
  HAL_GPIO_WritePin(portArr[9], pinArr[9], 1);
  HAL_GPIO_WritePin(portArr[10], pinArr[10], 1);
  HAL_GPIO_WritePin(portArr[11], pinArr[11], 1);
  HAL_GPIO_WritePin(portArr[12], pinArr[12], 1);
}
void setNumberOnClock(int num)
{
	HAL_GPIO_WritePin(portArr[num], pinArr[num], 0);
}
void clearNumberOnClock(int num)
{
	HAL_GPIO_WritePin(portArr[num], pinArr[num], 1);
}

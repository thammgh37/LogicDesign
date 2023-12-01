/*
 * blink_led_mode.c
 *
 *  Created on: Oct 29, 2023
 *      Author: ASUS TUF GAMING
 */
#include "blink_led_mode.h"

void blink_led_mode(){
	switch (status) {
		case INIT:
			HAL_GPIO_WritePin(LED_NORMAL_MODE_GPIO_Port, LED_NORMAL_MODE_Pin, SET);
			HAL_GPIO_WritePin(LED_CHAR_MODE_GPIO_Port, LED_CHAR_MODE_Pin, SET);
			HAL_GPIO_WritePin(LED_ANI_MODE_GPIO_Port, LED_ANI_MODE_Pin, SET);
			HAL_GPIO_WritePin(LED_COLOR_MODE_GPIO_Port, LED_COLOR_MODE_Pin, SET);

			break;
		case NORMAL_MODE:
			if(timer3_flag == 1){
				setTimer3(500);//0.5s
				HAL_GPIO_TogglePin(LED_NORMAL_MODE_GPIO_Port, LED_NORMAL_MODE_Pin);
				HAL_GPIO_WritePin(LED_CHAR_MODE_GPIO_Port, LED_CHAR_MODE_Pin, SET);
				HAL_GPIO_WritePin(LED_ANI_MODE_GPIO_Port, LED_ANI_MODE_Pin, SET);
				HAL_GPIO_WritePin(LED_COLOR_MODE_GPIO_Port, LED_COLOR_MODE_Pin, SET);
			}
			  break;
		case SET_CHAR:
			if(timer3_flag == 1){
				setTimer3(500);//0.5s
				HAL_GPIO_WritePin(LED_NORMAL_MODE_GPIO_Port, LED_NORMAL_MODE_Pin, SET);
				HAL_GPIO_TogglePin(LED_CHAR_MODE_GPIO_Port, LED_CHAR_MODE_Pin);
				HAL_GPIO_WritePin(LED_ANI_MODE_GPIO_Port, LED_ANI_MODE_Pin, SET);
				HAL_GPIO_WritePin(LED_COLOR_MODE_GPIO_Port, LED_COLOR_MODE_Pin, SET);
			}
			  break;
		case SET_ANIMATION:
			if(timer3_flag == 1){
				setTimer3(500);//0.5s
				HAL_GPIO_WritePin(LED_NORMAL_MODE_GPIO_Port, LED_NORMAL_MODE_Pin, SET);
				HAL_GPIO_WritePin(LED_CHAR_MODE_GPIO_Port, LED_CHAR_MODE_Pin, SET);
				HAL_GPIO_TogglePin(LED_ANI_MODE_GPIO_Port, LED_ANI_MODE_Pin);
				HAL_GPIO_WritePin(LED_COLOR_MODE_GPIO_Port, LED_COLOR_MODE_Pin, SET);
			}
			break;
		case SET_COLOR:
			if(timer3_flag == 1){
				setTimer3(500);//0.5s
				HAL_GPIO_WritePin(LED_NORMAL_MODE_GPIO_Port, LED_NORMAL_MODE_Pin, SET);
				HAL_GPIO_WritePin(LED_CHAR_MODE_GPIO_Port, LED_CHAR_MODE_Pin, SET);
				HAL_GPIO_WritePin(LED_ANI_MODE_GPIO_Port, LED_ANI_MODE_Pin, SET);
				HAL_GPIO_TogglePin(LED_COLOR_MODE_GPIO_Port, LED_COLOR_MODE_Pin);
			}
			  break;
		default:
			break;
	}
}


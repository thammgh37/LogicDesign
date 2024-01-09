/*
 * led_matrix_driver.c
 *
 *  Created on: Dec 3, 2023
 *      Author: ASUS TUF GAMING
 */
#include <driver.h>

void display_col(int col){
	switch(col){
	case 1:
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, RESET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, RESET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, RESET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, RESET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, RESET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, RESET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, RESET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, RESET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, RESET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, RESET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, RESET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, RESET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, RESET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, RESET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, RESET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, RESET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, RESET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, RESET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, RESET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, RESET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, RESET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, RESET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, RESET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, RESET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, RESET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, RESET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, RESET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, RESET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, RESET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, RESET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, RESET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, RESET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, RESET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, RESET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, RESET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, RESET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, RESET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, RESET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, RESET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, RESET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, RESET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, RESET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, RESET);
		break;
	case 8:
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, RESET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, RESET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, RESET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, RESET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, RESET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, RESET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, RESET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
		break;
	default:
		break;
	}
}
void display_row(uint8_t buffer){
	if((buffer & 0x01) == 0x01 ){
		HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, SET);
	}
	else HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, RESET);
	if((buffer & 0x02) == 0x02 ){
		HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, SET);
	}
	else HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, RESET);
	if((buffer & 0x04) == 0x04 ){
		HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, SET);
	}
	else HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, RESET);
	if((buffer & 0x08) == 0x08 ){
		HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, SET);
	}
	else HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, RESET);
	if((buffer & 0x10) == 0x10 ){
		HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, SET);
	}
	else HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, RESET);
	if((buffer & 0x20) == 0x20 ){
		HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, SET);
	}
	else HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, RESET);
	if((buffer & 0x40) == 0x40 ){
		HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, SET);
	}
	else HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, RESET);
	if((buffer & 0x80) == 0x80 ){
		HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, SET);
	}
	else HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, RESET);
}

void led_normal_on(){
	HAL_GPIO_WritePin(LED_NORMAL_MODE_GPIO_Port, LED_NORMAL_MODE_Pin, RESET);
	HAL_GPIO_WritePin(LED_CHAR_MODE_GPIO_Port, LED_CHAR_MODE_Pin, SET);
	HAL_GPIO_WritePin(LED_ANI_MODE_GPIO_Port, LED_ANI_MODE_Pin, SET);
}
void led_char_on(){
	HAL_GPIO_WritePin(LED_NORMAL_MODE_GPIO_Port, LED_NORMAL_MODE_Pin, SET);
	HAL_GPIO_WritePin(LED_CHAR_MODE_GPIO_Port, LED_CHAR_MODE_Pin, RESET);
	HAL_GPIO_WritePin(LED_ANI_MODE_GPIO_Port, LED_ANI_MODE_Pin, SET);
}
void led_ani_on(){
	HAL_GPIO_WritePin(LED_NORMAL_MODE_GPIO_Port, LED_NORMAL_MODE_Pin, SET);
	HAL_GPIO_WritePin(LED_CHAR_MODE_GPIO_Port, LED_CHAR_MODE_Pin, SET);
	HAL_GPIO_WritePin(LED_ANI_MODE_GPIO_Port, LED_ANI_MODE_Pin, RESET);
}


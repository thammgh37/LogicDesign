/*
 * driver.c
 *
 *  Created on: Dec 1, 2023
 *      Author: ASUS TUF GAMING
 */

#include "driver.h"

void display_red1_green2(){
	HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, RESET);
	HAL_GPIO_WritePin(LED1_YELLOW_GPIO_Port, LED1_YELLOW_Pin, SET);
	HAL_GPIO_WritePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin, SET);
	HAL_GPIO_WritePin(LED2_RED_GPIO_Port, LED2_RED_Pin, SET);
	HAL_GPIO_WritePin(LED2_YELLOW_GPIO_Port, LED2_YELLOW_Pin, SET);
	HAL_GPIO_WritePin(LED2_GREEN_GPIO_Port, LED2_GREEN_Pin, RESET);
}
void display_red1_yellow2(){
	HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, RESET);
	HAL_GPIO_WritePin(LED1_YELLOW_GPIO_Port, LED1_YELLOW_Pin, SET);
	HAL_GPIO_WritePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin, SET);
	HAL_GPIO_WritePin(LED2_RED_GPIO_Port, LED2_RED_Pin, SET);
	HAL_GPIO_WritePin(LED2_YELLOW_GPIO_Port, LED2_YELLOW_Pin, RESET);
	HAL_GPIO_WritePin(LED2_GREEN_GPIO_Port, LED2_GREEN_Pin, SET);
}
void display_green1_red2(){
	HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, SET);
	HAL_GPIO_WritePin(LED1_YELLOW_GPIO_Port, LED1_YELLOW_Pin, SET);
	HAL_GPIO_WritePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin, RESET);
	HAL_GPIO_WritePin(LED2_RED_GPIO_Port, LED2_RED_Pin, RESET);
	HAL_GPIO_WritePin(LED2_YELLOW_GPIO_Port, LED2_YELLOW_Pin, SET);
	HAL_GPIO_WritePin(LED2_GREEN_GPIO_Port, LED2_GREEN_Pin, SET);
}
void display_yellow1_red2(){
	HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, SET);
	HAL_GPIO_WritePin(LED1_YELLOW_GPIO_Port, LED1_YELLOW_Pin, RESET);
	HAL_GPIO_WritePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin, SET);
	HAL_GPIO_WritePin(LED2_RED_GPIO_Port, LED2_RED_Pin, RESET);
	HAL_GPIO_WritePin(LED2_YELLOW_GPIO_Port, LED2_YELLOW_Pin, SET);
	HAL_GPIO_WritePin(LED2_GREEN_GPIO_Port, LED2_GREEN_Pin, SET);
}
void blink_yellow(){
	HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, SET);
	HAL_GPIO_TogglePin(LED1_YELLOW_GPIO_Port, LED1_YELLOW_Pin);
	HAL_GPIO_WritePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin, SET);
	HAL_GPIO_WritePin(LED2_RED_GPIO_Port, LED2_RED_Pin, SET);
	HAL_GPIO_TogglePin(LED2_YELLOW_GPIO_Port, LED2_YELLOW_Pin);
	HAL_GPIO_WritePin(LED2_GREEN_GPIO_Port, LED2_GREEN_Pin, SET);
}
void turn_on_yellow(){
	HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, SET);
	HAL_GPIO_WritePin(LED1_YELLOW_GPIO_Port, LED1_YELLOW_Pin, RESET);
	HAL_GPIO_WritePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin, SET);
	HAL_GPIO_WritePin(LED2_RED_GPIO_Port, LED2_RED_Pin, SET);
	HAL_GPIO_WritePin(LED2_YELLOW_GPIO_Port, LED2_YELLOW_Pin, RESET);
	HAL_GPIO_WritePin(LED2_GREEN_GPIO_Port, LED2_GREEN_Pin, SET);
}
void blink_red1_green2(){
	HAL_GPIO_TogglePin(LED1_RED_GPIO_Port, LED1_RED_Pin);
	HAL_GPIO_WritePin(LED1_YELLOW_GPIO_Port, LED1_YELLOW_Pin, SET);
	HAL_GPIO_WritePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin, SET);
	HAL_GPIO_WritePin(LED2_RED_GPIO_Port, LED2_RED_Pin, SET);
	HAL_GPIO_WritePin(LED2_YELLOW_GPIO_Port, LED2_YELLOW_Pin, SET);
	HAL_GPIO_TogglePin(LED2_GREEN_GPIO_Port, LED2_GREEN_Pin);
}
void blink_green1_red2(){
	HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, SET);
	HAL_GPIO_WritePin(LED1_YELLOW_GPIO_Port, LED1_YELLOW_Pin, SET);
	HAL_GPIO_TogglePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin);
	HAL_GPIO_TogglePin(LED2_RED_GPIO_Port, LED2_RED_Pin);
	HAL_GPIO_WritePin(LED2_YELLOW_GPIO_Port, LED2_YELLOW_Pin, SET);
	HAL_GPIO_WritePin(LED2_GREEN_GPIO_Port, LED2_GREEN_Pin, SET);
}
void display_led_7seg(int num){
	switch(num){
	case 0:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, RESET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, RESET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, SET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, SET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, SET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, SET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, RESET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, SET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, SET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, SET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, SET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, RESET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, SET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, RESET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, SET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, RESET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, RESET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, SET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, SET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, RESET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, RESET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, RESET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
		break;
	default:
		break;
	}
}
int enable_led_7seg = 0;
void control_led_7seg(){
	if(timer2_flag == 1){
		setTimer2(500);
		enable_led_7seg = 1 -enable_led_7seg;
	}
	if(enable_led_7seg == 0){
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, RESET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
		display_led_7seg(time_road1);
	}
	else {
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, RESET);
		display_led_7seg(time_road2);
	}
}
void turn_off_led_7seg(){
	HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
	HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
}

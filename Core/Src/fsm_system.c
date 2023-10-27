/*
 * fsn_system.c
 *
 *  Created on: Oct 27, 2023
 *      Author: ADMIN
 */
#include "main.h"

int hour = 12;
int minute = 30;
int second = 57;
int led_buffer[4] = {1,2,3,0};
int idx = 0;
int state =INIT;
void saveHourSet(){
	hour = led_buffer[0]* 10 + led_buffer[1];
}
void saveMinuteSet(){
	minute = led_buffer[2]* 10 + led_buffer[3];
}
void plusHourOnDisplay(){
	int tmpHour = led_buffer[0] * 10 + led_buffer[1];
	tmpHour++;
	if (tmpHour >= 24){
		tmpHour = 0;
	}
	led_buffer[0] = tmpHour/10;
	led_buffer[1] = tmpHour%10;
}
void plusMinuteOnDisplay(){
	int tmpMinute = led_buffer[2] * 10 + led_buffer[3];
	tmpMinute++;
	if (tmpMinute >= 60){
		tmpMinute = 0;
	}
	led_buffer[2] = tmpMinute/10;
	led_buffer[3] = tmpMinute%10;
}
void display7SEG(int num){
	switch (num){
	case 0:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 0);
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 0);
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 0);
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 1);
		break;
	case 1:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 1);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 1);
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 1);
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 1);
		break;
	case 2:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 1);
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 0);
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 0);
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 1);
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 0);
		break;
	case 3:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 0);
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 1);
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 0);
		break;
	case 4:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 1);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 1);
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 0);
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 0);
		break;
	case 5:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 1);
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 0);
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 0);
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 0);
		break;
	case 6:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 1);
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 0);
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 0);
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 0);
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 0);
		break;
	case 7:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 1);
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 1);
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 1);
		break;
	case 8:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 0);
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 0);
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 0);
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 0);
		break;
	case 9:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 0);
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 0);
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 0);
		break;
	}
}
void update7SEG(int index){
	switch (index){
	case 0:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
		break;
	case 1:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
		break;
	case 2:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
		break;
	case 3:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
		break;
	default:
		break;
	}
	display7SEG(led_buffer[index]);
}
void updateBuffer(){
	led_buffer[0] = hour/10;
	led_buffer[1] = hour%10;
	led_buffer[2] = minute/10;
	led_buffer[3] = minute%10;
}
void secondPlus(){
	second ++;
	if (second >= 60){
		minute ++;
		second = 0;
	}
	if (minute >= 60){
		hour ++;
		minute =0;
	}
	if (hour >= 24){
		hour = 0;
	}
	updateBuffer();
}
void fsmSystemRun(){
	switch (state) {
		case INIT:
			state = NORMAL;
			setTimer3(100);
			break;
		case NORMAL:
			if (isButtonPressLong(0) == 1){
				state = HOURSET;
				setTimer1(1000);
				HAL_GPIO_TogglePin(LED_Long_GPIO_Port, LED_Long_Pin);
			}
			if (timer3_flag == 1){
				setTimer3(100);
				secondPlus();
			}
			break;
		case HOURSET:
			if (timer1_flag == 1){
				updateBuffer();
				state = NORMAL;
			}
			if (isButtonPressLong(0) == 1){
				updateBuffer();
				state = NORMAL;
				HAL_GPIO_TogglePin(LED_Long_GPIO_Port, LED_Long_Pin);
			}
			if (isButtonPress(1) == 1){
				setTimer1(1000);
				plusHourOnDisplay();
				HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
			}
			if (isButtonPress(2) == 1){
				setTimer1(1000);
				saveHourSet();
				updateBuffer();
				HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
			}
			if (isButtonPress(0) == 1){
				updateBuffer();
				setTimer1(1000);
				state = MINUTESET;
				HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
			}
			break;
		case MINUTESET:
			if (timer1_flag == 1){
				updateBuffer();
				state = NORMAL;
			}
			if (isButtonPressLong(0) == 1){
				updateBuffer();
				state = NORMAL;
				HAL_GPIO_TogglePin(LED_Long_GPIO_Port, LED_Long_Pin);
			}
			if (isButtonPress(1) == 1){
				setTimer1(1000);
				plusMinuteOnDisplay();
				HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
			}
			if (isButtonPress(2) == 1){
				setTimer1(1000);
				saveMinuteSet();
				updateBuffer();
				HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
			}
			if (isButtonPress(0) == 1){
				updateBuffer();
				setTimer1(1000);
				state = HOURSET;
				HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
			}
			break;
		default:
			break;
	}
	if (timer2_flag == 1){
		setTimer2(10);
		if (idx >3){
		  idx =0 ;
		}
		update7SEG(idx++);
	}
}

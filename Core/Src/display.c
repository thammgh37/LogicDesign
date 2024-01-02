/*
 * display.c
 *
 *  Created on: Jan 2, 2024
 *      Author: ADMIN
 */
#include "display.h"
#include "main.h"

int idx = 0;

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

void setLedMode(int mode){
	switch (mode) {
		case NORMAL:
			HAL_GPIO_WritePin(MODE1_GPIO_Port, MODE1_Pin, RESET);
			HAL_GPIO_WritePin(MODE2_GPIO_Port, MODE2_Pin, SET);
			HAL_GPIO_WritePin(MODE3_GPIO_Port, MODE3_Pin, SET);
			break;
		case HOURSET:
			HAL_GPIO_WritePin(MODE1_GPIO_Port, MODE1_Pin, SET);
			HAL_GPIO_WritePin(MODE2_GPIO_Port, MODE2_Pin, RESET);
			HAL_GPIO_WritePin(MODE3_GPIO_Port, MODE3_Pin, SET);
			break;
		case MINUTESET:
			HAL_GPIO_WritePin(MODE1_GPIO_Port, MODE1_Pin, SET);
			HAL_GPIO_WritePin(MODE2_GPIO_Port, MODE2_Pin, SET);
			HAL_GPIO_WritePin(MODE3_GPIO_Port, MODE3_Pin, RESET);
			break;
		default:
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

void displayClock(){
	if (timer2_flag == 1){
		setTimer2(10);
		if (idx > 3){
		  idx = 0 ;
		}
		update7SEG(idx++);
	}
}

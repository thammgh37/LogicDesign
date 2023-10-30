/*
 * display_led_matrix.c
 *
 *  Created on: Oct 1, 2023
 *      Author: ASUS TUF GAMING
 */

#include "display_led_matrix.h"
#define A_stable_red 1
#define A_stable_green 2
#define A_stable_yellow 3
#define A_run_red 4
#define A_run_green 5
#define A_run_yellow 6

#define B_stable_red 7
#define B_stable_green 8
#define B_stable_yellow 9
#define B_run_red 10
#define B_run_green 11
#define B_run_yellow 12

const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
int state_led_matrix = 0;
uint16_t cot_red[8]= {ENM0_Pin,ENM1_Pin,ENM2_Pin,ENM3_Pin,ENM4_Pin,ENM5_Pin,ENM6_Pin,ENM7_Pin};
uint16_t cot_green[8]= {gENM0_Pin,gENM1_Pin,gENM2_Pin,gENM3_Pin,gENM4_Pin,gENM5_Pin,gENM6_Pin,gENM7_Pin};
uint16_t hang[8]= {ROW0_Pin,ROW1_Pin,ROW2_Pin,ROW3_Pin,ROW4_Pin,ROW5_Pin,ROW6_Pin,ROW7_Pin};


uint8_t test[1][8]= 	{			{ 0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF} };
uint8_t test1[1][8]= 	{			{ 0xFE,0xFD,0xFC,0xFB,0xFA,0xF9,0xF8,0xF7} };
uint8_t test2[1][8]= 	{			{ 0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08} };
uint8_t matrix_off[1][8]= 	{			{ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00} };

uint8_t a_stay[1][8]= 	{			{ 0x66,0x66,0x66,0x7E,0x66,0x66,0x3C,0x00} };//6666667e66663c00


uint8_t a_run[14][8]={ 					{ 0x66,0x66,0x66,0x7E,0x66,0x66,0x3C,0x00},//6666667e66663c00
										{ 0x33,0x33,0x33,0x3F,0x33,0x33,0x1E,0x00},//3333333f33331e00
										{ 0x19,0x19,0x19,0x1f,0x19,0x19,0x0F,0x00},//1919191f19190f00
										{ 0x0C,0x0C,0x0C,0x0F,0x0C,0x0C,0x07,0x00},//0c0c0c0f0c0c0700
										{ 0x06,0x06,0x06,0x07,0x06,0x06,0x03,0x00},//0606060706060300
										{ 0x03,0x03,0x03,0x03,0x03,0x03,0x01,0x00},//0303030303030100
										{ 0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00},//0101010101010000
										{ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},//0000000000000000
										{ 0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00},//8080808080800000
										{ 0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x80,0x00},//c0c0c0c0c0c08000
										{ 0x60,0x60,0x60,0xE0,0x60,0x60,0xC0,0x00},//606060e06060c000
										{ 0x30,0x30,0x30,0xF0,0x30,0x30,0xE0,0x00},//303030f03030e000
										{ 0x98,0x98,0x98,0xF8,0x98,0x98,0xF0,0x00},//989898f89898f000
										{ 0xcc,0xcc,0xcc,0xFC,0xcc,0xcc,0x78,0x00}//ccccccfccccc7800
};

uint8_t b_stay[1][8]= 	{			{ 0x00,0x7C,0x66,0x66,0x7C,0x66,0x66,0x7C} };//007c66667c66667c


uint8_t b_run[14][8]={ 					{ 0x00,0x7C,0x66,0x66,0x7C,0x66,0x66,0x7C},//007c66667c66667c
										{ 0x00,0xF8,0xCC,0xCC,0xF8,0xCC,0xCC,0xF8},//00f8ccccf8ccccf8
										{ 0x00,0xF0,0x98,0x98,0xF0,0x98,0x98,0xF0},//00f09898f09898f0
										{ 0x00,0xE0,0x30,0x30,0xe0,0x30,0x30,0xe0},//00e03030e03030e0
										{ 0x00,0xC0,0x60,0x60,0xC0,0x60,0x60,0xC0},//00c06060c06060c0
										{ 0x00,0x80,0xC0,0xC0,0x80,0xC0,0xC0,0x80},//0080c0c080c0c080
										{ 0x00,0x00,0x80,0x80,0x00,0x80,0x80,0x00},//0000808000808000
										{ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},//0000000000000000
										{ 0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01},//0001010101010101
										{ 0x00,0x03,0x03,0x03,0x03,0x03,0x03,0x03},//0003030303030303
										{ 0x00,0x07,0x06,0x06,0x07,0x06,0x06,0x07},//0007060607060607
										{ 0x00,0x0F,0x0C,0x0C,0x0F,0x0C,0x0C,0x0F},//000f0c0c0f0c0c0f
										{ 0x00,0x1F,0x19,0x19,0x1F,0x19,0x19,0x1F},//001f19191f19191f
										{ 0x00,0x3E,0x33,0x33,0x3E,0x33,0x33,0x3E}//003e33333e33333e
};
void writeByte(GPIO_TypeDef* port, uint16_t* pins, uint8_t byte){
	HAL_GPIO_WritePin(port, pins[0], byte & 0x01);
	HAL_GPIO_WritePin(port, pins[1], byte & 0x02);
	HAL_GPIO_WritePin(port, pins[2], byte & 0x04);
	HAL_GPIO_WritePin(port, pins[3], byte & 0x08);
	HAL_GPIO_WritePin(port, pins[4], byte & 0x10);
	HAL_GPIO_WritePin(port, pins[5], byte & 0x20);
	HAL_GPIO_WritePin(port, pins[6], byte & 0x40);
	HAL_GPIO_WritePin(port, pins[7], byte & 0x80);
}


void displayLedMatrix_red(int index1, int index2, uint8_t buffer[][8]){
	switch (index2){
	case 0:
		writeByte(ENM0_GPIO_Port, cot_red, 0X01);
		writeByte(gENM0_GPIO_Port, cot_green, 0X00);
		writeByte(ROW0_GPIO_Port, hang, buffer[index1][index2]);
		break;
	case 1:
		writeByte(ENM1_GPIO_Port, cot_red, 0X02);
		writeByte(gENM0_GPIO_Port, cot_green, 0X00);
		writeByte(ROW1_GPIO_Port, hang, buffer[index1][index2]);
		break;
	case 2:
		writeByte(ENM2_GPIO_Port, cot_red, 0X04);
		writeByte(gENM0_GPIO_Port, cot_green, 0X00);
		writeByte(ROW2_GPIO_Port, hang, buffer[index1][index2]);
		break;
	case 3:
		writeByte(ENM3_GPIO_Port, cot_red, 0X08);
		writeByte(gENM0_GPIO_Port, cot_green, 0X00);
		writeByte(ROW3_GPIO_Port, hang, buffer[index1][index2]);
		break;
	case 4:
		writeByte(ENM4_GPIO_Port, cot_red, 0X10);
		writeByte(gENM0_GPIO_Port, cot_green, 0X00);
		writeByte(ROW4_GPIO_Port, hang, buffer[index1][index2]);
		break;
	case 5:
		writeByte(ENM5_GPIO_Port, cot_red, 0X20);
		writeByte(gENM0_GPIO_Port, cot_green, 0X00);
		writeByte(ROW5_GPIO_Port, hang, buffer[index1][index2]);
		break;
	case 6:
		writeByte(ENM6_GPIO_Port, cot_red, 0X40);
		writeByte(gENM0_GPIO_Port, cot_green, 0X00);
		writeByte(ROW6_GPIO_Port, hang, buffer[index1][index2]);
		break;
	case 7:
		writeByte(ENM0_GPIO_Port, cot_red, 0X80);
		writeByte(gENM0_GPIO_Port, cot_green, 0X00);
		writeByte(ROW0_GPIO_Port, hang, buffer[index1][index2]);
		break;
	default:
		break;
	}
}
void displayLedMatrix_green(int index1, int index2, uint8_t buffer[][8]){
	switch (index2){
	case 0:
		writeByte(ENM0_GPIO_Port, cot_red, 0X00);
		writeByte(gENM0_GPIO_Port, cot_green, 0X00);
		writeByte(ROW0_GPIO_Port, hang, buffer[index1][index2]);
		break;
	case 1:
		writeByte(ENM1_GPIO_Port, cot_red, 0X00);
		writeByte(gENM0_GPIO_Port, cot_green, 0X02);
		writeByte(ROW1_GPIO_Port, hang, buffer[index1][index2]);
		break;
	case 2:
		writeByte(ENM2_GPIO_Port, cot_red, 0X00);
		writeByte(gENM0_GPIO_Port, cot_green, 0X04);
		writeByte(ROW2_GPIO_Port, hang, buffer[index1][index2]);
		break;
	case 3:
		writeByte(ENM3_GPIO_Port, cot_red, 0X00);
		writeByte(gENM0_GPIO_Port, cot_green, 0X08);
		writeByte(ROW3_GPIO_Port, hang, buffer[index1][index2]);
		break;
	case 4:
		writeByte(ENM4_GPIO_Port, cot_red, 0X00);
		writeByte(gENM0_GPIO_Port, cot_green, 0X10);
		writeByte(ROW4_GPIO_Port, hang, buffer[index1][index2]);
		break;
	case 5:
		writeByte(ENM5_GPIO_Port, cot_red, 0X00);
		writeByte(gENM0_GPIO_Port, cot_green, 0X20);
		writeByte(ROW5_GPIO_Port, hang, buffer[index1][index2]);
		break;
	case 6:
		writeByte(ENM6_GPIO_Port, cot_red, 0X00);
		writeByte(gENM0_GPIO_Port, cot_green, 0X40);
		writeByte(ROW6_GPIO_Port, hang, buffer[index1][index2]);
		break;
	case 7:
		writeByte(ENM0_GPIO_Port, cot_red, 0X00);
		writeByte(gENM0_GPIO_Port, cot_green, 0X80);
		writeByte(ROW0_GPIO_Port, hang, buffer[index1][index2]);
		break;
	default:
		break;
	}
}


void set_state_matrix(){
	if(mode_char == A && mode_animation == stable && mode_color == red) state_led_matrix = A_stable_red;
	if(mode_char == A && mode_animation == stable && mode_color == green) state_led_matrix = A_stable_green;
	if(mode_char == A && mode_animation == stable && mode_color == yellow) state_led_matrix = A_stable_yellow;
	if(mode_char == A && mode_animation == run && mode_color == red) state_led_matrix = A_run_red;
	if(mode_char == A && mode_animation == run && mode_color == green) state_led_matrix = A_run_green;
	if(mode_char == A && mode_animation == run && mode_color == yellow) state_led_matrix = A_run_yellow;

	if(mode_char == B && mode_animation == stable && mode_color == red) state_led_matrix = B_stable_red;
	if(mode_char == B && mode_animation == stable && mode_color == green) state_led_matrix = B_stable_green;
	if(mode_char == B && mode_animation == stable && mode_color == yellow) state_led_matrix = B_stable_yellow;
	if(mode_char == B && mode_animation == run && mode_color == red) state_led_matrix = B_run_red;
	if(mode_char == B && mode_animation == run && mode_color == green) state_led_matrix = B_run_green;
	if(mode_char == B && mode_animation == run && mode_color == yellow) state_led_matrix = B_run_yellow;
}

// mat co chu cam day 1 - 12, ben phai la row1, ben canh la red1
void displayLedMatrix(int index1, int index2){
	set_state_matrix();
	switch(state_led_matrix){

	case A_stable_red:
		displayLedMatrix_red(0, index2, a_stay);
		break;
	case A_stable_green:
		displayLedMatrix_green(0, index2, a_stay);
		break;
	case A_stable_yellow:
		displayLedMatrix_red(0, index2, a_stay);
		break;
	case A_run_red:
		displayLedMatrix_red(index1, index2, a_run);
		break;
	case A_run_green:
		displayLedMatrix_green(index1, index2, a_run);
		break;
	case A_run_yellow:
		displayLedMatrix_red(index1, index2, a_run);
		break;

	case B_stable_red:
		displayLedMatrix_red(0, index2, b_stay);
		break;
	case B_stable_green:
		displayLedMatrix_green(0, index2, b_stay);
		break;
	case B_stable_yellow:
		displayLedMatrix_red(0, index2, b_stay);
		break;
	case B_run_red:
		displayLedMatrix_red(index1, index2, b_run);
		break;
	case B_run_green:
		displayLedMatrix_green(index1, index2, b_run);
		break;
	case B_run_yellow:
		displayLedMatrix_red(index1, index2, b_run);
		break;
	default:
		break;
	}
}

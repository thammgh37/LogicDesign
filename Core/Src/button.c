/*
 * button.c
 *
 *  Created on: Sep 30, 2023
 *      Author: ASUS TUF GAMING
 */

#include "button.h"



int button_flag_pressed_once[num_buttons]  = {0, 0, 0};
int button_flag_pressed_hold[num_buttons]  = {0, 0, 0};
int en_pressed_once[num_buttons] = {0, 0, 0};

int keyReg0[num_buttons] =  	{NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyReg1[num_buttons] =  	{NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyReg2[num_buttons] =  	{NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyReg3[num_buttons] =  	{NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int time_for_key_press[num_buttons] = {2000, 2000, 2000};

void reset_all_button(){
	for(int i=0; i< num_buttons; i++){
		button_flag_pressed_once[i] = 0;
		button_flag_pressed_hold[i] = 0;
	}
}

void key_n_process_pressed_once(int n){
	button_flag_pressed_once[n] = 1;
}
void key_n_process_pressed_hold(int n){
	button_flag_pressed_hold[n] = 1;
}

int is_button_pressed_once(int n){
	if(button_flag_pressed_once[n] == 1){
		button_flag_pressed_once[n] = 0;
		return 1;
	}
	else {
		return 0;
	}
}
int is_button_pressed_hold(int n){
	if(button_flag_pressed_hold[n] == 1){
		button_flag_pressed_hold[n] = 0;
		return 1;
	}
	else {
		return 0;
	}
}



void get_key_input(int n){
	keyReg0[n] = keyReg1[n];
	keyReg1[n] = keyReg2[n];
	// set up button n here
	switch(n){
	case 0:
		 keyReg2[0] = HAL_GPIO_ReadPin(BUTTON_MODE_GPIO_Port, BUTTON_MODE_Pin);
		break;
	case 1:
		 keyReg2[1] = HAL_GPIO_ReadPin(BUTTON_CHANGE_GPIO_Port, BUTTON_CHANGE_Pin);
		break;
	case 2:
		 keyReg2[2] = HAL_GPIO_ReadPin(BUTTON_MODE_GPIO_Port, BUTTON_MODE_Pin);
		break;
	default:
		break;
	}
	/////////
	if((keyReg0[n] == keyReg1[n]) && (keyReg1[n] == keyReg2[n]) ){
		if(keyReg2[n] != keyReg3[n]){
			keyReg3[n] = keyReg2[n];
			if(keyReg2[n] == NORMAL_STATE && en_pressed_once[n] == 1){
				//TODO when pressed once
				en_pressed_once[n] = 0;
				key_n_process_pressed_once(n);
			}
			if(keyReg2[n] == PRESSED_STATE){
				en_pressed_once[n] = 1;
			}
			time_for_key_press[n] = 200;
		}
		else{
			time_for_key_press[n]--;
			if(time_for_key_press[n] == 0){
				if(keyReg2[n] == PRESSED_STATE){
					//todo when hold pressed
					en_pressed_once[n] = 0;
					key_n_process_pressed_hold(n);
				}
				time_for_key_press[n] = 200;
			}
		}
	}
}

void get_key_input_all(){


	for(int i = 0; i < num_buttons ;i++){
		get_key_input(i);
	}
}


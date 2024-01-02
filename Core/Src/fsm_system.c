/*
 * fsn_system.c
 *
 *  Created on: Oct 27, 2023
 *      Author: ADMIN
 */
#include "main.h"

int state = INIT;

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
			setLedMode(state);
			if (isButtonPressLong(0) == 1){
				state = HOURSET;
				setTimer1(1000);
			}
			if (timer3_flag == 1){
				setTimer3(100);
				secondPlus();
			}
			break;
		case HOURSET:
			setLedMode(state);
			if (timer1_flag == 1){
				updateBuffer();
				state = NORMAL;
			}
			if (isButtonPressLong(0) == 1){
				updateBuffer();
				state = NORMAL;
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
			setLedMode(state);
			if (timer1_flag == 1){
				updateBuffer();
				state = NORMAL;
			}
			if (isButtonPressLong(0) == 1){
				updateBuffer();
				state = NORMAL;
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
}

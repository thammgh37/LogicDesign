/*
 * fsm_clock.c
 *
 *  Created on: Oct 25, 2023
 *      Author: HP
 */

#include "fsm_clock.h"

uint16_t pinArr[] = {LED1_Pin, LED2_Pin, LED3_Pin, LED4_Pin, LED5_Pin,
                     LED6_Pin, LED7_Pin, LED8_Pin, LED9_Pin, LED10_Pin, LED11_Pin, LED12_Pin};

GPIO_TypeDef *portArr[] = {LED1_GPIO_Port, LED2_GPIO_Port, LED3_GPIO_Port, LED4_GPIO_Port,
                           LED5_GPIO_Port, LED6_GPIO_Port, LED7_GPIO_Port, LED8_GPIO_Port, LED9_GPIO_Port,
                           LED10_GPIO_Port, LED11_GPIO_Port, LED12_GPIO_Port};
enum ClockState{
	NORMAL_STATE,
	CHANGE_STATE
};
enum ClockMode{
	CHANGE_HOUR,
	CHANGE_MINUTE,
	CHANGE_SECOND
};
int second =0 , minute =0, hour=0;
enum ClockState currentState = NORMAL_STATE;
enum ClockMode currentMode = CHANGE_HOUR;
int _step = 1;
// ======= LED MODE ==========
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
}
void setNumberOnClock(int num)
{
  HAL_GPIO_WritePin(portArr[num], pinArr[num], 0);
}
void clearNumberOnClock(int num)
{
  HAL_GPIO_WritePin(portArr[num], pinArr[num], 1);
}
void init_clock(int _second,int _minute, int _hour){
	clearAllCLock();
	offAllLedMode();
	currentState = NORMAL_STATE;
	currentMode = CHANGE_HOUR;
	changeLedMode();
	second = _second;
	minute = _minute;
	hour = _hour;
	setNumberOnClock(second/5);
	setNumberOnClock(minute/5);
	setNumberOnClock(hour/2);
}
// ======= SETUP CLOCK ===========
void setupClock(int step){
	if(currentState == NORMAL_STATE) return;
	switch(currentMode){
		case CHANGE_HOUR:
			if(hour/2 != minute/5 && hour/2 != second/5)
				clearNumberOnClock(hour/2);
			hour+=step;
			if(hour > 23 || hour < 0){
				hour = 0;
			}
			setNumberOnClock(hour/2);
			break;
		case CHANGE_MINUTE:
			if(hour/2 != minute/5 && minute/5 != second/5)
				clearNumberOnClock(minute / 5);
			minute+=step*5;
			if(minute > 59 || minute < 0){
				minute = 0;
			}
			setNumberOnClock(minute / 5);
			break;
		case CHANGE_SECOND:
			if(second/5 != hour/2 && minute/5 != second/5)
			clearNumberOnClock(second / 5);
			second+=step*5;
			if(second > 59 || second < 0){
				second = 0;
			}
			setNumberOnClock(second / 5);
			break;
		default:
			break;
	}
}
// ====== CHECK BUTTON FUNCTION ======
void checkButtonClock(){
	if(isButtonLongPress(0)){
		currentState = 1 - currentState;
		if(currentState == CHANGE_STATE){
			changeLedMode();
		}
	}
	if(isButtonPress(0)){
		if(currentState == CHANGE_STATE){
			currentMode++;
			currentMode %= 3;
			changeLedMode();
		}
	}
	else if(isButtonPress(1)){
		setupClock(_step);
	}
	else if(isButtonPress(2)){
		setupClock(-_step);
	}
}
// ======= FSM FUNCTION =======
void fsm_clock(){
	if(currentState == CHANGE_STATE) return;
	offAllLedMode();
	currentMode = CHANGE_HOUR;
	if (second/5 != minute/5 && second/5 != hour/2)
	{
	  clearNumberOnClock(second/5);
	}
	second++;
	if (second > 59)
	{
	  second = 0;
	  clearNumberOnClock(minute/5);
	  minute+=5;
	}
	if (minute > 59)
	{
	  minute = 0;
	  clearNumberOnClock(hour/2);
	  hour+=2;
	}
	if (hour > 23)
	  hour = 0;
	setNumberOnClock(hour/2);
	setNumberOnClock(minute/5);
	setNumberOnClock(second/5);
}




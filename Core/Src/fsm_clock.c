/*
 * fsm_clock.c
 *
 *  Created on: Oct 25, 2023
 *      Author: HP
 */

#include "fsm_clock.h"

int second =0 , minute =0, hour=0;
enum ClockState currentState = NORMAL_STATE;
enum ClockMode currentMode = CHANGE_HOUR;
int _step = 1;
// ======= INIT MODE ==========
void init_clock(int _second,int _minute, int _hour){
	clearAllCLock();
	offAllLedMode();
	currentState = NORMAL_STATE;
	currentMode = CHANGE_HOUR;
	changeLedMode();
	second = _second;
	minute = _minute;
	hour = _hour;
	setNumberOnClock(_second/5);
	setNumberOnClock(_minute/5);
	setNumberOnClock(_hour);
}
// ======= SETUP CLOCK ===========
void setupClock(int step){
	if(currentState == NORMAL_STATE) return;
	switch(currentMode){
		case CHANGE_HOUR:
			if(hour != minute/5 && hour != second/5)
				clearNumberOnClock(hour);
			hour+=step;
			if(hour >= 12){
				hour = 0;
			}
			else if(hour < 0){
				hour = 11;
			}
			break;
		case CHANGE_MINUTE:
			if(hour != minute/5 && minute/5 != second/5)
				clearNumberOnClock(minute / 5);
			minute+=step*5;
			if(minute >= 60){
				minute = 1;
				clearNumberOnClock(hour);
				hour++;
				if(hour >= 12){
					hour = 0;
				}

			}
			else if(minute <= 0){
				minute = 59;
				clearNumberOnClock(hour);
				hour--;
				if(hour < 0){
					hour = 11;
				}
			}
			break;
		case CHANGE_SECOND:
			if(second/5 != hour && minute/5 != second/5)
				clearNumberOnClock(second / 5);
			second+=step*5;
			if(second > 60){
				second = 1;
				clearNumberOnClock(minute / 5);
				minute+=step*5;
				if(minute >= 60){
					minute = 1;
					clearNumberOnClock(hour);
					hour++;
					if(hour >= 12){
						hour = 0;
					}
				}

			}
			else if(second < 0){
				second = 59;
				clearNumberOnClock(minute / 5);
				minute+=step*5;
				if(minute <= 0){
					minute = 59;
					clearNumberOnClock(hour);
					hour--;
					if(hour < 0){
						hour = 11;
					}
				}
			}
			break;
		default:
			break;
	}
	setNumberOnClock(hour);
	setNumberOnClock(minute / 5);
	setNumberOnClock(second / 5);
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
// ======= MAIN FSM =======
void fsm_clock(){
	if(currentState == CHANGE_STATE) return;
	offAllLedMode();
	currentMode = CHANGE_HOUR;
	if (second/5 != minute/5 && second/5 != hour)
	{
	  clearNumberOnClock(second/5);
	}
	second++;
	if (second >= 60)
	{
	  second = 0;
	  clearNumberOnClock(minute/5);
	  minute+=5;
	}
	if (minute >= 60)
	{
	  minute = 0;
	  clearNumberOnClock(hour);
	  hour+=1;
	}
	if (hour >= 12)
	  hour = 0;
	setNumberOnClock(hour);
	setNumberOnClock(minute/5);
	setNumberOnClock(second/5);
}




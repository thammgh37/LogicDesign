/*
 * fsm_clock.h
 *
 *  Created on: Oct 25, 2023
 *      Author: HP
 */

#ifndef INC_FSM_CLOCK_H_
#define INC_FSM_CLOCK_H_

#include "button.h"
#include "main.h"
#include "timer.h"
#include "driver.h"

extern enum ClockState{
	NORMAL_STATE,
	CHANGE_STATE
};
extern enum ClockMode{
	CHANGE_HOUR,
	CHANGE_MINUTE,
	CHANGE_SECOND
};
extern enum ClockState currentState;
extern enum ClockMode currentMode;
void init_clock(int,int,int);
void fsm_clock();
void checkButtonClock();
#endif /* INC_FSM_CLOCK_H_ */

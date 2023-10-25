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

void init_clock(int,int,int);
void fsm_clock();
void checkButtonClock();
#endif /* INC_FSM_CLOCK_H_ */

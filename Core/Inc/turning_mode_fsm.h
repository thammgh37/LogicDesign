/*
 * turning_mode_fsm.h
 *
 *  Created on: Dec 2, 2023
 *      Author: ASUS TUF GAMING
 */

#ifndef INC_TURNING_MODE_FSM_H_
#define INC_TURNING_MODE_FSM_H_
#include "global.h"
#include "software_timer.h"
#include "button.h"
#include "driver.h"
#define SET_RED1_GREEN2 1
#define SET_YELLOW1_YELLOW2 2
#define SET_GREEN1_RED2 3


extern int turning_mode_state;
void turning_mode_fsm();


#endif /* INC_TURNING_MODE_FSM_H_ */

/*
 * normal_mode_fsm.h
 *
 *  Created on: Dec 1, 2023
 *      Author: ASUS TUF GAMING
 */

#ifndef INC_NORMAL_MODE_FSM_H_
#define INC_NORMAL_MODE_FSM_H_

#include "global.h"
#include "software_timer.h"
#include "driver.h"
#define RED1_GREEN2 1
#define RED1_YELLOW2 2
#define GREEN1_RED2 3
#define YELLOW1_RED2 4

extern int normal_mode_state;
void normal_mode_fsm();


#endif /* INC_NORMAL_MODE_FSM_H_ */

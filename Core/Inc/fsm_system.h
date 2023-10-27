/*
 * fsm_system.h
 *
 *  Created on: Oct 27, 2023
 *      Author: ADMIN
 */

#ifndef INC_FSM_SYSTEM_H_
#define INC_FSM_SYSTEM_H_

#define INIT		1
#define NORMAL		2
#define	HOURSET		3
#define MINUTESET	4

#define NUMLED		4

extern int state;
extern int led_buffer[4];
extern int second;
extern int minute;
extern int hour;
void fsmSystemRun();
void update7SEG(int index);
void display7SEG(int num);
void updateBuffer();

#endif /* INC_FSM_SYSTEM_H_ */

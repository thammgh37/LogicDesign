/*
 * normal_mode_fsm.c
 *
 *  Created on: Dec 1, 2023
 *      Author: ASUS TUF GAMING
 */
#include "normal_mode_fsm.h"

int normal_mode_state = RED1_GREEN2;

void decrease_time(){
	if(time_road1 > 0) time_road1--;
	if(time_road2 > 0) time_road2--;
}
void normal_mode_fsm(){
	switch(normal_mode_state){
	case RED1_GREEN2:
		display_red1_green2();
		if(timer1_flag == 1){
			setTimer1(1000);
			decrease_time();
		}
		if(time_road2 <= 0){
			normal_mode_state = RED1_YELLOW2;
			time_road2 = time_yellow2;
			setTimer1(1000);
		}
		break;
	case RED1_YELLOW2:
		display_red1_yellow2();
		if(timer1_flag == 1){
			setTimer1(1000);
			decrease_time();
		}
		if(time_road2 <= 0){
			normal_mode_state = GREEN1_RED2;
			time_road1 = time_green1;
			time_road2 = time_red2;
			setTimer1(1000);
		}
		break;
	case GREEN1_RED2:
		display_green1_red2();
		if(timer1_flag == 1){
			setTimer1(1000);
			decrease_time();
		}
		if(time_road1 <= 0){
			normal_mode_state = YELLOW1_RED2;
			time_road1 = time_yellow1;
			setTimer1(1000);
		}
		break;
	case YELLOW1_RED2:
		display_yellow1_red2();
		if(timer1_flag == 1){
			setTimer1(1000);
			decrease_time();
		}
		if(time_road1 <= 0){
			normal_mode_state = RED1_GREEN2;
			time_road1 = time_red1;
			time_road2 = time_green2;
			setTimer1(1000);
		}
		break;
	default:
		break;
	}
}

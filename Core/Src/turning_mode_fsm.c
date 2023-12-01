/*
 * turning_mode_fsm.c
 *
 *  Created on: Dec 2, 2023
 *      Author: ASUS TUF GAMING
 */
#include "turning_mode_fsm.h"

int turning_mode_state = SET_RED1_GREEN2;
void turning_mode_fsm(){
	switch(turning_mode_state){
	case SET_RED1_GREEN2:
		if(timer1_flag == 1){
			setTimer1(500);
			blink_red1_green2();
		}
		// increase time
		if(is_button_pressed_once(1) || is_button_pressed_hold(1)){
			time_red1++;
			if(time_red1 > 9){
				time_red1 = 0;
			}
			time_green2 = time_red1 - time_yellow2;
			if(time_green2 < 0) {
				time_red1 = time_yellow2;
				time_green2 = 0;
			}
			time_road1 = time_red1;
			time_road2 = time_green2;
		}
		// decrease time
		if(is_button_pressed_once(2) || is_button_pressed_hold(2)){
			time_red1--;
			if(time_red1 < 0){
				time_red1 = 9;
			}
			time_green2 = time_red1 - time_yellow2;
			if(time_green2 < 0){
				time_red1 = time_yellow2;
				time_green2 = 0;
			}
			time_road1 = time_red1;
			time_road2 = time_green2;
		}
		if(is_button_pressed_once(0)){
			turning_mode_state = SET_YELLOW1_YELLOW2;
			turn_on_yellow();
			time_road1 = time_yellow1;
			time_road2 = time_yellow2;
			setTimer1(500);
		}
		break;
	case SET_YELLOW1_YELLOW2:
		if(timer1_flag == 1){
			setTimer1(500);
			blink_yellow();
		}
		// increase time
		if(is_button_pressed_once(1) || is_button_pressed_hold(1)){
			time_yellow1++;
			if(time_yellow1 > 9){
				time_yellow1 = 0;
			}
			time_yellow2 = time_yellow1;
			time_red2 = time_green1 + time_yellow1;
			if(time_red2 > 9) {
				time_red2 = 9;
				time_yellow1 = time_red2 - time_green1;
				time_yellow2 = time_yellow1;
			}
			time_red1 = time_green2 + time_yellow2;
			if(time_red1 > 9) {
				time_red1 = 9;
				time_yellow2 = time_red1 - time_green2;
				time_yellow1 = time_yellow2;
			}
			time_road1 = time_yellow1;
			time_road2 = time_yellow2;
		}
		// decrease time
		if(is_button_pressed_once(2) || is_button_pressed_hold(2)){
			time_yellow1--;
			if(time_yellow1 < 0){
				time_yellow1 = 9;
			}
			time_yellow2 = time_yellow1;
			time_red2 = time_green1 + time_yellow1;
			if(time_red2 > 9) {
				time_red2 = 9;
				time_yellow1 = time_red2 - time_green1;
				time_yellow2 = time_yellow1;
			}
			time_red1 = time_green2 + time_yellow2;
			if(time_red1 > 9) {
				time_red1 = 9;
				time_yellow2 = time_red1 - time_green2;
				time_yellow1 = time_yellow2;
			}
			time_road1 = time_yellow1;
			time_road2 = time_yellow2;
		}
		if(is_button_pressed_once(0)){
			turning_mode_state = SET_GREEN1_RED2;
			display_green1_red2();
			time_road1 = time_green1;
			time_road2 = time_red2;
			setTimer1(500);
		}
		break;
	case SET_GREEN1_RED2:
		if(timer1_flag == 1){
			setTimer1(500);
			blink_green1_red2();
		}
		// increase time
		if(is_button_pressed_once(1) || is_button_pressed_hold(1)){
			time_red2++;
			if(time_red2 > 9){
				time_red2 = 0;
			}
			time_green1 = time_red2 - time_yellow1;
			if(time_green1 < 0) {
				time_red2 = time_yellow1;
				time_green1 = 0;
			}
			time_road1 = time_green1;
			time_road2 = time_red2;
		}
		// decrease time
		if(is_button_pressed_once(2) || is_button_pressed_hold(2)){
			time_red2--;
			if(time_red2 < 0){
				time_red2 = 9;
			}
			time_green1 = time_red2 - time_yellow1;
			if(time_green1 < 0){
				time_red2 = time_yellow1;
				time_green1 = 0;
			}
			time_road1 = time_green1;
			time_road2 = time_red2;
		}
		if(is_button_pressed_once(0)){
			turning_mode_state = SET_RED1_GREEN2;
			display_red1_green2();
			time_road1 = time_red1;
			time_road2 = time_green2;
			setTimer1(500);
		}
		break;
	default:
		break;
	}
}


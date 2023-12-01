/*
 * light_traffic_fsm.c
 *
 *  Created on: Dec 1, 2023
 *      Author: ASUS TUF GAMING
 */
#include "light_traffic_fsm.h"

void light_traffic_fsm(){
	switch(status){
	case INIT:
		status = NORMAL_MODE;
		normal_mode_state = RED1_GREEN2;
		time_road1 = time_red1;
		time_road2 = time_green2;
		setTimer1(1000);
		setTimer2(500);
		break;
	case NORMAL_MODE:
		normal_mode_fsm();
		control_led_7seg();
		if(is_button_pressed_hold(0)){
			status = BLINK_YELLOW_MODE;
			turn_on_yellow();
			turn_off_led_7seg();
			setTimer1(500);
		}
		break;
	case BLINK_YELLOW_MODE:
		if(timer1_flag == 1){
			setTimer1(500);
			blink_yellow();
		}
		if(is_button_pressed_hold(0)){
			status = TURNING_MODE;
			reset_all_button();
			turning_mode_state = SET_RED1_GREEN2;
			display_red1_green2();
			time_road1 = time_red1;
			time_road2 = time_green2;
			setTimer1(500);
			setTimer2(500);
		}
		break;
	case TURNING_MODE:
		turning_mode_fsm();
		control_led_7seg();
		if(is_button_pressed_hold(0)){
			status = NORMAL_MODE;
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


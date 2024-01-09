/*
 * control_led_matrix.c
 *
 *  Created on: Oct 1, 2023
 *      Author: ASUS TUF GAMING
 */

#include "control_led_matrix.h"
int index_led = 1;
int trans = 0;

void scan_matrix(){
	  if (index_led >= 9){
		  index_led = 1;
	  }
	  if (timer1_flag == 1){
		  setTimer1(2); //10ms
		  displayLedMatrix(trans, index_led);
		  index_led++;
	  }
	  if(timer2_flag == 1){
		  trans++;
		  setTimer2(500);//500ms
		  if(trans >= 14){
			  trans = 0;
		  }
	  }
}

void set_state(){
	  index_led = 0;
	  trans = 0;
	  setTimer1(2);//10ms
	  setTimer2(500);//500ms
}

void controlLedMatrix(){
	switch (status) {
		case INIT:
			status = NORMAL_MODE;
			set_state();
			mode_char = A;
			mode_animation = stable;
			break;
		case NORMAL_MODE:
			 scan_matrix();
			 led_normal_on();
			  if(is_button_pressed_once(0) || is_button_pressed_hold(0)){
				  status = SET_CHAR;
				  set_state();
				  reset_all_button();
			  }
			  break;
		case SET_CHAR:
			 scan_matrix();
			 led_char_on();
			  if(is_button_pressed_once(0) || is_button_pressed_hold(0)){
				  status = SET_ANIMATION;
				  set_state();
			  }
			  if(is_button_pressed_once(1) || is_button_pressed_hold(1)){
				  mode_char++;
				  if(mode_char > last_char) mode_char = first_char;
				  set_state();
			  }
			  break;
		case SET_ANIMATION:
			 scan_matrix();
			 led_ani_on();
			  if(is_button_pressed_once(0) || is_button_pressed_hold(0)){
				  status = NORMAL_MODE;
				  set_state();
			  }
			  if(is_button_pressed_once(1) || is_button_pressed_hold(1)){
				  mode_animation++;
				  if(mode_animation > last_ani) mode_animation = first_ani;
				  set_state();
			  }
			break;
		default:
			break;
	}
}
/*
 * button.h
 *
 *  Created on: Sep 30, 2023
 *      Author: ASUS TUF GAMING
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "software_timer.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET
#define num_buttons 3

void get_key_input_all();

// set up more function of button if more than 3 buttons

int is_button_pressed_once(int n);
int is_button_pressed_hold(int n);
void reset_all_button();
/////////////////////////
#endif /* INC_BUTTON_H_ */

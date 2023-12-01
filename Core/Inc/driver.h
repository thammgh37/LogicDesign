/*
 * driver.h
 *
 *  Created on: Dec 1, 2023
 *      Author: ASUS TUF GAMING
 */

#ifndef INC_DRIVER_H_
#define INC_DRIVER_H_

#include "main.h"
#include "software_timer.h"
#include "global.h"
void display_red1_green2();
void display_red1_yellow2();
void display_green1_red2();
void display_yellow1_red2();
void blink_yellow();
void turn_on_yellow();
void blink_red1_green2();
void blink_green1_red2();
void display_led_7seg(int num);
void control_led_7seg();
void turn_off_led_7seg();
#endif /* INC_DRIVER_H_ */

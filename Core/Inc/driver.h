/*
 * led_matrix_driver.h
 *
 *  Created on: Dec 3, 2023
 *      Author: ASUS TUF GAMING
 */

#ifndef INC_DRIVER_H_
#define INC_DRIVER_H_
#include "main.h"

void display_col(int col);
void display_row(uint8_t buffer);

void led_normal_on();
void led_char_on();
void led_ani_on();

#endif /* INC_DRIVER_H_ */

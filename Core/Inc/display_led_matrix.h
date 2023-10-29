/*
 * display_led_matrix.h
 *
 *  Created on: Oct 1, 2023
 *      Author: ASUS TUF GAMING
 */

#ifndef INC_DISPLAY_LED_MATRIX_H_
#define INC_DISPLAY_LED_MATRIX_H_
#include "main.h"
#include "software_timer.h"
#include "global.h"

#define first_color 10
#define red 10
#define green 11
#define last_color 11
#define yellow 12


#define first_ani 13
#define stable 13
#define run 14
#define last_ani 14

#define first_char 15
#define A 15
#define B 16
#define last_char 16

extern int mode_char;
extern int mode_animation;
extern int mode_color;

void displayLedMatrix(int index1, int index2);


#endif /* INC_DISPLAY_LED_MATRIX_H_ */

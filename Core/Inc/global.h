/*
 * global.h
 *
 *  Created on: Sep 29, 2023
 *      Author: ASUS TUF GAMING
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define INIT 0
#define NORMAL_MODE 2
#define SET_CHAR 3
#define SET_ANIMATION 4
#define SET_COLOR 5

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

extern int status;

#endif /* INC_GLOBAL_H_ */

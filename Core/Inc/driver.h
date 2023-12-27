/*
 * driver.h
 *
 *  Created on: Dec 27, 2023
 *      Author: phongtran
 */

#ifndef INC_DRIVER_H_
#define INC_DRIVER_H_

#include "main.h"
#include "fsm_clock.h"

void offAllLedMode();
void changeLedMode();
// ======= LED CLOCK =========
void clearAllCLock();
void setNumberOnClock(int);
void clearNumberOnClock(int);
#endif /* INC_DRIVER_H_ */

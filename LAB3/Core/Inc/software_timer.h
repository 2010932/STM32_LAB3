/*
 * software_timer.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Admin
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"

extern int timer1_flag,timer2_flag,timer3_flag,timer4_flag;

void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void setTimer4(int duration);
void timeRun();

#endif /* INC_SOFTWARE_TIMER_H_ */

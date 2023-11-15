/*
 * global.h
 *
 *  Created on: Nov 9, 2023
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include <input_reading.h>
#include "software_timer.h"
#include "display7SEG.h"

#define INIT 0
#define RED13_GREEN24 1
#define RED13_AMBER24 2
#define GREEN13_RED24 3
#define AMBER13_RED24 4

#define NORMAL 11
#define SET_TIME_RED 12
#define SET_TIME_AMBER 13
#define SET_TIME_GREEN 14

extern int state,current_state;
extern int time_red,time_amber,time_green;
extern int index_led;
extern int mode;
extern int counter_red, counter_amber, counter_green;
extern int countRed1,countRed2,countAmber1,countAmber2,countGreen1,countGreen2;

void clear_led_red_amber_green();

#endif /* INC_GLOBAL_H_ */

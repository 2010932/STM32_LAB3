/*
 * fsm_mode4.c
 *
 *  Created on: Nov 14, 2023
 *      Author: Admin
 */

#include "fsm_mode4.h"

void fsm_mode4(){
	if (timer1_flag == 1){
		setTimer1(250);
		HAL_GPIO_TogglePin(GPIOA, GREEN13_Pin | GREEN24_Pin);
	}
	if (timer2_flag == 1){
		update7SEG_mode_234( counter_green,4);
		index_led++;
		if (index_led>=4) index_led=0;
		setTimer2(250);
	}
	if (isButton2Pressed() == 1){
		counter_green++;
		if (counter_green >= 100) counter_green = 1;
	}

	if (isButton3Pressed() == 1){
		time_green = counter_green;
		countGreen1 = counter_green;
		countGreen2 = counter_green;
	}

	if (isButton1Pressed() == 1){
		mode = NORMAL;
		clear_led_red_amber_green();
		index_led = 0;
		if (( time_amber +  time_green ) != time_red){
			state = INIT;
		}
		if (( time_amber + time_green) == time_red){
			state = RED13_GREEN24;
		}
	}
}

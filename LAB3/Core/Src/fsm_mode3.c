/*
 * fsm_mode3.c
 *
 *  Created on: Nov 13, 2023
 *      Author: Admin
 */

#include "fsm_mode3.h"

void fsm_mode3(){
	if (timer1_flag == 1){
		setTimer1(250);
		HAL_GPIO_TogglePin(GPIOA, AMBER13_Pin | AMBER24_Pin);
	}
	if (timer2_flag == 1){
		update7SEG_mode_234( counter_amber,3);
		index_led++;
		if (index_led>=4) index_led=0;
		setTimer2(250);
	}
	if (isButton1Pressed() == 1){
		mode = SET_TIME_GREEN;
		clear_led_red_amber_green();
		index_led = 0;
	}

	if (isButton2Pressed() == 1){
		counter_amber++;
		if (counter_amber >= 100) counter_amber = 1;
	}

	if (isButton3Pressed() == 1){
		time_amber = counter_amber;
		countAmber1 = counter_amber;
		countAmber2 = counter_amber;
	}
}

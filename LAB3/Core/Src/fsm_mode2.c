/*
 * fsm_mode2.c
 *
 *  Created on: Nov 13, 2023
 *      Author: Admin
 */

#include "fsm_mode2.h"

void fsm_mode2(){
	if (timer1_flag == 1){
		setTimer1(250);
		HAL_GPIO_TogglePin(GPIOA, RED13_Pin | RED24_Pin);
	}

	if (timer2_flag == 1){
		update7SEG_mode_234( counter_red,2);
		index_led++;
		if (index_led>=4) index_led=0;
		setTimer2(250);
	}

	if (isButton1Pressed() == 1){
		mode = SET_TIME_AMBER;
		clear_led_red_amber_green();
		index_led = 0;
	}

	if (isButton2Pressed() == 1){
		counter_red++;
		if (counter_red >= 100) counter_red = 1;
	}

	if (isButton3Pressed() == 1){
		time_red = counter_red;
		countRed1 = counter_red;
		countRed2 = counter_red;
	}
}

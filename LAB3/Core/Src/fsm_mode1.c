/*
 * fsm_mode1.c
 *
 *  Created on: Nov 11, 2023
 *      Author: Admin
 */

#include "fsm_mode1.h"

void fsm_mode1(){
	if (timer2_flag == 1){
			update7SEG_mode_1(index_led);
			index_led++;
			if (index_led>=4) index_led=0;
			setTimer2(250);
		}

	if (timer1_flag == 1){
		setTimer1(1000);
		clear_led_red_amber_green();
		switch (state){
			case INIT:
				HAL_GPIO_WritePin(GPIOA, RED13_Pin | RED24_Pin | AMBER13_Pin | AMBER24_Pin  | GREEN13_Pin | GREEN24_Pin  , SET);
				break;
			case RED13_GREEN24:
			  	HAL_GPIO_WritePin(GPIOA, RED13_Pin | GREEN24_Pin , SET);
			  	time_red--;
			  	time_green--;
			  	if (time_green <= 0){
			  		state = RED13_AMBER24;
			  	}
			  	break;
			case RED13_AMBER24:
			  	HAL_GPIO_WritePin(GPIOA, RED13_Pin | AMBER24_Pin , SET);
			  	time_red--;
			  	time_amber--;
			  	if (time_amber <= 0){
			  		state = GREEN13_RED24;
			  		time_red = 5;
			  		time_amber = 2;
			  		time_green = 3;
			  	}
			  	break;
			 case GREEN13_RED24:
			  	HAL_GPIO_WritePin(GPIOA, RED24_Pin | GREEN13_Pin , SET);
			  	time_red--;
			  	time_green--;
			  	if (time_green <= 0){
			  		state = AMBER13_RED24;
			  	}
			  	break;
			 case AMBER13_RED24:
				HAL_GPIO_WritePin(GPIOA, RED24_Pin | AMBER13_Pin , SET);
				time_red--;
			  	time_amber--;
			  	if (time_amber <= 0){
			  		state = RED13_GREEN24;
			  		time_red = 5;
			  		time_amber = 2;
			  		time_green = 3;
			  	}
			  	break;
			}
		current_state = state;
	}
	if (isButton1Pressed() == 1){
		mode = SET_TIME_RED;
		index_led = 0;
		clear_led_red_amber_green();
	}
}

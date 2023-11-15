/*
 * global.c
 *
 *  Created on: Nov 9, 2023
 *      Author: Admin
 */
#include "global.h"

int current_state;
int state = RED13_GREEN24;
int mode = NORMAL;
int time_red = 5;
int time_amber = 2;
int time_green = 3;
int counter_red = 5, counter_amber = 2, counter_green = 3;
int countRed1 = 5, countAmber1 = 2, countGreen1 = 3, countRed2 = 5, countAmber2 = 2, countGreen2 = 3;
void clear_led_red_amber_green(){
          	HAL_GPIO_WritePin(GPIOA, RED13_Pin | RED24_Pin | AMBER13_Pin | AMBER24_Pin  | GREEN13_Pin | GREEN24_Pin  , RESET);
}

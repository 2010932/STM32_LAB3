/*
 * display7SEG.c
 *
 *  Created on: Nov 11, 2023
 *      Author: Admin
 */

#include "display7SEG.h"


int led_buffer_1 [4] = {0,5,0,3};
int led_buffer_2 [4] = {};
int index_led = 0;

void display7SEG( int num ){
      char LED7SEG [10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90 };
      for ( int i = 0; i < 7; ++ i) {
      HAL_GPIO_WritePin ( GPIOB , GPIO_PIN_0 << i , ( LED7SEG [num ] >> i ) & 1) ;
      }
}

void clear_led_7seg(){
          	HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN2_Pin | EN3_Pin | EN4_Pin , SET);
}

//void update7SEG_mode_1(){
//	clear_led_7seg();
//	if (timer3_flag ==1){
//		switch (state){
//			case INIT:
//				led_buffer_1 [0] = 0;
//				led_buffer_1 [1] = 0;
//				led_buffer_1 [2] = 0;
//				led_buffer_1 [3] = 0;
//			case RED13_GREEN24:
//				led_buffer_1 [0] = counter_red / 10;
//				led_buffer_1 [1] = counter_red % 10;
//				led_buffer_1 [2] = counter_green / 10;
//				led_buffer_1 [3] = counter_green % 10;
//				break;
//			case RED13_AMBER24:
//				led_buffer_1 [0] = counter_red / 10;
//				led_buffer_1 [1] = counter_red % 10;
//				led_buffer_1 [2] = counter_amber / 10;
//				led_buffer_1 [3] = counter_amber % 10;
//				break;
//			case GREEN13_RED24:
//				led_buffer_1 [0] = counter_green / 10;
//				led_buffer_1 [1] = counter_green % 10;
//				led_buffer_1 [2] = counter_red / 10;
//				led_buffer_1 [3] = counter_red % 10;
//				break;
//			case AMBER13_RED24:
//				led_buffer_1 [0] = counter_amber / 10;
//				led_buffer_1 [1] = counter_amber % 10;
//				led_buffer_1 [2] = counter_red / 10;
//				led_buffer_1 [3] = counter_red % 10;
//				break;
//		}
//	}
//
//	switch (index_led){
//  	  	  case 0:
//  	  		  display7SEG(led_buffer_1 [0]);
//  	  		  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
//  	  		  break;
//  	  	  case 1:
//  	  		  display7SEG(led_buffer_1 [1]);
//  	  		  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
//  	  		  break;
//  	  	  case 2:
//  	  		  display7SEG(led_buffer_1 [2]);
//  	  	      HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
//  	  		  break;
//  	  	  case 3:
//  	  		  display7SEG(led_buffer_1 [3]);
//  	  		  HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, RESET);
//  	  		  break;
//  	  	  default:
//  	  		  break;
//		}
// }

void update7SEG_mode_1(int index_led){
	clear_led_7seg();
	if (state == INIT){
		led_buffer_1[0] = 0;
		led_buffer_1[1] = 0;
		led_buffer_1[2] = 0;
		led_buffer_1[3] = 0;
	}else{
		if (timer3_flag == 1){
			led_buffer_1[0] = countRed1 / 10;
			led_buffer_1[1] = countRed1 % 10;
			countRed1--;
			if (countRed1 < 0){
			led_buffer_1[0] = countGreen1 / 10;
			led_buffer_1[1] = countGreen1 % 10;
			countGreen1--;
			}
			if (countGreen1 < 0){
			led_buffer_1[0] = countAmber1 / 10;
			led_buffer_1[1] = countAmber1 % 10;
			countAmber1--;
			}
			if (countAmber1 == 0){
				countRed1 = counter_red;
				countGreen1 = counter_green;
				countAmber1 = counter_amber;
			}
			setTimer3(1000);
			}
		if (timer4_flag == 1){
			led_buffer_1[2] = countGreen2 / 10;
			led_buffer_1[3] = countGreen2 % 10;
			countGreen2--;
			if (countGreen2 < 0){
			led_buffer_1[2] = countAmber2 / 10;
			led_buffer_1[3] = countAmber2 % 10;
			countAmber2--;
			}
			if (countAmber2 < 0){
			led_buffer_1[2] = countRed2 / 10;
			led_buffer_1[3] = countRed2 % 10;
			countRed2--;
			}
			if (countRed2 == 0){
				countRed2 = counter_red;
				countGreen2 = counter_green;
				countAmber2= counter_amber;
			}
			setTimer4(1000);
		}
	  }
	switch (index_led){
  	  	  case 0:
  	  		  display7SEG(led_buffer_1[0]);
  	  		  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
  	  		  break;
  	  	  case 1:
  	  		  display7SEG(led_buffer_1[1]);
  	  		  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
  	  		  break;
  	  	  case 2:
  	  		  display7SEG(led_buffer_1[2]);
  	  	      HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
  	  		  break;
  	  	  case 3:
  	  		  display7SEG(led_buffer_1[3]);
  	  		  HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, RESET);
  	  		  break;
  	  	  default:
  	  		  break;
  	  }
    }
void update7SEG_mode_234(int num1, int num2){
	clear_led_7seg();
	led_buffer_2 [0] = num1/10;
	led_buffer_2 [1] = num1%10;
	led_buffer_2 [2] = num2/10;
	led_buffer_2 [3] = num2%10;

	switch (index_led){
	  	  	  case 0:
	  	  		  display7SEG(led_buffer_2 [0]);
	  	  		  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
	  	  		  break;
	  	  	  case 1:
	  	  		  display7SEG(led_buffer_2 [1]);
	  	  		  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
	  	  		  break;
	  	  	  case 2:
	  	  		  display7SEG(led_buffer_2 [2]);
	  	  	      HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
	  	  		  break;
	  	  	  case 3:
	  	  		  display7SEG(led_buffer_2 [3]);
	  	  		  HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, RESET);
	  	  		  break;
	  	  	  default:
	  	  		  break;
			}
}


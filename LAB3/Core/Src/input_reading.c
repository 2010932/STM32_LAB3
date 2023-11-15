/*
 * button.c
 *
 *  Created on: Nov 13, 2023
 *      Author: Admin
 */

#include <input_reading.h>
#include "main.h"

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;

int KeyReg01 = NORMAL_STATE;
int KeyReg11 = NORMAL_STATE;
int KeyReg21 = NORMAL_STATE;
int KeyReg31 = NORMAL_STATE;

int KeyReg02 = NORMAL_STATE;
int KeyReg12 = NORMAL_STATE;
int KeyReg22 = NORMAL_STATE;
int KeyReg32 = NORMAL_STATE;

int TimeOutForKeyPress =  100;

int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}
int isButton2Pressed(){
	if(button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	return 0;
}
int isButton3Pressed(){
	if(button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess1(){
	button1_flag = 1;
}

void subKeyProcess2(){
	button2_flag = 1;
}

void subKeyProcess3(){
	button3_flag = 1;
}


void getKeyInput(){
  KeyReg2 = KeyReg1;
  KeyReg1 = KeyReg0;
  KeyReg21 = KeyReg11;
  KeyReg11 = KeyReg01;
  KeyReg22 = KeyReg12;
  KeyReg12 = KeyReg02;

  KeyReg0  = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
  KeyReg01 = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);
  KeyReg02 = HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin);

  if ((KeyReg1 == KeyReg0) && (KeyReg1 == KeyReg2)){
     if (KeyReg2 != KeyReg3){
     KeyReg3 = KeyReg2;
     if (KeyReg3 == PRESSED_STATE){
        TimeOutForKeyPress = 100;
        subKeyProcess1();
        }
     }else{
        TimeOutForKeyPress --;
        if (TimeOutForKeyPress == 0){
        TimeOutForKeyPress = 100;
        if (KeyReg3 == PRESSED_STATE){
        	mode = NORMAL ;
        	state = current_state;
         	}
         }
      }
   }

   if ((KeyReg11 == KeyReg01) && (KeyReg11 == KeyReg21)){
      if (KeyReg21 != KeyReg31){
      KeyReg31 = KeyReg21;
      if (KeyReg31 == PRESSED_STATE){
         TimeOutForKeyPress = 100;
         subKeyProcess2();
         }
      }
    }

    if ((KeyReg12 == KeyReg02) && (KeyReg12 == KeyReg22)){
        if (KeyReg22 != KeyReg32){
        KeyReg32 = KeyReg22;
        if (KeyReg32 == PRESSED_STATE){
            TimeOutForKeyPress = 100;
            subKeyProcess3();
        	}
        }else{
            TimeOutForKeyPress --;
            if (TimeOutForKeyPress == 0){
            TimeOutForKeyPress = 100;
            if (KeyReg32 == PRESSED_STATE){
                subKeyProcess3();
                }
            }
         }
    }
}

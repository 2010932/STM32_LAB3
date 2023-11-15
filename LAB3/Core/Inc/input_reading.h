/*
 * button.h
 *
 *  Created on: Nov 13, 2023
 *      Author: Admin
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include "global.h"
#include "main.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

extern int button1_flag;
extern int button2_flag;
extern int button3_flag;

int isButton1Pressed();
int isButton2Pressed();
int isButton3Pressed();

void getKeyInput();


#endif /* INC_INPUT_READING_H_ */

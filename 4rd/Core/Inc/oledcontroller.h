/*
 * oledcontroller.h
 *
 *  Created on: 2023. 5. 18.
 *      Author: 82106
 */

#ifndef INC_OLEDCONTROLLER_H_
#define INC_OLEDCONTROLLER_H_

#include "ssd1306.h"
#include "controlType.h"

void opening();
void printDefault();
void printTemper(int temper);
void toggleScreen();
void startToggle();
void printHeaterState(ON_OFF_t onOff);
void printBackground();

#endif /* INC_OLEDCONTROLLER_H_ */

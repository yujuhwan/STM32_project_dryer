/*
 * heaterController.h
 *
 *  Created on: Apr 7, 2023
 *      Author: 82106
 */

#ifndef INC_HEATERCONTROLLER_H_
#define INC_HEATERCONTROLLER_H_

#include "main.h"
#include "controlType.h"
#include "defines.h"
uint8_t getHeaterState();
void heaterOnOff(uint8_t onOff);

void setDesiredTemper(void);

int getDesiredTemper(void);

void heaterControl(float temper);
void temper_up(void);
void temper_down(void);

void setFixedTemper(void);
int getFixedTemper(void);


#endif /* INC_HEATERCONTROLLER_H_ */

#include "heaterController.h"
#include "oledController.h"
#include "ledController.h"

static uint8_t m_state = 0;


//static int m_before_temper = 0;

static int m_desired_temper = DEFAULT_TEMPER;
static int m_fixed_temper = DEFAULT_TEMPER;

void initHeater(){
	m_state=0;
	heaterOnOff(OFF_t);
}

void heaterControl(float temper){

	if(m_state){

		if((int)temper >= (m_fixed_temper - GOING_UP_GAP)){
				heaterOnOff(OFF_t);
		}
	}else{
		if((int)temper <  m_fixed_temper - GOING_DOWN_GAP){
			heaterOnOff(ON_t);
		}
	}


}

void temper_up(){

	m_desired_temper++;
	if(m_desired_temper > 99){
		m_desired_temper = 0;
	}
	printTemper(m_desired_temper);

}

void temper_down(){

	m_desired_temper--;
	if(m_desired_temper < 0){
		m_desired_temper = 99;
	}
	printTemper(m_desired_temper);

}



void setFixedTemper(){
	m_fixed_temper = m_desired_temper;
}

int getFixedTemper(void){
	return m_desired_temper;
}


void heaterOnOff(uint8_t onOff){

	HAL_GPIO_WritePin(PB5_RELAY_ON_OFF_CTRL_GPIO_Port, PB5_RELAY_ON_OFF_CTRL_Pin,onOff);
	m_state = onOff;

	if(onOff == ON_t){
		led2OnOff(ON_t);
		printHeaterState(ON_t);
	}else{
		led2OnOff(OFF_t);
		printHeaterState(OFF_t);
	}

}


uint8_t getHeaterState(){
	return m_state;
}

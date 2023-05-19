#include "fnd_controller.h"

uint8_t _LED_0F[29];
static SPI_HandleTypeDef * m_hspi;

void init_fnd(SPI_HandleTypeDef * hspi) {
	_LED_0F[0] = 0xC0; //0
	_LED_0F[1] = 0xF9; //1
	_LED_0F[2] = 0xA4; //2
	_LED_0F[3] = 0xB0; //3
	_LED_0F[4] = 0x99; //4
	_LED_0F[5] = 0x92; //5
	_LED_0F[6] = 0x82; //6
	_LED_0F[7] = 0xF8; //7
	_LED_0F[8] = 0x80; //8
	_LED_0F[9] = 0x90; //9
	_LED_0F[10] = 0x88; //A
	_LED_0F[11] = 0x83; //b
	_LED_0F[12] = 0xC6; //C
	_LED_0F[13] = 0xA1; //d
	_LED_0F[14] = 0x86; //E
	_LED_0F[15] = 0x8E; //F
	_LED_0F[16] = 0xC2; //G
	_LED_0F[17] = 0x89; //H
	_LED_0F[18] = 0xF9; //I
	_LED_0F[19] = 0xF1; //J
	_LED_0F[20] = 0xC3; //L
	_LED_0F[21] = 0xA9; //n
	_LED_0F[22] = 0xC0; //O
	_LED_0F[23] = 0x8C; //P
	_LED_0F[24] = 0x98; //q
	_LED_0F[25] = 0x92; //S
	_LED_0F[26] = 0xC1; //U
	_LED_0F[27] = 0x91; //Y
	_LED_0F[28] = 0xFE; //hight -
	m_hspi = hspi;
}

void send(uint8_t X) {

	/*for (int i = 8; i >= 1; i--) {
		if (X & 0x80) {
			HAL_GPIO_WritePin(FND_DIO_GPIO_Port, FND_DIO_Pin, HIGH);
		} else {
			HAL_GPIO_WritePin(FND_DIO_GPIO_Port, FND_DIO_Pin, LOW);
		}
		X <<= 1;
		HAL_GPIO_WritePin(FND_SCLK_GPIO_Port, FND_SCLK_Pin, LOW);
		HAL_GPIO_WritePin(FND_SCLK_GPIO_Port, FND_SCLK_Pin, HIGH);
	}*/
	HAL_SPI_Transmit(m_hspi, &X, 1, 100);
}


 void send_port(uint8_t X, uint8_t port)
 {
 send(X);
 send(port);
 HAL_GPIO_WritePin(FND_RCLK_GPIO_Port, FND_RCLK_Pin, LOW);
 HAL_GPIO_WritePin(FND_RCLK_GPIO_Port, FND_RCLK_Pin, HIGH);
 }



void digit4_show(int n, int replay, uint8_t showZero) {
	int n1, n2, n3, n4;

	n1 = (int) n % 10;
	n2 = (int) ((n % 100)) / 10;
	n3 = (int) ((n % 1000)) / 100;
	n4 = (int) ((n % 10000)) / 1000;

	for (int i = 0; i <= replay; i++) {
		send_port(_LED_0F[n1], 0b0001);
		if (showZero | n > 9){
			send_port(_LED_0F[n2], 0b0010);
		}
		if (showZero | n > 99){
			send_port(_LED_0F[n3], 0b0100);
		}
		if (showZero | n > 999){
			send_port(_LED_0F[n4], 0b1000);
		}
	}
}

static uint8_t m_tempercount = 0;
void digit4_temper(int temper) {
	int n1, n2, n3, n4;

	n1 = (int) temper % 10;
	n2 = (int) ((temper % 100)) / 10;
	n3 = (int) ((temper)) / 100;
	n4 = (int) ((temper)) / 1000;

	switch (m_tempercount) {

	case 0:
		send_port(_LED_0F[n1], 0b0001); //0
		break;
	case 1:
		send_port(_LED_0F[n2] & 0x7F, 0b0010); //1
		break;
	case 2:
		if (temper > 99) {
			send_port(_LED_0F[n3], 0b0100);
		}
		break;
	case 3:
		if (temper > 999) {
			send_port(_LED_0F[n4], 0b1000);
		}
		break;
	default:
		break;
	}

	m_tempercount++;

	if (temper > 999 && m_tempercount >= 4) {
		m_tempercount = 0;
	}else if(temper > 99 && m_tempercount >= 3){
		m_tempercount = 0;
	}else if(temper <= 99 && m_tempercount >= 2){
		m_tempercount = 0;
	}

}

void digit4_replay(int n, int replay) {
	digit4_show(n, replay, false);
}

void digit4(int n) {
	digit4_show(n, 0, false);
}

void digit4showZero_replay(int n, int replay) {
	digit4_show(n, replay, true);
}

void digit4showZero(int n) {
	digit4_show(n, 0, true);
}

void digit2(int n, int port, int replay) {
	int n1, n2;
	n1 = (int) n % 10;
	n2 = (int) ((n % 100) - n1) / 10;

	for (int i = 0; i <= replay; i++) {
		send_port(_LED_0F[n1], port);
		send_port(_LED_0F[n2], port << 1);
	}
}

void digit2_port(int n, int port) {
	digit2(n, port, 0);
}

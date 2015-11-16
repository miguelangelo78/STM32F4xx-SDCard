#include "stm32f4xx.h"

/* Port handling macros: */
#define PA(val) GPIOA->ODR = val;
#define PAB(pin, val) GPIO_WriteBit(GPIOA, (pin), (val));
#define PAI(pin) GPIO_ReadInputData(GPIOA);
#define PABI(pin) GPIO_ReadInputDataBit(GPIOA, (pin));

/* SPI Pin definitions: (PORTA) */
#define MOSI 	GPIO_Pin_7 	/* PA7, OUTPUT */
#define MISO 	GPIO_Pin_6 	/* PA6, INPUT */
#define SCK 	GPIO_Pin_5 	/* PA5, OUTPUT */
#define CS 		GPIO_Pin_4 	/* PA4, OUTPUT */

/* Helper Macros: */
#define SD_SET_CS() 	PAB(CS, 1)
#define SD_CLEAR_CS() 	PAB(CS, 0)

void init_port() {
	GPIO_InitTypeDef port_out = {
		.GPIO_Pin = MOSI | SCK | CS,
		.GPIO_Mode = GPIO_Mode_OUT,
		.GPIO_OType = GPIO_OType_PP,
		.GPIO_PuPd = GPIO_PuPd_DOWN,
		.GPIO_Speed = GPIO_Speed_100MHz
	};
	GPIO_InitTypeDef port_in = {
		.GPIO_Pin = MISO | GPIO_Pin_0,
		.GPIO_Mode = GPIO_Mode_IN,
		.GPIO_OType = GPIO_OType_PP,
		.GPIO_PuPd = GPIO_PuPd_DOWN,
		.GPIO_Speed = GPIO_Speed_100MHz
	};

	/* Initialize only PORTA: */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	GPIO_Init(GPIOA, &port_out);
	GPIO_Init(GPIOA, &port_in);
}

int main(void) {
	init_port();

	for(;;);
}

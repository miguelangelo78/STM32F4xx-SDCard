#include "stm32f4xx.h"
#include "defines.h"
#include "tm_stm32f4_delay.h"
#include "tm_stm32f4_fatfs.h"
#include <stdio.h>
#include <string.h>
#include "port.h"

int main(void) {
	FATFS fs;

	SystemInit();

	if(f_mount(&fs, "", 1) == FR_OK) {
		init_gpio(GPIOD, GPIO_PIN_12 | GPIO_Pin_13 | GPIO_Pin_14, 0);
		GPIO_WriteBit(GPIOD, GPIO_Pin_12, 1);

		f_mount(0, "", 1);
	} else {
		init_gpio(GPIOD, GPIO_PIN_12 | GPIO_Pin_13 | GPIO_Pin_14, 0);
		GPIO_WriteBit(GPIOD, GPIO_Pin_14, 1);
	}

	GPIO_WriteBit(GPIOD, GPIO_Pin_13, 1);
	while (1);
}

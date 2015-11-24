/*
 * port.h
 *
 *  Created on: Nov 16, 2015
 *      Author: Miguel
 */

#ifndef PORT_H_
#define PORT_H_

/* Port handling macros: */
#define PA(val) GPIOA->ODR = val; /* Output to port */
#define PAB(pin, val) GPIO_WriteBit(GPIOA, (pin), (val)); /* Output to port's pin */
#define PAI(pin) GPIO_ReadInputData(GPIOA); /* Read entire port */
#define PABI(pin) GPIO_ReadInputDataBit(GPIOA, (pin)); /* Read port's pin */

/* General purpose Port initializer function (one port at a time): */
inline void init_gpio(GPIO_TypeDef * gpio, uint32_t out_pins, uint32_t in_pins) {
	/* Default Port initializations: */
	GPIO_InitTypeDef port_out = {
		.GPIO_Pin = out_pins,
		.GPIO_Mode = GPIO_Mode_OUT,
		.GPIO_OType = GPIO_OType_PP,
		.GPIO_PuPd = GPIO_PuPd_DOWN,
		.GPIO_Speed = GPIO_Speed_100MHz
	};
	GPIO_InitTypeDef port_in = {
		.GPIO_Pin = in_pins,
		.GPIO_Mode = GPIO_Mode_IN,
		.GPIO_OType = GPIO_OType_PP,
		.GPIO_PuPd = GPIO_PuPd_DOWN,
		.GPIO_Speed = GPIO_Speed_100MHz
	};

	/* Initialize port: */
	switch((uint32_t)gpio) {
	case (uint32_t)GPIOA: RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); break;
	case (uint32_t)GPIOB: RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE); break;
	case (uint32_t)GPIOC: RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE); break;
	case (uint32_t)GPIOD: RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE); break;
	case (uint32_t)GPIOE: RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE); break;
	case (uint32_t)GPIOF: RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE); break;
	case (uint32_t)GPIOG: RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE); break;
	case (uint32_t)GPIOH: RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH, ENABLE); break;
	case (uint32_t)GPIOI: RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOI, ENABLE); break;
	}

	if(out_pins) /* Won't initialize if out_pins is 0 */
		GPIO_Init(gpio, &port_out);
	if(in_pins) /* Won't initialize if in_pins is 0 */
		GPIO_Init(gpio, &port_in);
}

#endif /* PORT_H_ */

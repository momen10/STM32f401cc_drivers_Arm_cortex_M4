/*
 * RCC_int.h
 *
 *  Created on: Jun 29, 2023
 *      Author: Mo'men
 */

#ifndef MCAL_RCC_INT_H_
#define MCAL_RCC_INT_H_

typedef enum{
	RCC_AHB1 ,
	RCC_AHB2,
	RCC_APB1,
	RCC_APB2
}RCC_BusId_t;

typedef enum{
	GPIO_A,
	GPIO_B,
	GPIO_C,
	GPIO_D,
	GPIO_E,
	GPIOH =7,
	CRC = 12,
	DMA1=21,
	DMA2=22,
	OTGFS = 7,
	TIM2=0,
	TIM3,
	TIM4,
	TIM5,
	WWDG = 11,
	SPI2 = 14,
	SPI3,
	USART2 = 17,
	I2C1 = 21,
	I2C2,
	I2C3,
	PWR = 28,
	TIM1=0,
	USART1 = 4,
	USART6,
	ADC1 = 8,
	SDIO = 11,
	SPI1,
	SPI4,
	SYSCFG,
	TIM9 = 16,
	TIM10,
	TIM11
}RCC_PerId_t;

void MRCC_vInit(void);
void MRCC_vEnableClock(RCC_BusId_t copy_Bus_ID , RCC_PerId_t copy_Per_ID);
void MRCC_vDisableClock(RCC_BusId_t copy_Bus_ID , RCC_PerId_t copy_Per_ID);
#endif /* MCAL_RCC_INT_H_ */

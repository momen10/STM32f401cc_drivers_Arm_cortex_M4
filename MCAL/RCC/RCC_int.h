/*
 * NAME :RCC_int.h
 *
 * Created on: Jun 29, 2023
 *
 * Author: Mo'men Ahmed
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
RCC_GPIO_A,
RCC_GPIO_B,
RCC_GPIO_C,
RCC_GPIO_D,
RCC_GPIO_E,
RCC_GPIOH =7,
RCC_CRC = 12,
RCC_DMA1=21,
RCC_DMA2=22,
RCC_OTGFS = 7,
RCC_TIM2=0,
RCC_TIM3,
RCC_TIM4,
RCC_TIM5,
RCC_WWDG = 11,
RCC_SPI2 = 14,
RCC_SPI3,
RCC_USART2 = 17,
RCC_I2C1 = 21,
RCC_I2C2,
RCC_I2C3,
RCC_PWR = 28,
RCC_TIM1=0,
RCC_USART1 = 4,
RCC_USART6,
RCC_ADC1 = 8,
RCC_SDIO = 11,
RCC_SPI1,
RCC_SPI4,
RCC_SYSCFG,
RCC_TIM9 = 16,
RCC_TIM10,
RCC_TIM11
}RCC_PerId_t;

void MRCC_vInit(void);
void MRCC_vEnableClock(RCC_BusId_t copy_Bus_ID , RCC_PerId_t copy_Per_ID);
void MRCC_vDisableClock(RCC_BusId_t copy_Bus_ID , RCC_PerId_t copy_Per_ID);
#endif /* MCAL_RCC_INT_H_ */

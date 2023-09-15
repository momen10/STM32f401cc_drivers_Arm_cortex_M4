/*
 * NAME :GPIO_prv.h
 *
 * Created on: Jul 3, 2023
 *
 * Author: Mo'men Ahmed
 */

#ifndef MCAL_GPIO_GPIO_PRV_H_
#define MCAL_GPIO_GPIO_PRV_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#define GPIOA_BASE_ADDR     0x40020000
#define GPIOB_BASE_ADDR     0x40020400
#define GPIOC_BASE_ADDR     0x40020800

typedef struct{
  u32 MODER;
  u32 OTYPER;
  u32 OSPEEDER;
  u32 PUPDR;
  u32 IDR;
  u32 ODR;
  u32 BSRR;
  u32 LCKR;
  u32 AFRL;
  u32 AFRH;
}GPIO_MemMap_t;


#define GPIOA  ((volatile GPIO_MemMap_t*) (GPIOA_BASE_ADDR) )
#define GPIOB  ((volatile GPIO_MemMap_t*) (GPIOB_BASE_ADDR) )
#define GPIOC  ((volatile GPIO_MemMap_t*) (GPIOC_BASE_ADDR) )

typedef enum{
	Digital_input,    Digital_output,
	Alternative_func, Analog_input
}GPIO_Mode_t;

typedef enum{
	Push_pull, Open_drain
}GPIO_OutType_t;

typedef enum{
	Low , Medium,
	High, Very_high
}GPIO_OutSpeed_t;

typedef enum{
	No_resistor, Pull_up,
	Pull_down
}GPIO_InputPullType_t;

typedef enum{
	AF0,  AF1,   AF2,  AF3,
	AF4,  AF5,   AF6,  AF7,
	AF8,  AF9,   AF10, AF11,
	AF12, AF13,  AF14, AF15,
	Not_AF
}GPIO_AlternativeFunctions_t;


typedef enum{
	LOGIC_ZERO, LOGIC_ONE
}GPIO_PinValues_t;

#endif /* MCAL_GPIO_GPIO_PRV_H_ */

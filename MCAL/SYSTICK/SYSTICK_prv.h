/*
 * NAME :SYSTICK_prv.h
 *
 * Created on: Jul 17, 2023
 *
 * Author: Mo'men Ahmed
 */
#include "../../LIB/STD_TYPES.h"

#ifndef MCAL_SYSTICK_SYSTICK_PRV_H_
#define MCAL_SYSTICK_SYSTICK_PRV_H_

#define STK_BASE_ADDR 0xE000E010

#define ENABLE_BIT     0
#define TICKINT_BIT    1
#define CLKSOURCE_BIT  2
#define COUNT_FLAG_BIT 16

#define STK_AHB_8     0
#define STK_AHB       1

#define STK_INT_EN    1
#define STK_INT_DIS   0

#define TICKS_ONE_SEC 		1000UL
#define TICKS_HALF_SEC 		500UL
#define TICKS_ONE_MILLI_SEC 1000
#define TICKS_ONE_MICRO_SEC 1

typedef struct{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
}STK_MemMap_t;

#define SYSTICK ((volatile STK_MemMap_t*)(STK_BASE_ADDR))

#endif /* MCAL_SYSTICK_SYSTICK_PRV_H_ */

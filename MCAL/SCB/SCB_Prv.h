/*
 * NAME :SCB_Prv.h
 *
 * Created on: Sep 5, 2023
 *
 * Author: Mo'men Ahmed
 */

#ifndef MCAL_SCB_SCB_PRV_H_
#define MCAL_SCB_SCB_PRV_H_

#include "../../LIB/STD_TYPES.h"

#define SCB_BASE_ADDRESS   0xE000ED00

typedef struct{
	volatile u32 CPUID;
	volatile u32 ICSR;
	volatile u32 VTOR;
	volatile u32 AIRCR;
	volatile u32 SCR;
	volatile u32 CCR;
	volatile u32 SHPR[3];
    volatile u32 SHCSR;
    volatile u32 CFSR;
    volatile u32 HFSR;
    volatile u32 MMAR;
    volatile u32 BFAR;
    volatile u32 AFSR;
}SCB_MemMap_t;

#define SCB ((volatile SCB_MemMap_t*)(SCB_BASE_ADDRESS))



#endif /* MCAL_SCB_SCB_PRV_H_ */

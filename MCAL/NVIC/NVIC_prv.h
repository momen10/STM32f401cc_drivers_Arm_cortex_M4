/*
   NAME        : NVIC_prv.h

   AUTHOR      : MO'MEN AHMED
   
   DATE        : 8/8/2023
   
   DESCRIPTION : Private header file for NVIC driver 
 */

#ifndef MCAL_NVIC_NVIC_PRV_H_
#define MCAL_NVIC_NVIC_PRV_H_
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#define NVIC_BASE_ADDR    0xE000E100
#define AIRCR_VECTKEY     0x05fa
#define SCB_BASE_ADDR     0xE000ED00

//We have some registers are repeated 7 times but there are 25 locations
//(25*4 bytes) are memory reserved so I have to make an array of 32 location
typedef struct {
	u32 ISER[32];
	u32 ICER[32];
	u32 ISPR[32];
	u32 ICPR[32];
	u32 IABR[32];
	u32 reserved[32];
	u8 IPR[84];
//	u8 IPR[128];
}NVIC_MemMap_t;

typedef struct {
	u32 CPUID;
	u32 ICSR;
	u32 VTOR;
	u32 AIRCR;
	u32 SCR;
	u32 CCR;
	u32 SHPR1;
	u32 SHPR2;
	u32 SHPR3;
	u32 SHCSR;
	u32 CFSR;
	u32 HFSR;
	u32 reserved;
	u32 MMAR;
	u32 BFAR;
	u32 AFSR;
}SCB_MemMap_t;

#define NVIC   ((volatile NVIC_MemMap_t *)(NVIC_BASE_ADDR))

#define SCB    ((volatile SCB_MemMap_t*)(SCB_BASE_ADDR))

#endif /* MCAL_NVIC_NVIC_PRV_H_ */

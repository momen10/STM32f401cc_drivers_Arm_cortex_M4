/*
 * Name : NVIC_prog.c
 *
 * Date : Jul 5, 2023
 *
 * Author : Mo'men
 *
 * Description : Private Header file for EXTI module
 */

#ifndef MCAL_EXTI_EXTI_PRV_H_
#define MCAL_EXTI_EXTI_PRV_H_

#define EXTI_BASE_ADDR    0x40013C00
#define SYSCFG_BASE_ADDR  0x40013800

typedef struct{
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}MEXTI_MemMap_t;

#define EXTI   ((volatile MEXTI_MemMap_t *)(EXTI_BASE_ADDR))

typedef struct{
	u32 MEMRMP;
	u32 PMC;
	u32 EXTICR[4];
	u16 reserved;
	u32 CMPCR;
}MSYSCFG_MemMap_t;

#define SYSCFG  ((volatile MSYSCFG_MemMap_t*)(SYSCFG_BASE_ADDR))


#endif /* MCAL_EXTI_EXTI_PRV_H_ */

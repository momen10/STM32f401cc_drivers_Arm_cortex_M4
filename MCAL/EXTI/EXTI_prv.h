/*
 * NAME: EXTI_prv.h
 *
 * Created on: Jul 17, 2023
 *
 * Author: Mo'men Ahmed
 */

#ifndef MCAL_EXTI_EXTI_PRV_H_
#define MCAL_EXTI_EXTI_PRV_H_

#define EXTI_BASE_ADDR   0x40013C00

typedef struct{
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}MEXTI_MemMap_t;

#define EXTI   ((volatile MEXTI_MemMap_t *)(EXTI_BASE_ADDR))


#endif /* MCAL_EXTI_EXTI_PRV_H_ */

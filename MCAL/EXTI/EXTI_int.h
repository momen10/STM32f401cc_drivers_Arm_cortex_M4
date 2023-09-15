/*
 * NAME: EXTI_int.h
 *
 * Created on: Jul 17, 2023
 *
 * Author: Mo'men Ahmed
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

typedef enum{
	Rising_edge, Falling_edge , On_change
}MEXTI_TriggerOption_t;

typedef enum{
	EXTI_LIN0,
	EXTI_LIN1,
	EXTI_LIN2,
	EXTI_LIN3,
	EXTI_LIN4,
	EXTI_LIN5,
	EXTI_LIN6,
	EXTI_LIN7,
	EXTI_LIN8,
	EXTI_LIN9,
	EXTI_LIN10,
	EXTI_LIN11,
	EXTI_LIN12,
	EXTI_LIN13,
	EXTI_LIN14,
	EXTI_LIN15,
}MEXTI_LineNum_t;

typedef enum{
 EXTI_Port_A,
 EXTI_Port_B,
 EXTI_Port_C
}EXTI_Port_t;

void MEXTI_vInit(void);
void MEXTI_vEnableLine (u8 A_u8LineNo , MEXTI_TriggerOption_t trigger_option);
void MEXTI_vDisableLine (u8 A_u8LineNo );
void MEXTI_vSoftwareTrigger(u8 A_u8LineNo);
void MEXTI_vSetTriggerOption(u8 A_u8LineNo , MEXTI_TriggerOption_t trigger_option);
void MEXTI_vSetCallBack (MEXTI_LineNum_t A_enLineNo ,void (*A_ptrCallBack)(void));
void MEXTI_vSetPortConfig (MEXTI_LineNum_t A_enLineNo, EXTI_Port_t Port_ID );

#endif /* MCAL_EXTI_EXTI_INT_H_ */

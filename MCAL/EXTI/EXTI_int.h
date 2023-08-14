/*
 * Name : NVIC_prog.c
 *
 * Date : Jul 5, 2023
 *
 * Author : Mo'men
 *
 * Description : Interface Header file for EXTI module
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
	EXTI_PORTA, EXTI_PORTB,
	EXTI_PORTC, EXTI_PORTD
}EXTI_PORT_ID;

void MEXTI_vInit(void);
void MEXTI_vEnableLine (MEXTI_LineNum_t A_enLineNo , MEXTI_TriggerOption_t trigger_option);
void MEXTI_vDisableLine (MEXTI_LineNum_t A_enLineNo );
void MEXTI_vSoftwareTrigger(MEXTI_LineNum_t A_enLineNo);
void MEXTI_vClearPendingFlag(MEXTI_LineNum_t A_enLineNo);
void MEXTI_vSetTriggerOption(MEXTI_LineNum_t A_enLineNo , MEXTI_TriggerOption_t trigger_option);
void MEXTI_vSetCallBack (MEXTI_LineNum_t A_enLineNo ,void (*A_ptrCallBack)(void));
void MEXTI_vSetPort(EXTI_PORT_ID A_enPort_ID , MEXTI_LineNum_t A_enLineNo);

#endif /* MCAL_EXTI_EXTI_INT_H_ */

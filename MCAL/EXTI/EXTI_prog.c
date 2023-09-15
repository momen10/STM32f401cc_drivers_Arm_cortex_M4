/*
 * NAME: EXTI_prog.c
 *
 * Created on: Jul 17, 2023
 *
 * Author: Mo'men Ahmed
 */

#include "EXTI_cfg.h"
#include "EXTI_int.h"
#include "EXTI_prv.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "SYSCFG_prv.h"

static volatile void (*EXTI_LINE0_PTR) (void);
static volatile void (*EXTI_LINE1_PTR) (void);
static volatile void (*EXTI_LINE2_PTR) (void);
static volatile void (*EXTI_LINE3_PTR) (void);
static volatile void (*EXTI_LINE4_PTR) (void);
static volatile void (*EXTI_LINE5_PTR) (void);


void MEXTI_vInit(void)
{
	//clear all pending flags:
	EXTI->PR =0xffffffff;
}

void MEXTI_vEnableLine (MEXTI_LineNum_t A_enLineNo , MEXTI_TriggerOption_t A_enTriggerOption)
{
	//input validation:
	if (A_enLineNo >15)
	{

	}
	else
	{
		SET_BIT(EXTI ->IMR , A_enLineNo);
		switch(A_enTriggerOption)
		{
		case (Rising_edge):
				SET_BIT(EXTI ->RTSR , A_enLineNo);
		        CLR_BIT(EXTI ->FTSR , A_enLineNo);
				break;
		case(Falling_edge):
				SET_BIT(EXTI ->FTSR , A_enLineNo);
				CLR_BIT(EXTI ->RTSR , A_enLineNo);
				break;
		case(On_change):
				SET_BIT(EXTI ->RTSR , A_enLineNo);
				SET_BIT(EXTI ->FTSR , A_enLineNo);
				break;
		}
	}

}
void MEXTI_vDisableLine (MEXTI_LineNum_t A_enLineNo)
{
	if (A_enLineNo > 15)
	{

	}
	else
	{
	  CLR_BIT(EXTI ->IMR , A_enLineNo);
	}
}
void MEXTI_vSoftwareTrigger(u8 A_u8LineNo)
{
	if(A_u8LineNo < 16)
	{
		SET_BIT( EXTI ->SWIER , A_u8LineNo );
	}
	else{

	}
}
void MEXTI_vSetTriggerOption(MEXTI_LineNum_t A_enLineNo , MEXTI_TriggerOption_t A_enTriggerOption)
{
	if (A_enLineNo >15)
	{

	}
	else
	{
		switch(A_enTriggerOption)
		{
		case (Rising_edge):
				SET_BIT(EXTI ->RTSR , A_enLineNo);
		        CLR_BIT(EXTI ->FTSR , A_enLineNo);
				break;
		case(Falling_edge):
				SET_BIT(EXTI ->FTSR , A_enLineNo);
				CLR_BIT(EXTI ->RTSR , A_enLineNo);
				break;
		case(On_change):
				SET_BIT(EXTI ->RTSR , A_enLineNo);
				SET_BIT(EXTI ->FTSR , A_enLineNo);
				break;
		}
	}
}

void MEXTI_vSetCallBack (MEXTI_LineNum_t A_enLineNo, void (*A_ptrCallBack)(void))
{
	switch (A_enLineNo)
	{
	case EXTI_LIN0:
		EXTI_LINE0_PTR = A_ptrCallBack ;
		break;
	case EXTI_LIN1:
		EXTI_LINE1_PTR = A_ptrCallBack ;
		break;
	case EXTI_LIN2:
		EXTI_LINE2_PTR = A_ptrCallBack ;
		break;
	case EXTI_LIN3:
		EXTI_LINE3_PTR = A_ptrCallBack ;
		break;
	case EXTI_LIN4:
		EXTI_LINE4_PTR = A_ptrCallBack ;
		break;
	case EXTI_LIN5:
		EXTI_LINE5_PTR = A_ptrCallBack ;
		break;
	}
}

//interrupt handler (ISR)
volatile u8 interrupts =0;
void EXTI0_IRQHandler (void)
{
	if(EXTI_LINE0_PTR != NULL)
	{
		interrupts++;
		(*EXTI_LINE0_PTR)();
		MEXTI_vInit();
	}
}

void MEXTI_vSetPortConfig (MEXTI_LineNum_t A_enLineNo, EXTI_Port_t Port_ID )
{
	u8 L_u8Index = A_enLineNo/4;
	u8 L_u8ShiftingValue = ((A_enLineNo %4) *4);
	u8 L_u8MaskingValue = 0b1111;
//first, clean the required 4 bits:
	SYSCFG ->EXTICR[L_u8Index] &= ~(L_u8MaskingValue << L_u8ShiftingValue);
//then insert the required port number.
	SYSCFG ->EXTICR[L_u8Index] |= (Port_ID << L_u8ShiftingValue);

}

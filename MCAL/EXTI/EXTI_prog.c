/*
 * Name : NVIC_prog.c
 *
 * Date : Jul 5, 2023
 *
 * Author : Mo'men
 *
 * Description : Program Source file for EXTI module
 */

#include "EXTI_cfg.h"
#include "EXTI_int.h"
#include "EXTI_prv.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

static volatile void (*EXTI_LINE_PTR[16]) (void);
//static volatile void (*EXTI_LINE1_PTR) (void);
//static volatile void (*EXTI_LINE2_PTR) (void);
//static volatile void (*EXTI_LINE3_PTR) (void);
//static volatile void (*EXTI_LINE4_PTR) (void);
//static volatile void (*EXTI_LINE5_PTR) (void);


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

void MEXTI_vClearPendingFlag(MEXTI_LineNum_t A_enLineNo)
{
	SET_BIT(EXTI->PR , A_enLineNo);
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
	EXTI_LINE_PTR[A_enLineNo] = A_ptrCallBack ;
}

void MEXTI_vSetPort(EXTI_PORT_ID A_enPort_ID , MEXTI_LineNum_t A_enLineNo)
{
	//CLEARING THE REQUIRED 4 BITS
   SYSCFG->EXTICR[A_enLineNo/4] &= ~(0b1111      << 4*(A_enLineNo % 4) );
	//INSERTING THE REQUIRED PORT
   SYSCFG->EXTICR[A_enLineNo/4] |=  (A_enPort_ID << 4*(A_enLineNo % 4));
}


//interrupt handler (ISR)
void EXTI0_IRQHandler (void)
{
	MEXTI_vClearPendingFlag(EXTI_LIN0);
	if(EXTI_LINE_PTR[0] != NULL)
	{
		(*EXTI_LINE_PTR[0])();
	}
}

void EXTI1_IRQHandler (void)
{
	MEXTI_vClearPendingFlag(EXTI_LIN1);
	if(EXTI_LINE_PTR[1] != NULL)
	{
		(*EXTI_LINE_PTR[1])();
	}
}

void EXTI2_IRQHandler (void)
{
	MEXTI_vClearPendingFlag(EXTI_LIN2);
	if(EXTI_LINE_PTR[2] != NULL)
	{
		(*EXTI_LINE_PTR[2])();
	}
}

void EXTI3_IRQHandler (void)
{
	MEXTI_vClearPendingFlag(EXTI_LIN3);
	if(EXTI_LINE_PTR[3] != NULL)
	{
		(*EXTI_LINE_PTR[3])();
	}
}

void EXTI4_IRQHandler (void)
{
	MEXTI_vClearPendingFlag(EXTI_LIN4);
	if(EXTI_LINE_PTR[4] != NULL)
	{
		(*EXTI_LINE_PTR[4])();
	}
}

void EXTI9_5_IRQHandler (void)
{
	if (GET_BIT(EXTI->PR, 5) == 1)
	{
		MEXTI_vClearPendingFlag(EXTI_LIN5);
		if(EXTI_LINE_PTR[5] != NULL)
		{
		  (*EXTI_LINE_PTR[5])();
		}
	}
	else if (GET_BIT(EXTI->PR, 6) == 1)
	{
		MEXTI_vClearPendingFlag(EXTI_LIN6);
		if(EXTI_LINE_PTR[6] != NULL)
		{
		  (*EXTI_LINE_PTR[6])();
		}
	}
	else if (GET_BIT(EXTI->PR, 7) == 1)
	{
		MEXTI_vClearPendingFlag(EXTI_LIN7);
		if(EXTI_LINE_PTR[7] != NULL)
		{
		  (*EXTI_LINE_PTR[7])();
		}
	}
	else if (GET_BIT(EXTI->PR, 8) == 1)
	{
		MEXTI_vClearPendingFlag(EXTI_LIN8);
		if(EXTI_LINE_PTR[8] != NULL)
		{
		  (*EXTI_LINE_PTR[8])();
		}
	}
	else if (GET_BIT(EXTI->PR, 9) == 1)
	{
		MEXTI_vClearPendingFlag(EXTI_LIN9);
		if(EXTI_LINE_PTR[9] != NULL)
		{
		  (*EXTI_LINE_PTR[9])();
		}
	}
}

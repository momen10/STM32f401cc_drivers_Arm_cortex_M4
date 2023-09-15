/*
 * NAME :SYSTICK_prog.c
 *
 * Created on: Jul 17, 2023
 *
 * Author: Mo'men Ahmed
 */

#ifndef MCAL_SYSTICK_SYSTICJ_PROG_C_
#define MCAL_SYSTICK_SYSTICJ_PROG_C_

#include "SYSTICK_cfg.h"
#include "SYSTICK_prv.h"
#include "SYSTICK_int.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

static volatile void (*STK_CallBackPTR) (void) = NULL;
static u8 SingleFlag;

void MSTK_vInit(void)
{
#if STK_CLK_SOURCE == STK_AHB_8
	CLR_BIT(SYSTICK -> CTRL , CLKSOURCE_BIT );
#elif STK_CLK_SOURCE == STK_AHB
	SET_BIT(SYSTICK -> CTRL , CLKSOURCE_BIT );
#endif

#if STK_INT_OPTION == STK_INT_EN
	 SET_BIT(SYSTICK ->CTRL, TICKINT_BIT);
#elif STK_INT_OPTION == STK_INT_DIS
	 CLR_BIT(SYSTICK ->CTRL, TICKINT_BIT);
#endif
}
void MSTK_vStartTimer(u32 A_u32PreloadValue)
{
	//enabling the peripheral
 SET_BIT(SYSTICK ->CTRL, ENABLE_BIT);
 SYSTICK->LOAD = ((A_u32PreloadValue-1) & 0x00ffffff);
}

void MSTK_vStopTimer(void)
{
	//Disabling the peripheral
 CLR_BIT(SYSTICK ->CTRL, ENABLE_BIT);
}

void MSTK_vDelayms(u32 A_u32DelayMilliSec)
{
	//let the HSI = 16MHZ , AHB = 16 MHz
	//AHB/8 = 2MHZ , Ttick = 0.5 microsec
	 //load the value
	//1- WRITE ANY VALUE TO VALUE REG TO RESET IT
	 SYSTICK -> VAL  = 0;

	 //2-ADD LOAD VALUE
	 SYSTICK->LOAD =  (((A_u32DelayMilliSec * TICKS_ONE_MILLI_SEC)-1) & 0x00ffffff);

	 //3- START TIMER
	 SET_BIT(SYSTICK ->CTRL, ENABLE_BIT);

	 //4-POLLING
	 while(GET_BIT(SYSTICK->CTRL,COUNT_FLAG_BIT) != 1){}

	 //5- STOP TIMER
	 MSTK_vStopTimer();
}

void MSTK_vSetIntervalSingle(u32 A_u32DelayMilliSec, void (*CallBackFunc) (void))
{
	//0- SET CALLBACK FUNCTION
	 STK_CallBackPTR = CallBackFunc;
	//1- WRITE ANY VALUE TO VALUE REG TO RESET IT
	 SYSTICK -> VAL  = 0;

	 //2-ADD LOAD VALUE
	 SYSTICK -> LOAD =  (((A_u32DelayMilliSec * TICKS_ONE_MILLI_SEC)-1) & 0x00ffffff);

	 //3- START TIMER
	 SET_BIT(SYSTICK ->CTRL, ENABLE_BIT);

	 SingleFlag =1;
}
void MSTK_vSetIntervalPeriodic(u32 A_u32DelayMilliSec, void (*CallBackFunc) (void))
{
	SingleFlag =0;
	//0- SET CALLBACK FUNCTION
	MSTK_vSetCallBack(CallBackFunc);

	//1- RESET THE VALUE OF TIMER
	 SYSTICK ->VAL =0;

	//2-ADD LOAD VALUE
	 SYSTICK->LOAD = (((A_u32DelayMilliSec * TICKS_ONE_MILLI_SEC)-1) & 0x00ffffff);

	 //3- START TIMER
	 SET_BIT(SYSTICK ->CTRL, ENABLE_BIT);
}
u32 MSTK_u32GetElapsedTime (void)
{
	u32 L_u32ElapsedTicks = SYSTICK ->LOAD - SYSTICK->VAL;
	return (L_u32ElapsedTicks);
}
u32 MSTK_u32GetRemainingTime (void)
{
	u32 L_u32RemainingTicks = SYSTICK->VAL;
	return L_u32RemainingTicks;
}

void MSTK_vSetCallBack(void (*copy_ptr)(void))
{
	STK_CallBackPTR = copy_ptr;
}

void SysTick_Handler(void)
{
	if(STK_CallBackPTR != NULL)
	{
		(*STK_CallBackPTR)();
	}
	if (SingleFlag==1)
	{
		//stop the timer:
		SingleFlag = 0;
		MSTK_vStopTimer();
	}
	else
	{
       //PERIODIC, KEEP IT
	}

}

void MSTK_vDelayus(u32 A_u32DelayMicroSec)
{
	//let the HSI = 16MHZ , AHB = 16 MHz
	//AHB/8 = 2MHZ , Ttick = 0.5 microsec
	 //load the value
	//1- WRITE ANY VALUE TO VALUE REG TO RESET IT
	 SYSTICK -> VAL  = 0;

	 //2-ADD LOAD VALUE
	 SYSTICK->LOAD =  (((A_u32DelayMicroSec * TICKS_ONE_MICRO_SEC)-1) & 0x00ffffff);

	 //3- START TIMER
	 SET_BIT(SYSTICK ->CTRL, ENABLE_BIT);

	 //4-POLLING
	 while(GET_BIT(SYSTICK->CTRL,COUNT_FLAG_BIT) != 1){}

	 //5- STOP TIMER
	 MSTK_vStopTimer();
}

void MSTK_vSetIntervalSingleMicro(u32 A_u32DelayMicroSec, void (*CallBackFunc) (void))
{
	//0- SET CALLBACK FUNCTION
	 STK_CallBackPTR = CallBackFunc;
	//1- WRITE ANY VALUE TO VALUE REG TO RESET IT
	 SYSTICK -> VAL  = 0;

	 //2-ADD LOAD VALUE
	 SYSTICK -> LOAD =  (((A_u32DelayMicroSec * TICKS_ONE_MICRO_SEC)-1) & 0x00ffffff);

	 //3- START TIMER
	 SET_BIT(SYSTICK ->CTRL, ENABLE_BIT);

	 SingleFlag =1;
}
void MSTK_vSetIntervalPeriodicMicro(u32 A_u32DelayMicroSec, void (*CallBackFunc) (void))
{
	SingleFlag =0;
	//0- SET CALLBACK FUNCTION
	MSTK_vSetCallBack(CallBackFunc);

	//1- RESET THE VALUE OF TIMER
	 SYSTICK ->VAL =0;

	//2-ADD LOAD VALUE
	 SYSTICK->LOAD = (((A_u32DelayMicroSec * TICKS_ONE_MICRO_SEC)-1) & 0x00ffffff);

	 //3- START TIMER
	 SET_BIT(SYSTICK ->CTRL, ENABLE_BIT);
}
#endif /* MCAL_SYSTICK_SYSTICJ_PROG_C_ */

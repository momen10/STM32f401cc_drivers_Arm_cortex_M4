/*
 * SYSTICJ_prog.c
 *
 *  Created on: Jul 17, 2023
 *      Author: Dell
 */

#ifndef MCAL_SYSTICK_SYSTICJ_PROG_C_
#define MCAL_SYSTICK_SYSTICJ_PROG_C_

#include "SYSTICK_cfg.h"
#include "SYSTICK_prv.h"
#include "SYSTICK_int.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

static volatile void (*STK_CallBackPTR) (void);
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
	 SYSTICK->LOAD = 0;
	 SYSTICK ->VAL =0;

	 SYSTICK->LOAD =  (((A_u32DelayMilliSec * TICKS_ONE_MILLI_SEC)-1) & 0x00ffffff);

	 SET_BIT(SYSTICK ->CTRL, ENABLE_BIT);

	 volatile u8 reading = GET_BIT(SYSTICK->CTRL,COUNT_FLAG_BIT);
	 while(reading != 1){
		 reading = GET_BIT(SYSTICK->CTRL,COUNT_FLAG_BIT);
	 }

	 CLR_BIT(SYSTICK ->CTRL, ENABLE_BIT);
	 SYSTICK->LOAD = 0;
	 SYSTICK ->VAL =0;
}
void MSTK_vSetIntervalSingle(u32 A_u32DelayMilliSec, void (*CallBackFunc) (void))
{
	//enable interrupt
	 SET_BIT(SYSTICK ->CTRL, TICKINT_BIT);

	SingleFlag =1;
	// set the callback function:
	STK_CallBackPTR = CallBackFunc;
	//first : reset the value of timer
	 SYSTICK->LOAD = 0;
	 SYSTICK ->VAL =0;

	 //start the timer
	 SYSTICK->LOAD =  (((A_u32DelayMilliSec * TICKS_ONE_MILLI_SEC)-1) & 0x00ffffff);
	 SET_BIT(SYSTICK ->CTRL, ENABLE_BIT);
// awel mal flag ytrfe3 hayro7 lel handler y3ml code el function

}
void MSTK_vSetIntervalPeriodic(u32 A_u32DelayMilliSec, void (*CallBackFunc) (void))
{
	//enable interrupt
	 SET_BIT(SYSTICK ->CTRL, TICKINT_BIT);
	SingleFlag =0;
	// set the callback function:
	MSTK_vSetCallBack(CallBackFunc);
	//first : reset the value of timer
	 SYSTICK ->VAL =0;
	 //start the timer
	 SYSTICK->LOAD = (A_u32DelayMilliSec * TICKS_ONE_MILLI_SEC)-1;
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
	(*STK_CallBackPTR)();
	if (SingleFlag==1)
	{
		//stop the timer:
		SingleFlag = 0;
		 CLR_BIT(SYSTICK ->CTRL, ENABLE_BIT);
	}
	else
	{

	}
}
#endif /* MCAL_SYSTICK_SYSTICJ_PROG_C_ */

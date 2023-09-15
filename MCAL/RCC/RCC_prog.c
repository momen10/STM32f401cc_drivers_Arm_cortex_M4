/*
 * NAME :RCC_int.h
 *
 * Created on: Jun 29, 2023
 *
 * Author: Mo'men Ahmed
 */
#include "RCC_cfg.h"
#include "RCC_int.h"
#include "RCC_prv.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

//RCC initialization
void MRCC_vInit(void)
{
#if SYSTEM_CLOCK == HSI
	CLR_BIT (RCC -> CFGR , SW0 );
	CLR_BIT (RCC -> CFGR , SW1 );
	SET_BIT (RCC -> CR   , HSION);
#elif SYSTEM_CLOCK == HSE
		  SET_BIT(RCC -> CFGR , SW0);
		  CLR_BIT (RCC -> CFGR , SW1 );
	#if   HSE_BYPASSING == HSE_NOT_BYPASSED
		  CLR_BIT(RCC -> CR   , HSEBYP);
	#elif HSE_BYPASSING == HSE_BYPASSED
		  SET_BIT(RCC -> CR   , HSEBYP);
#endif
	SET_BIT (RCC -> CR   , HSEON);
#elif SYSTEM_CLOCK == PLL
	SET_BIT(RCC -> CFGR , SW1);
//checking P,N,M values
#if  PLLP != 2  && PLLP != 4  && PLLP != 6 && PLLP != 8
#warning "invalid p value"
#endif
#if  PLLN < 192 || PLLN > 432
#warning "invalid N value"
#endif
#if  PLLM < 2 || PLLM > 63
#warning "invalid M value"
#endif

//inserting P value
	(RCC -> PLLCFGR) &= 0xFFFCFFF;  //clearing the required bits
#if   PLLP == 2
	  RCC -> PLLCFGR |= 0<<16       //inserting the required p value
#elif PLLP == 4
      RCC -> PLLCFGR |= 1<<16
#elif PLLP == 6
	  RCC -> PLLCFGR |= 2<<16
#elif PLLP == 8
	  RCC -> PLLCFGR |= 3<<16
#endif

//inserting N value:
	  (RCC -> PLLCFGR) &= FFFF803F; //clearing the required bits
	  RCC -> PLLCFGR |= PLLN << 6;	  //inserting the required N value

//inserting M value
	  (RCC -> PLLCFGR) &= FFFFFFC0
	   RCC -> PLLCFGR |= PLLM ;

//determining PLL input
	  RCC-> PLLCFGR |= PLL_SOURCE << 22;
#else
#error "invalid clock source"
#endif
//DETERMINING AHB PRESCALER
	  RCC -> CFGR &= 0xFFFFFF0F;

	  RCC -> CFGR |= (AHB_PRESCALER << 4);

//DETERMINING APB2 PRESCALER
	  RCC -> CFGR &= ~((u32)(0b111 << 13));
	  RCC -> CFGR |= (APB2_PRESCALER << 13);
}

void MRCC_vEnableClock(RCC_BusId_t copy_Bus_ID , RCC_PerId_t copy_Per_ID)
{
	switch (copy_Bus_ID)
	{
	 case RCC_AHB1: SET_BIT(RCC->AHB1ENR, copy_Per_ID);
		            break;
	 case RCC_AHB2: SET_BIT(RCC->AHB2ENR, copy_Per_ID);
		            break;
	 case RCC_APB1: SET_BIT(RCC->APB1ENR, copy_Per_ID);
		            break;
	 case RCC_APB2: SET_BIT(RCC->APB2ENR, copy_Per_ID);
		            break;
	 default:
		 break; //invalid
	}
}

void MRCC_vDisableClock(RCC_BusId_t copy_Bus_ID , RCC_PerId_t copy_Per_ID)
{
	switch (copy_Bus_ID)
	{
	 case RCC_AHB1: CLR_BIT(RCC->AHB1ENR, copy_Per_ID);
		            break;
	 case RCC_AHB2: CLR_BIT(RCC->AHB2ENR, copy_Per_ID);
		            break;
	 case RCC_APB1: CLR_BIT(RCC->APB1ENR, copy_Per_ID);
		            break;
	 case RCC_APB2: CLR_BIT(RCC->APB2ENR, copy_Per_ID);
		            break;
	 default:
		 break; //invalid
	}
}

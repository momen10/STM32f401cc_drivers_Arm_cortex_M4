/*
 * Name : NVIC_prog.c
 *
 * Date : Jul 5, 2023
 *      Author: Dell
 */

#include "NVIC_int.h"
#include "NVIC_prv.h"
#include "NVIC_cfg.h"

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

void MNVIC_vNvicEnablePerInterrupt(u8 Copy_u8PerID)
{
	u8 register_index = (u8)(Copy_u8PerID / 32);
	NVIC -> ISER[register_index] = 1 << (Copy_u8PerID % 32);
}

void MNVIC_vNvicDisablePerInterrupt(u8 Copy_u8PerID)
{
	u8 register_index = (u8)(Copy_u8PerID / 32);
	NVIC -> ICER[register_index] = 1 << (Copy_u8PerID % 32);
}

void MNVIC_vSetPendingFlag(u8 Copy_u8PerID)
{
	u8 register_index = (u8)(Copy_u8PerID / 32);
	NVIC -> ISPR[register_index] = 1 << (Copy_u8PerID % 32);
}

void MNVIC_vClearPendingFlag(u8 Copy_u8PerID)
{
	u8 register_index = (u8)(Copy_u8PerID / 32);
	NVIC -> ICPR[register_index] = 1 << (Copy_u8PerID % 32);
}

u8 MNVIC_u8GetActiveFlag (u8 Copy_u8PerID)
{
	u8 active_flag;
	u8 register_index = (u8)(Copy_u8PerID / 32);
    active_flag = GET_BIT(NVIC -> IABR[register_index],  (Copy_u8PerID % 32) );
    return active_flag;
}

void MNVIC_vInterruptGroupingConfig(PriorityOptions Copy_enPriorityOption)
{
	//I have to write the vectkey and priority option at same time.
SCB->AIRCR |= ((AIRCR_VECTKEY << 16) | (Copy_enPriorityOption << 8)) ;
}

//Options for priority number : -7 to -1 : internal interrupts
//                              0  to 84 : external interrupts
//options for group priority : 0 to 15
//options for sub priority :   0 to 15
void MNVIC_vSetPriority (s8 Copy_s8PriorityNum, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority  )
{
	u32 local_GroupingOption;
	//reading the three bits of priority option in SCB at AIRCR register
	local_GroupingOption = ((SCB->AIRCR & 0X00000700)>>8);
	u8 Local_u8PriorityData = Copy_u8SubPriority | (Copy_u8GroupPriority<<(local_GroupingOption-3));
	if(Copy_s8PriorityNum<0)
	{
		if(Copy_s8PriorityNum == USAGE_FAULT_PRIORITY ||
		   Copy_s8PriorityNum == MEM_MANAGE_PRIORITY  ||
		   Copy_s8PriorityNum == BUS_FAULT_PRIORITY)
		{
			Copy_s8PriorityNum += 3;    //NOW THEY ARE 0 OR 1 OR 2
			NVIC->ISPR[1] |= (Local_u8PriorityData << (4+ 8*Copy_s8PriorityNum));
		}
		else if(Copy_s8PriorityNum == SV_CALL_PRIORITY)
		{
			Copy_s8PriorityNum += 7;    //NOW IT IS 4
			NVIC->ISPR[2] |= (Local_u8PriorityData << (4+ 8*Copy_s8PriorityNum));
		}
		else if(Copy_s8PriorityNum == SYSTICK_PRIORITY ||
				Copy_s8PriorityNum == PENDSV_PRIORITY)
		{
			Copy_s8PriorityNum += 8;    //NOW THEY ARE  2 OR 3
			NVIC->ISPR[3] |= (Local_u8PriorityData << (4+ 8*Copy_s8PriorityNum));
		}
	}
	else
	{
		NVIC->IPR[Copy_s8PriorityNum] = Local_u8PriorityData << 4;
	}
}




/*
 * NVIC_prog.c
 *
 *  Created on: Jul 5, 2023
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
	u8 local_GroupingOption;
	//reading the three bits of priority option in SCB at AIRCR register
	local_GroupingOption = (SCB->AIRCR & 0X00000700);
	if(Copy_s8PriorityNum<0)
	{
		if (local_GroupingOption == four_bits_group)
		{
			if (Copy_s8PriorityNum == MEM_MANAGE_PRIORITY)
			{
				Copy_s8PriorityNum += 7;
				SCB ->SHPR1 |= (Copy_u8GroupPriority <<4);
			}
			else if(Copy_s8PriorityNum == BUS_FAULT_PRIORITY)
			{
				Copy_s8PriorityNum += 6;
				SCB ->SHPR1 |= (Copy_u8GroupPriority <<12);
			}
			else if (Copy_s8PriorityNum == USAGE_FAULT_PRIORITY)
			{
				Copy_s8PriorityNum += 5;
				SCB ->SHPR1 |= (Copy_u8GroupPriority <<20);
			}
			else if (Copy_s8PriorityNum == SV_CALL_PRIORITY)
			{
				Copy_s8PriorityNum += 4;
				SCB ->SHPR2 |= (Copy_u8GroupPriority <<28);
			}
			else if (Copy_s8PriorityNum == SYSTICK_PRIORITY)
			{
				Copy_s8PriorityNum += 1;
				SCB ->SHPR3 |= (Copy_u8GroupPriority <<28);
			}
		}
		else if (local_GroupingOption ==three_bits_group_one_sub)
		{
			if (Copy_s8PriorityNum == MEM_MANAGE_PRIORITY)
			{
				Copy_s8PriorityNum += 7;
				SCB ->SHPR1 |= (Copy_u8GroupPriority <<5)
							| (Copy_u8SubPriority <<4);
			}
			else if(Copy_s8PriorityNum == BUS_FAULT_PRIORITY)
			{
				Copy_s8PriorityNum += 6;
				SCB ->SHPR1 |= (Copy_u8GroupPriority <<13)
							| (Copy_u8SubPriority <<12);
			}
			else if (Copy_s8PriorityNum == USAGE_FAULT_PRIORITY)
			{
				Copy_s8PriorityNum += 5;
				SCB ->SHPR1 |= (Copy_u8GroupPriority <<21)
							| (Copy_u8SubPriority <<20);
			}
			else if (Copy_s8PriorityNum == SV_CALL_PRIORITY)
			{
				Copy_s8PriorityNum += 4;
				SCB ->SHPR2 |= (Copy_u8GroupPriority <<29)
						    | (Copy_u8SubPriority <<28);
			}
			else if (Copy_s8PriorityNum == SYSTICK_PRIORITY)
			{
				Copy_s8PriorityNum += 1;
				SCB ->SHPR3 |= (Copy_u8GroupPriority <<29)
							| (Copy_u8SubPriority <<28);
			}

		}
		else if (local_GroupingOption == two_bits_group_two_sub)
		{
			if (Copy_s8PriorityNum == MEM_MANAGE_PRIORITY)
			{
				Copy_s8PriorityNum += 7;
				SCB ->SHPR1 |= (Copy_u8GroupPriority <<6)
										| (Copy_u8SubPriority <<4);
			}
			else if(Copy_s8PriorityNum == BUS_FAULT_PRIORITY)
			{
				Copy_s8PriorityNum += 6;
				SCB ->SHPR1 |= (Copy_u8GroupPriority <<14)
										| (Copy_u8SubPriority <<12);
			}
			else if (Copy_s8PriorityNum == USAGE_FAULT_PRIORITY)
			{
				Copy_s8PriorityNum += 5;
				SCB ->SHPR1 |= (Copy_u8GroupPriority <<22)
										| (Copy_u8SubPriority <<20);
			}
			else if (Copy_s8PriorityNum == SV_CALL_PRIORITY)
			{
				Copy_s8PriorityNum += 4;
				SCB ->SHPR2 |= (Copy_u8GroupPriority <<30)
							    		| (Copy_u8SubPriority <<28);
			}
			else if (Copy_s8PriorityNum == SYSTICK_PRIORITY)
			{
				Copy_s8PriorityNum += 1;
				SCB ->SHPR3 |= (Copy_u8GroupPriority <<30)
										| (Copy_u8SubPriority <<28);
			}
		}
		else if (local_GroupingOption == one_bit_group_three_sub)
		{
			if (Copy_s8PriorityNum == MEM_MANAGE_PRIORITY)
			{
				Copy_s8PriorityNum += 7;
				SCB ->SHPR1 |= (Copy_u8GroupPriority <<7)
										| (Copy_u8SubPriority <<4);
			}
			else if(Copy_s8PriorityNum == BUS_FAULT_PRIORITY)
			{
				Copy_s8PriorityNum += 6;
				SCB ->SHPR1 |= (Copy_u8GroupPriority <<15)
										| (Copy_u8SubPriority <<12);
			}
			else if (Copy_s8PriorityNum == USAGE_FAULT_PRIORITY)
			{
				Copy_s8PriorityNum += 5;
				SCB ->SHPR1 |= (Copy_u8GroupPriority <<23)
										| (Copy_u8SubPriority <<20);
			}
			else if (Copy_s8PriorityNum == SV_CALL_PRIORITY)
			{
				Copy_s8PriorityNum += 4;
				SCB ->SHPR2 |= (Copy_u8GroupPriority <<31)
							    		| (Copy_u8SubPriority <<28);
			}
			else if (Copy_s8PriorityNum == SYSTICK_PRIORITY)
			{
				Copy_s8PriorityNum += 1;
				SCB ->SHPR3 |= (Copy_u8GroupPriority <<31)
										| (Copy_u8SubPriority <<28);
			}

		}
		else if (local_GroupingOption == four_bits_sub)
		{
			if (Copy_s8PriorityNum == MEM_MANAGE_PRIORITY)
			{
				Copy_s8PriorityNum += 7;
				SCB ->SHPR1 |= (Copy_u8SubPriority <<4);
			}
			else if(Copy_s8PriorityNum == BUS_FAULT_PRIORITY)
			{
				Copy_s8PriorityNum += 6;
				SCB ->SHPR1 |= (Copy_u8SubPriority <<12);
			}
			else if (Copy_s8PriorityNum == USAGE_FAULT_PRIORITY)
			{
				Copy_s8PriorityNum += 5;
				SCB ->SHPR1 |= (Copy_u8SubPriority <<20);
			}
			else if (Copy_s8PriorityNum == SV_CALL_PRIORITY)
			{
				Copy_s8PriorityNum += 4;
				SCB ->SHPR2 |= (Copy_u8SubPriority <<28);
			}
			else if (Copy_s8PriorityNum == SYSTICK_PRIORITY)
			{
				Copy_s8PriorityNum += 1;
				SCB ->SHPR3 |= (Copy_u8SubPriority <<28);
			}
		}
	}
	else
	{
		if (local_GroupingOption == four_bits_group)
		{
			NVIC -> IPR[Copy_s8PriorityNum] = Copy_u8GroupPriority <<4;
		}
		else if (local_GroupingOption ==three_bits_group_one_sub)
		{
			NVIC -> IPR[Copy_s8PriorityNum] = (Copy_u8GroupPriority <<5)
					                        | (Copy_u8SubPriority <<4) ;
		}
		else if (local_GroupingOption == two_bits_group_two_sub)
		{
			NVIC -> IPR[Copy_s8PriorityNum] = (Copy_u8GroupPriority <<6)
					                        | (Copy_u8SubPriority <<4) ;
		}
		else if (local_GroupingOption == one_bit_group_three_sub)
		{
			NVIC -> IPR[Copy_s8PriorityNum] = (Copy_u8GroupPriority <<7)
					                        | (Copy_u8SubPriority <<4) ;
		}
		else if (local_GroupingOption == four_bits_sub)
		{
			NVIC -> IPR[Copy_s8PriorityNum] = Copy_u8SubPriority <<4;
		}
	}
}




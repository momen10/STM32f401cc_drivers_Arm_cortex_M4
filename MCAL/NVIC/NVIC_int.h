/*
 * NVIC_int.h
 *
 *  Created on: Jul 5, 2023
 *      Author: Dell
 */

#ifndef MCAL_NVIC_NVIC_INT_H_
#define MCAL_NVIC_NVIC_INT_H_

#include "../../LIB/STD_TYPES.h"

#define SYSTICK_PRIORITY       -1
#define PENDSV_PRIORITY        -2
#define DEBUG_MONITOR_PRIORITY -3
#define SV_CALL_PRIORITY       -4
#define USAGE_FAULT_PRIORITY   -5
#define BUS_FAULT_PRIORITY     -6
#define MEM_MANAGE_PRIORITY    -7


typedef enum{
	four_bits_group = 3, three_bits_group_one_sub,
	two_bits_group_two_sub,
	one_bit_group_three_sub,
	four_bits_sub
}PriorityOptions;

void MNVIC_vNvicEnablePerInterrupt(u8 Copy_u8PerID);
void MNVIC_vNvicDisablePerInterrupt(u8 Copy_u8PerID);
void MNVIC_vSetPendingFlag(u8 Copy_u8PerID);
void MNVIC_vClearPendingFlag(u8 Copy_u8PerID);
u8 MNVIC_u8GetActiveFlag (u8 Copy_u8PerID);
void MNVIC_vInterruptGroupingConfig(PriorityOptions Copy_enPriorityOption);
void MNVIC_vSetPriority (s8 Copy_s8PriorityNum, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority);


#endif /* MCAL_NVIC_NVIC_INT_H_ */

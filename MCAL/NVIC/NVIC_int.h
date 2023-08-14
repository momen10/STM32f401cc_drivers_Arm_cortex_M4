/*
   NAME : NVIC_int.h

   AUTHOR      : MO'MEN AHMED
   
   DATE        : 8/8/2023
   
   DESCRIPTION : Interface header file for NVIC driver 
 */

#ifndef MCAL_NVIC_NVIC_INT_H_
#define MCAL_NVIC_NVIC_INT_H_

#include "../../LIB/STD_TYPES.h"

#define SYSTICK_PRIORITY       -5
#define PENDSV_PRIORITY        -6

#define SV_CALL_PRIORITY       -4

#define USAGE_FAULT_PRIORITY   -1
#define BUS_FAULT_PRIORITY     -2
#define MEM_MANAGE_PRIORITY    -3

#define EXTI0_POSITION          6


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

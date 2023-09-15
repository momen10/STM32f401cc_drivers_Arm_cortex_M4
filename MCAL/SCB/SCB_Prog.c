/*
 * NAME :SCB_Prog.c
 *
 * Created on: Sep 5, 2023
 *
 * Author: Mo'men Ahmed
 */
#include "../../LIB/STD_TYPES.h"

#include "SCB_Interface.h"
#include "SCB_Prv.h"

void MSCB_vSetResetVectAddress (u32 A_u32Address)
{
    SCB->VTOR = A_u32Address;
}




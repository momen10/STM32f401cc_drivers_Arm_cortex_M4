/*
 * NAME :seven_segment.c
 *
 * Created on: Jul 4, 2023
 *
 * Author: Mo'men Ahmed
 */

#include "seven_segment.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include "../../MCAL/RCC/RCC_int.h"

extern MGPIO_Config_t SevSegm_Pins[SEV_SEG_PINS];

void SevSeg_vInit(void)
{
#if SEV_SEG_METHOD == S2P_METHOD
	Seven_segment_Config_t my_ss ={
			.type = COMMON_CATHODE
	};

#elif SEV_SEG_METHOD == DIRECT_METHOD
	for (u8 i =0 ; i<SEV_SEG_PINS ; i++)
	{
      MGPIO_vInit(&SevSegm_Pins[i]);
	}
	Seven_segment_Config_t my_ss ={
			.type = COMMON_CATHODE
	};

#endif
}


void Led_A_Off(Seven_segment_Config_t* copy_Config_st)
{
	MGPIO_vSetPinFast(copy_Config_st -> A_Port, copy_Config_st -> A_Pin, LOGIC_ZERO);
}
void Led_B_Off(Seven_segment_Config_t* copy_Config_st)
{
	MGPIO_vSetPinFast(copy_Config_st -> B_Port, copy_Config_st -> B_Pin, LOGIC_ZERO);
}
void Led_C_Off(Seven_segment_Config_t* copy_Config_st)
{
	MGPIO_vSetPin(copy_Config_st -> C_Port, copy_Config_st -> C_Pin ,LOGIC_ZERO);
}
void Led_D_Off(Seven_segment_Config_t* copy_Config_st)
{
	MGPIO_vSetPin(copy_Config_st -> D_Port, copy_Config_st -> D_Pin ,LOGIC_ZERO);
}
void Led_E_Off(Seven_segment_Config_t* copy_Config_st)
{
	MGPIO_vSetPin(copy_Config_st -> E_Port, copy_Config_st -> E_Pin, LOGIC_ZERO);
}
void Led_F_Off(Seven_segment_Config_t* copy_Config_st)
{
	MGPIO_vSetPin(copy_Config_st -> F_Port, copy_Config_st -> F_Pin, LOGIC_ZERO);
}
void Led_G_Off(Seven_segment_Config_t* copy_Config_st)
{
	MGPIO_vSetPin(copy_Config_st -> G_Port, copy_Config_st -> G_Pin, LOGIC_ZERO);
}
void Led_Dot_Off(Seven_segment_Config_t* copy_Config_st)
{
	MGPIO_vSetPin(copy_Config_st -> Dot_Port, copy_Config_st -> Dot_Pin, LOGIC_ZERO);
}

void Led_A_On(Seven_segment_Config_t* copy_Config_st)
{
	MGPIO_vSetPin(copy_Config_st -> A_Port, copy_Config_st -> A_Pin, LOGIC_ONE);
}
void Led_B_On(Seven_segment_Config_t* copy_Config_st)
{
	MGPIO_vSetPin(copy_Config_st -> B_Port, copy_Config_st -> B_Pin, LOGIC_ONE);
}
void Led_C_On(Seven_segment_Config_t* copy_Config_st)
{
	MGPIO_vSetPin(copy_Config_st -> C_Port, copy_Config_st -> C_Pin ,LOGIC_ONE);
}
void Led_D_On(Seven_segment_Config_t* copy_Config_st)
{
	MGPIO_vSetPin(copy_Config_st -> D_Port, copy_Config_st -> D_Pin ,LOGIC_ONE);
}
void Led_E_On(Seven_segment_Config_t* copy_Config_st)
{
	MGPIO_vSetPin(copy_Config_st -> E_Port, copy_Config_st -> E_Pin, LOGIC_ONE);
}
void Led_F_On(Seven_segment_Config_t* copy_Config_st)
{
	MGPIO_vSetPin(copy_Config_st -> F_Port, copy_Config_st -> F_Pin, LOGIC_ONE);
}
void Led_G_On(Seven_segment_Config_t* copy_Config_st)
{
	MGPIO_vSetPin(copy_Config_st -> G_Port, copy_Config_st -> G_Pin, LOGIC_ONE);
}
void Led_Dot_On(Seven_segment_Config_t* copy_Config_st)
{
	MGPIO_vSetPin(copy_Config_st -> Dot_Port, copy_Config_st -> Dot_Pin, LOGIC_ONE);
}

void Display_Zero(Seven_segment_Config_t* copy_Config_st)
{
Led_A_On(copy_Config_st);
Led_B_On(copy_Config_st);
Led_C_On(copy_Config_st);
Led_D_On(copy_Config_st);
Led_E_On(copy_Config_st);
Led_F_On(copy_Config_st);
Led_G_Off(copy_Config_st);
}
void Display_One(Seven_segment_Config_t* copy_Config_st)
{
Led_B_On(copy_Config_st);
Led_C_On(copy_Config_st);
Led_A_Off(copy_Config_st);
Led_D_Off(copy_Config_st);
Led_E_Off(copy_Config_st);
Led_F_Off(copy_Config_st);
Led_G_Off(copy_Config_st);
}
void Display_Two(Seven_segment_Config_t* copy_Config_st)
{
Led_A_On(copy_Config_st);
Led_B_On(copy_Config_st);
Led_C_Off(copy_Config_st);
Led_G_On(copy_Config_st);
Led_D_On(copy_Config_st);
Led_E_On(copy_Config_st);
Led_F_Off(copy_Config_st);
}
void Display_Three(Seven_segment_Config_t* copy_Config_st)
{
Led_A_On(copy_Config_st);
Led_B_On(copy_Config_st);
Led_G_On(copy_Config_st);
Led_C_On(copy_Config_st);
Led_D_On(copy_Config_st);
Led_E_Off(copy_Config_st);
Led_F_Off(copy_Config_st);
}
void Display_Four(Seven_segment_Config_t* copy_Config_st)
{
Led_G_On(copy_Config_st);
Led_B_On(copy_Config_st);
Led_C_On(copy_Config_st);
Led_F_On(copy_Config_st);
Led_A_Off(copy_Config_st);
Led_D_Off(copy_Config_st);
Led_E_Off(copy_Config_st);
}
void Display_Five(Seven_segment_Config_t* copy_Config_st)
{
Led_A_On(copy_Config_st);
Led_G_On(copy_Config_st);
Led_C_On(copy_Config_st);
Led_D_On(copy_Config_st);
Led_F_On(copy_Config_st);
Led_B_Off(copy_Config_st);
Led_E_Off(copy_Config_st);
}
void Display_Six(Seven_segment_Config_t* copy_Config_st)
{
Led_A_On(copy_Config_st);
Led_G_On(copy_Config_st);
Led_C_On(copy_Config_st);
Led_D_On(copy_Config_st);
Led_E_On(copy_Config_st);
Led_F_On(copy_Config_st);
Led_B_Off(copy_Config_st);
}
void Display_Seven(Seven_segment_Config_t* copy_Config_st)
{
Led_A_On(copy_Config_st);
Led_B_On(copy_Config_st);
Led_C_On(copy_Config_st);
Led_D_Off(copy_Config_st);
Led_E_Off(copy_Config_st);
Led_F_Off(copy_Config_st);
Led_G_Off(copy_Config_st);
}
void Display_Eight(Seven_segment_Config_t* copy_Config_st)
{
Led_A_On(copy_Config_st);
Led_B_On(copy_Config_st);
Led_C_On(copy_Config_st);
Led_D_On(copy_Config_st);
Led_E_On(copy_Config_st);
Led_F_On(copy_Config_st);
Led_G_On(copy_Config_st);
}
void Display_Nine(Seven_segment_Config_t* copy_Config_st)
{
Led_A_On(copy_Config_st);
Led_B_On(copy_Config_st);
Led_C_On(copy_Config_st);
Led_F_On(copy_Config_st);
Led_G_On(copy_Config_st);
Led_D_Off(copy_Config_st);
Led_E_Off(copy_Config_st);
}

void Display_Number(Seven_segment_Config_t* ptr_str , u8 num)
{
	switch(num)
	{
	case 0 :
		Display_Zero(ptr_str);
		break;
	case 1 :
		Display_One(ptr_str);
		break;
	case 2 :
		Display_Two(ptr_str);
		break;
	case 3 :
		Display_Three(ptr_str);
		break;
	case 4 :
		Display_Four(ptr_str);
		break;
	case 5 :
		Display_Five(ptr_str);
		break;
	case 6 :
		Display_Six(ptr_str);
		break;
	case 7 :
		Display_Seven(ptr_str);
		break;
	case 8 :
		Display_Eight(ptr_str);
		break;
	case 9 :
		Display_Nine(ptr_str);
		break;
	}
}

void TurnOff(Seven_segment_Config_t* ptr_str)
{
switch(ptr_str -> type )
{
case COMMON_CATHODE :
	MGPIO_vSetPin(ptr_str -> Com_Port, ptr_str-> Com_Pin, LOGIC_ONE);
	break;
case COMMON_ANODE:
	MGPIO_vSetPin(ptr_str -> Com_Port, ptr_str-> Com_Pin, LOGIC_ZERO);
	break;
}

}

void TurnOn(Seven_segment_Config_t* ptr_str)
{
	switch(ptr_str -> type )
	{
	case COMMON_CATHODE :
		MGPIO_vSetPin(ptr_str -> Com_Port, ptr_str-> Com_Pin, LOGIC_ZERO);
		break;
	case COMMON_ANODE:
		MGPIO_vSetPin(ptr_str -> Com_Port, ptr_str-> Com_Pin, LOGIC_ONE);
		break;
	}
}

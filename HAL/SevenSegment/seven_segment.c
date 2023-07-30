/*
 * seven_segment.c
 *
 *  Created on: Jul 4, 2023
 *      Author: Dell
 */

#include "seven_segment.h"
#include "../../MCAL/GPIO/GPIO.int.h"
#include "../../MCAL/RCC/RCC_int.h"

void Seven_seg_Init (Seven_segment_Config_t* Config_st)
{
	switch (Config_st -> A_Port)
	{
	case Port_A:
		MRCC_vEnableClock(RCC_AHB1 , GPIO_A);
		break;
	case Port_B:
		MRCC_vEnableClock(RCC_AHB1 , GPIO_B);
		break;
	case Port_C:
		MRCC_vEnableClock(RCC_AHB1 , GPIO_C);
		break;
	}
	switch (Config_st -> B_Port)
	{
	case Port_A:
		MRCC_vEnableClock(RCC_AHB1 , GPIO_A);
		break;
	case Port_B:
		MRCC_vEnableClock(RCC_AHB1 , GPIO_B);
		break;
	case Port_C:
		MRCC_vEnableClock(RCC_AHB1 , GPIO_C);
		break;
	}
	switch (Config_st -> C_Port)
	{
	case Port_A:
		MRCC_vEnableClock(RCC_AHB1 , GPIO_A);
		break;
	case Port_B:
		MRCC_vEnableClock(RCC_AHB1 , GPIO_B);
		break;
	case Port_C:
		MRCC_vEnableClock(RCC_AHB1 , GPIO_C);
		break;
	}
	switch (Config_st -> D_Port)
	{
	case Port_A:
		MRCC_vEnableClock(RCC_AHB1 , GPIO_A);
		break;
	case Port_B:
		MRCC_vEnableClock(RCC_AHB1 , GPIO_B);
		break;
	case Port_C:
		MRCC_vEnableClock(RCC_AHB1 , GPIO_C);
		break;
	}
	switch (Config_st -> E_Port)
	{
	case Port_A:
		MRCC_vEnableClock(RCC_AHB1 , GPIO_A);
		break;
	case Port_B:
		MRCC_vEnableClock(RCC_AHB1 , GPIO_B);
		break;
	case Port_C:
		MRCC_vEnableClock(RCC_AHB1 , GPIO_C);
		break;
	}
	switch (Config_st -> F_Port)
	{
	case Port_A:
		MRCC_vEnableClock(RCC_AHB1 , GPIO_A);
		break;
	case Port_B:
		MRCC_vEnableClock(RCC_AHB1 , GPIO_B);
		break;
	case Port_C:
		MRCC_vEnableClock(RCC_AHB1 , GPIO_C);
		break;
	}
	switch (Config_st -> G_Port)
	{
	case Port_A:
		MRCC_vEnableClock(RCC_AHB1 , GPIO_A);
		break;
	case Port_B:
		MRCC_vEnableClock(RCC_AHB1 , GPIO_B);
		break;
	case Port_C:
		MRCC_vEnableClock(RCC_AHB1 , GPIO_C);
		break;
	}
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


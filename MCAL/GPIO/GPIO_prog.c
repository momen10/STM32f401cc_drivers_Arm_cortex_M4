/*
 * GPIO_prog.c
 *
 *  Created on: Jul 3, 2023
 *      Author: Dell
 */

#include "GPIO.config.h"
#include "GPIO.int.h"
#include "GPIO_prv.h"

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

void MGPIO_vInit(MGPIO_Config_t* copy_Config_Struct)
{
	switch (copy_Config_Struct->Port_ID)
	{
	case Port_A:
		//First, determine the mode of the GPIO
		//clearing the required two bits
		GPIOA -> MODER &= ~(0b11 << (copy_Config_Struct->Pin_ID)*2 );
		//inserting the required option
		GPIOA -> MODER |= (copy_Config_Struct->mode <<
				(copy_Config_Struct->Pin_ID)*2 );

		if (copy_Config_Struct ->mode == Digital_input ||
				copy_Config_Struct ->mode == Analog_input )
		{
			//clearing the required two bits
			GPIOA -> PUPDR &= ~(0b11 << (copy_Config_Struct->Pin_ID)*2 );
			//inserting the required option
			GPIOA -> PUPDR |= (copy_Config_Struct->input_pull_type <<
					(copy_Config_Struct->Pin_ID)*2 );
		}
		else if (copy_Config_Struct ->mode == Digital_output)
		{
			//clear the required bit
			GPIOA -> OTYPER &= ~(1<<copy_Config_Struct->Pin_ID);
			//insert the required option
			GPIOA -> OTYPER |= (copy_Config_Struct -> output_type);

			GPIOA -> OSPEEDER &= ~(0b11 << (copy_Config_Struct -> Pin_ID)*2 );
			//inserting the required option
			GPIOA -> OSPEEDER |= (copy_Config_Struct -> output_speed <<
					(copy_Config_Struct -> Pin_ID)*2 );
		}
		else if (copy_Config_Struct ->mode == Alternative_func)
		{
			if (copy_Config_Struct -> Pin_ID >= 0 && copy_Config_Struct -> Pin_ID <=7 )
			{
				//clearing the required 4 bits:
				GPIOA -> AFRL &= ~(0b1111 << (copy_Config_Struct -> Pin_ID) *4);
				//inserting the required option:
				GPIOA -> AFRL |= (copy_Config_Struct -> Alt_func
						<< (copy_Config_Struct -> Pin_ID) *4);
			}
			else
			{
				//clearing the required 4 bits:
				GPIOA -> AFRH &= ~(0b1111 << (copy_Config_Struct -> Pin_ID) *4);
				//inserting the required option:
				GPIOA -> AFRH |= (copy_Config_Struct -> Alt_func
						<< (copy_Config_Struct -> Pin_ID) *4);
			}
		}

		break;

	case Port_B:
		//clearing the required two bits
		GPIOB -> MODER &= ~(0b11 << (copy_Config_Struct->Pin_ID)*2 );
		//inserting the required option
		GPIOB -> MODER |= (copy_Config_Struct->mode <<
				(copy_Config_Struct->Pin_ID)*2 );
		if (copy_Config_Struct ->mode == Digital_input ||
				copy_Config_Struct ->mode == Analog_input )
		{
			//clearing the required two bits
			GPIOB -> PUPDR &= ~(0b11 << (copy_Config_Struct->Pin_ID)*2 );
			//inserting the required option
			GPIOB -> PUPDR |= (copy_Config_Struct->input_pull_type <<
					(copy_Config_Struct->Pin_ID)*2 );
		}
		else if (copy_Config_Struct ->mode == Digital_output)
		{
			//clear the required bit
			GPIOB -> OTYPER &= ~(1<<copy_Config_Struct->Pin_ID);
			//insert the required option
			GPIOB -> OTYPER |= (copy_Config_Struct -> output_type);

			GPIOB -> OSPEEDER &= ~(0b11 << (copy_Config_Struct -> Pin_ID)*2 );
			//inserting the required option
			GPIOB -> OSPEEDER |= (copy_Config_Struct -> output_speed <<
					(copy_Config_Struct -> Pin_ID)*2 );
		}
		else if (copy_Config_Struct ->mode == Alternative_func)
		{
			if (copy_Config_Struct -> Pin_ID >= 0 && copy_Config_Struct -> Pin_ID <=7 )
			{
				//clearing the required 4 bits:
				GPIOB -> AFRL &= ~(0b1111 << (copy_Config_Struct -> Pin_ID) *4);
				//inserting the required option:
				GPIOB -> AFRL |= (copy_Config_Struct -> Alt_func
						<< (copy_Config_Struct -> Pin_ID) *4);
			}
			else
			{
				//clearing the required 4 bits:
				GPIOB -> AFRH &= ~(0b1111 << (copy_Config_Struct -> Pin_ID) *4);
				//inserting the required option:
				GPIOB -> AFRH |= (copy_Config_Struct -> Alt_func
						<< (copy_Config_Struct -> Pin_ID) *4);
			}
		}
		break;
	case Port_C:
		//clearing the required two bits
		GPIOC -> MODER &= ~(0b11 << (copy_Config_Struct->Pin_ID)*2 );
		//inserting the required option
		GPIOC -> MODER |= (copy_Config_Struct->mode <<
				(copy_Config_Struct->Pin_ID)*2 );

		if (copy_Config_Struct ->mode == Digital_input ||
				copy_Config_Struct ->mode == Analog_input )
		{
			//clearing the required two bits
			GPIOC -> PUPDR &= ~(0b11 << (copy_Config_Struct->Pin_ID)*2 );
			//inserting the required option
			GPIOC -> PUPDR |= (copy_Config_Struct->input_pull_type <<
					(copy_Config_Struct->Pin_ID)*2 );
		}
		else if (copy_Config_Struct ->mode == Digital_output)
		{
			//clear the required bit
			GPIOC -> OTYPER &= ~(1<<copy_Config_Struct->Pin_ID);
			//insert the required option
			GPIOC -> OTYPER |= (copy_Config_Struct -> output_type);

			GPIOC -> OSPEEDER &= ~(0b11 << (copy_Config_Struct -> Pin_ID)*2 );
			//inserting the required option
			GPIOC -> OSPEEDER |= (copy_Config_Struct -> output_speed <<
					(copy_Config_Struct -> Pin_ID)*2 );
		}
		else if (copy_Config_Struct ->mode == Alternative_func)
		{
			if (copy_Config_Struct -> Pin_ID >= 0 && copy_Config_Struct -> Pin_ID <=7 )
			{
				//clearing the required 4 bits:
				GPIOC -> AFRL &= ~(0b1111 << (copy_Config_Struct -> Pin_ID) *4);
				//inserting the required option:
				GPIOC -> AFRL |= (copy_Config_Struct -> Alt_func
						<< (copy_Config_Struct -> Pin_ID) *4);
			}
			else
			{
				//clearing the required 4 bits:
				GPIOC -> AFRH &= ~(0b1111 << (copy_Config_Struct -> Pin_ID) *4);
				//inserting the required option:
				GPIOC -> AFRH |= (copy_Config_Struct -> Alt_func
						<< (copy_Config_Struct -> Pin_ID) *4);
			}
		}
		break;
	}

}

void MGPIO_vSetPin(GPIO_PortNum_t copy_Port_ID, GPIO_PinNum_t copy_Pin_ID ,GPIO_PinValues_t Pin_value)
{
	switch (copy_Port_ID)
	{
	case Port_A:
		if(Pin_value == LOGIC_ZERO)
		{
			CLR_BIT(GPIOA -> ODR, copy_Pin_ID);
		}
		else
		{
			SET_BIT(GPIOA -> ODR, copy_Pin_ID);
		}
		break;
	case Port_B:
		if(Pin_value == LOGIC_ZERO)
		{
			CLR_BIT(GPIOB -> ODR, copy_Pin_ID);
		}
		else
		{
			SET_BIT(GPIOB -> ODR, copy_Pin_ID);
		}
		break;
	case Port_C:
		if(Pin_value == LOGIC_ZERO)
		{
			CLR_BIT(GPIOC -> ODR, copy_Pin_ID);
		}
		else
		{
			SET_BIT(GPIOC -> ODR, copy_Pin_ID);
		}
		break;
	}
}

void MGPIO_vSetPinFast(GPIO_PortNum_t copy_Port_ID, GPIO_PinNum_t copy_Pin_ID ,GPIO_PinValues_t Pin_value)
{
	switch(copy_Port_ID)
	{
	case Port_A:
		if(Pin_value == LOGIC_ZERO)
		{
			SET_BIT(GPIOA -> BSRR, copy_Pin_ID + 16);
		}
		else
		{
			SET_BIT(GPIOA -> BSRR, copy_Pin_ID);
		}
		break;
	case Port_B:
		if(Pin_value == LOGIC_ZERO)
		{
			SET_BIT(GPIOB -> BSRR, copy_Pin_ID + 16);
		}
		else
		{
			SET_BIT(GPIOB -> BSRR, copy_Pin_ID);
		}
		break;
	case Port_C:
		if(Pin_value == LOGIC_ZERO)
		{
			SET_BIT(GPIOC -> BSRR, copy_Pin_ID + 16);
		}
		else
		{
			SET_BIT(GPIOC -> BSRR, copy_Pin_ID);
		}
		break;
	}

}

u8 MGPIO_u8GetPin(GPIO_PortNum_t copy_Port_ID, GPIO_PinNum_t copy_Pin_ID )
{
 u8 pin_value=0;
 switch (copy_Port_ID)
 {
 case Port_A:
	 pin_value = GET_BIT(GPIOA ->IDR, copy_Pin_ID);
	 break;
 case Port_B:
	 pin_value = GET_BIT(GPIOB ->IDR, copy_Pin_ID);
	 break;
 case Port_C:
	 pin_value = GET_BIT(GPIOC ->IDR, copy_Pin_ID);
	 break;
 }
 return pin_value;
}

/*
 * NAME : DAC_config.h
 *
 * Created on: Aug 21, 2023
 *      
 * Author: Mo'men Ahmed
 */

#include "../../MCAL/GPIO/GPIO_int.h"
#include "DAC_config.h"

MGPIO_Config_t DAC_BITS [DAC_RESOLUTION]={
		{.mode = Digital_output, .Port_ID = DAC_PORT_ID, .Pin_ID= DAC_BIT0_PIN, .output_speed = Low, .output_type = Push_pull },
		{.mode = Digital_output, .Port_ID = DAC_PORT_ID, .Pin_ID= DAC_BIT1_PIN, .output_speed = Low, .output_type = Push_pull },
		{.mode = Digital_output, .Port_ID = DAC_PORT_ID, .Pin_ID= DAC_BIT2_PIN, .output_speed = Low, .output_type = Push_pull },
		{.mode = Digital_output, .Port_ID = DAC_PORT_ID, .Pin_ID= DAC_BIT3_PIN, .output_speed = Low, .output_type = Push_pull },
		{.mode = Digital_output, .Port_ID = DAC_PORT_ID, .Pin_ID= DAC_BIT4_PIN, .output_speed = Low, .output_type = Push_pull },
		{.mode = Digital_output, .Port_ID = DAC_PORT_ID, .Pin_ID= DAC_BIT5_PIN, .output_speed = Low, .output_type = Push_pull },
		{.mode = Digital_output, .Port_ID = DAC_PORT_ID, .Pin_ID= DAC_BIT6_PIN, .output_speed = Low, .output_type = Push_pull },
		{.mode = Digital_output, .Port_ID = DAC_PORT_ID, .Pin_ID= DAC_BIT7_PIN, .output_speed = Low, .output_type = Push_pull },
};



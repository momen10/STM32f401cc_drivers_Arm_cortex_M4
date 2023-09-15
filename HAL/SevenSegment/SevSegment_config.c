/*
 * NAME :seven_segment_config.c
 *
 * Created on: Jul 4, 2023
 *
 * Author: Mo'men Ahmed
 */



#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include "seven_segment.h"

#if SEV_SEG_METHOD == DIRECT_METHPD
MGPIO_Config_t SevSegm_Pins [SevSegm_Pins]={
		{.mode = Digital_output, .output_speed = Low , .Port_ID = GPIO_Port_A, .Pin_ID = GPIO_Pin4, .output_type= Push_pull },
		{.mode = Digital_output, .output_speed = Low , .Port_ID = GPIO_Port_A, .Pin_ID = GPIO_Pin5, .output_type= Push_pull },
		{.mode = Digital_output, .output_speed = Low , .Port_ID = GPIO_Port_A, .Pin_ID = GPIO_Pin6, .output_type= Push_pull },
		{.mode = Digital_output, .output_speed = Low , .Port_ID = GPIO_Port_A, .Pin_ID = GPIO_Pin6, .output_type= Push_pull },
		{.mode = Digital_output, .output_speed = Low , .Port_ID = GPIO_Port_A, .Pin_ID = GPIO_Pin6, .output_type= Push_pull },
		{.mode = Digital_output, .output_speed = Low , .Port_ID = GPIO_Port_A, .Pin_ID = GPIO_Pin6, .output_type= Push_pull },
		{.mode = Digital_output, .output_speed = Low , .Port_ID = GPIO_Port_A, .Pin_ID = GPIO_Pin6, .output_type= Push_pull },
};

#endif

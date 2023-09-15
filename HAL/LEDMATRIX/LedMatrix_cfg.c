/*
 * NAME :LedMatrix_cfg.c
 *
 * Created on: Jul 24, 2023
 *     
 * Author: Mo'men Ahmed
 */

//this file is configuration.c : it is source file contains all the
//configuration variables to configure the project in the linking time
//not pre build nor post build

#include "../../MCAL/GPIO/GPIO_int.h"
#include "LedMatrix_cfg.h"

MGPIO_Config_t rows[NO_ROWS] =
{
  { .Port_ID = GPIO_Port_A, .Pin_ID = GPIO_Pin0, .mode = Digital_output, .output_type =Push_pull,
	.output_speed = Low, .input_pull_type= No_resistor, .Alt_func = Not_AF},

  { .Port_ID = GPIO_Port_A, .Pin_ID = GPIO_Pin1,.mode = Digital_output, .output_type =Push_pull,
    .output_speed = Low, .input_pull_type= No_resistor, .Alt_func = Not_AF },

  { .Port_ID = GPIO_Port_A, .Pin_ID = GPIO_Pin2, .mode = Digital_output, .output_type =Push_pull,
	.output_speed = Low, .input_pull_type= No_resistor, .Alt_func = Not_AF},

  { .Port_ID = GPIO_Port_A, .Pin_ID = GPIO_Pin3, .mode = Digital_output, .output_type =Push_pull,
	.output_speed = Low, .input_pull_type= No_resistor, .Alt_func = Not_AF},

  { .Port_ID = GPIO_Port_A, .Pin_ID = GPIO_Pin4, .mode = Digital_output, .output_type =Push_pull,
	.output_speed = Low, .input_pull_type= No_resistor, .Alt_func = Not_AF},

  { .Port_ID = GPIO_Port_A, .Pin_ID = GPIO_Pin5, .mode = Digital_output, .output_type =Push_pull,
	.output_speed = Low, .input_pull_type= No_resistor, .Alt_func = Not_AF},

  { .Port_ID = GPIO_Port_A, .Pin_ID = GPIO_Pin6, .mode = Digital_output, .output_type =Push_pull,
	.output_speed = Low, .input_pull_type= No_resistor, .Alt_func = Not_AF},

  {.Port_ID = GPIO_Port_A, .Pin_ID = GPIO_Pin7,  .mode = Digital_output, .output_type =Push_pull,
   .output_speed = Low, .input_pull_type= No_resistor,  .Alt_func = Not_AF}
};

MGPIO_Config_t cols[NO_COLS] =
{
  { .Port_ID = GPIO_Port_B, .Pin_ID = GPIO_Pin8, .mode = Digital_output, .output_type =Push_pull,
	.output_speed = Low, .input_pull_type= No_resistor, .Alt_func = Not_AF},

  { .Port_ID = GPIO_Port_B, .Pin_ID = GPIO_Pin9,.mode = Digital_output, .output_type =Push_pull,
    .output_speed = Low, .input_pull_type= No_resistor, .Alt_func = Not_AF },

  { .Port_ID = GPIO_Port_B, .Pin_ID = GPIO_Pin10, .mode = Digital_output, .output_type =Push_pull,
	.output_speed = Low, .input_pull_type= No_resistor, .Alt_func = Not_AF},

  { .Port_ID = GPIO_Port_B, .Pin_ID = GPIO_Pin12, .mode = Digital_output, .output_type =Push_pull,
	.output_speed = Low, .input_pull_type= No_resistor, .Alt_func = Not_AF},

  { .Port_ID = GPIO_Port_B, .Pin_ID = GPIO_Pin13, .mode = Digital_output, .output_type =Push_pull,
	.output_speed = Low, .input_pull_type= No_resistor, .Alt_func = Not_AF},

  { .Port_ID = GPIO_Port_B, .Pin_ID = GPIO_Pin14, .mode = Digital_output, .output_type =Push_pull,
	.output_speed = Low, .input_pull_type= No_resistor, .Alt_func = Not_AF},

  { .Port_ID = GPIO_Port_B, .Pin_ID = GPIO_Pin15, .mode = Digital_output, .output_type =Push_pull,
	.output_speed = Low, .input_pull_type= No_resistor, .Alt_func = Not_AF},

  {.Port_ID = GPIO_Port_B, .Pin_ID = GPIO_Pin7,  .mode = Digital_output, .output_type =Push_pull,
   .output_speed = Low, .input_pull_type= No_resistor,  .Alt_func = Not_AF}
};

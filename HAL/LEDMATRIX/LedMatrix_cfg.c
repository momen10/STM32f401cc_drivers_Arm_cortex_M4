/*
 * LedMatrix_cfg.c
 *
 *  Created on: Jul 25, 2023
 *      Author: Dell
 */

//this file is configuration.c : it is source file contains all the
//configuration variables to configure the project in the linking time
//not pre build nor post build

#include "../../MCAL/GPIO/GPIO_int.h"
#include "LedMatrix_cfg.h"

MGPIO_Config_t rows[NO_ROWS] =
{
  { .Port_ID = Port_A, .Pin_ID = Pin0, .mode = Digital_output, .output_type =Push_pull,
	.output_speed = Low, .input_pull_type= No_resistor, .Alt_func = Not_AF},

  { .Port_ID = Port_A, .Pin_ID = Pin1,.mode = Digital_output, .output_type =Push_pull,
    .output_speed = Low, .input_pull_type= No_resistor, .Alt_func = Not_AF },

  { .Port_ID = Port_A, .Pin_ID = Pin2, .mode = Digital_output, .output_type =Push_pull,
	.output_speed = Low, .input_pull_type= No_resistor, .Alt_func = Not_AF},

  { .Port_ID = Port_A, .Pin_ID = Pin3, .mode = Digital_output, .output_type =Push_pull,
	.output_speed = Low, .input_pull_type= No_resistor, .Alt_func = Not_AF},

  { .Port_ID = Port_A, .Pin_ID = Pin4, .mode = Digital_output, .output_type =Push_pull,
	.output_speed = Low, .input_pull_type= No_resistor, .Alt_func = Not_AF},

  { .Port_ID = Port_A, .Pin_ID = Pin5, .mode = Digital_output, .output_type =Push_pull,
	.output_speed = Low, .input_pull_type= No_resistor, .Alt_func = Not_AF},

  { .Port_ID = Port_A, .Pin_ID = Pin6, .mode = Digital_output, .output_type =Push_pull,
	.output_speed = Low, .input_pull_type= No_resistor, .Alt_func = Not_AF},

  {.Port_ID = Port_A, .Pin_ID = Pin7,  .mode = Digital_output, .output_type =Push_pull,
   .output_speed = Low, .input_pull_type= No_resistor,  .Alt_func = Not_AF}
};

MGPIO_Config_t cols[NO_COLS] =
{
  { .Port_ID = Port_B, .Pin_ID = Pin8, .mode = Digital_output, .output_type =Push_pull,
	.output_speed = Low, .input_pull_type= No_resistor, .Alt_func = Not_AF},

  { .Port_ID = Port_B, .Pin_ID = Pin9,.mode = Digital_output, .output_type =Push_pull,
    .output_speed = Low, .input_pull_type= No_resistor, .Alt_func = Not_AF },

  { .Port_ID = Port_B, .Pin_ID = Pin10, .mode = Digital_output, .output_type =Push_pull,
	.output_speed = Low, .input_pull_type= No_resistor, .Alt_func = Not_AF},

  { .Port_ID = Port_B, .Pin_ID = Pin12, .mode = Digital_output, .output_type =Push_pull,
	.output_speed = Low, .input_pull_type= No_resistor, .Alt_func = Not_AF},

  { .Port_ID = Port_B, .Pin_ID = Pin13, .mode = Digital_output, .output_type =Push_pull,
	.output_speed = Low, .input_pull_type= No_resistor, .Alt_func = Not_AF},

  { .Port_ID = Port_B, .Pin_ID = Pin14, .mode = Digital_output, .output_type =Push_pull,
	.output_speed = Low, .input_pull_type= No_resistor, .Alt_func = Not_AF},

  { .Port_ID = Port_B, .Pin_ID = Pin15, .mode = Digital_output, .output_type =Push_pull,
	.output_speed = Low, .input_pull_type= No_resistor, .Alt_func = Not_AF},

  {.Port_ID = Port_B, .Pin_ID = Pin7,  .mode = Digital_output, .output_type =Push_pull,
   .output_speed = Low, .input_pull_type= No_resistor,  .Alt_func = Not_AF}
};

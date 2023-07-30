/*
 * S2P_cfg.c
 *
 *  Created on: Jul 25, 2023
 *      Author: Dell
 */

#include "../../MCAL/GPIO/GPIO_int.h"

	MGPIO_Config_t serial_data = { .Port_ID = Port_A, .Pin_ID = Pin0,
			     .mode = Digital_output, .output_type =Push_pull,
			     .output_speed = Low, .input_pull_type= No_resistor, .Alt_func = Not_AF
	};

	MGPIO_Config_t shift_clock = { .Port_ID = Port_A, .Pin_ID = Pin1,
			     .mode = Digital_output, .output_type =Push_pull,
			     .output_speed = Low, .input_pull_type= No_resistor, .Alt_func = Not_AF
	};

	MGPIO_Config_t latch_clock = { .Port_ID = Port_A, .Pin_ID = Pin2,
			     .mode = Digital_output, .output_type =Push_pull,
			     .output_speed = Low, .input_pull_type= No_resistor, .Alt_func = Not_AF
	};




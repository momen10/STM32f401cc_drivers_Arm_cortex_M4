/*
 * NAME : IR_prog.c
 *
 * Created on: Aug 22, 2023
 * 
 * Author: Mo'men Ahmed 
 */

#include "../../MCAL/GPIO/GPIO_int.h"
#include "IR_Interface.h"
#include "IR_config.h"
#include "IR_prv.h"


void HIR_vInit(void)
{
	MGPIO_Config_t IR_Pin ={
			.mode = Digital_input, .input_pull_type = No_resistor, .Port_ID = IR_PORT_ID, .Pin_ID = IR_PIN_ID
	};

	MGPIO_vInit(&IR_Pin);
}



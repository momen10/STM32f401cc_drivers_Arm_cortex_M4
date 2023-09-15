/*
 * NAME : DAC_prog.c
 *
 * Created on: Aug 21, 2023
 *      
 * Author: Mo'men Ahmed
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_int.h"
#include "../../MCAL/SYSTICK/SYSTICK_int.h"

#include "DAC_config.h"
#include "DAC_prv.h"
#include "DAC_interface.h"
#include "song4.h"


extern MGPIO_Config_t DAC_BITS[DAC_RESOLUTION];
void DAC_vInit(void)
{
for (u8 i =0; i< DAC_RESOLUTION ; i++)
{
	MGPIO_vInit(&DAC_BITS[i]);
}
}

void DAC_vWrite(void)
{
	static u32 iterator=0;
	for (u8 i=0 ; i<DAC_RESOLUTION; i++)
	{
		MGPIO_vSetPin(DAC_BITS[i].Port_ID, DAC_BITS[i].Pin_ID,GET_BIT(song4_raw[iterator],i));
	}

	iterator ++;
	if (iterator == song4_raw_len)
	{
		iterator = 0;
	}
}


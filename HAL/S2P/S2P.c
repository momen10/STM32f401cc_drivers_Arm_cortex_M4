/*
 * NAME : S2P.c
 *
 * Created on: Jul 25, 2023
 *
 * Author: Mo'men Ahmed
 */


#include "S2P.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/SYSTICK/SYSTICK_int.h"

extern MGPIO_Config_t serial_data;
extern MGPIO_Config_t shift_clock;
extern MGPIO_Config_t latch_clock;

//make a pulse on shift clock
static void HS2P_vShiftData(void)
{
	//2- shift the bit
	MGPIO_vSetPin(shift_clock.Port_ID , shift_clock.Pin_ID , LOGIC_ONE);
	MSTK_vDelayms(1);
	MGPIO_vSetPin(shift_clock.Port_ID , shift_clock.Pin_ID , LOGIC_ZERO);
	MSTK_vDelayms(1);
}

//make a pulse on latch clock
static void HS2P_vLatchData(void)
{
	//3- output the data to the latches
	MGPIO_vSetPin(latch_clock.Port_ID , latch_clock.Pin_ID , LOGIC_ONE);
	MSTK_vDelayms(1);
	MGPIO_vSetPin(latch_clock.Port_ID , latch_clock.Pin_ID , LOGIC_ZERO);
	MSTK_vDelayms(1);
}

void HS2P_vInit(void)
{
	MGPIO_vInit(&serial_data);
	MGPIO_vInit(&shift_clock);
	MGPIO_vInit(&latch_clock);

    MSTK_vInit();
}

void HS2P_vSendData(u16 data)
{
		u8 serial_bit;
		//1- put data in serial data pin
		for (s8 i=8*NO_OF_SHIFT_REG - 1 ; i>0  ;i--)
		{
			serial_bit = GET_BIT(data, i);
			if(serial_bit)
			{
				MGPIO_vSetPin(serial_data.Port_ID, serial_data.Pin_ID, LOGIC_ONE);
			}
			else
			{
				MGPIO_vSetPin(serial_data.Port_ID, serial_data.Pin_ID, LOGIC_ZERO);
			}
             //shift the bit into the shift regiter
             HS2P_vShiftData();
		}
        HS2P_vLatchData();
}


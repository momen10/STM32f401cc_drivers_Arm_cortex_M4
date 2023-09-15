/*
 * NAME :LedMatrix_prog.c
 *
 * Created on: Jul 24, 2023
 *     
 * Author: Mo'men Ahmed
 */

#include "LedMatrix_prv.h"
#include "LedMatrix_int.h"
#include "LedMatrix_cfg.h"

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_int.h"

#include "../../MCAL/SYSTICK/SYSTICK_int.h"
#include "../S2P/S2P.h"


void HLEDMTX_vInit (void)
{
#if LED_MTX_METHOD == DIRECT_METHOD

 for (u8 i=0; i< NO_ROWS ;i++)
 {
	 MGPIO_vInit(&rows[i]);
 }
 for (u8 i=0; i< NO_COLS ;i++)
 {
	 MGPIO_vInit(&cols[i]);
 }

#elif LED_MTX_METHOD == SHIFT_REG_METHOD
HS2P_vInit();
#endif
MSTK_vInit();
}

void HLEDMTX_vDisplayFrame (u8 frame[], u32 frame_delay)
{
	//frame[] here is the values of columns
	for (u8 j=0 ;j< frame_delay; j++)
	{
        #if LED_MTX_METHOD == DIRECT_METHOD
		//1- disable all rows
		for (u8 i=0 ; i<NO_ROWS ;i++)
		{
			MGPIO_vSetPin(rows[i].Port_ID, rows[i].Pin_ID, LOGIC_ZERO);
		}

		//2- set columns values
		for (u8 x=0 ; x<NO_COLS; x++)
		{
			if (GET_BIT(~(frame[x]),j))
			{
				MGPIO_vSetPin(cols[x].Port_ID , cols[x].Pin_ID, LOGIC_ONE );
			}
			else
			{
				MGPIO_vSetPin(cols[x].Port_ID , cols[x].Pin_ID, LOGIC_ZERO );
			}
		}
		//3- set current row
		MGPIO_vSetPin(rows[j].Port_ID, rows[j].Pin_ID, LOGIC_ONE);

		#elif LED_MTX_METHOD == SHIFT_REG_METHOD
		u16 Local_u16S2pData ;
		//1- disable all rows
		Local_u16S2pData = 0x00ff;
		//2- set row values
		//3- set current row
		Local_u16S2pData = ((u16)(~(frame[j])) |  ((1<<j)<<8));
		HS2P_vSendData(Local_u16S2pData);
        #endif

		//4-delay 2.5 ms
		MSTK_vDelayms(ON_TIME);
	}
}



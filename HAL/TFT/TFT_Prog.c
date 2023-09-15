/*
 * NAME: TFT_Prog.h
 *
 * Created on: Aug 25, 2023
 *
 * Author: Mo'men Ahmed
 */


#include "TFT_Interface.h"
#include "TFT_config.h"
#include "TFT_prv.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include "../../MCAL/SPI/SPI_Interface.h"
#include "../../MCAL/SYSTICK/SYSTICK_int.h"
//#include "leo.h"

void TFT_vResetSequence(void)
{
	MGPIO_vSetPin(TFT_RESET_PORT, TFT_RESET_PIN, LOGIC_ONE);
	MSTK_vDelayus(100);
	MGPIO_vSetPin(TFT_RESET_PORT, TFT_RESET_PIN, LOGIC_ZERO);
	MSTK_vDelayus(10);
	MGPIO_vSetPin(TFT_RESET_PORT, TFT_RESET_PIN, LOGIC_ONE);
	MSTK_vDelayus(100);
	MGPIO_vSetPin(TFT_RESET_PORT, TFT_RESET_PIN, LOGIC_ZERO);
	MSTK_vDelayus(100);
	MGPIO_vSetPin(TFT_RESET_PORT, TFT_RESET_PIN, LOGIC_ONE);
	MSTK_vDelayms(120);
}

void HTFT_vSendCommand(u16 A_u16Command)
{
 MGPIO_vSetPin(TFT_A0_PORT, TFT_A0_PIN, LOGIC_ZERO);

 (void) MSPI_u16SendReceive(A_u16Command);
}


void HTFT_vSendData(u16 A_u16Data)
{
	 MGPIO_vSetPin(TFT_A0_PORT, TFT_A0_PIN, LOGIC_ONE);

	(void) MSPI_u16SendReceive(A_u16Data);
}

void HTFT_vInit(void)
{
	//1- SET PIN DIRECTIONS
	MGPIO_Config_t ResetPin ={
			.mode = Digital_output, .output_speed = Low,
			.output_type = Push_pull, .Port_ID = TFT_RESET_PORT,
			.Pin_ID = TFT_RESET_PIN
	};

	MGPIO_Config_t A0Pin ={
			.mode = Digital_output, .output_speed = Low,
			.output_type = Push_pull, .Port_ID = TFT_A0_PORT,
			.Pin_ID = TFT_A0_PIN
	};

	MGPIO_vInit(&ResetPin);
	MGPIO_vInit(&A0Pin);

	//2- INIT SPI AND STK
	MSPI_vInit();
	MSTK_vInit();

	//3- RESET SEQUENCE
	TFT_vResetSequence();

	//4-SLEEPOUT
	HTFT_vSendCommand(TFT_SLEEPOUT_CMD);

	//5- WAIT 10ms
	MSTK_vDelayms(10);

	//6-SET COLOR MODE
	HTFT_vSendCommand(TFT_CLRMODE_CMD);
	HTFT_vSendData(TFT_RGB565_MODE);

    //7-DISPLAY ON
	HTFT_vSendCommand(TFT_DISPLAYON_CMD);

}

void HTFT_vDisplayImg(const u16 * arr_img)
{
//1- SET X LIMITS
	HTFT_vSendCommand(TFT_SETX_CMD);
	//SEND HIGH BYTE FIRST THEN LOW BYTE
	HTFT_vSendData((u8)(TFT_XSTART>>8));
	HTFT_vSendData((u8)(TFT_XSTART));

	HTFT_vSendData((u8)(TFT_XEND>>8));
	HTFT_vSendData((u8)(TFT_XEND));
//2- SET Y LIMITS
	HTFT_vSendCommand(TFT_SETY_CMD);
	//SEND HIGH BYTE FIRST THEN LOW BYTE
	HTFT_vSendData((u8)(TFT_YSTART>>8));
	HTFT_vSendData((u8)(TFT_YSTART));

	HTFT_vSendData((u8)(TFT_YEND>>8));
	HTFT_vSendData((u8)(TFT_YEND));

//3- LOOP ON THE ARRAY AND DISPLAY
	HTFT_vSendCommand(TFT_IMGDATA_CMD);
	for (u16 i=0; i< 20480; i++)
	{
		//SEND HIGH BYTE FIRST THEN LOW BYTE
		HTFT_vSendData((u8)(arr_img[i]>>8));
		HTFT_vSendData(arr_img[i] & 0x00ff);
	}
}


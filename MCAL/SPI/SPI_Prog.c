/*
 * NAME :SPI_Prog.c
 *
 * Created on: Aug 23, 2023
 *
 * Author: Mo'men Ahmed
 */

#ifndef MCAL_SPI_SPI_PROG_C_
#define MCAL_SPI_SPI_PROG_C_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../GPIO/GPIO_int.h"
#include "SPI_Interface.h"
#include "SPI_prv.h"
#include "SPI_config.h"

extern MSPI_Config_t My_SPI;

void MSPI_vInit (void)
{
	MGPIO_Config_t MOSI_PIN={
			.mode = Alternative_func, .Port_ID = GPIO_Port_A,
			.Pin_ID = GPIO_Pin7,      .Alt_func = AF5,
			.output_type = Push_pull, .output_speed = Very_high,
			.input_pull_type =No_resistor
	};

	MGPIO_Config_t MISO_PIN={
			.mode = Alternative_func,   .Port_ID = GPIO_Port_A,
			.Pin_ID = GPIO_Pin6,        .input_pull_type = No_resistor,
			.Alt_func = AF5 ,			.output_type = Push_pull,
			.output_speed = Very_high,  .input_pull_type =No_resistor
	};

	MGPIO_Config_t SCK_PIN={
			.mode = Alternative_func, .Port_ID = GPIO_Port_A,
			.Pin_ID = GPIO_Pin5,      .Alt_func = AF5,
			.output_type = Push_pull, .output_speed = Very_high,
			.input_pull_type =No_resistor
	};

	MGPIO_vInit(&MOSI_PIN);
	MGPIO_vInit(&MISO_PIN);
	MGPIO_vInit(&SCK_PIN);

	//1- SET ALL OPTIONS
	switch(My_SPI.Phase)
	{
	case Sample_First:
		CLR_BIT(SPI1->CR[0], CPHA_BIT);
		break;
	case Setup_First:
		SET_BIT(SPI1->CR[0], CPHA_BIT);
		break;
	}

	switch (My_SPI.Polarity)
	{
	case Leading_Rising:
		CLR_BIT(SPI1->CR[0], CPOL_BIT);
		break;
	case Leading_Falling:
		SET_BIT(SPI1->CR[0], CPOL_BIT);
		break;
	}

	switch(My_SPI.Mode)
	{
	case Master:
		SET_BIT(SPI1->CR[0], MSTR_BIT);
		break;
	case Slave:
		CLR_BIT(SPI1->CR[0], MSTR_BIT);
		break;
	}

	//SET BAUD RATE :
	SPI1->CR[0] &= 0xffffffc7;
	SPI1->CR[0] |= (My_SPI.BaudeRate << 3);

	switch (My_SPI.SSM)
	{
	case SSM_Disable:
		CLR_BIT(SPI1->CR[0], SSM_BIT);
		break;
	case SSM_Enable:
		SET_BIT(SPI1->CR[0], SSM_BIT);
		switch(My_SPI.SSI)
		{
		case SSI_Disable:
			CLR_BIT(SPI1->CR[0], SSI_BIT);
			break;
		case SSI_ForceActive:
			SET_BIT(SPI1->CR[0], SSI_BIT);
			break;
		}
		break;
	}

	switch (My_SPI.DataFormat)
	{
	case SPI_8Bits:
		CLR_BIT(SPI1->CR[0], DFF_BIT);
		break;
	case SPI_16Bits:
		SET_BIT(SPI1->CR[0], DFF_BIT);
		break;
	}

	switch(My_SPI.BiDiMode)
	{
	case SPI_FullDuplex:
		CLR_BIT(SPI1->CR[0], BIDIMODE_BIT);
		break;
	case SPI_UniDirection:
		SET_BIT(SPI1->CR[0], BIDIMODE_BIT);
	    switch(My_SPI.BiDiOutEn)
	    {
	    case SPI_ReceiveOnly:
			CLR_BIT(SPI1->CR[0], BIDIOE_BIT);
	    	break;
	    case SPI_TransmitOnly:
			SET_BIT(SPI1->CR[0], BIDIOE_BIT);
	    	break;
	    }
		break;
	}

	//2- ENABLE SPI
	SET_BIT(SPI1->CR[0], SPE_BIT);
}


u16 MSPI_u16SendReceive(u16 Data)
{
	u16 ReceivedData;
  SPI1->DR = Data;
  while(GET_BIT(SPI1->SR, BSY_BIT) == 1)
  {
	  asm("NOP");
  }

  ReceivedData = SPI1->DR;
  return ReceivedData;
}


#endif /* MCAL_SPI_SPI_PROG_C_ */

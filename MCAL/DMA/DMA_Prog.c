/*
 * NAME: DMA_Prog.c
 *
 * Created on: Aug 27, 2023
 *
 * Author: Mo'men Ahmed
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "DMA_Prv.h"
#include "DMA_Config.h"
#include "DMA_Interface.h"

void (*GlobalPtr_CallBackPtr0) (void) = NULL;

extern DMA_Config_t My_DMA;

void MDMA_vInit(void)
{
 //1-MAKE SURE DMA IS DISABLED
	CLR_BIT(DMA2->S[0].CR, DMA_EN_BIT);

//2- MAKE THE REQUIRED OPTIONS
	DMA2->S[0].CR &= (~(0b111UL) << 25);
	DMA2->S[0].CR |= (My_DMA.Channel << 25);

	DMA2->S[0].CR &= (~(0b11UL) << 23);
	DMA2->S[0].CR |= (My_DMA.MemBurstMode << 23);

	DMA2->S[0].CR &= (~(0b11UL) << 21);
	DMA2->S[0].CR |= (My_DMA.PerBurstMode << 21);

	DMA2->S[0].CR &= (~(0b11UL) << 16);
	DMA2->S[0].CR |= (My_DMA.Priority_level << 16);

	switch (My_DMA.PerIncMode)
	{
	case DMA_PSize:
		CLR_BIT(DMA2->S[0].CR , DMA_PINCOS_BIT);
		break;
	case DMA_Fixed_32 :
		SET_BIT(DMA2->S[0].CR , DMA_PINCOS_BIT);
		break;
	}

	DMA2->S[0].CR &= (~(0b11U) << 13);
	DMA2->S[0].CR |= (My_DMA.MemDataSize << 13);

	DMA2->S[0].CR &= (~(0b11U) << 11);
	DMA2->S[0].CR |= (My_DMA.PerDataSize << 11);

	switch (My_DMA.MemIncMode)
	{
	case DMA_MemFixedPtr:
		CLR_BIT(DMA2->S[0].CR , DMA_MINC_BIT);
		break;
	case DMA_MemIncPtr :
		SET_BIT(DMA2->S[0].CR , DMA_MINC_BIT);
		break;
	}

	switch (My_DMA.PerIncMode)
	{
	case DMA_PerFixedPtr:
		CLR_BIT(DMA2->S[0].CR , DMA_PINC_BIT);
		break;
	case DMA_PerIncPtr :
		SET_BIT(DMA2->S[0].CR , DMA_PINC_BIT);
		break;
	}

	DMA2->S[0].CR &= (~(0b11U) << 6);
	DMA2->S[0].CR |= (My_DMA.DataTransferDirection << 6);

	switch (My_DMA.PerFlowCtrl)
	{
	case DMA_DMACtrl:
		CLR_BIT(DMA2->S[0].CR , DMA_PFCTRL_BIT);
		break;
	case DMA_PerCtrl :
		SET_BIT(DMA2->S[0].CR , DMA_PFCTRL_BIT);
		break;
	}

	switch (My_DMA.CircMode)
	{
	case DMA_CircModeDisabled:
		CLR_BIT(DMA2->S[0].CR , DMA_CIRC_BIT);
		break;
	case DMA_CircModeEnabled :
		SET_BIT(DMA2->S[0].CR , DMA_CIRC_BIT);
		break;
	}

}


void MDMA_vSetStream(u8  A_u8StreamId      , u32* A_pu32SrcAddress,
		             u32* A_pu32DestAddress ,u16 A_u16NumOfDataElements)
{
  DMA2->S[A_u8StreamId].NDTR = A_u16NumOfDataElements;
  DMA2->S[A_u8StreamId].PAR  = (u32)A_pu32SrcAddress;
  DMA2->S[A_u8StreamId].M0AR = (u32)A_pu32DestAddress;
}

void MDMA_vEnableStream(u8  A_u8StreamId)
{
	//1- SET THE REQUIRED INTERRUPT ENBALES
	switch (My_DMA.TCIE)
	{
	case DMA_TCIE_Disabled:
		CLR_BIT(DMA2->S[0].CR , DMA_TCIE_BIT);
		break;
	case DMA_TCIE_Enabled :
		SET_BIT(DMA2->S[0].CR , DMA_TCIE_BIT);
		break;
	}

	switch (My_DMA.HTIE)
	{
	case DMA_HTIE_Disabled:
		CLR_BIT(DMA2->S[0].CR , DMA_HTIE_BIT);
		break;
	case DMA_HTIE_Enabled :
		SET_BIT(DMA2->S[0].CR , DMA_HTIE_BIT);
		break;
	}

	switch (My_DMA.TEIE)
	{
	case DMA_TEIE_Disabled:
		CLR_BIT(DMA2->S[0].CR , DMA_TEIE_BIT);
		break;
	case DMA_TEIE_Enabled :
		SET_BIT(DMA2->S[0].CR , DMA_TEIE_BIT);
		break;
	}

	switch (My_DMA.DMEIE)
	{
	case DMA_DMEIE_Disabled:
		CLR_BIT(DMA2->S[0].CR , DMA_DMEIE_BIT);
		break;
	case DMA_DMEIE_Enabled :
		SET_BIT(DMA2->S[0].CR , DMA_DMEIE_BIT);
		break;
	}

	//2- ENABLE THE DMA
	SET_BIT(DMA2->S[0].CR, DMA_EN_BIT);
}

void MDMA_vSetStreamCallback(u8  A_u8StreamId , void (*fptr)(void))
{
	GlobalPtr_CallBackPtr0 = fptr;
}

void MDMA_vClearIntFlag (u8 A_u8streamId , u8 A_u8IntID)
{
	if (A_u8streamId >= 0 && A_u8streamId <=3)
	{
		switch(A_u8streamId)
		{
		case 0:
		case 1:
			SET_BIT(DMA2->LIFCR ,  (2+6*A_u8streamId + A_u8IntID));
			break;
		case 2:
		case 3:
			SET_BIT(DMA2->LIFCR ,  (18+6*(A_u8streamId-2) + A_u8IntID));
            break;
		}
	}
	else if(A_u8streamId >= 4 && A_u8streamId <=7)
	{
		switch(A_u8streamId)
		{
		case 0:
		case 1:
			SET_BIT(DMA2->HIFCR ,  (2+6*A_u8streamId + A_u8IntID));
			break;
		case 2:
		case 3:
			SET_BIT(DMA2->HIFCR ,  (18+6*(A_u8streamId-2) + A_u8IntID));
            break;
		}
	}
}

//ISR OF STREAM 0
void DMA2_Stream0_IRQHandler(void)
{
	if(GlobalPtr_CallBackPtr0 != NULL)
	{
		GlobalPtr_CallBackPtr0();
	}
}

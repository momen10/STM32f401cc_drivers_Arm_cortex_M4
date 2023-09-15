/*
 * NAME: DMA_Interface.h
 *
 * Created on: Aug 27, 2023
 *
 * Author: Mo'men Ahmed
 */

#ifndef MCAL_DMA_DMA_INTERFACE_H_
#define MCAL_DMA_DMA_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


void MDMA_vInit(void);
void MDMA_vSetStream(u8  A_u8StreamId      , u32* A_pu32SrcAddress,
		             u32* A_pu32DestAddress ,u16 A_u16NumOfDataElements);

void MDMA_vEnableStream(u8  A_u8StreamId);
void MDMA_vSetStreamCallback(u8  A_u8StreamId , void (*fptr)(void));
void MDMA_vClearIntFlag (u8 A_u8streamId , u8 A_u8IntID);

typedef enum{
	 DMEIE_ID ,TEIF_ID ,  HTIF_ID  ,TCIF_ID
}DMA_IntID_t;

typedef enum{
	DMA_CH0, DMA_CH1,  DMA_CH2,  DMA_CH3,
	DMA_CH4, DMA_CH5,  DMA_CH6,  DMA_CH7,
}DMA_ChannelSelect_t;

typedef enum{
	DMA_MemSingleTransfer, DMA_MemINC4, DMA_MemINC8, DMA_MemINC16
}DMA_MemBurstConfig_t;

typedef enum{
	DMA_PerSingleTransfer, DMA_PerINC4, DMA_PerINC8, DMA_PerINC16
}DMA_PerBurstConfig_t;

typedef enum{
	DMA_LowPr, DMA_MediumPr, DMA_HighPr, DMA_VeryHighPr
}DMA_PriorityLevel_t;

typedef enum{
	DMA_PSize , DMA_Fixed_32
}DMA_PerIncOffSize;

typedef enum{
	DMA_MemByte, DMA_MemHalfWord, DMA_MemWord
}DMA_MemDataSize;

typedef enum{
	DMA_PerByte, DMA_PerHalfWord, DMA_PerWord
}DMA_PerDataSize;

typedef enum{
	DMA_MemFixedPtr, DMA_MemIncPtr
}DMA_MemIncMode_t;

typedef enum{
	DMA_PerFixedPtr, DMA_PerIncPtr
}DMA_PerIncMode_t;

typedef enum{
	DMA_PerToMem, DMA_MemToPer,
	DMA_MemToMem //ONLY VALID IN DMA2
}DMA_DataTransferDir_t;

typedef enum{
	DMA_DMACtrl,  DMA_PerCtrl
}DMA_PerFlowCtrl;

typedef enum{
	DMA_CircModeDisabled, DMA_CircModeEnabled
}DMA_CircMode_t;

typedef enum{
	DMA_TCIE_Disabled,  DMA_TCIE_Enabled
}DMA_TransferCompleteIntEn;

typedef enum{
	DMA_HTIE_Disabled,  DMA_HTIE_Enabled
}DMA_HalfTransferIntEn;

typedef enum{
	DMA_TEIE_Disabled,  DMA_TEIE_Enabled
}DMA_TransferErrorIntEn;

typedef enum{
	DMA_DMEIE_Disabled,  DMA_DMEIE_Enabled
}DMA_DirectModeErrorIntEn;

typedef struct {
	DMA_ChannelSelect_t       Channel;
	DMA_MemBurstConfig_t      MemBurstMode;
	DMA_PerBurstConfig_t      PerBurstMode;
	DMA_PriorityLevel_t       Priority_level;
	DMA_PerIncOffSize         IncSize;
	DMA_MemDataSize           MemDataSize;
	DMA_PerDataSize           PerDataSize;
	DMA_MemIncMode_t          MemIncMode;
	DMA_PerIncMode_t          PerIncMode;
	DMA_DataTransferDir_t     DataTransferDirection;
	DMA_PerFlowCtrl           PerFlowCtrl;
	DMA_CircMode_t            CircMode;
	DMA_TransferCompleteIntEn TCIE;
	DMA_HalfTransferIntEn     HTIE;
	DMA_TransferErrorIntEn    TEIE;
	DMA_DirectModeErrorIntEn  DMEIE;
}DMA_Config_t;
#endif /* MCAL_DMA_DMA_INTERFACE_H_ */

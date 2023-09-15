/*
 * NAME :Flash_Prog.c
 *
 * Created on: Aug 31, 2023
 *
 * Author: Mo'men Ahmed
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "FMI_Interface.h"
#include "FMI_Prv.h"
#include "FMI_Config.h"

void MFMI_vEraseAppArea(FMI_SectorNum_t A_u8StartingSector)
{
  for (u8 i = A_u8StartingSector ; i< FLASH_NUM_OF_SECTORS ; i++)
  {
	  MFMI_vEraseSector(i);
  }
}

void MFMI_vEraseSector(FMI_SectorNum_t A_u8SectorNum)
{
	//1- CHECK THAT BUSY FLAG IS CLEARED
	while(GET_BIT(FMI->SR, FMI_BSY_BIT) == 1);
	//2- UNLOCK FLASH CONTROL REG USING KEY REGISTER
	if(GET_BIT(FMI->CR , FMI_LOCK_BIT) == 1)
	{
		FMI->KEYR = FMI_KEY1;
		FMI->KEYR = FMI_KEY2;
	}
	//3-SELECT WHICH SECTOR YOU WANT TO ERASE
	//3-a- CLEAR THE REQUIRED 4 BITS
	FMI->CR &= ~((u32)(0b1111 << 3));
	//3-b- INSERT THE REQUIRED SECTOR
	FMI->CR |= (A_u8SectorNum << 3);

	//4- SET THE SECTOR ERASE BIT
	SET_BIT(FMI->CR, FMI_SER_BIT);

	//5-START THE OPERATION
	SET_BIT(FMI->CR, FMI_STRT_BIT);

	//6-WAIT FOR THE BUSY FLAG TO BE CLEARED
    while(GET_BIT(FMI->SR , FMI_BSY_BIT) == 1);

	//7-CLEAR THE EOP FLAG
    SET_BIT(FMI->SR, FMI_EOP_BIT);

    //8-DESELECT THE ERASE ENABLE
	CLR_BIT(FMI->CR, FMI_SER_BIT);

}
void MFMI_vFlashWrite(FMI_WriteOperationData* WriteStruct)
{
	//1- CHECK THAT BUSY FLAG IS CLEARED
	while(GET_BIT(FMI->SR, FMI_BSY_BIT) == 1);
	//2- UNLOCK FLASH CONTROL REG USING KEY REGISTER
	if(GET_BIT(FMI->CR , FMI_LOCK_BIT) == 1)
	{
		FMI->KEYR = FMI_KEY1;
		FMI->KEYR = FMI_KEY2;
	}

	//3- SELECT THE PSIZE
	//a) CLEAR THE REQ 2 BITS
	FMI->CR &= ~((u32)(0b11 << 8));
	//b) SET THE REQ PSIZE
	FMI->CR |= (WriteStruct->PSize << 8);

	//4-SET THE PROGRAM BIT
	SET_BIT(FMI->CR, FMI_PG_BIT);

	//5-START THE OPERATION
//	SET_BIT(FMI->CR, FMI_STRT_BIT);

	//6-WRITE THE DATA ARRAY IN FLASH ADDRESS
	for (u16 i=0 ; i<WriteStruct->DataSize; i++)
	{
		*((volatile u16*)(WriteStruct->StartAddress)) = WriteStruct->Data[i];
		//WAIT FOR THE BUSY FLAG
		while(GET_BIT(FMI->SR, FMI_BSY_BIT) == 1);
		//INCREMENT THE ADDRESS
		WriteStruct->StartAddress +=2;
		//CLEAR THE EOP BITS
	    SET_BIT(FMI->SR, FMI_EOP_BIT);
	}

	//7- DEACTIVATE THE WRITE MODE
	CLR_BIT(FMI->CR, FMI_PG_BIT);
}



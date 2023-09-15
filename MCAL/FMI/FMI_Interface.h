/*
 * NAME :Flash_Interface.h
 *
 * Created on: Aug 31, 2023
 *
 * Author: Mo'men Ahmed
 */

#ifndef MCAL_FMI_FMI_INTERFACE_H_
#define MCAL_FMI_FMI_INTERFACE_H_

typedef enum{
	FMI_SEC0 , FMI_SEC1 , FMI_SEC2,
	FMI_SEC3,  FMI_SEC4,  FMI_SEC5
}FMI_SectorNum_t;

typedef enum{
	FMI_Byte, FMI_HalfWord,
	FMI_Word, FMI_DoubleWord
}FMI_PSIZE_t;

typedef struct{
	u32          StartAddress;
	u16*         Data;
	u16          DataSize;
	FMI_PSIZE_t  PSize;
}FMI_WriteOperationData;

void MFMI_vEraseAppArea(FMI_SectorNum_t A_u8StartingSector);
void MFMI_vEraseSector(FMI_SectorNum_t A_u8SectorNum);
void MFMI_vFlashWrite(FMI_WriteOperationData* WriteStruct);


#endif /* MCAL_FMI_FMI_INTERFACE_H_ */

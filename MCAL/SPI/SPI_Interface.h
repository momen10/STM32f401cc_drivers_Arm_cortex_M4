/*
 * NAME :SPI_Interface.h
 *
 * Created on: Aug 23, 2023
 *
 * Author: Mo'men Ahmed
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

typedef enum{
	Leading_Rising, Leading_Falling
}MSPI_ClockPolarity_t;

typedef enum{
	Sample_First , Setup_First
}MSPI_ClockPhase_t;

typedef enum{
	Slave, Master
}MSPI_Mode_t;

typedef enum{
	SPI_FCPU_2, SPI_FCPU_4,  SPI_FCPU_8,   SPI_FCPU_16,
	SPI_FCPU_32,SPI_FCPU_64, SPI_FCPU_128, SPI_FCPU_256
}MSPI_BaudRate_t;

typedef enum{
	SSM_Disable, SSM_Enable
}MSPI_SoftwareSlaveManage_t;

typedef enum{
	SSI_Disable, SSI_ForceActive
}MSPI_SlaveSelectInternal_t;

typedef enum{
	SPI_8Bits , SPI_16Bits
}MSPI_DataFrameFormat_t;

typedef enum{
	SPI_FullDuplex, SPI_UniDirection
}MSPI_BidiMode_t;

typedef enum{
	SPI_ReceiveOnly ,SPI_TransmitOnly
}MSPI_BidiOutEn_t;

typedef struct {
	MSPI_ClockPolarity_t         Polarity;
	MSPI_ClockPhase_t            Phase;
	MSPI_Mode_t                  Mode;
	MSPI_BaudRate_t              BaudeRate;
	MSPI_SoftwareSlaveManage_t   SSM;
	MSPI_SlaveSelectInternal_t   SSI;
	MSPI_DataFrameFormat_t       DataFormat;
	MSPI_BidiMode_t              BiDiMode;
	MSPI_BidiOutEn_t             BiDiOutEn;
}MSPI_Config_t;

void MSPI_vInit (void);
u16 MSPI_u16SendReceive(u16);


#endif /* MCAL_SPI_SPI_INTERFACE_H_ */

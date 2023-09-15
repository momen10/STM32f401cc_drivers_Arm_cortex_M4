/*
 * NAME :SPI_Config.c
 *
 * Created on: Aug 23, 2023
 *
 * Author: Mo'men Ahmed
 */



#include "../../LIB/STD_TYPES.h"

#include "SPI_Interface.h"

MSPI_Config_t My_SPI ={
		.Mode = Master , .Polarity= Leading_Falling, .Phase = Setup_First,
		.DataFormat = SPI_8Bits, .SSM = SSM_Enable, .BiDiMode = SPI_FullDuplex,
		.BaudeRate = SPI_FCPU_2, .SSI = SSI_ForceActive
};


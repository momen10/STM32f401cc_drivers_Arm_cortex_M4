/*
 * NAME: DMA_Config.c
 *
 * Created on: Aug 27, 2023
 *
 * Author: Mo'men Ahmed
 */


#include "DMA_Interface.h"

DMA_Config_t My_DMA = {
 .MemDataSize = DMA_MemWord,   .PerDataSize = DMA_PerWord,
 .MemIncMode  = DMA_MemIncPtr, .PerIncMode  = DMA_PerIncPtr,
 .CircMode = DMA_CircModeEnabled, .DataTransferDirection = DMA_MemToMem,
 .TCIE = DMA_TCIE_Enabled
};


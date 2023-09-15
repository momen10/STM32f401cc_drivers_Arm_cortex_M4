/*
 * NAME: DMA_Prv.h
 *
 * Created on: Aug 27, 2023
 *
 * Author: Mo'men Ahmed
 */

#ifndef MCAL_DMA_DMA_PRV_H_
#define MCAL_DMA_DMA_PRV_H_

#define DMA1_BASE_ADDRESS  0x40026000
#define DMA2_BASE_ADDRESS  0x40026400

#define  DMA_EN_BIT       0
#define  DMA_PINCOS_BIT   15
#define  DMA_MINC_BIT     10
#define  DMA_PINC_BIT     9
#define  DMA_PFCTRL_BIT   5
#define  DMA_TCIE_BIT     4
#define  DMA_HTIE_BIT     3
#define  DMA_TEIE_BIT     2
#define  DMA_DMEIE_BIT    1
#define  DMA_CIRC_BIT     8

typedef struct{
	volatile u32 CR;
	volatile u32 NDTR;
	volatile u32 PAR;
	volatile u32 M0AR;
	volatile u32 M1AR;
	volatile u32 FCR;
}DMA_Stream_t;

typedef struct {
  volatile u32 LISR;
  volatile u32 HISR;
  volatile u32 LIFCR;
  volatile u32 HIFCR;
  volatile DMA_Stream_t S[8];
}DMA_MemMap_t;

#define DMA1  ((volatile DMA_MemMap_t*)(DMA1_BASE_ADDRESS))
#define DMA2  ((volatile DMA_MemMap_t*)(DMA2_BASE_ADDRESS))

#endif /* MCAL_DMA_DMA_PRV_H_ */

/*
 * NAME :SPI_prv.h
 *
 * Created on: Aug 23, 2023
 *
 * Author: Mo'men Ahmed
 */

#ifndef MCAL_SPI_SPI_PRV_H_
#define MCAL_SPI_SPI_PRV_H_

#define SPI1_BASE_ADDRESS   0x40013000
#define SPI2_BASE_ADDRESS   0x40003800
#define SPI3_BASE_ADDRESS   0x40003C00
#define SPI4_BASE_ADDRESS   0x40013400

#define CPHA_BIT      0
#define CPOL_BIT      1
#define MSTR_BIT      2
#define SSM_BIT       9
#define SSI_BIT       8
#define DFF_BIT       11
#define BIDIMODE_BIT  15
#define BIDIOE_BIT    14
#define SPE_BIT       6
#define BSY_BIT       7

typedef struct {
	u32 CR[2];
	u32 SR;
	u32 DR;
	u32 CRCPR;
	u32 RXCRCR;
	u32 TXCRCR;
	u32 I2SCFGR;
	u32 I2SPR;
}MSPI_MemMap_t;

#define SPI1  ((volatile MSPI_MemMap_t *)(SPI1_BASE_ADDRESS))
#define SPI2  ((volatile MSPI_MemMap_t *)(SPI2_BASE_ADDRESS))
#define SPI3  ((volatile MSPI_MemMap_t *)(SPI3_BASE_ADDRESS))
#define SPI4  ((volatile MSPI_MemMap_t *)(SPI4_BASE_ADDRESS))

#endif /* MCAL_SPI_SPI_PRV_H_ */

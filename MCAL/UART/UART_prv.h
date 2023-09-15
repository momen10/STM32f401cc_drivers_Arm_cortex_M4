/*
 * NAME :UART_prv.h
 *
 * Created on: Aug 23, 2023
 *
 * Author: Mo'men Ahmed
 */

#ifndef MCAL_UART_UART_PRV_H_
#define MCAL_UART_UART_PRV_H_

#include "../../LIB/STD_TYPES.h"

#define UART_DIV_SAMPLING16(_PCLK_, _BAUD_)            ((u32)((((u64)(_PCLK_))*25U)/(4U*((u64)(_BAUD_)))))
#define UART_DIVMANT_SAMPLING16(_PCLK_, _BAUD_)        (UART_DIV_SAMPLING16((_PCLK_), (_BAUD_))/100U)
#define UART_DIVFRAQ_SAMPLING16(_PCLK_, _BAUD_)        ((((UART_DIV_SAMPLING16((_PCLK_), (_BAUD_)) - (UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) * 100U)) * 16U) + 50U) / 100U)
/* UART BRR = mantissa + overflow + fraction
            = (UART DIVMANT << 4) + (UART DIVFRAQ & 0xF0) + (UART DIVFRAQ & 0x0FU) */
#define UART_BRR_SAMPLING16(_PCLK_, _BAUD_)            ((UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) << 4U) + \
                                                        (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0xF0U) + \
                                                        (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0x0FU))

#define UART_DIV_SAMPLING8(_PCLK_, _BAUD_)             ((u32)((((u64)(_PCLK_))*25U)/(2U*((u64)(_BAUD_)))))
#define UART_DIVMANT_SAMPLING8(_PCLK_, _BAUD_)         (UART_DIV_SAMPLING8((_PCLK_), (_BAUD_))/100U)
#define UART_DIVFRAQ_SAMPLING8(_PCLK_, _BAUD_)         ((((UART_DIV_SAMPLING8((_PCLK_), (_BAUD_)) - (UART_DIVMANT_SAMPLING8((_PCLK_), (_BAUD_)) * 100U)) * 8U) + 50U) / 100U)
/* UART BRR = mantissa + overflow + fraction
            = (UART DIVMANT << 4) + ((UART DIVFRAQ & 0xF8) << 1) + (UART DIVFRAQ & 0x07U) */
#define UART_BRR_SAMPLING8(_PCLK_, _BAUD_)             ((UART_DIVMANT_SAMPLING8((_PCLK_), (_BAUD_)) << 4U) + \
                                                        ((UART_DIVFRAQ_SAMPLING8((_PCLK_), (_BAUD_)) & 0xF8U) << 1U) + \
                                                        (UART_DIVFRAQ_SAMPLING8((_PCLK_), (_BAUD_)) & 0x07U))
#define UART_FAIL             0
#define UART_SUCCESS          1

    // CR1 REGISTER BITS
#define UART_OVER8_BIT        15
#define UART_M_BIT            12
#define UART_PCE_BIT          10
#define UART_PS_BIT           9
#define UART_RE_BIT           2
#define UART_PEIE_BIT         8
#define UART_RXNEIE_BIT       5
#define UART_TCIE_BIT         6
#define UART_TXEIE_BIT        7
#define UART_UE_BIT           13

// CR2 REGISTER BITS
#define UART_STOP0_BIT        12

// CR3 REGISTER BITS
#define UART_ONEBIT_BIT       11

//SR REGISTER BITS
#define UART_TXE_BIT          7
#define UART_TC_BIT           6
#define UART_RXNE_BIT         5



typedef struct {
	u32 SR;
	u32 DR;
	u32 BRR;
	u32 CR[3];
	u32 GTPR;
}UART_MemMap_t;



#endif /* MCAL_UART_UART_PRV_H_ */

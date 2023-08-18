/*
 * RCC_prv.h
 *
 *  Created on: Jun 29, 2023
 *      Author:  Mo'men
 */

#ifndef MCAL_RCC_PRV_H_
#define MCAL_RCC_PRV_H_
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#define RCC_BASE_ADDR   0x40023800

//RCC REGISTER MAP
typedef struct{
u32 CR;
u32 PLLCFGR;
u32 CFGR;
u32 CIR;
u32 AHB1RSTR;
u32 AHB2RSTR;
u32 reserved1;
u32 reserved2;
u32 APB1RSTR;
u32 APB2RSTR;
u32 reserved3;
u32 reserved4;
u32 AHB1ENR;
u32 AHB2ENR;
u32 reserved5;
u32 reserved6;
u32 APB1ENR;
u32 APB2ENR;
u32 reserved7;
u32 reserved8;
u32 AHB1LPENR;
u32 AHB2LPENR;
u32 reserved9;
u32 reserved10;
u32 APB1LPENR;
u32 APB2LPENR;
u32 reserved11;
u32 reserved12;
u32 BDCR;
u32 CSR;
u32 reserved13;
u32 reserved14;
u32 SSCGR;
u32 PLLI2SCFGR;
u32 reserved15;
u32 DCKCFGR;
}RCC_MemMap_t;

//pointer to structure including all RCC REGISTERS. pointing to first register
//and the offset is calculated by the compiler depending on the size of each element
#define RCC ((volatile RCC_MemMap_t*) RCC_BASE_ADDR)

//options of system clock source
#define   HSI     0
#define   HSE     1
#define   PLL     2



//RCC bits definitions:
#define HSEON    16
#define HSEBYP   18
#define CSSON    19
#define PLLON    24
#define HSION    0
#define HSITRIM0 3
#define HSITRIM1 4
#define HSITRIM2 5
#define HSITRIM3 6
#define HSITRIM4 7
#define HSICAL0  8
#define HSICAL1  9
#define HSICAL2  10
#define HSICAL3  11
#define HSICAL4  12
#define HSICAL5  13
#define HSICAL6  14
#define HSICAL7  15
#define SW0      0
#define SW1      1

//AHB PRESCALER OPTIONS
#define AHB_FCPU          7
#define AHB_FCPU_2        8
#define AHB_FCPU_4        9
#define AHB_FCPU_8        10
#define AHB_FCPU_16       11
#define AHB_FCPU_64       12
#define AHB_FCPU_128      13
#define AHB_FCPU_256      14
#define AHB_FCPU_512      15

//HSE BYPASSING OPTIONS:
#define HSE_NOT_BYPASSED  0
#define HSE_BYPASSED      1


#endif /* MCAL_RCC_PRV_H_ */

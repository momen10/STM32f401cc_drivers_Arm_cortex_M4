/*
 * RCC_cfg.h
 *
 *  Created on: Jun 29, 2023
 *      Author:  Mo'men
 */

#ifndef MCAL_RCC_CFG_H_
#define MCAL_RCC_CFG_H_

#include "RCC_prv.h"

/*options of system clock:
 * 1- HSI
 * 2- HSE
 * 3- PLL
 *  */
#define SYSTEM_CLOCK  HSI

//HSE options
#if SYSTEM_CLOCK == HSE
/*              HSE bypassing options
 * 1- HSE_NOT_BYPASSED
 * 2- HSE_BYPASSED*/
#define HSE_BYPASSING    HSE_NOT_BYPASSED
#endif



//PLL options:
/* P values : 2,4,,6,8
 * N range : 192 -> 432
 * M range : 2 -> 63*/
#if SYSTEM_CLOCK == PLL
#define PLLP          2
#define PLLN          192
#define PLLM          2
#define HSI_PLL_INPUT 0
#define HSE_PLL_INPUT 1
//PLL input options : 1- HSI_PLL_INPUT , 2- HSE_PLL_INPUT
#define PLL_SOURCE    HSI_PLL_INPUT
#endif

/*              AHB PRESCALER OPTIONS :
 * 1-RCC_FCPU      2-RCC_FCPU_2    3-RCC_FCPU_4
 * 4-RCC_FCPU_8    5-RCC_FCPU_16   6-RCC_FCPU_64
 * 7-RCC_FCPU_128  8-RCC_FCPU_256  9-RCC_FCPU_512
 * */
#define AHB_PRESCALER     AHB_FCPU_2

#endif /* MCAL_RCC_CFG_H_ */

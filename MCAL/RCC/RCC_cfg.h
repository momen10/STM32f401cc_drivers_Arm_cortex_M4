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
#define SYSTEM_CLOCK  HSE

//HSE options
#if SYSTEM_CLOCK == HSE
#define HSE_NOT_BYPASSED  0
#define HSE_BYPASSED      1
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

/*HSE bypassing options
 * 1- HSE_NOT_BYPASSED
 * 2- HSE_BYPASSED*/
#define HSE_BYPASSING    HSE_NOT_BYPASSED


#endif /* MCAL_RCC_CFG_H_ */

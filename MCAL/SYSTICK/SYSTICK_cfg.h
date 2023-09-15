/*
 * NAME :SYSTICK_cfg.h
 *
 * Created on: Jul 17, 2023
 *
 * Author: Mo'men Ahmed
 */

#ifndef MCAL_SYSTICK_SYSTICK_CFG_H_
#define MCAL_SYSTICK_SYSTICK_CFG_H_

#include "SYSTICK_prv.h"

//systick clock sources: STK_AHB OR STK_AHB_8
#define STK_CLK_SOURCE   STK_AHB_8

//systick options for interrupt enable: STK_INT_EN STK_INT_DIS
#define STK_INT_OPTION   STK_INT_EN


#endif /* MCAL_SYSTICK_SYSTICK_CFG_H_ */

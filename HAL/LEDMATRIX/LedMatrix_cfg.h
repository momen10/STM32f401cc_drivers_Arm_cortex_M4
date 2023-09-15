/*
 * NAME :LedMatrix_cfg.h
 *
 * Created on: Jul 24, 2023
 *     
 * Author: Mo'men Ahmed
 */

#ifndef HAL_LEDMATRIX_LEDMATRIX_CFG_H_
#define HAL_LEDMATRIX_LEDMATRIX_CFG_H_

#include "../../MCAL/GPIO/GPIO_int.h"
#include "LedMatrix_prv.h"

//METHODS OPTIONS :1- DIRECT_METHOD , 2-SHIFT_REG_METHOD
#define LED_MTX_METHOD     SHIFT_REG_METHOD

#define NO_ROWS    8
#define NO_COLS    8
#define ON_TIME    2.5 //milliseconds

//I have to extern the variables of configuration in config.c file
extern MGPIO_Config_t rows[NO_ROWS];
extern MGPIO_Config_t cols[NO_COLS];


#endif /* HAL_LEDMATRIX_LEDMATRIX_CFG_H_ */

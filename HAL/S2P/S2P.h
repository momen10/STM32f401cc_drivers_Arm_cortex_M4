/*
 * NAME : S2P.h
 *
 * Created on: Jul 25, 2023
 *
 * Author: Mo'men Ahmed
 */

#ifndef HAL_S2P_S2P_H_
#define HAL_S2P_S2P_H_

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_int.h"

#define NO_OF_SHIFT_REG    2

void HS2P_vInit(void);
void HS2P_vSendData(u16 data);




#endif /* HAL_S2P_S2P_H_ */

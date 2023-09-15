/*
 * NAME: TFT_Interface.h
 *
 * Created on: Aug 25, 2023
 *
 * Author: Mo'men Ahmed
 */

#ifndef HAL_TFT_TFT_INTERFACE_H_
#define HAL_TFT_TFT_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"


void HTFT_vSendCommand(u16 A_u16Command);
void HTFT_vSendData(u16 A_u16Data);
void HTFT_vInit(void);
void HTFT_vDisplayImg(const u16 * arr);
void TFT_vResetSequence(void);


#endif /* HAL_TFT_TFT_INTERFACE_H_ */

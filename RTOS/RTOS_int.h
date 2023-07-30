/*
 * RTOS_config.h
 *
 *  Created on: Jul 27, 2023
 *      Author: Dell
 */

#ifndef RTOS_RTOS_INT_H_
#define RTOS_RTOS_INT_H_

#include "../LIB/STD_TYPES.h"

#include "RTOS_prv.h"

ErrorState RTOS_enCreateTask (void (*TaskHandler) (void), u8 priority,
		               u16 Copy_u16Period, u16 Copy_u16FirstDelay);

ErrorState RTOS_enDeleteTask (u8 Copy_u8Priority);
ErrorState RTOS_enSuspendTask(u8 Copy_u8Priority);
ErrorState RTOS_enResumeTask (u8 Copy_u8Priority);
void RTOS_vScheduler(void);
void RTOS_vStartOs(void);

#endif /* RTOS_RTOS_INT_H_ */

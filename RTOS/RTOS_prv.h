/*
 * RTOS_prv.h
 *
 *  Created on: Jul 27, 2023
 *      Author: Dell
 */

#ifndef RTOS_RTOS_PRV_H_
#define RTOS_RTOS_PRV_H_

#include "../LIB/STD_TYPES.h"

typedef enum{
	Dorment, Waiting, Running, Suspended
}TaskRunningState;

typedef struct{
  void (*TaskHandler)(void);
  u16 Periodicity;
  u16 First_Delay;
  TaskRunningState RunningState;
}Task;

typedef enum{
	No_Error ,Out_Of_Range , Reserved_Task, Not_Exist
}ErrorState;



#endif /* RTOS_RTOS_PRV_H_ */

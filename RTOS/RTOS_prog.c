/*
 * RTOS_prog.c

 *
 *  Created on: Jul 27, 2023
 *      Author: Dell
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "RTOS_cfg.h"
#include "RTOS_int.h"
#include "RTOS_prv.h"

#include "../MCAL/SYSTICK/SYSTICK_int.h"

//CREATE ALL SYSTEM TASKS AND INITIALIZE TO ZERO
Task System_Tasks[MAX_NUM_OF_TASKS] = {0} ;
//CREATE ARRAY FOR FIRST DELAYS OF ALL TASKS
u16  TaskTiming[MAX_NUM_OF_TASKS];
//DEFINING EMPTY TASK THAT IS INITIALZED TO ZERO
Task EmptyTask = {0};


u8 RTOS_vCreateTask (void (*TaskHandler) (void), u8 Copy_u8Priority,
		               u16 Copy_u16Period, u16 Copy_u16FirstDelay)
{
	ErrorState Local_u8ErrorState = No_Error;
	//CHECKING THAT THE PASSED PRIORITY WITHIN THE RANGE
	if(Copy_u8Priority < MAX_NUM_OF_TASKS)
	{
		//CHECKING THAT THIS INDEX IS NOT RESERVED TO ANOTHER TASK
		if(System_Tasks[Copy_u8Priority].TaskHandler != 0)
		{
			//according to passed priority, its index in array will be = priority
//			System_Tasks[Copy_u8Priority].First_Delay = Copy_u16FirstDelay;
            TaskTiming  [Copy_u8Priority]             = Copy_u16FirstDelay;
			System_Tasks[Copy_u8Priority].Periodicity = Copy_u16Period;
			System_Tasks[Copy_u8Priority].TaskHandler = TaskHandler;
		}
		else
		{
			Local_u8ErrorState = Reserved_Task;
		}
	}
	else
	{
        //OUT OF RANGE
		Local_u8ErrorState = Out_Of_Range;
	}
return Local_u8ErrorState;
}

ErrorState RTOS_enDeleteTask (u8 Copy_u8Priority)
{
	ErrorState local_enErrorState = No_Error;
	if(Copy_u8Priority < MAX_NUM_OF_TASKS)
	{
	  System_Tasks[Copy_u8Priority] = EmptyTask;
	}
	else
	{
		local_enErrorState = Out_Of_Range;
	}
	return local_enErrorState;
}

ErrorState RTOS_enSuspendTask(u8 Copy_u8Priority)
{
	ErrorState local_enErrorState = No_Error;
	if(Copy_u8Priority < MAX_NUM_OF_TASKS)
	{
		//CHECK THAT THE TASK EXISTS
		if(System_Tasks[Copy_u8Priority].TaskHandler != 0)
		{
			System_Tasks[Copy_u8Priority].RunningState = Suspended;
		}
		else
		{
			local_enErrorState = Not_Exist;
		}
	}
	else
	{
		local_enErrorState = Out_Of_Range;
	}
	return local_enErrorState;
}

ErrorState RTOS_enResumeTask (u8 Copy_u8Priority)
{
	ErrorState local_enErrorState = No_Error;
	if(Copy_u8Priority < MAX_NUM_OF_TASKS)
	{
		//CHECK THAT THE TASK EXISTS
		if(System_Tasks[Copy_u8Priority].TaskHandler != 0)
		{
			System_Tasks[Copy_u8Priority].RunningState = Running;
		}
		else
		{
			local_enErrorState = Not_Exist;
		}
	}
	else
	{
		local_enErrorState = Out_Of_Range;
	}
	return local_enErrorState;
}

void RTOS_vScheduler(void)
{
	//LOOPING OVER ALL SYSTEM TASKS AND RUN THE READY ONES ONLY
	//IN THE REQEUIRED TIME
	u8 local_u8Counter = 0;
	for (;local_u8Counter < MAX_NUM_OF_TASKS; local_u8Counter)
	{
		//CHECKING THAT THIS TASK EXISTS
		if(System_Tasks[local_u8Counter] .TaskHandler != 0)
		{
			//CHECKING THAT THE TIME OF THE TASK HAS COME
			if(TaskTiming[local_u8Counter] == 0)
			{
			    //RUN THE TASK
				System_Tasks[local_u8Counter].TaskHandler();
				//RELOAD THE VALUE OF PERIODICITY IN TIMING ARRAY
				TaskTiming [local_u8Counter] =
			             System_Tasks[local_u8Counter].Periodicity;
			}
			else
			{
				//DONOT RUN THE TASK AND DECREMENT TIMING BY ONE
				//TILL IT REACHES ZERO
				TaskTiming [local_u8Counter] -- ;
			}
		}
		else
		{

		}
	}
}

void RTOS_vStartOs(void)
{
	MSTK_vSetIntervalPeriodic(RTOS_TICK_TIME ,RTOS_vScheduler );
}

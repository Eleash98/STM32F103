//Author	:	Mohamed Gamal Eleish
//Date		:	11/10/2020
//Version	:	V01

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_Config.h"

#include "STK_interface.h"

#define 	NULL		0

static Task OS_Tasks[NUMBER_OF_TASKS]={NULL};

void OS_voidCreatTask(u8 Copy_u8TaskID,u16 Copy_u16Period,void (*Copy_voidPTR)(void),u16 Copy_u16FirstDelay)
{
	OS_Tasks[Copy_u8TaskID].Period = Copy_u16Period;
	OS_Tasks[Copy_u8TaskID].TaskHandler = Copy_voidPTR;
	OS_Tasks[Copy_u8TaskID].FirstDelay = Copy_u16FirstDelay;
	OS_Tasks[Copy_u8TaskID].State = READY;
}
void OS_voidStart(void)
{
	/*Initialization*/
	MSTK_voidInit();
	MSTK_voidSetIntervalPeriodic(1000,Scheduler);  /*1000 = one milli second*/
}

void OS_voidDeleteTask(u8 Copy_u8Priority)
{
	OS_Tasks[Copy_u8Priority].TaskHandler = NULL;
}

void OS_voidSuspendTask(u8 Copy_u8TaskID)
{
	OS_Tasks[Copy_u8TaskID].State = PAUSED;
}

void OS_voidResumeTask(u8 Copy_u8TaskID)
{
	OS_Tasks[Copy_u8TaskID].State = READY;
}


static void Scheduler(void)
{
	volatile u8 Local_u8TaskCounter = 0;
	for(Local_u8TaskCounter=0;Local_u8TaskCounter<NUMBER_OF_TASKS;Local_u8TaskCounter++)
	{
		if ((OS_Tasks[Local_u8TaskCounter].TaskHandler != NULL) && (OS_Tasks[Local_u8TaskCounter].State == READY)){
			if (OS_Tasks[Local_u8TaskCounter].FirstDelay == 0){
				OS_Tasks[Local_u8TaskCounter].FirstDelay = OS_Tasks[Local_u8TaskCounter].Period-1;
				OS_Tasks[Local_u8TaskCounter].TaskHandler();
			}
			else
			{
				OS_Tasks[Local_u8TaskCounter].FirstDelay--;
			}
		}
	}
}

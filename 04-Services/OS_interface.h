//Author	:	Mohamed Gamal Eleish
//Date		:	11/10/2020
//Version	:	V01

#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H



void OS_voidCreatTask(u8 Copy_u8TaskID,u16 Copy_u16Period,void (*Copy_voidPTR)(void),u16 Copy_u16FirstDelay);
void OS_voidStart(void);
void OS_voidDeleteTask(u8 Copy_u8TaskID);
void OS_voidSuspendTask(u8 Copy_u8TaskID);
void OS_voidResumeTask(u8 Copy_u8TaskID);
#endif


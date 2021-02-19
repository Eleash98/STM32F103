//Author	:	Mohamed Gamal Eleish
//Date		:	11/10/2020
//Version	:	V01


#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

#define READY		0
#define PAUSED		1

typedef struct{
	u16 Period;
	void (*TaskHandler)(void);
	u8 State;
	u16 FirstDelay;
}Task;

static void Scheduler(void);

#endif

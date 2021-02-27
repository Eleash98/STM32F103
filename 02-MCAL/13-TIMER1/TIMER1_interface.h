//Author	:	Mohamed G. Eleish
//Version	:	V01
//Date		:	20 FEB	2021


#ifndef TIMER1_INTERFACE
#define TIMER1_INTERFACE

/*External Trigger Clock Sources*/
#define TIMER1_CLOCK_EXTERNAL_T1		0
#define TIMER1_CLOCK_EXTERNAL_T2		1
#define TIMER1_CLOCK_EXTERNAL_T1_EDGE	2

/*Polarity*/
#define TIMER1_POLARITY_ACTIVE_HIGH		0
#define TIMER1_POLARITY_ACTIVE_LOW		1

/*Active Edge*/
#define TIMER1_EDGE_RISING				0
#define TIMER1_EDGE_FALLING				1

/*Internal Prescalars*/
#define TIMER1_PRESCALAR_1				0
#define TIMER1_PRESCALAR_2				1
#define TIMER1_PRESCALAR_4				2
#define TIMER1_PRESCALAR_8				3

/*Filters*/
#define TIMER1_FILTER_NO				0
#define TIMER1_FILTER_FCK_INT_N_2		1
#define TIMER1_FILTER_FCK_INT_N_4		2
#define TIMER1_FILTER_FCK_INT_N_8		3

#define TIMER1_FILTER_FDTS_2_N_6		4
#define TIMER1_FILTER_FDTS_2_N_8		5

#define TIMER1_FILTER_FDTS_4_N_6		6
#define TIMER1_FILTER_FDTS_4_N_8		7

#define TIMER1_FILTER_FDTS_8_N_6		8
#define TIMER1_FILTER_FDTS_8_N_8		9

#define TIMER1_FILTER_FDTS_16_N_5		10
#define TIMER1_FILTER_FDTS_16_N_6		11
#define TIMER1_FILTER_FDTS_16_N_8		12

#define TIMER1_FILTER_FDTS_32_N_5		13
#define TIMER1_FILTER_FDTS_32_N_6		14
#define TIMER1_FILTER_FDTS_32_N_8		15


/*Trigger Inputs for Internal Trigger mode*/
#define TIMER1_CLOCK_INTERNAL_T2		1
#define TIMER1_CLOCK_INTERNAL_T3		2
#define TIMER1_CLOCK_INTERNAL_T4		3

/*Slave Modes For the Timer*/
#define TIMER1_SLAVE_RESET_ON_EDGE		0
#define TIMER1_SLAVE_RUN_ON_LEVEL		1
#define TIMER1_SLAVE_COUNT_ON_EVENT		2

/*Slave Mode Pins*/
#define TIMER1_SLAVE_PIN_TI1			0
#define TIMER1_SLAVE_PIN_TI2			1

/*Slave Mode Events*/
#define TIMER1_SLAVE_EVENT_ACTIVE_HIGH	0
#define TIMER1_SLAVE_EVENT_ACTIVE_LOW	1

#define TIMER1_SLAVE_EVENT_RISING_EDGE	0
#define TIMER1_SLAVE_EVENT_FALLING_EDGE	1


/*Counting Direction*/
#define TIMER1_COUNTING_UP				0
#define TIMER1_COUNTING_DOWN			1

/*Alignment Mode*/
#define TIMER1_ALIGNMENT_EDGE			0
#define TIMER1_ALIGNMENT_CENTER_MODE1	1
#define TIMER1_ALIGNMENT_CENTER_MODE2	2
#define TIMER1_ALIGNMENT_CENTER_MODE3	3

/*Interrupts' IDs*/


/***********Module Configuration********/

void MTIM1_voidSetTimeBase(u16 Copy_u16Prescalar, u8 Copy_u8RepetitionCounter);

void MTIM1_voidSetClockInternal(u8 Copy_u8Direction);
void MTIM1_voidSetClockETRPin(u8 Copy_u8Polarity, u8 Copy_u8Prescalar, u8 Copy_u8Filter);
void MTIM1_voidSetClockExternalTrigger(u8 Copy_u8TimerInputPin, u8 Copy_u8Filter, u8 Copy_u8Edge);
void MTIM1_voidSetClockInternalTrigger(u8 Copy_u8InputTrigger);

void MTIM1_voidSetSlaveMode(u8 Copy_u8SlaveMode, u8 Copy_u8Event, u8 Copy_u8TimerInputPin, u8 Copy_u8Filter);

void MTIM1_voidEnableTimer(u16 Copy_u16Preload, u16 Copy_u16TopValue);

//void MTIM1_voidConfigureInputChannel(u8 Copy_u8ChannelID, u8 Copy_u8Filter, u8 Copy_u8Edge);

/*void MTIMER1_voidConfigureTriggerController(u8 Copy_u8Mode);

void MTIMER1_voidConfigureSlaveController(u8 Copy_u8Mode);

void MTIMER1_voidConfigureEncoder(u8 Copy_u8Mode);

void MTIMER1_voidConfigureInputChannel(u8 Copy_u8ChannelID, u8 Copy_u8Mode);

void MTIMER1_voidConfigureOutputChannel(u8 Copy_u8ChannelID, u8 Copy_u8Mode);
*/












/*
/////////////////////////////////////
void MTIMER1_voidStart(u16 Copy_u16PreLoad);

void MTIMER1_voidStop(void);

void MTIMER1_voidResume(void);
////////////////////////////////////

void MTIMER1_voidSetClockSource(u8 Copy_u8ClockSource);

void MTIMER1_voidSetCountingDirection(u8 Copy_u8Direction);

void MTIMER1_voidSetAlignment(u8 Copy_u8Alignment);

void MTIMER1_voidEnableAutoReloadPreload(void);

void MTIMER1_voidDisableAutoReloadPreload(void);

//void MTIMER1_voidSetCounter(u8 Copy_u8CounterID, u16 Copy_u16CounterValue);

u16 MTIMER1_u16GetCounterValue(u8 Copy_u8CounterID);

///////////////////////////////////////////////////////////
void MTIMER1_voidEnableInterrupt(u8 Copy_u8InterruptID);

void MTIMER1_voidDisableInterrupt(u8 Copy_u8InterruptID);

void MTIMER1_voidSetCallBack(u8 Copy_u8InterruptID, void(*CallBack));
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
void MTIMER1_voidSetIntervalSingle(u16 Copy_u16Ticks);

void MTIMER1_voidSetIntervalPeriodic(u16 Copy_u16Ticks);

void MTIMER1_voidSetBusyWait(u16 Copy_u16Ticks);

void MTIMER1_voidStopInterval(void);
///////////////////////////////////////////////////////////////

////////////////////////////////////////////////////
void MTIMER1_voidSetPrescalar(u16 Copy_u16Psc);

void MTIMER1_voidSetTopValue(u16 Copy_u16Value);

void MTIMER1_voidSetCompareValue(u8 Copy_u8ChannelID, u16 Copy_u16Value);

void MTIMER1_voidSetChannelFilter(u8 Copy_u8ChannelID, u8 Copy_u8Filter);

void MTIMER_voidSetCaptureLatch(u8 Copy_u8ChannelID, u8 Copy_u8SignalLatch);
/////////////////////////////////////////////////////


void MTIMER1_voidSetInputBreak(u8 Copy_u8State);
*/
#endif
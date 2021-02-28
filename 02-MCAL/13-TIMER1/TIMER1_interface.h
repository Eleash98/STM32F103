//Author	:	Mohamed G. Eleish
//Version	:	V01
//Date		:	20 FEB	2021


#ifndef TIMER1_INTERFACE
#define TIMER1_INTERFACE

/*****************General Constant Macros**********************/
/*Internal Prescalars*/
#define TIMER1_PRESCALAR_1				0
#define TIMER1_PRESCALAR_2				1
#define TIMER1_PRESCALAR_4				2
#define TIMER1_PRESCALAR_8				3

/*Filters*/
#define TIMER1_FILTER_NONE				0
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



/***************************Timer Settings**************************/
#define TIMER1_SETTING_FILTER_DIV_1				0
#define TIMER1_SETTING_FILTER_DIV_2				1
#define TIMER1_SETTING_FILTER_DIV_4				2
void MTIM1_voidConfigureFilterDivision(u8 Copy_u8Division);

#define TIMER1_CHANGE_IMMEDIATE					0
#define TIMER1_CHANGE_ON_NEXT_UPDATE			1
void MTIM1_voidConfigureTopValueChange(u8 Copy_u8Setting);
void MTIM1_voidConfigureCCControlChange(u8 Copy_u8Setting);

#define TIMER1_ONE_PULSE_MODE_DISABLED			0
#define TIMER1_ONE_PULSE_MODE_ENABLED			1
void MTIM1_voidConfigureOnePulseMode(u8 Copy_u8Mode);

#define TIMER1_UPDATE_SOURCE_ANY				0
#define TIMER1_UPDATE_SOURCE_OVER_UNDER_FLOW	1
void MTIM1_voidConfigureUpdateRequestSource(u8 Copy_u8Source);

#define TIMER1_CC_CONTROL_UPDATE_SRC_SW_ONLY		0
#define TIMER1_CC_CONTROL_UPDATE_SRC_SW_TRIG		1
void MTIM1_voidConfigureCCControlUpdateSource(u8 Copy_u8Source);

/***************Setting Time Base and clock source*****************/

/**************Constant macros************************/
/*
 * Only Used with clock setting functions
 */
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

/*Trigger Inputs for Internal Trigger mode*/
#define TIMER1_CLOCK_INTERNAL_T2		1
#define TIMER1_CLOCK_INTERNAL_T3		2
#define TIMER1_CLOCK_INTERNAL_T4		3

/*Counting Direction*/
#define TIMER1_COUNTING_UP				0
#define TIMER1_COUNTING_DOWN			1

/*Alignment Mode*/
#define TIMER1_ALIGNMENT_EDGE			0
#define TIMER1_ALIGNMENT_CENTER_MODE1	1/*Output compare interrupt flags Set when Down Counting*/
#define TIMER1_ALIGNMENT_CENTER_MODE2	2/*Output compare interrupt flags Set when Up Counting*/
#define TIMER1_ALIGNMENT_CENTER_MODE3	3/*Output compare interrupt flags Set when Up & Down Counting*/



void MTIM1_voidSetTimeBase(u8 Copy_u8Allignment, u16 Copy_u16Prescalar, u8 Copy_u8RepetitionCounter);

void MTIM1_voidSetClockInternal(void);
void MTIM1_voidSetClockETRPin(u8 Copy_u8Polarity, u8 Copy_u8Prescalar, u8 Copy_u8Filter);
void MTIM1_voidSetClockExternalTrigger(u8 Copy_u8TimerInputPin, u8 Copy_u8Filter, u8 Copy_u8Edge);
void MTIM1_voidSetClockInternalTrigger(u8 Copy_u8InputTrigger);


/********************Control the timer throughout external signals*************************/
/*
 * Only works with internal clock and External Trigger pin Mode (ETR)
 */
/*Slave Modes For the Timer*/
#define TIMER1_SLAVE_RESET_ON_EDGE		4
#define TIMER1_SLAVE_RUN_ON_LEVEL		5
#define TIMER1_SLAVE_COUNT_ON_EVENT		6

/*Slave Mode Pins*/
#define TIMER1_SLAVE_PIN_TI1			0
#define TIMER1_SLAVE_PIN_TI2			1

/*Slave Mode Events*/
#define TIMER1_SLAVE_EVENT_ACTIVE_HIGH	0
#define TIMER1_SLAVE_EVENT_ACTIVE_LOW	1

#define TIMER1_SLAVE_EVENT_RISING_EDGE	0
#define TIMER1_SLAVE_EVENT_FALLING_EDGE	1

void MTIM1_voidSetSlaveMode(u8 Copy_u8SlaveMode, u8 Copy_u8Event, u8 Copy_u8TimerInputPin, u8 Copy_u8Filter);


/***********************Controlling Other Timers from Timer1************************/
#define TIMER1_MASTER_UPDATE_GEN			0
#define TIMER1_MASTER_ENABLE				1
#define TIMER1_MASTER_UPDATE_EVENT			2
#define TIMER1_MASTER_CCI1_FLAG_SET			3
#define TIMER1_MASTER_OC1_FLAG_SET			4
#define TIMER1_MASTER_OC2_FLAG_SET			5
#define TIMER1_MASTER_OC3_FLAG_SET			6
#define TIMER1_MASTER_OC4_FLAG_SET			7

#define TIMER1_MASTER_SYNCH_ENABLED			1
#define TIMER1_MASTER_SYNCH_DISABLED		0

void MTIM1_voidSetMasterTrigOut(u8 Copy_u8TriggerSource, u8 Copy_u8SynchEnable);




/***********************Controlling  the Timer with Software****************************/
void MTIM1_voidEnableTimer(u8 Copy_u8Direction, u16 Copy_u16Preload, u16 Copy_u16TopValue);
void MTIM1_voidStartTimer(void);
void MTIM1_voidStopTimer(void);
void MTIM1_voidSetCounter(u16 Copy_u16CounterValue);
void MTIM1_voidSetTopValue(u16 Copy_u16TopValue);

void MTIM1_voidEnableUpdateEvent(void);
void MTIM1_voidDisableUpdateEvent(void);

/***************Interrupt ID's*************************/
#define TIMER1_INTERRUPT_UPDATE					0
#define TIMER1_INTERRUPT_CC1					1
#define TIMER1_INTERRUPT_CC2					2
#define TIMER1_INTERRUPT_CC3					3
#define TIMER1_INTERRUPT_CC4					4
#define TIMER1_INTERRUPT_COMMUTAION				5
#define TIMER1_INTERRUPT_TRIGGER				6
#define TIMER1_INTERRUPT_BREAK					7
#define TIMER1_INTERRUPT_UPDATE_DMA				8

void MTIM1_voidEnableInterrupt(u8 Copy_u8Interrupt);
void MTIM1_voidDisableInterrupt(u8 Copy_u8Interrupt);



/****************Generate Event By SW*******************/
#define TIMER1_GEN_EVENT_UPDATE			1
#define TIMER1_GEN_EVENT_CC1			2
#define TIMER1_GEN_EVENT_CC2			4
#define TIMER1_GEN_EVENT_CC3			8
#define TIMER1_GEN_EVENT_CC4			16
#define TIMER1_GEN_EVENT_CC_CTR_UPDATE	32
#define TIMER1_GEN_EVENT_TRIGGER		64
#define TIMER1_GEN_EVENT_BREAK			128

void MTIM1_voidGenerateEvent(u8 Copy_u8Event);





u16 MTIM1_u16GetCounter(void);





/***************************Timer Output Channels Control********************/
#define TIMER1_OUTPUT_CHANNEL1				0
#define TIMER1_OUTPUT_CHANNEL2				2
#define TIMER1_OUTPUT_CHANNEL3				4
#define TIMER1_OUTPUT_CHANNEL4				6

#define TIMER1_OUTPUT_COM_CHANNEL1			1
#define TIMER1_OUTPUT_COM_CHANNEL2			3
#define TIMER1_OUTPUT_COM_CHANNEL3			5


#define TIMER1_OUTPUT_IDLE_LOW				0
#define TIMER1_OUTPUT_IDLE_HIGH				1
void MTIM1_voidConfigureOutputIdle(u8 Copy_u8ChannelID, u8 Copy_u8IdleState);


/********************DMA With Timer1******************************/
#define TIMER1_DMA_SRC_REQUEST_ON_CC_EVENT			0
#define TIMER1_DMA_SRC_REQUEST_ON_UPDATE_EVENT		1
void MTIM1_voidConfigureDMARequestSource(u8 Copy_u8Source);

/**************DMA Requests*************************/
#define TIMER1_DMA_REQUEST_UPDATE					8
#define TIMER1_DMA_REQUEST_CC1						9
#define TIMER1_DMA_REQUEST_CC2						10
#define TIMER1_DMA_REQUEST_CC3						11
#define TIMER1_DMA_REQUEST_CC4						12
#define TIMER1_DMA_REQUEST_COMMUTATION				13
#define TIMER1_DMA_REQUEST_TRIGGER					14

void MTIM1_voidEnableDMARequest(u8 Copy_u8DMARequest);
void MTIM1_voidDisableDMARequest(u8 Copy_u8DMARequest);



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

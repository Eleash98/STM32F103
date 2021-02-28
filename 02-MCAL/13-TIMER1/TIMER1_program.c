//Author	:	Mohamed G. Eleish
//Version	:	V01
//Date		:	20 FEB	2021

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER1_interface.h"
#include "TIMER1_private.h"

/***************************Timer Settings**************************/

void MTIM1_voidConfigureFilterDivision(u8 Copy_u8Division)
{
	TIMER1->CR1 &= ~(0x300);
	TIMER1->CR1 |= ((Copy_u8Division & 3) << 8);
}

void MTIM1_voidConfigureTopValueChange(u8 Copy_u8Setting)
{
	CLR_BIT(TIMER1->CR1,7);
	TIMER1->CR1 |= ((Copy_u8Setting & 1) << 7);
}

void MTIM1_voidConfigureCCControlChange(u8 Copy_u8Setting)
{
	CLR_BIT(TIMER1->CR2,0);
	TIMER1->CR2 |= (Copy_u8Setting & 1);
}

void MTIM1_voidConfigureOnePulseMode(u8 Copy_u8Mode)
{
	CLR_BIT(TIMER1->CR1,3);
	TIMER1->CR1 |= ((Copy_u8Mode & 1) << 3);
}

void MTIM1_voidConfigureUpdateRequestSource(u8 Copy_u8Source)
{
	CLR_BIT(TIMER1->CR1,2);
	TIMER1->CR1 |= ((Copy_u8Source & 1) << 2);
}

void MTIM1_voidConfigureCCControlUpdateSource(u8 Copy_u8Source)
{
	CLR_BIT(TIMER1->CR2,1);
	TIMER1->CR2 |= ((Copy_u8Source & 1) <<1);
}

/***************Setting Time Base and clock source*****************/

void MTIM1_voidSetTimeBase(u8 Copy_u8Allignment, u16 Copy_u16Prescalar, u8 Copy_u8RepetitionCounter)
{
	TIMER1->CR1 &= ~(0x60);
	TIMER1->CR1 |= ((Copy_u8Allignment&3) << 5);
	TIMER1->PSC = Copy_u16Prescalar;
	TIMER1->RCR = Copy_u8RepetitionCounter;
}

void MTIM1_voidSetClockInternal(void)
{
	// Disable slave mode controller
	TIMER1->SMCR &= ~7;

}

void MTIM1_voidSetClockETRPin( u8 Copy_u8Polarity, u8 Copy_u8Prescalar, u8 Copy_u8Filter)
{
	TIMER1->SMCR &= ~(0xFF00);
	TIMER1->SMCR |= ((Copy_u8Polarity&1)<<15) | (1<<14) | ((Copy_u8Prescalar&3)<<12) | ((Copy_u8Filter&0xF)<<8);
}

void MTIM1_voidSetClockExternalTrigger( u8 Copy_u8TimerInputPin, u8 Copy_u8Filter, u8 Copy_u8Edge)
{
	if(Copy_u8TimerInputPin == TIMER1_CLOCK_EXTERNAL_T1)
	{	
		/*Disable the input capture unit*/
		TIMER1->CCER &= ~3;
		
		/*Clear filter & input fields*/
		TIMER1->CCMR1 &= ~(0xF3);
		
		/*Select the filter and the input channel to TI1 */
		TIMER1->CCMR1 |= (1 | ((Copy_u8Filter&0xF)<<4));
		
		/*Select the Edge*/
		TIMER1->CCER |= ((Copy_u8Edge&1)<<1);
		
		/*Clear the Slave mode selection*/
		TIMER1->SMCR &= ~((7<<4));
		
		/*Set Slave mode Selection and trigger selection*/
		TIMER1->SMCR |= (5<<4) | (7);
		
	}
	else if (Copy_u8TimerInputPin == TIMER1_CLOCK_EXTERNAL_T2)
	{
		TIMER1->CCER &= ~(0x30);
		
		TIMER1->CCMR1 &= ~(0xF300);
		
		TIMER1->CCMR1 |= (1<<8) | ((Copy_u8Filter&0xF)<<12);
		
		TIMER1->CCER |= ((Copy_u8Edge&1)<<5);
		
		TIMER1->SMCR &= ~((7<<4));
		
		TIMER1->SMCR |= (0x67);
		
	}
	else if (Copy_u8TimerInputPin == TIMER1_CLOCK_EXTERNAL_T1_EDGE)
	{
		/*Disable the input capture unit*/
		TIMER1->CCER &= ~3;
		
		/*Select the Edge*/
		TIMER1->CCER |= ((Copy_u8Edge&1)<<1);
		
		/*Clear the Slave mode selection*/
		TIMER1->SMCR &= ~((7<<4));
		
		/*Set Slave mode Selection and trigger selection*/
		TIMER1->SMCR |= (4<<4) | (7);
		
	}
}
void MTIM1_voidSetClockInternalTrigger( u8 Copy_u8InputTrigger)
{
	TIMER1->SMCR &= ~(0x70);
	TIMER1->SMCR |= ((Copy_u8InputTrigger&7) << 4) | 7;
}

/********************Control the timer throughout external signals*************************/
/*
 * Only works with internal clock and External Trigger pin Mode (ETR)
 */
void MTIM1_voidSetSlaveMode(u8 Copy_u8SlaveMode, u8 Copy_u8Event, u8 Copy_u8TimerInputPin, u8 Copy_u8Filter)
{

	if(Copy_u8TimerInputPin == TIMER1_SLAVE_PIN_TI1)
	{
		/*Disable the input capture unit*/
		TIMER1->CCER &= ~3;
		
		/*Clear filter & input fields*/
		TIMER1->CCMR1 &= ~(0xF3);
		
		/*Select the filter and the input channel to TI1 */
		TIMER1->CCMR1 |= (1 | ((Copy_u8Filter&0xF)<<4));
		
		/*Select the Edge*/
		TIMER1->CCER |= ((Copy_u8Event&1)<<1);
		
		/*Clear the Slave mode selection*/
		TIMER1->SMCR &= ~((7<<4));
		
		/*Set Slave mode Selection and trigger selection*/
		TIMER1->SMCR |= (5<<4) | (Copy_u8SlaveMode);
	}
	else if (Copy_u8TimerInputPin == TIMER1_SLAVE_PIN_TI2)
	{
		/*Disable the input capture unit*/
		TIMER1->CCER &= ~(0x30);
		
		/*Clear filter & input fields*/
		TIMER1->CCMR1 &= ~(0xF300);
		
		/*Select the filter and the input channel to TI2 */
		TIMER1->CCMR1 |= (0x100 | ((Copy_u8Filter&0xF)<<12));
		
		/*Select the Edge*/
		TIMER1->CCER |= ((Copy_u8Event&1)<<5);
		
		/*Clear the Slave mode selection*/
		TIMER1->SMCR &= ~((7<<4));
		
		/*Set Slave mode Selection and trigger selection*/
		TIMER1->SMCR |= (6<<4) | (Copy_u8SlaveMode);
	}

	if(Copy_u8SlaveMode == TIMER1_SLAVE_COUNT_ON_EVENT)
		TOG_BIT(TIMER1->CCER,5);
}


/***********************Controlling  the Timer with Software****************************/
void MTIM1_voidEnableTimer(u8 Copy_u8Direction, u16 Copy_u16Preload, u16 Copy_u16TopValue)
{

	CLR_BIT(TIMER1->CR1,4);
	TIMER1->CR1 |= Copy_u8Direction<<4;

	TIMER1->CNT = Copy_u16Preload;
	
	TIMER1->ARR = Copy_u16TopValue;
	
	SET_BIT(TIMER1->CR1, 0);
}
void MTIM1_voidStartTimer(void)
{
	SET_BIT(TIMER1->CR1, 0);
}
void MTIM1_voidStopTimer(void)
{
	CLR_BIT(TIMER1->CR1, 0);
}
void MTIM1_voidSetCounter(u16 Copy_u16CounterValue)
{
	TIMER1->CNT = Copy_u16CounterValue;
}
void MTIM1_voidSetTopValue(u16 Copy_u16TopValue)
{
	TIMER1->ARR = Copy_u16TopValue;
}

void MTIM1_voidEnableUpdateEvent(void)
{
	CLR_BIT(TIMER1->CR1,1);
}

void MTIM1_voidDisableUpdateEvent(void)
{
	SET_BIT(TIMER1->CR1,1);
}

void MTIM1_voidGenerateEvent(u8 Copy_u8Event)
{
	TIMER1->EGR = Copy_u8Event;
}

void MTIM1_voidEnableInterrupt(u8 Copy_u8Interrupt)
{
	if(Copy_u8Interrupt > 7)
		return;
	SET_BIT(TIMER1->DIER,Copy_u8Interrupt);
}
void MTIM1_voidDisableInterrupt(u8 Copy_u8Interrupt)
{
	if(Copy_u8Interrupt > 7)
		return;
	CLR_BIT(TIMER1->DIER,Copy_u8Interrupt);
}

/***********************Controlling Other Timers from Timer1************************/
void MTIM1_voidSetMasterTrigOut(u8 Copy_u8TriggerSource, u8 Copy_u8SynchEnable)
{
	TIMER1->CR2	&= ~(0x70);
	TIMER1->CR2 |= ((Copy_u8TriggerSource & 7) << 4);

	CLR_BIT(TIMER1->SMCR,7);
	TIMER1->SMCR |= ((Copy_u8SynchEnable & 1) << 7);
}












u16 MTIM1_u16GetCounter(void)
{
	return TIMER1->CNT;
}




/***************************Timer Output Channels Control********************/
void MTIM1_voidConfigureOutputIdle(u8 Copy_u8ChannelID, u8 Copy_u8IdleState)
{
	if(Copy_u8ChannelID > 6)
		return;
	CLR_BIT(TIMER1->CR2,(Copy_u8ChannelID+8));
	TIMER1->CR2 |= ((Copy_u8IdleState & 1) << (Copy_u8ChannelID+8));
}


/********************DMA With Timer1******************************/
void MTIM1_voidConfigureDMARequestSource(u8 Copy_u8Source)
{
	CLR_BIT(TIMER1->CR2,3);
	TIMER1->CR2 |= ((Copy_u8Source & 1) << 3);
}

void MTIM1_voidEnableDMARequest(u8 Copy_u8DMARequest)
{
	if(Copy_u8DMARequest > 13 || Copy_u8DMARequest < 8)
		return;
	SET_BIT(TIMER1->DIER,Copy_u8DMARequest);
}
void MTIM1_voidDisableDMARequest(u8 Copy_u8DMARequest)
{
	if(Copy_u8DMARequest > 13 || Copy_u8DMARequest < 8)
		return;
	CLR_BIT(TIMER1->DIER,Copy_u8DMARequest);
}



/*
/////////////////////////////////////
void MTIMER1_voidStart(u16 Copy_u16PreLoad)
{
	TIMER1->CNT = Copy_u16PreLoad;
	SET_BIT(TIMER1->CR1,0);
}

void MTIMER1_voidStop(void)
{
	CLR_BIT(TIMER1->CR1,0);
}

void MTIMER1_voidResume(void)
{
	SET_BIT(TIMER1->CR1,0);
}
////////////////////////////////////

void MTIMER1_voidSetClockSource(u8 Copy_u8ClockSource);

void MTIMER1_voidSetCountingDirection(u8 Copy_u8Direction)
{
	if(Copy_u8Direction == TIMER1_COUNTING_UP)
		CLR_BIT(TIMER1->CR1,4);
	else
		SET_BIT(TIMER1->CR1,4);
}

void MTIMER1_voidSetAlignment(u8 Copy_u8Alignment)
{
	TIMER1->CR1 &= ~(3<<5);
	TIMER1->CR1 |= ((Copy_u8Alignment & 3) << 5);
}

void MTIMER1_voidEnableAutoReloadPreload(void)
{
	SET_BIT(TIMER1->CR1,7);
}

void MTIMER1_voidDisableAutoReloadPreload(void)
{
	CLR_BIT(TIMER1->CR1,7);
}


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

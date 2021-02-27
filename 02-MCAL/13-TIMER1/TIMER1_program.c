//Author	:	Mohamed G. Eleish
//Version	:	V01
//Date		:	20 FEB	2021

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER1_interface.h"
#include "TIMER1_private.h"


void MTIM1_voidSetTimeBase(u16 Copy_u16Prescalar, u8 Copy_u8RepetitionCounter)
{
	TIMER1->PSC = Copy_u16Prescalar;
	TIMER1->RCR = Copy_u8RepetitionCounter;
}

void MTIM1_voidSetClockInternal(u8 Copy_u8Direction)
{
	// Disable slave mode controller
	TIMER1->SMCR &= ~7;
	
	//configure direction
	CLR_BIT(TIMER1->CR1,4);
	
	TIMER1->CR1	|= ((Copy_u8Direction&1) << 4);
}

void MTIM1_voidSetClockETRPin(u8 Copy_u8Polarity, u8 Copy_u8Prescalar, u8 Copy_u8Filter)
{
	TIMER1->SMCR &= ~(0xFF00);
	TIMER1->SMCR |= ((Copy_u8Polarity&1)<<15) | (1<<14) | ((Copy_u8Prescalar&3)<<12) | ((Copy_u8Filter&0xF)<<8);
}

void MTIM1_voidSetClockExternalTrigger(u8 Copy_u8TimerInputPin, u8 Copy_u8Filter, u8 Copy_u8Edge)
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
void MTIMER1_voidSetClockInternalTrigger(u8 Copy_u8InputTrigger)
{
	TIMER1->SMCR &= ~(0x70);
	TIMER1->SMCR |= ((Copy_u8InputTrigger&7) << 4) | 7;
}


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
		TIMER1->CCER |= ((Copy_u8Edge&1)<<1);
		
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
		TIMER1->CCER |= ((Copy_u8Edge&1)<<5);
		
		/*Clear the Slave mode selection*/
		TIMER1->SMCR &= ~((7<<4));
		
		/*Set Slave mode Selection and trigger selection*/
		TIMER1->SMCR |= (6<<4) | (Copy_u8SlaveMode);
	}
}


void MTIM1_voidEnableTimer(u16 Copy_u16Preload, u16 Copy_u16TopValue)
{
	TIMER1->CNT = Copy_u16Preload;
	
	TIMER1->ARR = Copy_u16TopValue;
	
	SET_BIT(TIMER1->CR1, 0);
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
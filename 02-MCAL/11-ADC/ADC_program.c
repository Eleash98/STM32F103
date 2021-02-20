/*****************************************/
/* Author  :  Mohamed G. Eleish          */
/* Version :  V01                        */
/* Date    : 19 FEB 2021	             */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"



#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"



void  MADC1_voidInit(u8 Copy_u8Mode)
{
	switch(Copy_u8Mode)
	{
		case ADC1_MODE_SINGLE_CHANNEL_SINGLE_CONVERSION:
			//Clear Scan Bit
			CLR_BIT(ADC1->CR1,8);
			//Clear Cont Bit
			CLR_BIT(ADC1->CR2,1);
			break;
		case ADC1_MODE_SINGLE_CHANNEL_CONTINOUS_CONVERSION:
			//Clear Scan Bit
			CLR_BIT(ADC1->CR1,8);
			//SET Cont Bit
			SET_BIT(ADC1->CR2,1);
			break;
		case ADC1_MODE_MULTI_CHANNEL_SINGLE_CONVERSION:
			//SET Scan Bit
			SET_BIT(ADC1->CR1,8);
			//Clear Cont Bit
			CLR_BIT(ADC1->CR2,1);
			break;
		case ADC1_MODE_MULTI_CHANNEL_CONTINOUS_CONVERSION:
			//SET Scan Bit
			SET_BIT(ADC1->CR1,8);
			//SET Cont Bit
			SET_BIT(ADC1->CR2,1);
			break;
		case ADC1_MODE_DUAL_ADC:

			break;
		default:
			break;
	}
	//Enable the ADC
	SET_BIT(ADC1->CR2,0);
}






void MADC1_voidClearAnalogWatchdog(void)
{
	CLR_BIT(ADC1->CR1,23);
	CLR_BIT(ADC1->CR1,22);
}

void MADC1_voidSetSingleChannel(u8 Copy_u8ChannelType, u8 Copy_u8ChannelNumber)
{
	if(Copy_u8ChannelType == ADC1_CHANNEL_INJECTED)
		ADC1->JSQR = Copy_u8ChannelNumber<<15;
	else
		ADC1->SQR[3] = Copy_u8ChannelNumber;
}

u16 MADC1_u16ReadChannel(u8 Copy_u8ChannelType, u8 Copy_u8ChannelNumber)
{
	if(Copy_u8ChannelType == ADC1_CHANNEL_INJECTED)
	{
		ADC1->JSQR = Copy_u8ChannelNumber<<15;
		SET_BIT(ADC1->CR2,0);
		while(!GET_BIT(ADC1->SR,2));
		return MADC1_u16ReadInjectedData(Copy_u8ChannelNumber);
	}
	else
	{
		ADC1->SQR[3] = Copy_u8ChannelNumber;
		SET_BIT(ADC1->CR2,0);
		while(!GET_BIT(ADC1->SR,1));
		return MADC1_u16ReadRegularData();
	}

}

void MADC1_voidDisableExternalTrigger(u8 Copy_u8GroupType)
{
	if(Copy_u8GroupType == ADC1_CHANNEL_INJECTED)
		CLR_BIT(ADC1->CR2,15);
	else if(Copy_u8GroupType == ADC1_CHANNEL_REGULAR)
		CLR_BIT(ADC1->CR2,20);

}


void MADC1_voidStopContinous(void)
{
	CLR_BIT(ADC1->CR2,1);
}

void MADC1_voidStopADC(void)
{
	CLR_BIT(ADC1->CR2,0);
}

void MADC1_voidSetAutoInjectedConversion(void)
{
	SET_BIT(ADC1->CR1,10);
}

void MADC1_voidClearAutoInjectedConversion(void)
{
	CLR_BIT(ADC1->CR1,10);
}



void MADC1_voidSetDiscontinousMode(u8 Copy_u8GroupType, u8 Copy_u8NumberofChannels)
{
	ADC1->CR1 &= ~(7<<13);
	ADC1->CR1 |= (Copy_u8NumberofChannels & 7);

	if (Copy_u8GroupType == ADC1_CHANNEL_INJECTED)
		SET_BIT(ADC1->CR1,12);
	else if (Copy_u8GroupType == ADC1_CHANNEL_REGULAR)
		SET_BIT(ADC1->CR1,11);
}


void MADC_voidCallBack(u8 Copy_u8CallBackType, void(*ptr))
{
	if (ptr == 0)
		return;
	switch(Copy_u8CallBackType)
	{
		case ADC1_INTERRUPT_REGULAR_EOC:
			RegularEndOfCoversionHandler = ptr;
			break;
		case ADC1_INTERRUPT_INJECTED_EOC:
			InjectedEndOfConversionHandler = ptr;
			break;
		case ADC1_INTERRUPT_ANALOG_WATCHDOG:
			AnalogWatchdogHandler = ptr;
			break;
		default:
		break;
	}
}


/*Calibrates the ADC and returns the offset value*/
u16 MADC_u16Calibrate(void)
{	
	SET_BIT(ADC1->CR2,2);
	
	while(GET_BIT(ADC1->CR2,2));
	
	return ADC1->DR;
}

/*Sets the channels to be converted and theire priority in regular group*/
void MADC1_voidConfigureRegularGroup(u8 Copy_u8NumberOfChannels, u8 *Copy_u8PtrChannels, u8 *Copy_u8PtrChannelOrder)
{
	SET_BIT(ADC1->CR2,0);
	if (Copy_u8NumberOfChannels > 16)
		return;
	/*Insert the Number of channels*/
	ADC1->SQR[0] &= ~(0xF<<20);
	ADC1->SQR[0] |= (Copy_u8NumberOfChannels<<20);
	
	/*Insert the Channels Sequence*/
	while(Copy_u8NumberOfChannels != 255)
	{
		if(*Copy_u8PtrChannelOrder >= 1 && *Copy_u8PtrChannelOrder <= 6)
		{
			ADC1->SQR[2] &= ~(0x1F << ((*Copy_u8PtrChannelOrder-1)*5));
			ADC1->SQR[2] |= (*Copy_u8PtrChannels) << ((*Copy_u8PtrChannelOrder-1)*5);
		}
		else if(*Copy_u8PtrChannelOrder >= 7 && *Copy_u8PtrChannelOrder <= 12)
		{
			
			ADC1->SQR[1] &= ~(0x1F << ((*Copy_u8PtrChannelOrder - 7)*5));
			ADC1->SQR[1] |= (*Copy_u8PtrChannels) << ((*Copy_u8PtrChannelOrder - 7)*5);
		}
		else if(*Copy_u8PtrChannelOrder >= 13 && *Copy_u8PtrChannelOrder <= 16)
		{
			ADC1->SQR[0] &= ~(0x1F << ((*Copy_u8PtrChannelOrder - 13)*5));
			ADC1->SQR[0] |= (*Copy_u8PtrChannels) << ((*Copy_u8PtrChannelOrder - 13)*5);
		}
		else
		{
			
		}
		Copy_u8NumberOfChannels--;
		Copy_u8PtrChannelOrder++;
		Copy_u8PtrChannels++;
	}
}

/*Sets the channels to be converted and their priority in Injected group*/
void MADC1_voidConfigureInjectedGroup(u8 Copy_u8NumberOfChannels, u8 *Copy_u8PtrChannels, u8 *Copy_u8PtrChannelOrder)
{
	if(Copy_u8NumberOfChannels > 4)
		return;

	/*Insert Sequence Length*/
	ADC1->JSQR	&= ~(3<<20);
	ADC1->JSQR	|=	(Copy_u8NumberOfChannels<<20);
	

	/*Insert Channel Sequence*/
	u8 Local_u8Offset = 4-Copy_u8NumberOfChannels;
	while(Copy_u8NumberOfChannels != 255)
	{
		if(*Copy_u8PtrChannelOrder > Copy_u8NumberOfChannels)
			break;

		ADC1->JSQR	&= ~(0x1F << ((*Copy_u8PtrChannelOrder+Local_u8Offset-1)*5));
		ADC1->JSQR	|= (*Copy_u8PtrChannels) << ((*Copy_u8PtrChannelOrder+Local_u8Offset-1)*5);

		Copy_u8NumberOfChannels--;
		Copy_u8PtrChannelOrder++;
		Copy_u8PtrChannels++;
	}
	
}

/*Starts converting the Regular Group*/
void MADC1_voidStartRegularGroup(void)
{
	SET_BIT(ADC1->CR2,22);
}

/*Starts converting the Injected Group*/
void MADC1_voidStartInjectedGroup(void)
{
	SET_BIT(ADC1->CR2,21);
}

/*Sets the External Trigger type for injected or regular group*/
void MADC1_voidSetExternalTrigger(u8 Copy_u8GroupType, u8 Copy_u8Trigger)
{
	if(Copy_u8GroupType == ADC1_CHANNEL_INJECTED)
	{
		ADC1->CR2 &= ~(7<<12);
		ADC1->CR2 |= ((Copy_u8Trigger&7)<<12);
		SET_BIT(ADC1->CR2,15);
	}
	else if (Copy_u8GroupType == ADC1_CHANNEL_REGULAR)
	{
		ADC1->CR2 &= ~(7<<17);
		ADC1->CR2 |= ((Copy_u8Trigger&7)<<17);
		SET_BIT(ADC1->CR2,20);
	}
}


/*Enables Specific interrupt*/
void MADC1_voidEnableInterrupt(u8 Copy_u8Interrupt)
{
	if(Copy_u8Interrupt > 2)
		return;
	SET_BIT(ADC1->CR1,(Copy_u8Interrupt+5));
}

/*Disables Specific Interrupt*/
void MADC1_voidDisableInterrupt(u8 Copy_u8Interrupt)
{
	if(Copy_u8Interrupt > 2)
		return;
	CLR_BIT(ADC1->CR1,(Copy_u8Interrupt+5));
}

/*Returns the Status of Interrupt*/
u8 MADC1_u8GetInterruptStatus(u8 Copy_u8Interrupt)
{
	if(Copy_u8Interrupt > 2)
		return 255;
	return GET_BIT(ADC1->CR1,(Copy_u8Interrupt+5));
}

/*returns the Status of ADC flags*/
u8 MADC1_u8GetFlag(u8 Copy_u8Flag)
{
	if(Copy_u8Flag > 4)
		return 255;
	return GET_BIT(ADC1->SR,Copy_u8Flag);
}

/*Clears a Specific Flag*/
void MADC1_voidClearFlag(u8 Copy_u8Flag)
{
	if(Copy_u8Flag > 4)
		return;
	CLR_BIT(ADC1->SR,Copy_u8Flag);
}

/*Sets the Conversion Time for specific channel*/
void MADC1_voidSetConversionTime(u8 Copy_u8Channel, u8 Copy_u8ConversionTime)
{
	if (Copy_u8Channel >= 1 && Copy_u8Channel <= 10)
	{
		ADC1->SMPR2 &= ~(7 << ((Copy_u8Channel) *3));
		ADC1->SMPR2 |= (Copy_u8ConversionTime & 0x7) << ((Copy_u8Channel-1) *3);
	}
	else if (Copy_u8Channel >= 11 && Copy_u8Channel <= 18)
	{
		ADC1->SMPR1 &= ~(7 << ((Copy_u8Channel-10) *3));
		ADC1->SMPR1 |= (Copy_u8ConversionTime & 0x7) << ((Copy_u8Channel-11) *3);
	}
}

/*Reads the Internal Temperature Sensor Reading*/
s8 MADC1_s8ReadTemperature(void);

/*Reads The Internal reference voltage value*/
s8 MADC1_s8ReadInternalRef(void);

/*Enables DMA Request for regular or injected group*/
void MADC1_voidSetDMARequest(void)
{
	SET_BIT(ADC1->CR2,8);
}

/*Disables DMA Request for regular or injected group*/
void MADC1_voidClearDMARequest(void)
{
	CLR_BIT(ADC1->CR2,8);
}

/*Sets the Limits for the Analog WatchDog*/
void MADC1_voidSetAnalogWatchdog(u8 Copy_u8GroupType, u8 Copy_u8Mode, u8 Copy_u8ChannelNumber, u16 Copy_u16UpperLimit, u16 Copy_u16LowerLimit)
{
	if(Copy_u8GroupType == ADC1_CHANNEL_INJECTED)
	{
		CLR_BIT(ADC1->CR1,23);
		SET_BIT(ADC1->CR1,22);
	}
	else if(Copy_u8GroupType == ADC1_CHANNEL_REGULAR)
	{
		CLR_BIT(ADC1->CR1,22);
		SET_BIT(ADC1->CR1,23);
	}
	else if(Copy_u8GroupType == ADC1_CHANNEL_BOTH)
	{
		SET_BIT(ADC1->CR1,23);
		SET_BIT(ADC1->CR1,22);
	}
	else
		return;
	if(Copy_u8Mode == ADC1_WATCHDOG_SINGLE_CHANNEL)
		SET_BIT(ADC1->CR1,9);
	else if (Copy_u8Mode == ADC1_WATCHDOG_ALL_CHANNELS)
		CLR_BIT(ADC1->CR1,9);

	ADC1->CR1 &= ~(0x1F);
	ADC1->CR1 |= Copy_u8ChannelNumber & 0x1F;
	ADC1->HTR = Copy_u16UpperLimit;
	ADC1->LTR = Copy_u16LowerLimit;
}





/*Reads the Value of regular Data Register*/
u16 MADC1_u16ReadRegularData(void)
{
	u16 Local_u16Reading = GET_BIT(ADC1->CR2,11) == ADC1_ALLIGNMENT_LEFT? (ADC1->DR>>4):(ADC1->DR&0xFFF);
	return Local_u16Reading;
}

/*Reads the Value of an injected data Register*/
u16 MADC1_u16ReadInjectedData(u8 Copy_u8ChannelNumber)
{
	if(Copy_u8ChannelNumber > 4)
		return 0xFFFF;
	u16 Local_u16Reading = GET_BIT(ADC1->CR2,11) == ADC1_ALLIGNMENT_LEFT? (ADC1->JDR[Copy_u8ChannelNumber-1]>>3):(ADC1->JDR[Copy_u8ChannelNumber-1]&0x1FFF);
	return Local_u16Reading;
}

void MADC1_voidSetDataAlignment(u8 Copy_u8Alignment)
{
	if(Copy_u8Alignment == ADC1_ALLIGNMENT_RIGHT)
		CLR_BIT(ADC1->CR2,11);
	else
		SET_BIT(ADC1->CR2,11);
}

void MADC1_voidSetInjectedOffset(u8 Copy_u8Channel, u16 Copy_u16OffsetValue)
{
	if(Copy_u8Channel > 4)
		return;
	ADC1->JOFR[Copy_u8Channel-1] = Copy_u16OffsetValue & 0xFFF;
}

u32 *MADC1_u32PtrGetRegularDataAddress(void)
{
	return &(ADC1->DR);
}

/* ISR interrupt function for channel 1 */
void ADC1_2_IRQHandler(void)
{
	u8 Flag = ADC1->SR & 7;
	if(Flag != 0)
	{
		if(GET_BIT(Flag,0) == 1 && AnalogWatchdogHandler != 0)
		{
			AnalogWatchdogHandler();
			CLR_BIT(ADC1->SR,0);
		}
		if(GET_BIT(Flag,1) == 1 && RegularEndOfCoversionHandler != 0)
		{
			RegularEndOfCoversionHandler(MADC1_u16ReadRegularData());
			CLR_BIT(ADC1->SR,1);
		}
		if(GET_BIT(Flag,2) == 1 && InjectedEndOfConversionHandler != 0)
		{
			InjectedEndOfConversionHandler();
			CLR_BIT(ADC1->SR,2);
		}

	}
};

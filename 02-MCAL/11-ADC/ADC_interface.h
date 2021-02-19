/*****************************************/
/* Author  :  Mohamed G. Eleish          */
/* Version :  V01                        */
/* Date    : 19 FEB 2021	             */
/*****************************************/
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/*Alignment Options*/
#define ADC1_ALLIGNMENT_RIGHT		0
#define ADC1_ALLIGNMENT_LEFT		1

/*Interrupts*/
#define ADC1_INTERRUPT_REGULAR_EOC			0
#define ADC1_INTERRUPT_ANALOG_WATCHDOG		1
#define ADC1_INTERRUPT_INJECTED_EOC			2


/*Conversion Time*/
#define ADC1_CONVERSION_1_5_CYCLES			0
#define ADC1_CONVERSION_7_5_CYCLES			1
#define ADC1_CONVERSION_13_5_CYCLES			2
#define ADC1_CONVERSION_28_5_CYCLES			3
#define ADC1_CONVERSION_41_5_CYCLES			4
#define ADC1_CONVERSION_55_5_CYCLES			5
#define ADC1_CONVERSION_71_5_CYCLES			6
#define ADC1_CONVERSION_239_5_CYCLES		7

/*Flags*/
#define ADC1_FLAG_ANALOG_WATCHDOG			0
#define ADC1_FLAG_REGULAR_EOC				1
#define ADC1_FLAG_INJECTED_EOC				2
#define ADC1_FLAG_INJECTED_START			3
#define ADC1_FLAG_REGULAR_START				4

/*Channel & Group Types*/
#define ADC1_CHANNEL_INJECTED				0
#define ADC1_CHANNEL_REGULAR				1
#define ADC1_CHANNEL_BOTH					2	//Applicable only in SetWatchDogMode

/*External Triggers for Regular Group*/
#define ADC1_REG_EXT_TRIG_TIMER1_CC1		0
#define ADC1_REG_EXT_TRIG_TIMER1_CC2		1
#define ADC1_REG_EXT_TRIG_TIMER1_CC3		2
#define ADC1_REG_EXT_TRIG_TIMER2_CC2		3
#define ADC1_REG_EXT_TRIG_TIMER3_TRGO		4
#define ADC1_REG_EXT_TRIG_TIMER4_CC4		5
#define ADC1_REG_EXT_TRIG_EXTI_LINE11		6
#define ADC1_REG_EXT_TRIG_SW_START			7

/*External Triggers for Injected Group*/
#define ADC1_INJ_EXT_TRIG_TIMER1_TRGO		0
#define ADC1_INJ_EXT_TRIG_TIMER1_CC4		1
#define ADC1_INJ_EXT_TRIG_TIMER2_TRGO		2
#define ADC1_INJ_EXT_TRIG_TIMER2_CC1		3
#define ADC1_INJ_EXT_TRIG_TIMER3_CC4		4
#define ADC1_INJ_EXT_TRIG_TIMER4_TRGO		5
#define ADC1_INJ_EXT_TRIG_EXTI_LIN15		6
#define ADC1_INJ_EXT_TRIG_SW_START			7


/*Analog WatchDog Modes*/
#define ADC1_WATCHDOG_SINGLE_CHANNEL		0
#define ADC1_WATCHDOG_ALL_CHANNELS			1




/* Configuration of the adc */
void  MADC1_voidInit(u8 Copy_u8Mode);

void MADC1_voidClearAnalogWatchdog(void);

void MADC1_voidSetSingleChannel(u8 Copy_u8ChannelType, u8 Copy_u8Channel);

u16 MADC1_u16ReadChannel(u8 Copy_u8ChannelType, u8 Copy_u8ChannelNumber);

void MADC1_voidDisableExternalTrigger(u8 Copy_u8GroupType);

void MADC1_voidStopContinous(void);

void MADC1_voidStopADC(void);

void MADC1_voidClearAutoInjectedConversion(void);

void MADC1_voidSetAutoInjectedConversion(void);

void MADC1_voidSetDiscontinousMode(u8 Copy_u8GroupType, u8 Copy_u8NumberofChannels);

/* Collect the function will process in the interrupt */
void  MADC1_voidSetCallBack(u8 Copy_u8CallBackType,void(*ptr));

/*Calibrates the ADC and returns the offset value*/
u16 MADC_u16Calibrate(void);

/*Sets the channels to be converted and their priority in regular group*/
void MADC1_voidConfigureRegularGroup(u8 Copy_u8NumberOfChannels, u8 *Copy_u8PtrChannels, u8 *Copy_u8PtrChannelOrder);

/*Sets the channels to be converted and their priority in Injected group*/
void MADC1_voidConfigureInjectedGroup(u8 Copy_u8NumberOfChannels, u8 *Copy_u8PtrChannels, u8 *Copy_u8PtrChannelOrder);

/*Starts converting the Regular Group*/
void MADC1_voidStartRegularGroup(void);

/*Starts converting the Injected Group*/
void MADC1_voidStartInjectedGroup(void);

/*Sets the External Trigger type for injected or regular group*/
void MADC1_voidSetExternalTrigger(u8 Copy_u8GroupType, u8 Copy_u8Trigger);

/*Enables Specific interrupt*/
void MADC1_voidEnableInterrupt(u8 Copy_u8Interrupt);

/*Disables Specific Interrupt*/
void MADC1_voidDisableInterrupt(u8 Copy_u8Interrupt);

/*Returns the Status of Interrupt Flag*/
u8 MADC1_u8GetInterruptStatus(u8 Copy_u8Interrupt);

/*returns the Status of ADC flags*/
u8 MADC1_u8GetFlag(u8 Copy_u8Flag);

/*Clears a Specific Flag*/
void MADC1_voidClearFlag(u8 Copy_u8Flag);

/*Sets the Conversion Time for specific channel*/
void MADC1_voidSetConversionTime(u8 Copy_u8Channel, u8 Copy_u8ConversionTime);

/*Reads the Internal Temperature Sensor Reading*/
s8 MADC1_s8ReadTemperature(void);

/*Reads The Internal reference voltage value*/
s8 MADC1_s8ReadInternalRef(void);

/*Enables DMA Request for regular or injected group*/
void MADC1_voidSetDMARequest(u8 Copy_u8Group,u8 Copy_u8NumberOfChannels);

/*Disables DMA Request for regular or injected group*/
void MADC1_voidClearDMARequest(u8 Copy_u8Group,u8 Copy_u8NumberOfChannels);

/*Sets the Limits for the Analog WatchDog*/
void MADC1_voidSetAnalogWatchdog(u8 Copy_u8GroupType, u8 Copy_u8Mode, u8 Copy_u8ChannelNumber, u16 Copy_u16UpperLimit, u16 Copy_u16LowerLimit);

/*Reads the Value of regular Data Register*/
u16 MADC1_u16ReadRegularData(void);

/*Reads the Value of an injected data Register*/
u16 MADC1_u16ReadInjectedData(u8 Copy_u8ChannelNumber);

void MADC1_voidSetDataAlignment(u8 Copy_u8Alignment);

void MADC1_voidSetInjectedOffset(u8 Copy_u8Channel, u16 Copy_u16OffsetValue);


#endif

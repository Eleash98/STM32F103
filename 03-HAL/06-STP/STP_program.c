//Author	:	Mohamed Gamal Eleish
//Version	:	V01
//Date		:	28 FEB 2021
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"

#include "DIO_interface.h"
//#include "STK_interface.h"


void __delay_cycles(u32 Cycles)
{
	while(Cycles--)
		asm("NOP");
}







void HSTP_voidInit(STP_t *Copy_STPStruct)
{
	DIO_voidSetPinDirection(Copy_STPStruct->DataPin,Copy_STPStruct->DataPort,DIO_OUTPUT_SPEED_50MHZ_PP);
	DIO_voidSetPinDirection(Copy_STPStruct->SerialClockPin,Copy_STPStruct->SerialClockPort,DIO_OUTPUT_SPEED_50MHZ_PP);
	DIO_voidSetPinDirection(Copy_STPStruct->LatchPin,Copy_STPStruct->LatchPort,DIO_OUTPUT_SPEED_50MHZ_PP);

	DIO_voidClearPin(Copy_STPStruct->DataPin,Copy_STPStruct->DataPort);
	DIO_voidClearPin(Copy_STPStruct->SerialClockPin,Copy_STPStruct->SerialClockPort);
	DIO_voidClearPin(Copy_STPStruct->LatchPin,Copy_STPStruct->LatchPort);

	if(Copy_STPStruct->OutputEnPin != STP_PIN_HARDWARE_ENABLED && Copy_STPStruct->OutputEnPort != STP_PIN_HARDWARE_ENABLED)
	{
		DIO_voidSetPinDirection(Copy_STPStruct->OutputEnPin,Copy_STPStruct->OutputEnPort,DIO_OUTPUT_SPEED_50MHZ_PP);
		DIO_voidSetPin(Copy_STPStruct->OutputEnPin,Copy_STPStruct->OutputEnPort);
	}

	if(Copy_STPStruct->ResetPin != STP_PIN_HARDWARE_ENABLED && Copy_STPStruct->ResetPort != STP_PIN_HARDWARE_ENABLED)
	{
		DIO_voidSetPinDirection(Copy_STPStruct->ResetPin,Copy_STPStruct->ResetPort,DIO_OUTPUT_SPEED_50MHZ_PP);
		DIO_voidSetPin(Copy_STPStruct->ResetPin,Copy_STPStruct->ResetPort);
	}
}
void HSTP_voidShiftByteSynch(STP_t *Copy_STPStruct, u8 Copy_u8Byte)
{
	s8 Local_s8BitCounter;
	u8 Local_u8Bit;

	if(Copy_STPStruct->OutputEnPin != STP_PIN_HARDWARE_ENABLED && Copy_STPStruct->OutputEnPort != STP_PIN_HARDWARE_ENABLED)
		DIO_voidSetPin(Copy_STPStruct->OutputEnPin,Copy_STPStruct->OutputEnPort);

	DIO_voidClearPin(Copy_STPStruct->SerialClockPin,Copy_STPStruct->SerialClockPort);
	for(Local_s8BitCounter = 7; Local_s8BitCounter >=0; Local_s8BitCounter--)
	{
		Local_u8Bit = GET_BIT(Copy_u8Byte,Local_s8BitCounter);
		DIO_voidSetPinValue(Copy_STPStruct->DataPin,Copy_STPStruct->DataPort,Local_u8Bit);


		DIO_voidSetPin(Copy_STPStruct->SerialClockPin,Copy_STPStruct->SerialClockPort);
		__delay_cycles(50);
		DIO_voidClearPin(Copy_STPStruct->SerialClockPin,Copy_STPStruct->SerialClockPort);
		__delay_cycles(50);
	}
	DIO_voidSetPin(Copy_STPStruct->LatchPin,Copy_STPStruct->LatchPort);
	__delay_cycles(50);
	DIO_voidClearPin(Copy_STPStruct->LatchPin,Copy_STPStruct->LatchPort);
	__delay_cycles(50);


	if(Copy_STPStruct->OutputEnPin != STP_PIN_HARDWARE_ENABLED && Copy_STPStruct->OutputEnPort != STP_PIN_HARDWARE_ENABLED)
		DIO_voidClearPin(Copy_STPStruct->OutputEnPin,Copy_STPStruct->OutputEnPort);
}


void HSTP_voidReset(STP_t *Copy_STPStruct)
{
	DIO_voidClearPin(Copy_STPStruct->ResetPin,Copy_STPStruct->ResetPort);
	__delay_cycles(20);
	DIO_voidSetPin(Copy_STPStruct->ResetPin,Copy_STPStruct->ResetPort);
}

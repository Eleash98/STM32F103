//AUTHOR	:Mohamed Gamal
//VERSION	:V01
//DATE		:14-August-2020
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SSD_private.h"
#include "SSD_interface.h"
#include "SSD_config.h"

#include "DIO_interface.h"

void Seven_Segment_voidDisplay(u8 Copy_u8SegmentType, u8 Copy_u8Digit, u8 Copy_u8Port){
	if (Copy_u8Digit > 9)
		return;
	Copy_u8Digit = (Copy_u8SegmentType == COM_CATHODE)? Seven_Segment_Digits[Copy_u8Digit]: ~Seven_Segment_Digits[Copy_u8Digit];
	DIO_voidSetPortDirection(Copy_u8Port, DIO_OUTPUT_SPEED_10MHZ_PP);
	DIO_voidSetPortValue(Copy_u8Port,Copy_u8Digit);
}


void SSP_voidCreate7Segment(SSP_t *Copy_SSPStruct)
{
	DIO_voidSetPinDirection(Copy_SSPStruct->ApinNumber
}
void SSD_voidDisplay(SSD_t *Copy_SSDStruct, u8Copy_u8Number);
void SSD_voidClear(SSD_t *Copy_SSDStruct);
void SSD_voidSetDecimalPoint(SSD *Copy_SSDStruct);
void SSD_voidClearDecimalPoint(SSD *Copy_SSDStruct);

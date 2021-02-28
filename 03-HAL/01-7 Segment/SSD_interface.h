//AUTHOR	:Mohamed Gamal
//VERSION	:V02
//DATE		:14-August-2020

#ifndef SEVEN_SEGMENT_INTERFACE_H
#define SEVEN_SEGMENT_INTERFACE_H

#define SSD_TYPE_COMMON_ANODE		0
#define SSD_TYPE_COMMON_CATHODE		1

typedef struct
{
	u8 Type;
	u8 ApinNumber;
	u8 ApinPort;
	u8 BpinNumber;
	u8 BpinPort;
	u8 CpinNumber;
	u8 CpinPort;
	u8 DpinNumber;
	u8 DpinPort;
	u8 EpinNumber;
	u8 EpinPort;
	u8 FpinNumber;
	u8 FpinPort;
	u8 GpinNumber;
	u8 GpinPort;
}SSD_t;


void Seven_Segment_voidDisplay(u8 Copy_u8SegmentType, u8 Copy_u8Digit, u8 Copy_u8Port);

void SSD_voidCreate7Segment(SSD_t *Copy_SSDStruct);
void SSD_voidDisplay(SSD_t *Copy_SSDStruct, u8Copy_u8Number);
void SSD_voidClear(SSD_t *Copy_SSDStruct);
void SSD_voidSetDecimalPoint(SSD *Copy_SSDStruct);
void SSD_voidClearDecimalPoint(SSD *Copy_SSDStruct);


#endif
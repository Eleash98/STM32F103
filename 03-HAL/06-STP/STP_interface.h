//Author	:	Mohamed Gamal Eleish
//Version	:	V01
//Date		:	28 FEB 2021

#ifndef STP_INTERFACE_H
#define STP_INTERFACE_H

#define STP_PIN_HARDWARE_ENABLED	255

typedef struct
{

	u8 DataPin;
	u8 DataPort;
	u8 SerialClockPin;
		u8 SerialClockPort;
	u8 LatchPin;
	u8 LatchPort;
	u8 OutputEnPin;
	u8 OutputEnPort;
	u8 ResetPin;
	u8 ResetPort;
}STP_t;

void HSTP_voidInit(STP_t *Copy_STPStruct);
void HSTP_voidShiftByteSynch(STP_t *Copy_STPStruct, u8 Copy_u8Byte);
void HSTP_voidReset(STP_t *Copy_STPStruct);

#endif


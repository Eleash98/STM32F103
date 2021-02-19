//Author:	Mohamed Gamal
//Date	:	15 August 2020
//Version:	V01

//Version	:	V02
//Date		:	21-August 2020
/*Version 2 Has private structs so the user cannot change the LED specs*/

//Version	:	V03
//Date		:	26 August 2020
/*Version 3 add new functions that can initialize a LED array, set its value and shift values to it*/


#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#define ACTIVE_HIGH		1
#define ACTIVE_LOW		0

#define SHIFT_LEFT		0
#define SHIFT_RIGHT		1

 void *LED_voidAttachLEDToPin(u8 Copy_u8Pin, u8 Copy_u8Port, u8 Copy_u8LEDConfig);

 void LED_voidDisAttachLEDFromPin(void *L);

 void LED_voidOn(void *L);

 void LED_voidOff(void *L);

 void LED_voidToggle(void *L);

 void *LED_InitLEDArray(u8 Copy_StartPin, u16 Copy_NLEDs, u8 Copy_Port, u8 Copy_State);

 void LED_voidShift(void *L,u8 Copy_NLEDs,u8 Copy_ShiftLeftRight,u8	Copy_StartLED);

 void LED_voidSetArrayValue(void *L1,u8 Copy_NLEDs,u16 Copy_u16Value);

#endif

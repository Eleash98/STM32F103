//Author:	Mohamed Gamal
//Date	:	15 August 2020
//Version:	V01

//Version	:	V02
//Date		:	21-August 2020
/*Version 2 Has private structs so the user cannot change the LED specs*/

//Version	:	V03
//Date		:	26 August 2020
/*Version 3 add new functions that can initialize a LED array, set its value and shift values to it*/

#include <stdlib.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"
#include "DIO_interface.h"


void *LED_voidAttachLEDToPin(u8 Copy_u8Pin, u8 Copy_u8Port, u8 Copy_u8LEDConfig){
    LED *L = (LED*) malloc(sizeof(LED));
	L->Pin = Copy_u8Pin;
	L->Port = Copy_u8Port;
	L->Config = Copy_u8LEDConfig;
	DIO_voidSetPinDirection(Copy_u8Port,Copy_u8Pin,DIO_OUTPUT_SPEED_10MHZ_PP);
	if (Copy_u8LEDConfig == ACTIVE_HIGH)
		DIO_voidClearPin(L->Port,L->Pin);
	else
		DIO_voidSetPin(L->Port,L->Pin);
    return L;
}

void LED_voidDisAttachLEDFromPin(void *L1){
	LED *L = (LED*)L1;
	DIO_voidSetPinDirection(L->Port,L->Pin,DIO_INPUT_ANALOG);
		free(L);
}

void LED_voidOn(void *L1){
	LED *L = (LED *)L1;
	if (L->Config == ACTIVE_HIGH)
		DIO_voidSetPin(L->Port,L->Pin);
	else
		DIO_voidClearPin(L->Port,L->Pin);
}

void LED_voidOff(void *L1){
	LED *L = (LED *)L1;
	if (L->Config == ACTIVE_HIGH)
		DIO_voidClearPin(L->Port,L->Pin);
	else
		DIO_voidSetPin(L->Port,L->Pin);
}

void LED_voidToggle(void *L1){
	LED *L = (LED *)L1;
	if (DIO_voidGetPinValue(L->Port, L->Pin) == DIO_HIGH)
		DIO_voidClearPin(L->Port,L->Pin);
	else
		DIO_voidSetPin(L->Port,L->Pin);
}

void *LED_InitLEDArray(u8 Copy_StartPin, u16 Copy_NLEDs, u8 Copy_Port, u8 Copy_State){
    LED *L = (LED *) malloc(sizeof(LED)*Copy_NLEDs);
    for (int i = Copy_StartPin; i <Copy_NLEDs;i++){
        L[i].Port = Copy_Port;
        L[i].Config = Copy_State;
        L[i].Pin = i+Copy_StartPin;

    }

    DIO_voidSetPortDirection(Copy_Port,DIO_OUTPUT_SPEED_10MHZ_PP);
    return L;
}

void LED_voidSetArrayValue(void *L1,u8 Copy_NLEDs,u16 Copy_u16Value){
	LED *L = (LED*) L1;
	for (u8 i=0;i<Copy_NLEDs;i++){
		if(GET_BIT(Copy_u16Value,i) == 1)
			DIO_voidSetPin(L[i].Port,L[i].Pin);
		else
			DIO_voidClearPin(L[i].Port,L[i].Pin);
	}
}

void LED_voidShift(void *L,u8 Copy_NLEDs,u8 Copy_ShiftLeftRight,u8	Copy_StartLED){
	u32 Local_Value = (Copy_ShiftLeftRight == SHIFT_LEFT)? (Copy_StartLED)<<1 : Copy_StartLED>>1;// : (Copy_StartLED);
	LED_voidSetArrayValue(L,Copy_NLEDs,Local_Value);
}

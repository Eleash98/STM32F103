#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"

#include "LED_MTRX_interface.h"
#include "LED_MTRX_private.h"
#include "LED_MTRX_config.h"

// Set Pin direction for all pins
void HLEDMTRX_voidInit(void){
	
	DIO_voidSetPinDirection(LED_MTRX_ROW0_PIN,DIO_OUTPUT_SPEED_2MHZ_PP);
	DIO_voidSetPinDirection(LED_MTRX_ROW1_PIN,DIO_OUTPUT_SPEED_2MHZ_PP);
	DIO_voidSetPinDirection(LED_MTRX_ROW2_PIN,DIO_OUTPUT_SPEED_2MHZ_PP);
	DIO_voidSetPinDirection(LED_MTRX_ROW3_PIN,DIO_OUTPUT_SPEED_2MHZ_PP);
	DIO_voidSetPinDirection(LED_MTRX_ROW4_PIN,DIO_OUTPUT_SPEED_2MHZ_PP);
	DIO_voidSetPinDirection(LED_MTRX_ROW5_PIN,DIO_OUTPUT_SPEED_2MHZ_PP);
	DIO_voidSetPinDirection(LED_MTRX_ROW6_PIN,DIO_OUTPUT_SPEED_2MHZ_PP);
	DIO_voidSetPinDirection(LED_MTRX_ROW7_PIN,DIO_OUTPUT_SPEED_2MHZ_PP);
	
	DIO_voidSetPinDirection(LED_MTRX_COL0_PIN,DIO_OUTPUT_SPEED_2MHZ_PP);
	DIO_voidSetPinDirection(LED_MTRX_COL1_PIN,DIO_OUTPUT_SPEED_2MHZ_PP);
	DIO_voidSetPinDirection(LED_MTRX_COL2_PIN,DIO_OUTPUT_SPEED_2MHZ_PP);
	DIO_voidSetPinDirection(LED_MTRX_COL3_PIN,DIO_OUTPUT_SPEED_2MHZ_PP);
	DIO_voidSetPinDirection(LED_MTRX_COL4_PIN,DIO_OUTPUT_SPEED_2MHZ_PP);
	DIO_voidSetPinDirection(LED_MTRX_COL5_PIN,DIO_OUTPUT_SPEED_2MHZ_PP);
	DIO_voidSetPinDirection(LED_MTRX_COL6_PIN,DIO_OUTPUT_SPEED_2MHZ_PP);
	DIO_voidSetPinDirection(LED_MTRX_COL7_PIN,DIO_OUTPUT_SPEED_2MHZ_PP);
}


void HELDMTRX_voidRotate(){
	
}

void HLEDMTRX_voidDisplay(u8 *Copy_u8Data){
	//Disable all columms
	DisableAllColumns();
	while(1){
	//Enable Column 0
	SetRowValues(Copy_u8Data[0]);
	DIO_voidClearPin(LED_MTRX_COL0_PIN);
	MSTK_voidSetBusyWait(2500);
	DisableAllColumns();
	
	SetRowValues(Copy_u8Data[1]);
	DIO_voidClearPin(LED_MTRX_COL1_PIN);
	MSTK_voidSetBusyWait(2500);
	DisableAllColumns();
	
	SetRowValues(Copy_u8Data[2]);
	DIO_voidClearPin(LED_MTRX_COL2_PIN);
	MSTK_voidSetBusyWait(2500);
	DisableAllColumns();
	
	SetRowValues(Copy_u8Data[3]);
	DIO_voidClearPin(LED_MTRX_COL3_PIN);
	MSTK_voidSetBusyWait(2500);
	DisableAllColumns();
	
	SetRowValues(Copy_u8Data[4]);
	DIO_voidClearPin(LED_MTRX_COL4_PIN);
	MSTK_voidSetBusyWait(2500);
	DisableAllColumns();
	
	SetRowValues(Copy_u8Data[5]);
	DIO_voidClearPin(LED_MTRX_COL5_PIN);
	MSTK_voidSetBusyWait(2500);
	DisableAllColumns();
	
	SetRowValues(Copy_u8Data[6]);
	DIO_voidClearPin(LED_MTRX_COL6_PIN);
	MSTK_voidSetBusyWait(2500);
	DisableAllColumns();
	
	SetRowValues(Copy_u8Data[7]);
	DIO_voidClearPin(LED_MTRX_COL7_PIN);
	MSTK_voidSetBusyWait(2500);
	DisableAllColumns();
	}
}
void DisableAllColumns(void){
	DIO_voidSetPin(LED_MTRX_COL0_PIN);
	DIO_voidSetPin(LED_MTRX_COL1_PIN);
	DIO_voidSetPin(LED_MTRX_COL2_PIN);
	DIO_voidSetPin(LED_MTRX_COL3_PIN);
	DIO_voidSetPin(LED_MTRX_COL4_PIN);
	DIO_voidSetPin(LED_MTRX_COL5_PIN);
	DIO_voidSetPin(LED_MTRX_COL6_PIN);
	DIO_voidSetPin(LED_MTRX_COL7_PIN);
}


void SetRowValues (u8 Copy_u8Value){
	if (GET_BIT(Copy_u8Value,0))
		DIO_voidSetPin(LED_MTRX_ROW0_PIN);
	else 
		DIO_voidClearPin(LED_MTRX_ROW0_PIN);
	
	if (GET_BIT(Copy_u8Value,1))
		DIO_voidSetPin(LED_MTRX_ROW1_PIN);
	else 
		DIO_voidClearPin(LED_MTRX_ROW1_PIN);
	
	if (GET_BIT(Copy_u8Value,2))
		DIO_voidSetPin(LED_MTRX_ROW2_PIN);
	else 
		DIO_voidClearPin(LED_MTRX_ROW2_PIN);
	
	if (GET_BIT(Copy_u8Value,3))
		DIO_voidSetPin(LED_MTRX_ROW3_PIN);
	else 
		DIO_voidClearPin(LED_MTRX_ROW3_PIN);
	
	if (GET_BIT(Copy_u8Value,4))
		DIO_voidSetPin(LED_MTRX_ROW4_PIN);
	else 
		DIO_voidClearPin(LED_MTRX_ROW4_PIN);
	
	if (GET_BIT(Copy_u8Value,5))
		DIO_voidSetPin(LED_MTRX_ROW5_PIN);
	else 
		DIO_voidClearPin(LED_MTRX_ROW5_PIN);
	
	if (GET_BIT(Copy_u8Value,6))
		DIO_voidSetPin(LED_MTRX_ROW6_PIN);
	else 
		DIO_voidClearPin(LED_MTRX_ROW6_PIN);
	
	if (GET_BIT(Copy_u8Value,7))
		DIO_voidSetPin(LED_MTRX_ROW7_PIN);
	else 
		DIO_voidClearPin(LED_MTRX_ROW7_PIN);
}

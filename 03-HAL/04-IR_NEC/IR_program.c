//Author	:	Mohamed Gamal
//Version	:	V01
//Date		:	2 Septemper 2020

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "IR_interface.h"
#include "IR_config.h"
#include "IR_private.h"

#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "STK_interface.h"
#include "NVIC_interface.h"
#include "AFIO_interface.h"


void HIR_voidInit(){
	
	DIO_voidSetPinDirection(IR_RECEIVER_PORT,IR_RECEIVER_PIN,DIO_INPUT_PULLUP_DOWN);
	DIO_voidSetPin(IR_RECEIVER_PORT,IR_RECEIVER_PIN);
	
	MEXTI_voidSetCallBack(IR_RECEIVER_PIN, HIR_voidSetCode);
	MEXTI_voidSetSignalLatch(IR_RECEIVER_PIN,FALLING);
	
	MNVIC_voidInit();
	MNVIC_voidEnableInterrupt(6);
	//STK_voidInit();
	
	
	//MAFIO_voidSetEXTIConfiguration(IR_RECEIVER_PIN,IR_RECEIVER_PORT-2)
	
	
}

void HIR_voidSetCode(){
	static u8 Local_BitCounter = 0;
	if (Local_BitCounter == 0){
		STK
	}
}



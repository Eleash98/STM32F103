//AUTHOR	:Mohamed Gamal
//VERSION	:V01
//DATE		:11-August-2020

//Version 	:V02
//Date		:17-August-2020
/* Added DIO_voidSetPortDirection, DIO_voidSetPortValue */

//Version	:V03
//Date		:26 August 2020
/*Modified functions to use struct type register definitions*/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


void DIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode){
	switch(Copy_u8Port){
		case PORTA:
			if (Copy_u8Pin<=7){
				DIO_PORTA->CRL &= ~((0xF) << (Copy_u8Pin*4));
				DIO_PORTA->CRL |= (Copy_u8Mode) << (Copy_u8Pin*4);
			}
			else if (Copy_u8Pin <= 15){
				Copy_u8Pin -= 8;
				DIO_PORTA->CRH &= ~((0xF) << (Copy_u8Pin*4));
				DIO_PORTA->CRH |= (Copy_u8Mode) << (Copy_u8Pin*4);
			}
			break;
		case PORTB:
			if (Copy_u8Pin<=7){
				DIO_PORTB->CRL &= ~((0xF) << (Copy_u8Pin*4));
				DIO_PORTB->CRL |= (Copy_u8Mode) << (Copy_u8Pin*4);
			}
			else if (Copy_u8Pin <= 15){
				Copy_u8Pin -= 8;
				DIO_PORTB->CRH &= ~((0xF) << (Copy_u8Pin*4));
				DIO_PORTB->CRH |= (Copy_u8Mode) << (Copy_u8Pin*4);
			}
			break;
		case PORTC:
			if (Copy_u8Pin<=7){
				DIO_PORTC->CRL &= ~((0xF) << (Copy_u8Pin*4));
				DIO_PORTC->CRL |= (Copy_u8Mode) << (Copy_u8Pin*4);
			}
			else if (Copy_u8Pin <= 15){
				Copy_u8Pin -= 8;
				DIO_PORTC->CRH &= ~((0xF) << (Copy_u8Pin*4));
				DIO_PORTC->CRH |= (Copy_u8Mode) << (Copy_u8Pin*4);
			}
			break;
		default: /*return error*/	break;
	}
}

void DIO_voidSetPin(u8 Copy_u8Port, u8 Copy_u8Pin){
	switch (Copy_u8Port){
		case PORTA:
			DIO_PORTA->BSRR	= (1 << Copy_u8Pin);
			break;
		case PORTB:
			DIO_PORTB->BSRR	= (1 << Copy_u8Pin);
			break;
		case PORTC:
			DIO_PORTC->BSRR	= (1 << Copy_u8Pin);
			break;
		default: break;
	}
}
void DIO_voidClearPin(u8 Copy_u8Port, u8 Copy_u8Pin){
	switch (Copy_u8Port){
		case PORTA:
			DIO_PORTA->BRR	= (1 << Copy_u8Pin);
			break;
		case PORTB:
			DIO_PORTB->BRR	= (1 << Copy_u8Pin);
			break;
		case PORTC:
			DIO_PORTC->BRR	= (1 << Copy_u8Pin);
			break;
		default: break;
	}
}


u8 DIO_voidGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin){
	u8 LOC_u8Result = 0;
	switch (Copy_u8Port){
		case PORTA:
			LOC_u8Result = GET_BIT(DIO_PORTA->IDR,Copy_u8Pin);
			break;
		case PORTB:
			LOC_u8Result = GET_BIT(DIO_PORTB->IDR,Copy_u8Pin);
			break;
		case PORTC:
			LOC_u8Result = GET_BIT(DIO_PORTC->IDR,Copy_u8Pin);
			break;
		default:	break;
	}
	return LOC_u8Result;
}

void DIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Mode){
	u32 LOC_u32Mode = Copy_u8Mode;
	for (u8 i=0;i<7;i++){
		LOC_u32Mode = (LOC_u32Mode << 4);
		LOC_u32Mode |= Copy_u8Mode;
	}
	switch(Copy_u8Port){
		case PORTA:
			DIO_PORTA->CRL &= 0x0;
			DIO_PORTA->CRL |= LOC_u32Mode;
			break;
		case PORTB:
			DIO_PORTB->CRL &= 0x0;
			DIO_PORTB->CRL |= LOC_u32Mode;
			break;
		case PORTC:
			DIO_PORTC->CRL &= 0x0;
			DIO_PORTC->CRL |= LOC_u32Mode;
			break;
		default: /*return error*/ break;
	}
}
void DIO_voidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value){
	switch (Copy_u8Port){
		case PORTA:
			DIO_PORTA->ODR = Copy_u8Value;
			break;
		case PORTB:
			DIO_PORTB->ODR = Copy_u8Value;
			break;
		case PORTC:
			DIO_PORTC->ODR = Copy_u8Value;
			break;
		default: /*return error*/ break;
	}
}

void DIO_voidLockPin(u8 Copy_u8Port, u8 Copy_u8Pin){
	switch (Copy_u8Port){
		case PORTA:
			DIO_PORTA->LCKR	= (1 << Copy_u8Pin);
			break;
		case PORTB:
			DIO_PORTB->LCKR	= (1 << Copy_u8Pin);
			break;
		case PORTC:
			DIO_PORTC->LCKR	= (1 << Copy_u8Pin);
			break;
		default: break;
	}
}
void DIO_voidSetPullResistor(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode){
	switch (Copy_u8Port){
		case PORTA:
			if (Copy_u8Mode == PULL_UP)
				DIO_PORTA->ODR |= (1<<Copy_u8Pin);
			else
				DIO_PORTA->ODR &= ~(1<<Copy_u8Pin);
			break;
		case PORTB:
			if(Copy_u8Mode == PULL_UP)
				DIO_PORTB->ODR |= (1<<Copy_u8Pin);
			else
				DIO_PORTB->ODR &= ~(1<<Copy_u8Pin);
			break;
		case PORTC:
			if(Copy_u8Mode == PULL_UP)
				DIO_PORTC->ODR |= (1<<Copy_u8Pin);
			else
				DIO_PORTC->ODR &= ~(1<<Copy_u8Pin);
			break;
		default:	/*return error*/ break;
	}
}

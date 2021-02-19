//Author		:		Mohamed G. Eleish
//Date			:		16/10/2020
//Version		:		V01




#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "USART1_interface.h"
#include "USART1_private.h"
#include "USART1_config.h"



void MUSART1_voidInit(void)
{
	/*Baud Rate*/
	f32 Local_f32BRRValue	= (USART1_BUS_CLOCK/((u32)16*USART1_BAUD_RATE));
	u32 LocaL_u32Mantessa	= (u32)Local_f32BRRValue;
	Local_f32BRRValue = (Local_f32BRRValue - LocaL_u32Mantessa)*16;
	LocaL_u32Mantessa += Local_f32BRRValue/16;
	Local_f32BRRValue = ((Local_f32BRRValue/16) * 100);
	USAR11->BRR	=	(((u16)LocaL_u32Mantessa)<<4) | (((u8)Local_f32BRRValue));
	
	/*Stop Bits Select*/
	USART1->CR2 =(USART1_STOP_BITS<<12)|(USART1_CLK_PIN<<11)|(USART1_IDLE_STATE<<10)
				|(USART1_SEQUENCE<<9);
	
	USART1->CR3 |=(USART1_DMA_TRANSMITTER<<7)|(USART1_DMA_RECEIVER<<6)
	/*Enable Transmitter & Receiver*/
	SET_BIT(USART1->CR1,3);
	SET_BIT(USART1->CR1,2);
	
	/*Enable USART1*/
	Set_BIT(USART1->CR1,13);
	
}



void MUSART1_voidTransmit(u8 *Copy_Pu8Str)
{
	u8 i=0;
	while(Copy_Pu8Str[i] !='\0')
	{
		while(!GET_BIT(MUSART1->SR,6));
		MUSART1->DR = Copy_Pu8Str[i++];
	}
}

u8 MUSART1_u8Receive(void)
{
	while(!GET_BIT(USART1->SR,5));
	return ((MUSART1->DR)&0xFF);
}

void MUSART1_voidEnableRxCompleteInterrupt(void)
{
	SET_BIT(USART1->CR1,5);
}

void MUSART1_voidEnableTxCompleteInterrupt(void)
{
	SET_BIT(USART1->CR1,6);
}

void MUSART1_voidDisableRxCompleteInterrupt(void)
{
	CLR_BIT(USART1->CR1,5);
}

void MUSART1_voidEnableTxCompleteInterrupt(void)
{
	CLR_BIT(USART1->CR1,6);
}

void MUSART1_voidEnableIdleInterrupt(void)
{
	SET_BIT(USART1->CR1,4);
}
void MUSART1_voidDisableIdleInterrupt(void)
{
	CLR_BIT(USART1->CR1,4);
}

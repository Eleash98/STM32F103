//Author		:		Mohamed G. Eleish
//Date			:		16/10/2020
//Version		:		V01



#ifndef	USART1_INTERFACE_H
#define USART1_INTERFAEC_H


void MUSART1_voidInit(void);
void MUSART1_voidTransmit(u8 *Copy_Pu8Str);
u8 MUSART1_u8Receive(void);

void MUSART1_voidEnableRxCompleteInterrupt(void);
void MUSART1_voidEnableTxCompleteInterrupt(void);

void MUSART1_voidDisableRxCompleteInterrupt(void);
void MUSART1_voidEnableTxCompleteInterrupt(void);

void MUSART1_voidEnableIdleInterrupt(void);
void MUSART1_voidDisableIdleInterrupt(void);

#endif


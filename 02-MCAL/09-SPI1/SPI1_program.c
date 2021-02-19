//Author		:	Mohamed Gamal Eleish
//Date			:	15/10/2020
//Version 		:	V01



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#inlcude "SPI_config.h"

#include "DIO_interface.h"

void MSPI1_voidInit(void)
{
	SPI1->CR1 = (SPI1_BIDIRECTIONAL_MODE<<15)|(SPI1_BIDIRECTIONAL_DATA_MAODE<<14)
				|(SPI1_CRC<<13)|(SPI1_DATA_FORMAT<<11)|(SPI1_RECEIVE_ONLY<<10)
				|(SPI1_SLAVE_MANGEMENT<<9)|(SPI1_DATA_TRANSMIT_MODE<<7)
				|(SPI1_BAUD_RATE_PRESCALAR<<3)|(SPI1_MODE<<2)|(SPI1_IDLE_STATE<<1)
				|(SPI1_SEQUENCE);
	SET_BIT(SPI1->CR1,8);
	SET_BIT(SPI1->CR1,6);
}
void MSPI1_voidSendReceiveSynch(s8 Copy_u8SSPin,s8 Copy_u8SSPort,u8 Copy_u8DataToTransmit, u8 *Copy_dataToReceive)
{
	
	/*Clear SS Pin*/
	if((Copy_u8SSPin>-1) && (Copy_u8SSPort>-1));
		DIO_voidClearPin(Copy_u8SSPort,Copy_u8SSPin);
	
	/*Sen data*/
	SPI1-> DR = Copy_u8DataToTransmit;
	
	/*Wait busy flag*/
	while(GET_BIT(SPI1->SR,7));
	
	/*Read Received data*/
	*Copy_dataToReceive = SPI1->DR;
	
	/*Set SS Pin*/
	if((Copy_u8SSPin>-1) && (Copy_u8SSPort>-1));
		DIO_voidSetPin(Copy_u8SSPort,Copy_u8SSPin);
}

void ISR_IRQHandler()
{
	SPI1_PvoidReceiveHandler(SPI1->DR);
}

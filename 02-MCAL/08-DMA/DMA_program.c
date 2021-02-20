#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"


void MDMA_voidConfigureChannel(u8 Copy_u8ChNumber, u8 Copy_u8ChDirection, u8 Copy_u8ChPriority, u8 Copy_u8MemTransSize, 
									u8 Copy_u8PeriphTransSize, u8 Copy_u8MemInc, u8 Copy_u8PeriphInc, u8 Copy_u8CircMode)
{

	if(Copy_u8ChNumber > 6)
		return;
	DMA->Channel[Copy_u8ChNumber].CCR = 0;
	/*Direction Configuration*/
	if(Copy_u8ChDirection == DMA_DIRECTION_MEM_TO_MEM)
	{
		SET_BIT(DMA->Channel[Copy_u8ChNumber].CCR,14);
	}
	else if(Copy_u8ChDirection == DMA_DIRECTION_MEM_TO_PERIPH)
	{
		SET_BIT(DMA->Channel[Copy_u8ChNumber].CCR,4);
	}
	
	DMA->Channel[Copy_u8ChNumber].CCR |= (Copy_u8ChPriority<<12) | (Copy_u8MemTransSize<<10)
										|(Copy_u8PeriphTransSize<<8); 
	if(Copy_u8MemInc)
		SET_BIT(DMA->Channel[Copy_u8ChNumber].CCR,7);
	if(Copy_u8PeriphInc)
		SET_BIT(DMA->Channel[Copy_u8ChNumber].CCR,6);
	if(Copy_u8CircMode)
		SET_BIT(DMA->Channel[Copy_u8ChNumber].CCR,5);
}


void MDMA_voidSetAddress(u8 Copy_u8ChannelID,u32* Copy_Pu32SourceAddress, u32* Copy_Pu32DestAddress,u16 Copy_u16BlockLength)
{
	if(Copy_u8ChannelID  > 6)
		return;
	if(GET_BIT(DMA->Channel[Copy_u8ChannelID].CCR,14)
	{
		
		DMA->Channel[Copy_u8ChannelID].CPAR = (u32)Copy_Pu32SourceAddress;
		DMA->Channel[Copy_u8ChannelID].CMAR = (u32)Copy_Pu32DestAddress;
	}
	else if(GET_BIT(DMA->Channel[Copy_u8ChannelID].CCR,4)
	{
		DMA->Channel[Copy_u8ChannelID].CPAR = (u32)Copy_Pu32DestAddress;
		DMA->Channel[Copy_u8ChannelID].CMAR = (u32)Copy_Pu32SourceAddress;
	}
	DMA->Channel[Copy_u8ChannelID].CNDTR = Copy_u16BlockLength;
	
}

void MDMA_voidEnableChannel(u8 Copy_u8ChNumber)
{
	if(Copy_u8ChNumber > 6)
		return;
	SET_BIT(DMA->Channel[Copy_u8ChNumber].CCR,0);
}
void MDMA_voidDisableChannel(u8 Copy_u8ChannelID)
{
	if(Copy_u8ChannelID > 6)
		return;
	CLR_BIT(DMA->Channel[Copy_u8ChannelID].CCR,0);
}

void MDMA_voidEnableInterrupt(u8 Copy_u8ChNumber, u8 Copy_u8Interrupt)
{
	SET_BIT(DMA->Channel[Copy_u8ChNumber].CCR,Copy_u8Interrupt);
}


void MDMA_voidDisableInterrupt(u8 Copy_u8Interrupt)
{
	CLR_BIT(DMA->Channel[Copy_u8ChNumber].CCR,Copy_u8Interrupt);
}

void MDMA_voidAttachCallBack(u8 Copy_u8ChannelID, u8 Copy_u8InterruptType, void (*Copy_PvoidCallBack)(void))
{
	if (Copy_u8ChannelID < 1 || Copy_u8ChannelID > 7)
		return;
	switch(Copy_u8InterruptType)
	{
		case DMA_TRANSFER_COMPLETE_HANDLE:
			DMA_voidHandlers[(Copy_u8ChannelID-1)*3] = Copy_PvoidCallBack;
			break;
		case DMA_HALF_TRANSFER_COMPLETE_HANDLE:
			DMA_voidHandlers[((Copy_u8ChannelID-1)*3)+1] = Copy_PvoidCallBack;
			break;
		case DMA_TRANSFER_ERROR_HANDLE:
			DMA_voidHandlers[((Copy_u8ChannelID-1)*3)+2] = Copy_PvoidCallBack;
			break;
		default:
			break;
		
	}
}


void DMA1_Channel1_IRQHandler(void)
{
	if (GET_BIT(DMA->Channel[0].CCR,14))
		SET_BIT(DMA->IFCR,2);

	if(GET_BIT(DMA->ISR,3) == 1 && DMA_voidHandlers[2] != 0 && GET_BIT(DMA->Channel[0].CCR,3))
	{
		DMA_voidHandlers[2]();
	}
	if(GET_BIT(DMA->ISR,2) == 1 && DMA_voidHandlers[1] != 0 && GET_BIT(DMA->Channel[0].CCR,2))
	{
		DMA_voidHandlers[1]();
	}
	if(GET_BIT(DMA->ISR,1) == 1 && DMA_voidHandlers[0] != 0 && GET_BIT(DMA->Channel[0].CCR,1))
	{
		DMA_voidHandlers[0]();
	}
	DMA->IFCR = 1;
}

void DMA1_Channel2_IRQHandler(void)
{
	if (GET_BIT(DMA->Channel[1].CCR,14))
		SET_BIT(DMA->IFCR,6);
	if(GET_BIT(DMA->ISR,7) == 1 && DMA_voidHandlers[5] != 0 && GET_BIT(DMA->Channel[1].CCR,3))
	{
		//Transfer Error Handler
		DMA_voidHandlers[5]();
	}
	if(GET_BIT(DMA->ISR,6) == 1 && DMA_voidHandlers[4] != 0 && GET_BIT(DMA->Channel[1].CCR,2))
	{
		//Half Transfer Complete Handler
		DMA_voidHandlers[4]();
	}
	if(GET_BIT(DMA->ISR,5) == 1 && DMA_voidHandlers[3] != 0 && GET_BIT(DMA->Channel[1].CCR,1))
	{
		//Transfer Complete Handler
		DMA_voidHandlers[3]();
	}
	DMA->IFCR = 0x10;
}

void DMA1_Channel3_IRQHandler(void)
{
	if (GET_BIT(DMA->Channel[2].CCR,14))
		SET_BIT(DMA->IFCR,10);
	if(GET_BIT(DMA->ISR,11) == 1 && DMA_voidHandlers[8] != 0 && GET_BIT(DMA->Channel[2].CCR,3))
	{                                                                                  
		//Transfer Error Handler                                                       
		DMA_voidHandlers[8]();                                                         
	}                                                                                  
	if(GET_BIT(DMA->ISR,10) == 1 && DMA_voidHandlers[7] != 0 && GET_BIT(DMA->Channel[2].CCR,2))
	{                                                                                  
		//Half Transfer Complete Handler                                               
		DMA_voidHandlers[7]();                                                         
	}                                                                                  
	if(GET_BIT(DMA->ISR,9) == 1 && DMA_voidHandlers[6] != 0 &&  GET_BIT(DMA->Channel[2].CCR,1) )
	{
		//Transfer Complete Handler
		DMA_voidHandlers[6]();
	}
	DMA->IFCR = 0x100;
}

void DMA1_Channel4_IRQHandler(void)
{
	if (GET_BIT(DMA->Channel[3].CCR,14))
		SET_BIT(DMA->IFCR,14);
	if(GET_BIT(DMA->ISR,15) == 1 && DMA_voidHandlers[11] != 0 && GET_BIT(DMA->Channel[3].CCR,3))
	{                                                                                   
		//Transfer Error Handler                                                        
		DMA_voidHandlers[11]();                                                         
	}                                                                                   
	if(GET_BIT(DMA->ISR,14) == 1 && DMA_voidHandlers[10] != 0 && GET_BIT(DMA->Channel[3].CCR,2))
	{                                                                                   
		//Half Transfer Complete Handler                                                
		DMA_voidHandlers[10]();                                                         
	}                                                                                   
	if(GET_BIT(DMA->ISR,13) == 1 && DMA_voidHandlers[9] != 0  &&  GET_BIT(DMA->Channel[3].CCR,1))
	{
		//Transfer Complete Handler
		DMA_voidHandlers[9]();
	}
	DMA->IFCR = 0x1000;
}

void DMA1_Channel5_IRQHandler(void)
{
	if (GET_BIT(DMA->Channel[4].CCR,14))
		SET_BIT(DMA->IFCR,18);

	if(GET_BIT(DMA->ISR,19) == 1 && DMA_voidHandlers[14] != 0 && GET_BIT(DMA->Channel[4].CCR,3))
	{                                                                                   
		//Transfer Error Handler                                                        
		DMA_voidHandlers[14]();                                                         
	}                                                                                   
	if(GET_BIT(DMA->ISR,18) == 1 && DMA_voidHandlers[13] != 0 && GET_BIT(DMA->Channel[4].CCR,2))
	{                                                                                   
		//Half Transfer Complete Handler                                                
		DMA_voidHandlers[13]();                                                         
	}                                                                                   
	if(GET_BIT(DMA->ISR,17) == 1 && DMA_voidHandlers[12] != 0 &&  GET_BIT(DMA->Channel[4].CCR,1))
	{
		//Transfer Complete Handler
		DMA_voidHandlers[12]();
	}
	DMA->IFCR = 0x10000;
}

void DMA1_Channel6_IRQHandler(void)
{
	if (GET_BIT(DMA->Channel[5].CCR,14))
		SET_BIT(DMA->IFCR,22);
	if(GET_BIT(DMA->ISR,23) == 1 && DMA_voidHandlers[17] != 0 && GET_BIT(DMA->Channel[5].CCR,3))
	{                                                                                   
		//Transfer Error Handler                                                        
		DMA_voidHandlers[17]();                                                         
	}                                                                                   
	if(GET_BIT(DMA->ISR,22) == 1 && DMA_voidHandlers[16] != 0 && GET_BIT(DMA->Channel[5].CCR,2))
	{                                                                                   
		//Half Transfer Complete Handler                                                
		DMA_voidHandlers[16]();                                                         
	}                                                                                   
	if(GET_BIT(DMA->ISR,21) == 1 && DMA_voidHandlers[15] != 0 &&  GET_BIT(DMA->Channel[5].CCR,1))
	{
		//Transfer Complete Handler
		DMA_voidHandlers[15]();
	}
	DMA->IFCR = 0x100000;
}

void DMA1_Channel7_IRQHandler(void)
{
	if (GET_BIT(DMA->Channel[6].CCR,14))
		CLR_BIT(DMA->IFCR,26);
	if(GET_BIT(DMA->ISR,27) == 1 && DMA_voidHandlers[20] != 0 && GET_BIT(DMA->Channel[6].CCR,3))
	{                                                                                   
		//Transfer Error Handler                                                        
		DMA_voidHandlers[20]();                                                         
	}                                                                                   
	if(GET_BIT(DMA->ISR,26) == 1 && DMA_voidHandlers[19] != 0 && GET_BIT(DMA->Channel[6].CCR,2))
	{                                                                                   
		//Half Transfer Complete Handler                                                
		DMA_voidHandlers[19]();                                                         
	}                                                                                   
	if(GET_BIT(DMA->ISR,25) == 1 && DMA_voidHandlers[18] != 0 &&  GET_BIT(DMA->Channel[6].CCR,1))
	{
		//Transfer Complete Handler
		DMA_voidHandlers[18]();
	}
	DMA->IFCR = 0x1000000;
}


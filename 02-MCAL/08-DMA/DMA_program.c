#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"


void MDMA_voidInitChannels(void)
{
#if DMA_CHANNEL1_ENABLED == DMA_ENABLED
	DMA->Channel[0].CCR = 0;
	DMA->Channel[0].CCR |= (DMA_CH1_MEMMORY_TO_MEMORY_MODE<<14) 
						| (DMA_CH1_CHANNEL_PRIORITY<<12) |(DMA_CH1_MEMORY_SIZE<<10) 
						| (DMA_CH1_PERIPHERAL_SIZE<<8) | (DMA_CH1_MEMORY_INC<<7)
						| (DMA_CH1_PERIPHERAL_INC<<6) | (DMA_CH1_CIRCULAR_MODE<<5) 
						| (DMA_CH1_DATA_TRANSFER_DIRECTION<<4) | (DMA_CH1_TRANSFER_ERROR_INTERRUPT<<3) 
						| (DMA_CH1_HALF_TRANSFER_INTERRUPT<<2) | (DMA_CH1_TRANSFER_COMPLETED_INTERRUPT<<1); 
#endif

#if DMA_CHANNEL2_ENABLED == DMA_ENABLED
	DMA->Channel[1].CCR = 0;
	DMA->Channel[1].CCR |= (DMA_CH2_MEMMORY_TO_MEMORY_MODE<<14) 
						| (DMA_CH2_CHANNEL_PRIORITY<<12) |(DMA_CH2_MEMORY_SIZE<<10) 
						| (DMA_CH2_PERIPHERAL_SIZE<<8) | (DMA_CH2_MEMORY_INC<<7)
						| (DMA_CH2_PERIPHERAL_INC<<6) | (DMA_CH2_CIRCULAR_MODE<<5) 
						| (DMA_CH2_DATA_TRANSFER_DIRECTION<<4) | (DMA_CH2_TRANSFER_ERROR_INTERRUPT<<3) 
						| (DMA_CH2_HALF_TRANSFER_INTERRUPT<<2) | (DMA_CH2_TRANSFER_COMPLETED_INTERRUPT<<1); 
#endif

#if DMA_CHANNEL3_ENABLED == DMA_ENABLED
	DMA->Channel[2].CCR = 0;
	DMA->Channel[2].CCR |= (DMA_CH3_MEMMORY_TO_MEMORY_MODE<<14) 
						| (DMA_CH3_CHANNEL_PRIORITY<<12) |(DMA_CH3_MEMORY_SIZE<<10) 
						| (DMA_CH3_PERIPHERAL_SIZE<<8) | (DMA_CH3_MEMORY_INC<<7)
						| (DMA_CH3_PERIPHERAL_INC<<6) | (DMA_CH3_CIRCULAR_MODE<<5) 
						| (DMA_CH3_DATA_TRANSFER_DIRECTION<<4) | (DMA_CH3_TRANSFER_ERROR_INTERRUPT<<3) 
						| (DMA_CH3_HALF_TRANSFER_INTERRUPT<<2) | (DMA_CH3_TRANSFER_COMPLETED_INTERRUPT<<1); 
#endif

#if DMA_CHANNEL4_ENABLED == DMA_ENABLED
	DMA->Channel[3].CCR = 0;
	DMA->Channel[3].CCR |= (DMA_CH4_MEMMORY_TO_MEMORY_MODE<<14) 
						| (DMA_CH4_CHANNEL_PRIORITY<<12) |(DMA_CH4_MEMORY_SIZE<<10) 
						| (DMA_CH4_PERIPHERAL_SIZE<<8) | (DMA_CH4_MEMORY_INC<<7)
						| (DMA_CH4_PERIPHERAL_INC<<6) | (DMA_CH4_CIRCULAR_MODE<<5) 
						| (DMA_CH4_DATA_TRANSFER_DIRECTION<<4) | (DMA_CH4_TRANSFER_ERROR_INTERRUPT<<3) 
						| (DMA_CH4_HALF_TRANSFER_INTERRUPT<<2) | (DMA_CH4_TRANSFER_COMPLETED_INTERRUPT<<1); 
#endif

#if DMA_CHANNEL5_ENABLED == DMA_ENABLED
	DMA->Channel[4].CCR = 0;
	DMA->Channel[4].CCR |= (DMA_CH5_MEMMORY_TO_MEMORY_MODE<<14) 
						| (DMA_CH5_CHANNEL_PRIORITY<<12) |(DMA_CH5_MEMORY_SIZE<<10) 
						| (DMA_CH5_PERIPHERAL_SIZE<<8) | (DMA_CH5_MEMORY_INC<<7)
						| (DMA_CH5_PERIPHERAL_INC<<6) | (DMA_CH5_CIRCULAR_MODE<<5) 
						| (DMA_CH5_DATA_TRANSFER_DIRECTION<<4) | (DMA_CH5_TRANSFER_ERROR_INTERRUPT<<3) 
						| (DMA_CH5_HALF_TRANSFER_INTERRUPT<<2) | (DMA_CH5_TRANSFER_COMPLETED_INTERRUPT<<1); 
#endif

#if DMA_CHANNEL6_ENABLED == DMA_ENABLED
	DMA->Channel[5].CCR = 0;
	DMA->Channel[5].CCR |= (DMA_CH6_MEMMORY_TO_MEMORY_MODE<<14) 
						| (DMA_CH6_CHANNEL_PRIORITY<<12) |(DMA_CH6_MEMORY_SIZE<<10) 
						| (DMA_CH6_PERIPHERAL_SIZE<<8) | (DMA_CH6_MEMORY_INC<<7)
						| (DMA_CH6_PERIPHERAL_INC<<6) | (DMA_CH6_CIRCULAR_MODE<<5) 
						| (DMA_CH6_DATA_TRANSFER_DIRECTION<<4) | (DMA_CH6_TRANSFER_ERROR_INTERRUPT<<3) 
						| (DMA_CH6_HALF_TRANSFER_INTERRUPT<<2) | (DMA_CH6_TRANSFER_COMPLETED_INTERRUPT<<1); 
#endif

#if DMA_CHANNEL7_ENABLED == DMA_ENABLED
	DMA->Channel[6].CCR = 0;
	DMA->Channel[6].CCR |= (DMA_CH7_MEMMORY_TO_MEMORY_MODE<<14) 
						| (DMA_CH7_CHANNEL_PRIORITY<<12) |(DMA_CH7_MEMORY_SIZE<<10) 
						| (DMA_CH7_PERIPHERAL_SIZE<<8) | (DMA_CH7_MEMORY_INC<<7)
						| (DMA_CH7_PERIPHERAL_INC<<6) | (DMA_CH7_CIRCULAR_MODE<<5) 
						| (DMA_CH7_DATA_TRANSFER_DIRECTION<<4) | (DMA_CH7_TRANSFER_ERROR_INTERRUPT<<3) 
						| (DMA_CH7_HALF_TRANSFER_INTERRUPT<<2) | (DMA_CH7_TRANSFER_COMPLETED_INTERRUPT<<1); 
#endif

	
}


void MDMA_voidEnableChannel(u8 Copy_u8ChannelID,u32* Copy_Pu32PeripheralAddress, u32* Copy_Pu32MemoryAddress,u16 Copy_u16BlockLength)
{
	if(Copy_u8ChannelID < 1 || Copy_u8ChannelID > 7)
		return;
	DMA->Channel[Copy_u8ChannelID-1].CNDTR = Copy_u16BlockLength;
	DMA->Channel[Copy_u8ChannelID-1].CPAR = Copy_Pu32PeripheralAddress;
	DMA->Channel[Copy_u8ChannelID-1].CMAR = Copy_Pu32MemoryAddress;
	
	SET_BIT(DMA->Channel[Copy_u8ChannelID-1].CCR,0);
}

void MDMA_voidDisableChannel(u8 Copy_u8ChannelID)
{
	if(Copy_u8ChannelID < 1 || Copy_u8ChannelID > 7)
		return;
	DMA->Channel[Copy_u8ChannelID-1].CNDTR = 0;
	DMA->Channel[Copy_u8ChannelID-1].CPAR = 0;
	DMA->Channel[Copy_u8ChannelID-1].CMAR = 0;
	
	CLR_BIT(DMA->Channel[Copy_u8ChannelID-1].CCR,0);
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
	volatile u8 Local_u8InterruptType = ((DMA->ISR) & 0xE)>>1;
	switch(Local_u8InterruptType)
	{
		case 1:
			if(DMA_voidHandlers[0] != 0)
				DMA_voidHandlers[0]();
			DMA->IFCR = 0x3;
			break;
		case 2:
			if(DMA_voidHandlers[1] !=0)
				DMA_voidHandlers[1]();
			DMA->IFCR = 0x5;
			break;
		case 4:
			if(DMA_voidHandlers[2] != 0)
				DMA_voidHandlers[2]();
			DMA->IFCR = 0x9;
			break;
		default:
			DMA->IFCR = 0xF;
		break;
	}
}

void DMA1_Channel2_IRQHandler(void)
{
	if (GET_BIT(DMA->Channel[1].CCR,14))
		SET_BIT(DMA->IFCR,6);
	volatile u8 Local_u8InterruptType = ((DMA->ISR) & 0xE0)>>5;
	switch(Local_u8InterruptType)
	{
		case 1:
			if(DMA_voidHandlers[3] != 0)
				DMA_voidHandlers[3]();
			DMA->IFCR = 0x30;
			break;
		case 2:
			if(DMA_voidHandlers[4] != 0)
				DMA_voidHandlers[4]();
			DMA->IFCR = 0x50;
			break;
		case 4:
			if(DMA_voidHandlers[5] != 0)
				DMA_voidHandlers[5]();
			DMA->IFCR = 0x90;
			break;
		default:
			DMA->IFCR = 0xF0;
		break;
	}
}

void DMA1_Channel3_IRQHandler(void)
{
	if (GET_BIT(DMA->Channel[2].CCR,14))
		SET_BIT(DMA->IFCR,10);
	volatile u8 Local_u8InterruptType = ((DMA->ISR) & 0xE00)>>9;
	switch(Local_u8InterruptType)
	{
		case 1:
			if(DMA_voidHandlers[6] != 0)
				DMA_voidHandlers[6]();
			DMA->IFCR = 0x300;
			break;
		case 2:
			if(DMA_voidHandlers[7] != 0)
				DMA_voidHandlers[7]();
			DMA->IFCR = 0x500;
			break;
		case 4:
			if(DMA_voidHandlers[8] != 0)
				DMA_voidHandlers[8]();
			DMA->IFCR = 0x900;
			break;
		default:
			DMA->IFCR = 0xF00;
		break;
	}
}

void DMA1_Channel4_IRQHandler(void)
{
	if (GET_BIT(DMA->Channel[3].CCR,14))
		SET_BIT(DMA->IFCR,14);
	volatile u8 Local_u8InterruptType = ((DMA->ISR) & 0xE000)>>13;
	switch(Local_u8InterruptType)
	{
		case 1:
			if(DMA_voidHandlers[9] != 0)
				DMA_voidHandlers[9]();
			DMA->IFCR = 0x3000;
			break;
		case 2:
			if(DMA_voidHandlers[10] != 0)
				DMA_voidHandlers[10]();
			DMA->IFCR = 0x5000;
			break;
		case 4:
			if(DMA_voidHandlers[11] != 0)
				DMA_voidHandlers[11]();
			DMA->IFCR = 0x9000;
			break;
		default:
			DMA->IFCR = 0xF000;
		break;
	}
}

void DMA1_Channel5_IRQHandler(void)
{
	if (GET_BIT(DMA->Channel[4].CCR,14))
		SET_BIT(DMA->IFCR,18);
	volatile u8 Local_u8InterruptType = ((DMA->ISR) & 0xE0000)>>17;
	switch(Local_u8InterruptType)
	{
		case 1:
			if(DMA_voidHandlers[12] != 0)
				DMA_voidHandlers[12]();
			DMA->IFCR = 0x30000;
			break;
		case 2:
			if(DMA_voidHandlers[13] != 0)
				DMA_voidHandlers[13]();
			DMA->IFCR = 0x50000;
			break;
		case 4:
			if(DMA_voidHandlers[14] != 0)
				DMA_voidHandlers[14]();
			DMA->IFCR = 0x90000;
			break;
		default:
			DMA->IFCR = 0xF0000;
		break;
	}
}

void DMA1_Channel6_IRQHandler(void)
{
	if (GET_BIT(DMA->Channel[5].CCR,14))
		SET_BIT(DMA->IFCR,22);
	volatile u8 Local_u8InterruptType = ((DMA->ISR) & 0xE00000)>>21;
	switch(Local_u8InterruptType)
	{
		case 1:
			if(DMA_voidHandlers[15] != 0)
				DMA_voidHandlers[15]();
			DMA->IFCR = 0x300000;
			break;
		case 2:
			if(DMA_voidHandlers[16] != 0)
				DMA_voidHandlers[16]();
			DMA->IFCR = 0x500000;
			break;
		case 4:
			if(DMA_voidHandlers[17] != 0)
				DMA_voidHandlers[17]();
			DMA->IFCR = 0x900000;
			break;
		default:
			DMA->IFCR = 0xF00000;
		break;
	}
}

void DMA1_Channel7_IRQHandler(void)
{
	if (GET_BIT(DMA->Channel[6].CCR,14))
		CLR_BIT(DMA->IFCR,26);
	volatile u8 Local_u8InterruptType = ((DMA->ISR) & 0xE000000)>>25;
	switch(Local_u8InterruptType)
	{
		case 1:
			if(DMA_voidHandlers[18] != 0)
				DMA_voidHandlers[18]();
			DMA->IFCR = 0x3000000;
			break;
		case 2:
			if(DMA_voidHandlers[19] != 0)
				DMA_voidHandlers[19]();
			DMA->IFCR = 0x5000000;
			break;
		case 4:
			if(DMA_voidHandlers[20] != 0)
				DMA_voidHandlers[20]();
			DMA->IFCR = 0x9000000;
			break;
		default:
			DMA->IFCR = 0xF0000000;
		break;
	}
}


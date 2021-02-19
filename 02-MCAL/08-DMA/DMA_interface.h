//Author	:		Mohamed Gamal Eleish
//Date		:		12/10/2020
//Version	:		V01


#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

#define	DMA_CHANNEL1							1
#define DMA_CHANNEL2							2
#define DMA_CHANNEL3							3
#define DMA_CHANNEL4							4
#define DMA_CHANNEL5							5
#define DMA_CHANNEL6							6
#define DMA_CHANNEL7							7

#define DMA_TRANSFER_ERROR_HANDLE				0
#define DMA_HALF_TRANSFER_COMPLETE_HANDLE		1
#define DMA_TRANSFER_COMPLETE_HANDLE			2

void MDMA_voidInitChannels(void);
void MDMA_voidEnableChannel(u8 Copy_u8ChannelID,u32* Copy_Pu32SourceAddress, u32* Copy_Pu32DestinationAddress,u16 Copy_u16BlockLength);
void MDMA_voidAttachCallBack(u8 Copy_u8ChannelID, u8 Copy_u8InterruptType, void (*Copy_PvoidCallBack)(void));
void MDMA_voidDisableChannel(u8 Copy_u8ChannelID);

#endif


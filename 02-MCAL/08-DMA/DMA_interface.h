//Author	:		Mohamed Gamal Eleish
//Date		:		12/10/2020
//Version	:		V01


#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H
/*DMA Channels*/
#define	DMA_CHANNEL1								0
#define DMA_CHANNEL2								1
#define DMA_CHANNEL3								2
#define DMA_CHANNEL4								3
#define DMA_CHANNEL5								4
#define DMA_CHANNEL6								5
#define DMA_CHANNEL7								6

/*DMA Interrupts*/
#define DMA_INTERRUPT_TRANSFER_ERROR				0
#define DMA_INTERRUPT_HALF_TRANSFER_COMPLETE		1
#define DMA_INTERRUPT_TRANSFER_COMPLETE				2

/*Channel Direction*/
#define DMA_DIRECTION_MEM_TO_MEM					0
#define DMA_DIRECTION_MEM_TO_PREPH					1
#define DMA_DIRECTION_PERIPH_TO_MEM					2

/*Transfer size*/
#define DMA_TRANSFER_BYTE							0
#define DMA_TRANSFER_2BYTE							1
#define DMA_TRANSFER_4BYTE							2

/*Channel Priority*/
#define DMA_PRIORITY_LOW							0
#define DMA_PRIORITY_MEDIUM							1
#define DMA_PRIORITY_HIGH							2
#define DMA_PRIORITY_VERY_HIGH						3

/*Memory Increment*/
#define DMA_MEM_INC_DISABLED						0
#define DMA_MEM_INC_ENABLED							1

/*Peripheral Incerement*/
#define DMA_PERIPH_INC_DISABLED						0
#define DMA_PERIPH_INC_ENABLED						1

/*Circular Mode*/
#define DMA_CIRCULAR_DISABLED						0
#define DMA_CIRCULAR_ENABLED						1






void MDMA_voidConfigureChannel(u8 Copy_u8ChNumber, u8 Copy_u8ChDirection, u8 Copy_u8ChPriority, u8 Copy_u8MemTransSize, u8 Copy_u8PeriphTransSize, u8 Copy_u8MemInc, u8 Copy_u8PeriphInc, u8 Copy_u8CircMode);
void MDMA_voidSetAddress(u8 Copy_u8ChannelID,u32* Copy_Pu32SourceAddress, u32* Copy_Pu32DestAddress,u16 Copy_u16BlockLength);
void MDMA_voidAttachCallBack(u8 Copy_u8ChannelID, u8 Copy_u8InterruptType, void (*Copy_PvoidCallBack)(void));
void MDMA_voidEnableChannel(u8 Copy_u8ChNumber);
void MDMA_voidDisableChannel(u8 Copy_u8ChannelID);
void MDMA_voidEnableInterrupt(u8 Copy_u8Interrupt);
void MDMA_voidDisableInterrupt(u8 Copy_u8Interrupt);

#endif


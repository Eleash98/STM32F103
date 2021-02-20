//Author	:		Mohamed Gamal Eleish
//Date		:		12/10/2020
//Version	:		V01


#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

#define DMA_NUMBER_OF_CHANNELS		7

typedef struct
{
	volatile u32 CCR,
				 CNDTR,
				 CPAR,
				 CMAR,
				 Reserved;
}DMA_Channel_t;

typedef struct
{
	volatile u32 ISR,
				 IFCR;
	DMA_Channel_t Channel[DMA_NUMBER_OF_CHANNELS];
}DMA_t;

void (*DMA_voidHandlers[21])(void) = {0};

#define DMA		((volatile DMA_t*)0x40020000)

#endif


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


#define DMA_ENABLED						1
#define DMA_DISABLED					0

#define DMA_LOW							0
#define DMA_MEDIUM						1
#define DMA_HIGH						2
#define DMA_VERY_HIGH					3

#define DMA_8_BITS						0
#define DMA_16_BITS						1
#define DMA_32_BITS						2

#define DMA_READ_FROM_PERIPHERAL		0
#define DMA_READ_FROM_MEMORY			1

#endif


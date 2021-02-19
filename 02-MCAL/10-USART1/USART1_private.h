//Author		:		Mohamed G. Eleish
//Date			:		16/10/2020
//Version		:		V01



#ifndef	USART1_PRIVATE_H
#define USART1_PRIVATE_H

#define USART1_DISABLED				0
#define USART1_ENABLED				1

#define USART1_EVEN_PARITY			2
#define USART2_ODD_PARITY			3

#define USART1_1BIT					0
#define USART1_0_5_BIT				1
#define USART1_2_BIT				2
#define USART1_1_5_BIT				3

#define USART1_ASYNCHRONOUS
#define USART1_SYNCHRONOUS

#define USART1_IDLE_HIGH			1
#define USART1_IDLE_LOW				0

#define USART1_SETUP_THEN_READ		1
#define USART1_READ_THEN_SETUP		0


typedef struct
{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;
}USART_t;

#define USART1		((volatile USART_t*)(0x40013800))

#endif


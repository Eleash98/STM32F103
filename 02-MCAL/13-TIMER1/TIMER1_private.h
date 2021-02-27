//Author	:	Mohamed G. Eleish
//Version	:	V01
//Date		:	20 FEB	2021


#ifndef TIMER1_PRIVATE
#define TIMER1_PRIVATE

typedef struct
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMCR;
	volatile u32 DIER;
	volatile u32 SR;
	volatile u32 EGR;
	volatile u32 CCMR1;
	volatile u32 CCMR2;
	volatile u32 CCER;
	volatile u32 CNT;
	volatile u32 PSC;
	volatile u32 ARR;
	volatile u32 RCR;
	volatile u32 CCR[4];
	volatile u32 BDTR;
	volatile u32 DCR;
	volatile u32 DMAR;
}Timer1_t;

#define TIMER1		((volatile Timer1_t*)(0x40012C00))

#endif
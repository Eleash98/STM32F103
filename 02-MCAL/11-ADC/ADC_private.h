/*****************************************/
/* Author  :  Mohamed G. Eleish          */
/* Version :  V01                        */
/* Date    : 19 FEB 2021	             */
/*****************************************/
#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/*Register Definition*/
typedef struct{
	volatile u32 SR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMPR1;
	volatile u32 SMPR2;
	volatile u32 JOFR[4];
	volatile u32 HTR;
	volatile u32 LTR;
	volatile u32 SQR[3];
	volatile u32 JSQR;
	volatile u32 JDR[4];
	volatile u32 DR;
}ADC_t;

#define ADC1	((volatile ADC_t*)(0x40012400))



void (*RegularEndOfCoversionHandler)	(u16 Copy_u16Value) = 0;
void (*InjectedEndOfConversionHandler)	(void) 				= 0;
void (*AnalogWatchdogHandler)			(void) 				= 0;

#endif

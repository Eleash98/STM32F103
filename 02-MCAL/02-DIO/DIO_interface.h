//AUTHOR	:Mohamed Gamal
//VERSION	:V01
//DATE		:11 August 2020

//Version 	:V02
//Date		:17 August 2020
/* Added DIO_voidSetPortDirection, DIO_voidSetPortValue 
   Modified DIO_PORTA, DIO_PORTB, DIO_PORTC values*/
   
//Version	:V03
//Date		:26 August 2020
/*Modified definitions os the modes to Hex form*/


#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#define PORTA	2
#define	PORTB	3
#define PORTC	4

#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7
#define PIN8	8
#define PIN9	9
#define PIN10	10
#define PIN11	11
#define PIN12	12
#define PIN13	13
#define PIN14	14
#define PIN15	15


#define DIO_OUTPUT_SPEED_10MHZ_PP	0x1		//10Mhz push pull
#define DIO_OUTPUT_SPEED_10MHZ_OD	0x5		//10MHz	open drain
#define DIO_OUTPUT_SPEED_10MHZ_AFPP	0x9		//10MHz	alternative function open drain
#define DIO_OUTPUT_SPEED_10MHZ_AFOD	0xD		//10MHz	alternative function open drain

#define DIO_OUTPUT_SPEED_2MHZ_PP	0x2		//2Mhz  push pull
#define DIO_OUTPUT_SPEED_2MHZ_OD	0x6		//2MHz	open drain
#define DIO_OUTPUT_SPEED_2MHZ_AFPP	0xA		//2MHz	alternative function open drain
#define DIO_OUTPUT_SPEED_2MHZ_AFOD	0xE		//2MHz	alternative function open drain

#define DIO_OUTPUT_SPEED_50MHZ_PP	0x3		//50Mhz push pull
#define DIO_OUTPUT_SPEED_50MHZ_OD	0x7		//50MHz	open drain
#define DIO_OUTPUT_SPEED_50MHZ_AFPP	0xB		//50MHz	alternative function open drain
#define DIO_OUTPUT_SPEED_50MHZ_AFOD	0xF		//50MHz	alternative function open drain


#define DIO_INPUT_ANALOG		0x0			//Input Floating
#define DIO_INPUT_FLOATING		0x4			//Input Floating
#define DIO_INPUT_PULLUP_DOWN	0x8 		//Input Pullup/Down

#define PULL_UP			1
#define PULL_DOWN		0

#define DIO_HIGH		1
#define DIO_LOW			0

void DIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode);

void DIO_voidSetPin(u8 Copy_u8Port, u8 Copy_u8Pin);

void DIO_voidClearPin(u8 Copy_u8Port, u8 Copy_u8Pin);

u8 DIO_voidGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);

void DIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Mode);

void DIO_voidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);

void DIO_voidLockPin(u8 Copy_u8Port, u8 Copy_u8Pin);

void DIO_voidSetPullResistor(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode);

#endif


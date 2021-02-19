//AUTHOR	:Mohamed Gamal
//VERSION	:V01
//DATE		:11-August-2020

//Version	:V02
//Date		:26 August 2020
/*Used struct method in defining the registers*/


#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

/*Base Addresses*/
#define DIO_PORTA_BASE_ADDRESS	0x40010800
#define DIO_PORTB_BASE_ADDRESS	0x40010C00
#define DIO_PORTC_BASE_ADDRESS	0x40011000

typedef struct{
	volatile u32 CRL,CRH,IDR,ODR,BSRR,BRR,LCKR;
}DIO_t;

#define DIO_PORTA		((volatile DIO_t *)(DIO_PORTA_BASE_ADDRESS))
#define DIO_PORTB		((volatile DIO_t *)(DIO_PORTB_BASE_ADDRESS))
#define DIO_PORTC		((volatile DIO_t *)(DIO_PORTC_BASE_ADDRESS))


#endif

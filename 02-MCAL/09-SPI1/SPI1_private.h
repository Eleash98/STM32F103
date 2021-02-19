//Author		:	Mohamed Gamal Eleish
//Date			:	15/10/2020
//Version 		:	V01




#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H


#define SPI_DISABLED			0
#define SPI_ENABLED				1

#define SPI_8_BITS_FORMAT		0
#define SPI_16_BITS_FORMAT		1

#define SPI_HARDWARE_CONTROL	0
#define SPI_SOFTWARE_CONTROL	1

#define SPI_MSB_FIRST			0
#define SPI_LSB_FIRST			1

#define SPI_DIV_2				0
#define SPI_DIV_4				1
#define SPI_DIV_8				2
#define SPI_DIV_16				3
#define SPI_DIV_32				4
#define SPI_DIV_64				5
#define SPI_DIV_128				6
#define SPI_DIV_256				7

#define SPI_IDLE_LOW			0
#define SPI_IDLE_HIGH			1

#define SPI_READ_WRITE			0
#define SPI_WRITE_READ			1

#define SPI_SLAVE				0
#define SPI_MASTER				1
typedef struct
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 CRCPR;
	volatile u32 RXCRCR;
	volatile u32 TXCRCR;
	volatile u32 I2SCFGR;
	volatile u32 I2SPR;
	
}SPI_Rgister;

#define SPI1		((volatile SPI_Rgister*)(0x4003000))
#endif


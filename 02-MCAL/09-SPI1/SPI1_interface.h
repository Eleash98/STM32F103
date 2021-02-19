//Author		:	Mohamed Gamal Eleish
//Date			:	15/10/2020
//Version 		:	V01




#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void MSPI1_voidInit(void);
void MSPI1_voidSendReceiveSynch(u8 Copy_u8SSPin,u8 Copy_u8SSPort,u8 Copy_u8DataToTransmit, u8 *Copy_dataToReceive);
void MSPI1_voidSendReceiveAsynch(u8 Copy_u8SSPin,Copy_u8SSPort,u8 Copy_u8DataToTransmit, void (*SPI1_PvoidReceiveHandler)(u8 Copy_u8Data));

#endif


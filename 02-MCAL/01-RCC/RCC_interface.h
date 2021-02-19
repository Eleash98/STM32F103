//AUTHOR	:Mohamed Gamal
//VERSION	:V01
//DATE		:8-August-2020

/*Include Guard*/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/*Macro definitions*/
#define RCC_AHB     0
#define RCC_APB1    1
#define RCC_APB2    2


/*APB2	preipherals*/
#define RCC_AFIO		32
#define RCC_PORTA		34
#define RCC_PORTB		35
#define RCC_PORTC		36
#define RCC_ADC1		41
#define RCC_ADC2		42
#define RCC_TIM1		43
#define RCC_SPI1		44
#define RCC_TIM8		45
#define RCC_USART1		46
#define RCC_ADC3		47
#define RCC_TIM9		51
#define RCC_TIM10		52
#define RCC_TIM11		53

/*APB1	preipherals*/
#define RCC_TIM2		64
#define RCC_TIM3		65
#define RCC_TIM4		66
#define RCC_TIM5		67
#define RCC_TIM6		68
#define RCC_TIM7		69
#define RCC_TIM12		70
#define RCC_TIM13		71
#define RCC_TIM14		72
#define RCC_WWDG		75
#define RCC_SPI2		78
#define RCC_SPI3		79
#define RCC_USART2		81
#define RCC_USART3		82
#define RCC_USART4		83
#define RCC_USART5		84
#define RCC_I2C1		85
#define RCC_I2C2		86
#define RCC_USB			87
#define RCC_CAN			89
#define RCC_BKP			91
#define RCC_PWR			92
#define RCC_DAC			93


/*AHB preipherals*/
#define RCC_DMA1		0
#define RCC_DMA2		1
#define RCC_SRAM		2
#define RCC_FLITF		4
#define RCC_CRC			6
#define RCC_FSMC		8
#define RCC_SDIO		10


/*Functions Prototypes*/
void RCC_voidEnableClock(u8 Copy_u8PerId);
void RCC_voidDisableClock(u8 Copy_u8PerId);
void RCC_voidResetClock(u8 Copy_u8PerId);
void RCC_voidClockInit(void);

#endif // RCC_INTERFACE_H

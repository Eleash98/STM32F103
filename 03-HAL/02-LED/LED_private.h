//Author:	Mohamed Gamal
//Date	:	15 August 2020
//Version:	V01


//Version	:	V02
//Date		:	21-August 2020
/*Version 2 Has private structs so the user cannot change the LED specs*/

//Version	:	V03
//Date		:	26 August 2020
/*Version 3 add new functions that can initialize a LED array, set its value and shift values to it*/

#ifndef LED_PRIVATE_H
#define LED_PRIVATE_H


struct LED {
	u8 Pin,
	 Port,
	 Config;
};
typedef struct LED LED;


#endif

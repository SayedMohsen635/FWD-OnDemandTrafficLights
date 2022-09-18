/*
 * Button.h
 *
 * Created: 7/21/2022 11:59:56 AM
 *  Author: Sayed
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
typedef unsigned char uint8_t;
#include "../../MCAL/DIO Driver/DIO.h"
#include "../../MCAL/Timer Driver/Timer.h"

/*
	Function Name        : Button_vInit
	Function Returns     : void
	Function Arguments   : uint8_t , uint8_t
	Function Description : Setting a pin in a specific port for the button as an input
*/
void Button_vInit(uint8_t portName , uint8_t pinNumber);

/*
	Function Name        : Button_u8read
	Function Returns     : uint8_t
	Function Arguments   : uint8_t , uint8_t
	Function Description : Reading the status of the button
*/
uint8_t Button_u8read(uint8_t portName , uint8_t pinNumber);

#endif /* BUTTON_H_ */
/*
 * Led.h
 *
 * Created: 7/20/2022 3:14:14 AM
 *  Author: Sayed
 */ 


#ifndef LED_H_
#define LED_H_
typedef unsigned char uint8_t;
#include "../../MCAL/DIO Driver/DIO.h"
#include "../../MCAL/Timer Driver/Timer.h"

/*
	Function Name        : LED_vInit
	Function Returns     : void
	Function Arguments   : uint8_t , uint8_t
	Function Description : Setting the pin connected to the led as an output
*/
void LED_vInit(uint8_t portName , uint8_t pinNumber);	

/*
	Function Name        : LED_vTurnOn
	Function Returns     : void
	Function Arguments   : uint8_t , uint8_t
	Function Description : Turning the led on
*/
void LED_vTurnOn(uint8_t portName , uint8_t pinNumber);

/*
	Function Name        : LED_vTurnOff
	Function Returns     : void
	Function Arguments   : uint8_t , uint8_t
	Function Description : Turning the led off
*/
void LED_vTurnOff(uint8_t portName , uint8_t pinNumber);

/*
	Function Name        : LED_Toggle
	Function Returns     : void
	Function Arguments   : uint8_t , uint8_t
	Function Description : Toggling the led
*/
void LED_Toggle(uint8_t portName , uint8_t pinNumber);

#endif /* LED_H_ */
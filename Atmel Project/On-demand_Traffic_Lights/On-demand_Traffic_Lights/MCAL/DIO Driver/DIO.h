/*
 * DIO.h
 *
 * Created: 7/17/2022 7:04:28 PM
 *  Author: Sayed
 */ 


#ifndef DIO_H_
#define DIO_H_
#include <stdio.h>
#include "../../Utilities/registers.h"
#include "../../Utilities/stdMacros.h"
typedef unsigned char uint8_t;

/*
	Function Name        : DIO_vSetPinDir
	Function Returns     : void
	Function Arguments   : uint8_t , uint8_t , uint8_t 
	Function Description : Setting the direction of the pin in a particular register
*/
void DIO_vSetPinDir(uint8_t portName , uint8_t pinNumber , uint8_t Dir);

/*
	Function Name        : DIO_writePin
	Function Returns     : void
	Function Arguments   : uint8_t , uint8_t , uint8_t
	Function Description : Writing a value to a pin in a particular register
*/
void DIO_writePin(uint8_t portName , uint8_t pinNumber , uint8_t value);

/*
	Function Name        : DIO_u8readPin
	Function Returns     : uint8_t
	Function Arguments   : uint8_t , uint8_t
	Function Description : Reading a value of a pin from a particular register
*/
uint8_t DIO_u8readPin(uint8_t portName , uint8_t pinNumber);

/*
	Function Name        : DIO_togPin
	Function Returns     : void
	Function Arguments   : uint8_t , uint8_t
	Function Description : Toggling a pin in a particular register
*/
void DIO_togPin(uint8_t portName , uint8_t pinNumber);

/*
	Function Name        : DIO_setPortDir
	Function Returns     : void
	Function Arguments   : uint8_t , uint8_t
	Function Description : Setting the direction of a whole port register
*/
void DIO_setPortDir(uint8_t portName , uint8_t Dir);

/*
	Function Name        : DIO_writePort
	Function Returns     : void
	Function Arguments   : uint8_t , uint8_t
	Function Description : Writing a value to a whole port register
*/
void DIO_writePort(uint8_t portName , uint8_t value);

/*
	Function Name        : DIO_readPort
	Function Returns     : uint8_t
	Function Arguments   : uint8_t
	Function Description : Reading the value of a whole port register
*/
uint8_t DIO_readPort(uint8_t portName);

/*
	Function Name        : DIO_vPullUp
	Function Returns     : void
	Function Arguments   : uint8_t , uint8_t , uint8_t
	Function Description : Connecting the internal pull up resistor
*/
void DIO_vPullUp(uint8_t portName , uint8_t pinNumber , uint8_t connectValue);

/*
	Function Name        : DIO_writeLowNibble
	Function Returns     : void
	Function Arguments   : uint8_t , uint8_t
	Function Description : Writing the four low pins of the atmega32 of a specific port register
*/
void DIO_writeLowNibble(uint8_t portName , uint8_t value);

/*
	Function Name        : DIO_writeHighNibble
	Function Returns     : void
	Function Arguments   : uint8_t , uint8_t
	Function Description : Write the four high pins of the atmega32 of a specific port register
*/
void DIO_writeHighNibble(uint8_t portName , uint8_t value);

#endif /* DIO_H_ */
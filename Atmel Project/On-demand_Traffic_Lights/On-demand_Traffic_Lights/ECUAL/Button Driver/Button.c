/*
 * Button.c
 *
 * Created: 7/21/2022 12:00:07 PM
 *  Author: Sayed
 */ 

#include "Button.h"

/* This method is used to set a pin in a specific port for the button as an input */
void Button_vInit(uint8_t portName , uint8_t pinNumber){
	DIO_vSetPinDir(portName , pinNumber , 0);
}

/* This method is used to read the status of the button */
uint8_t Button_u8read(uint8_t portName , uint8_t pinNumber){
	return DIO_u8readPin(portName , pinNumber);
}

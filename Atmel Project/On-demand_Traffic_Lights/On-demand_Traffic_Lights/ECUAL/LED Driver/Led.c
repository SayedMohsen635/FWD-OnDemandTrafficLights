/*
 * Led.c
 *
 * Created: 7/20/2022 3:14:05 AM
 *  Author: Sayed
 */ 

#include "Led.h"

/* This method is used to set the pin connected to the led as an output */
void LED_vInit(uint8_t portName , uint8_t pinNumber){
	DIO_vSetPinDir(portName , pinNumber , 1);
}

/* This method is used to turn on the led */
void LED_vTurnOn(uint8_t portName , uint8_t pinNumber){
	DIO_writePin(portName , pinNumber , 1);
}

/* This method is used to turn off the led */
void LED_vTurnOff(uint8_t portName , uint8_t pinNumber){
	DIO_writePin(portName , pinNumber , 0);
}

/* This method is used to turn off the led */
void LED_Toggle(uint8_t portName , uint8_t pinNumber){
	DIO_togPin(portName , pinNumber);
}
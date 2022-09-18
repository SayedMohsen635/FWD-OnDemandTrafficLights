/*
 * App.h
 *
 * Created: 9/7/2022 4:17:30 PM
 *  Author: sayed
 */ 


#ifndef APP_H_
#define APP_H_
#define F_CPU 1000000UL
#include "../ECUAL/Button Driver/Button.h"
#include "../ECUAL/LED Driver/Led.h"
typedef unsigned char uint8_t;

/*
	Function Name        : appInit
	Function Returns     : void
	Function Arguments   : void
	Function Description : Initializing And Configuring All The Drivers , Timers And Interrupts.
*/
void appInit(void);

/*
	Function Name        : appStart
	Function Returns     : void
	Function Arguments   : void
	Function Description : Start The Scenario Of The Program Flow.
*/
void appStart(void);

#endif /* APP_H_ */
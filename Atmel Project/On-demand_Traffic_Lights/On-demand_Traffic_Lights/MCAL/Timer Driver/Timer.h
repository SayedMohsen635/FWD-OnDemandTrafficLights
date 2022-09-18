/*
 * Timer.h
 *
 * Created: 9/6/2022 3:09:03 PM
 *  Author: sayed
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#define CS00    0
#define CS01    1
#define CS02    2
#define TOV0	0
#define WGM01   3
#define WGM00   6
#define TOIE0	0
#define OCIE0   1
#define COM00   4
#define COM01   5

#include "../../Utilities/registers.h"
#include "../../Utilities/Interrupts.h"
#include "../../Utilities/stdMacros.h"

/*
	Function Name        : timerInit
	Function Returns     : void
	Function Arguments   : void
	Function Description : Initializing the normal mode of Timer 0.
*/
void timerInit(void);

/*
	Function Name        : timerStartWithNoPrescaler
	Function Returns     : void
	Function Arguments   : void
	Function Description : Start timer in the normal mode of Timer 0 with no prescaler.
*/
void timerStartWithNoPrescaler(void);

/*
	Function Name        : timerStartWithPrescaler
	Function Returns     : void
	Function Arguments   : void
	Function Description : Start timer in the normal mode of Timer 0 with 1024 prescaler.
*/
void timerStartWithPrescaler(void);

/*
	Function Name        : getTimerStatus
	Function Returns     : void
	Function Arguments   : void
	Function Description : Get the status of the flag of Timer 0.
*/
void getTimerStatus(void);

/*
	Function Name        : timerStop
	Function Returns     : void
	Function Arguments   : void
	Function Description : Stop timer in the normal mode of Timer 0.
*/
void timerStop(void);

#endif /* TIMER_H_ */
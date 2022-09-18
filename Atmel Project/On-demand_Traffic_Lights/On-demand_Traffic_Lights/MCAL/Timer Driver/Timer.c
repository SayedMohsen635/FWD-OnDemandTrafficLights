/*
 * Timer.c
 *
 * Created: 9/7/2022 4:16:37 PM
 *  Author: sayed
 */ 

#include "Timer.h"

void timerInit(void){
	// Select Timer Mode
	TCCR0 = 0x00;	// Normal Mode
	// Set Timer Initial Value
	TCNT0 = 0x00;
	// Enable I-Bit
	sei();
	// Enable Timer 0 Overflow Interrupt
	SET_BIT(TIMSK , TOIE0);	
}

void timerStartWithNoPrescaler(void){
	// Start Timer --> Set Prescaler
	SET_BIT(TCCR0 , CS00);	// No Prescaler
}

void timerStartWithPrescaler(void){
	// Start Timer --> Set 1024 Prescaler
	SET_BIT(TCCR0 , CS00);
	SET_BIT(TCCR0 , CS02);
}

void getTimerStatus(void){
	// Get Timer Flag
	READ_BIT(TIFR , TOV0);
}

void timerStop(void){
	// Stop Timer
	TCCR0 = 0x00;
}
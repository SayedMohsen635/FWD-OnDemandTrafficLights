/*
 * App.c
 *
 * Created: 9/7/2022 4:17:21 PM
 *  Author: sayed
 */ 

#include "App.h"
#define MAX_OVERFLOWS	20
volatile unsigned short Overflows;
volatile unsigned short Flag;
volatile unsigned short Counter;

void appInit(void){
	// 1. Configure Cars' Leds
	LED_vInit('A' , 0);		// Green
	LED_vInit('A' , 1);		// Yellow
	LED_vInit('A' , 2);		// Red
	
	// 2. Configure Pedestrians' Leds
	LED_vInit('B' , 0);		// Green
	LED_vInit('B' , 1);		// Yellow
	LED_vInit('B' , 2);		// Red
	
	// 3. Initialize Timer 0 in Normal Mode
	timerInit();
	
	// 4. Configure INT0 Interrupt
	MCUCR |= (1 << ISC00) | (1 << ISC01);		// Select the rising edge mode for INT0
	GICR |= (1 << INT0);						// Set the source of interrupt(Enable INT0)
}

void appStart(void){
	/* 1. Turn On Cars' Green Led For 5 Seconds */
	LED_vTurnOn('A' , 0);
	timerStartWithPrescaler();		// Start Timer With Prescaler 1024
	while(Overflows < MAX_OVERFLOWS);
	Overflows = 0;
	timerStop();					// Stop Timer
	if((Flag == 1) && (DIO_u8readPin('A' , 0) == 1)){
		LED_vTurnOff('A' , 0);
		timerStartWithPrescaler();		// Start Timer With Prescaler 1024
		while(Overflows < MAX_OVERFLOWS){
			LED_Toggle('A' , 1);
			LED_Toggle('B' , 1);
			// Delay For Toggling
			while(Counter < 50){
				Counter++;
			}
			Counter = 0;
		}
		Counter = 0;
		Overflows = 0;
		timerStop();					// Stop Timer
		LED_vTurnOff('A' , 1);
		LED_vTurnOff('B' , 1);
		LED_vTurnOn('A' , 2);
		LED_vTurnOn('B' , 0);
		timerStartWithPrescaler();		// Start Timer With Prescaler 1024
		while(Overflows < MAX_OVERFLOWS);
		Overflows = 0;
		timerStop();					// Stop Timer
		LED_vTurnOff('A' , 2);
		LED_vTurnOff('B' , 0);
		timerStartWithPrescaler();		// Start Timer With Prescaler 1024
		while(Overflows < MAX_OVERFLOWS){
			LED_Toggle('A' , 1);
			LED_Toggle('B' , 1);
			// Delay For Toggling
			while(Counter < 50){
				Counter++;
			}
			Counter = 0;
		}
		Counter = 0;
		Overflows = 0;
		timerStop();					// Stop Timer
		LED_vTurnOff('A' , 1);
		LED_vTurnOff('B' , 1);
		LED_vTurnOn('A' , 0);
		LED_vTurnOn('B' , 2);
		timerStartWithPrescaler();		// Start Timer With Prescaler 1024
		while(Overflows < MAX_OVERFLOWS);
		Overflows = 0;
		timerStop();					// Stop Timer
		LED_vTurnOff('A' , 0);
		LED_vTurnOff('B' , 2);
	}else{
		/* Turn Off Cars' Green Led for 5 Seconds */
		LED_vTurnOff('A' , 0);
	}
	/* To Prevent Interrupt From Being Executed Again */
	Flag = 0;
	/* 2. Blink Cars' Yellow Led for 5 Seconds */
	timerStartWithPrescaler();		// Start Timer With Prescaler 1024
	while(Overflows < MAX_OVERFLOWS){
		LED_Toggle('A' , 1);
		// Delay For Toggling
		while(Counter < 50){
			Counter++;
		}
		Counter = 0;
	}
	Counter = 0;
	Overflows = 0;
	timerStop();					// Stop Timer
	LED_vTurnOff('A' , 1);
	if(Flag == 1){
		timerStartWithPrescaler();		// Start Timer With Prescaler 1024
		while(Overflows < MAX_OVERFLOWS){
			LED_Toggle('A' , 1);
			LED_Toggle('B' , 1);
			// Delay For Toggling
			while(Counter < 50){
				Counter++;
			}
			Counter = 0;
		}
		Counter = 0;
		Overflows = 0;
		timerStop();					// Stop Timer
		LED_vTurnOff('A' , 1);
		LED_vTurnOff('B' , 1);
		LED_vTurnOn('A' , 2);
		LED_vTurnOn('B' , 0);
		timerStartWithPrescaler();		// Start Timer With Prescaler 1024
		while(Overflows < MAX_OVERFLOWS);
		Overflows = 0;
		timerStop();					// Stop Timer
		LED_vTurnOff('A' , 2);
		LED_vTurnOff('B' , 0);
		timerStartWithPrescaler();		// Start Timer With Prescaler 1024
		while(Overflows < MAX_OVERFLOWS){
			LED_Toggle('A' , 1);
			LED_Toggle('B' , 1);
			// Delay For Toggling
			while(Counter < 50){
				Counter++;
			}
			Counter = 0;
		}
		Counter = 0;
		Overflows = 0;
		timerStop();					// Stop Timer
		LED_vTurnOff('A' , 1);
		LED_vTurnOff('B' , 1);
		LED_vTurnOn('A' , 0);
		LED_vTurnOn('B' , 2);
		timerStartWithPrescaler();		// Start Timer With Prescaler 1024
		while(Overflows < MAX_OVERFLOWS);
		Overflows = 0;
		timerStop();					// Stop Timer
		LED_vTurnOff('A' , 0);
		LED_vTurnOff('B' , 2);
		timerStartWithPrescaler();		// Start Timer With Prescaler 1024
		while(Overflows < MAX_OVERFLOWS){
			LED_Toggle('A' , 1);
			// Delay For Toggling
			while(Counter < 50){
				Counter++;
			}
			Counter = 0;
		}
		Counter = 0;
		Overflows = 0;
		timerStop();					// Stop Timer
		LED_vTurnOff('A' , 1);
		LED_vTurnOn('A' , 2);
	}else{
		/* 3. Turn On Cars' Red Led for 5 Seconds */
		LED_vTurnOn('A' , 2);
	}
	/* To Prevent Interrupt From Being Executed Again */
	Flag = 0;
	timerStartWithPrescaler();		// Start Timer With Prescaler 1024
	while(Overflows < MAX_OVERFLOWS);
	Overflows = 0;
	timerStop();					// Stop Timer
	/* 4. Turn Off Cars' Red Led and Blink Cars' Yellow Led for 5 Seconds */
	if((Flag == 1) && (DIO_u8readPin('A' , 2) == 1)){
		LED_vTurnOn('B' , 0);
		timerStartWithPrescaler();		// Start Timer With Prescaler 1024
		while(Overflows < MAX_OVERFLOWS);
		Overflows = 0;
		timerStop();					// Stop Timer
		LED_vTurnOff('A' , 2);
		LED_vTurnOff('B' , 0);
		timerStartWithPrescaler();		// Start Timer With Prescaler 1024
		while(Overflows < MAX_OVERFLOWS){
			LED_Toggle('A' , 1);
			LED_Toggle('B' , 1);
			// Delay For Toggling
			while(Counter < 50){
				Counter++;
			}
			Counter = 0;
		}
		Counter = 0;
		Overflows = 0;
		timerStop();					// Stop Timer
		LED_vTurnOff('A' , 1);
		LED_vTurnOff('B' , 1);
		LED_vTurnOn('A' , 0);
		LED_vTurnOn('B' , 2);
		timerStartWithPrescaler();		// Start Timer With Prescaler 1024
		while(Overflows < MAX_OVERFLOWS);
		Overflows = 0;
		timerStop();					// Stop Timer
		LED_vTurnOff('A' , 0);
		LED_vTurnOff('B' , 2);
	}else{
		LED_vTurnOff('A' , 2);
		timerStartWithPrescaler();		// Start Timer With Prescaler 1024
		while(Overflows < MAX_OVERFLOWS){
			LED_Toggle('A' , 1);
			// Delay For Toggling
			while(Counter < 50){
				Counter++;
			}
			Counter = 0;
		}
		Counter = 0;
		Overflows = 0;
		timerStop();					// Stop Timer
		LED_vTurnOff('A' , 1);
	}
	Flag = 0;
}

ISR(TIMER0_OVF_vect){
	Overflows++;
}

ISR(EXT_INT_0){
	Flag = 1;
}
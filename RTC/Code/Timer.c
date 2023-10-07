/*

 * Timer.c
 *
 *  Created on: Sep 3, 2023
 *      Author: GAFFARY SOFFT
 */


#include "Timer.h"
#define F_CPU 1000000ul
#include "DIO.h"
#include <avr/interrupt.h>

extern volatile BYTE flag;
volatile BYTE tick;

ISR(TIMER0_COMP_vect){
	//////////////////////////////////////////////////////////////////////////
	//changed
	if(tick==5){
		flag = 1;
		tick = 0;
	}
	else{tick++;}
}

void timer_init(){
	tick = 0;
	sei();
	//SREG |= (1<<7);  // Enable global interrupt
	TIMSK |= (1<<1); // Enable Timer interrupt
	// SET CTC MODE
	TCCR0 &= ~(1<<6);
	TCCR0 |= (1<<3);
	// SET COUNTER CLOCK
	TCCR0 |= (1<<0);
	TCCR0 &= ~(1<<1);
	TCCR0 |= (1<<2);
	// SET COMPARING VALUE
	//////////////////////////////////////////////////////////////////////////
	//changed
	OCR0 = 200;
}


/*

 * main.c
 *
 *  Created on: Sep 3, 2023
 *      Author: GAFFARY SOFFT
 */


#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include "schedular.h"
#include "Interrupt.h"
#include "DIO.h"

int main(void)
{
		//////////////////////////////////////////////////////////////////////////
		//changed
		//first 3 pins in PORTB input with pull up resistor
	DDRB=0;
	PORTB=0X07;

	start();

	while (1)
    {
		engine();
		//////////////////////////////////////////////////////////////////////////
		//changed
		if(pin_read('B',0)==0)
		{
			BUTTON_1_PRESS();
			_delay_ms(250);
		}
		else if (pin_read('B',1)==0)
		{
			BUTTON_2_PRESS();
			_delay_ms(250);
		}
		else if (pin_read('B',2)==0)
		{
			BUTTON_3_PRESS();
			_delay_ms(250);
		}
	}

}




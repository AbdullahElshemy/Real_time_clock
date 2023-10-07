/*

* Schedular.c
 *
 *  Created on: Sep 3, 2023
 *      Author: GAFFARY SOFFT
 */



#include "interrupt.h"
#include "Timer.h"
#include "Schedular.h"
#include "clock.h"
#include "LCD.h"
#include "DIO.h"
#include "STD_TYPES.h"

BYTE mode; // extern to interrupt
BYTE HR;   // extern to interrupt
BYTE MIN;  // extern to interrupt
BYTE SEC;

BYTE DAY;
BYTE MONTH;
unsigned int YEAR;

BYTE TIME;
BYTE previous_time;

BYTE flag;

void start(){
	mode = 0;

	HR = 10;
	MIN =1;
	SEC = 00;

	DAY = 8;
	MONTH = 9;
	YEAR = 2024;

	TIME = PM;
	previous_time = TIME;

	flag = 0;
	LCD_init();
	 //interrupt_init();

	timer_init();
	clock_write(HR,MIN,SEC);
	date_write(DAY,MONTH,YEAR);
}

void engine()
{
	if(mode == 0)
	{
		if(flag == 1) {// one second
			SEC++;
			flag=0;
			if(SEC == 60){
				MIN++;
				SEC=0;
			}

			if (MIN > 59){
				HR++;
				MIN=0;
			}

			if (HR > 12){
				HR=1;
			}

			if(HR == 12){
				if(TIME==AM) {TIME = PM;}
				else if(TIME == PM) {TIME = AM;}
			}

			if(previous_time == PM && TIME == AM) {//new day
				previous_time = TIME;
				BYTE max_days;
				if(MONTH==1 ||MONTH==3 ||MONTH==5 ||MONTH==7 ||MONTH==8 ||MONTH==10 ||MONTH==12) {//31 days in these months
				max_days=31;
				}
				else if(MONTH==2) max_days = 28;
				else max_days = 30;

				if (DAY==max_days)
				{
					MONTH++;
					DAY = 1;
				}
				else {DAY++;}

				if(MONTH == 12){
					YEAR++;
					MONTH = 1;
				}
			}

			clock_write(HR,MIN,SEC);
			date_write(DAY,MONTH,YEAR);
		}
	}
	else
	{
		/**/
	}



}




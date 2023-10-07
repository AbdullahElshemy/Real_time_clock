/*

 * Interrupt.c
 *
 *  Created on: Sep 3, 2023
 *      Author: GAFFARY SOFFT
 */

#include <avr/interrupt.h>
#include "Interrupt.h"
#include "LCD.h"
#include "clock.h"
#include "schedular.h"

	//////////////////////////////////////////////////////////////////////////
	//changed

extern volatile BYTE mode;
extern volatile BYTE HR;
extern volatile BYTE MIN;
extern volatile BYTE SEC;
extern volatile BYTE TIME;
extern volatile BYTE DAY;
extern volatile BYTE MONTH;
extern volatile unsigned int YEAR;

// Mode Bottom
void BUTTON_1_PRESS(void)
{
		if(mode == 6) {mode = 0;}
		else {mode++;}
		clock_write(HR , MIN , SEC);
		date_write(DAY , MONTH, YEAR);
}


void BUTTON_2_PRESS(void)
{
	// increasing hours
	if(mode == 1){
		if(HR == 12) {HR = 1;}
		else {HR++;}
		clock_write(HR , MIN , SEC);
	}
	// increasing minuets
	else if(mode == 2){
		if(MIN == 59) {MIN = 0;}
		else {MIN++;}
		clock_write(HR , MIN , SEC);
	}
	// increasing seconds
	else if(mode == 3){
		if(SEC == 59) {SEC = 0;}
		else {SEC++;}
		clock_write(HR , MIN , SEC);
	}
	// increasing days
	else if(mode == 4){
		BYTE max_days;
		if(MONTH==1 ||MONTH==3 ||MONTH==5 ||MONTH==7 ||MONTH==8 ||MONTH==10 ||MONTH==12) max_days = 31;
		else if (MONTH == 2) max_days = 28;
		else max_days = 30;

		if(DAY == max_days) {DAY = 1;}
		else {DAY++;}
		date_write(DAY,MONTH,YEAR);
	}
	// increasing months
	else if(mode==5){
		if(MONTH==12) {MONTH = 1;}
		else {MONTH++;}
		date_write(DAY,MONTH,YEAR);
	}
	// increasing years
	else if(mode==6){
		YEAR++;
		date_write(DAY,MONTH,YEAR);
	}
}

void BUTTON_3_PRESS(void)
{
		// decreasing hours
		if(mode == 1){
			if(HR == 1) {HR = 12;}
			else {HR--;}
			clock_write(HR , MIN , SEC);
		}
		// decreasing minuets
		else if(mode == 2){
			if(MIN == 0) {MIN = 59;}
			else {MIN--;}
			clock_write(HR , MIN , SEC);
		}
		// decreasing hours
		else if(mode == 3){
			if(SEC == 0) {SEC = 59;}
			else {SEC --;}
			clock_write(HR , MIN , SEC);
		}
		// decreasing days
		else if(mode == 4){
			BYTE max_days;
			if(MONTH==1 ||MONTH==3 ||MONTH==5 ||MONTH==7 ||MONTH==8 ||MONTH==10 ||MONTH==12) max_days = 31;
			else if (MONTH == 2) max_days = 28;
			else max_days = 30;

			if(DAY == 1) {DAY = max_days;}
			else {DAY--;}
			date_write(DAY,MONTH,YEAR);
		}
		// decreasing months
		else if(mode==5){
			if(MONTH==1) {MONTH = 12;}
			else {MONTH--;}
			date_write(DAY,MONTH,YEAR);
		}
		// decreasing years
		else if(mode==6){
			YEAR--;
			date_write(DAY,MONTH,YEAR);
		}
}




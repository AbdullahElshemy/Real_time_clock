/*
 * LCD.h
 *
 *  Created on: Sep 3, 2023
 *      Author: GAFFARY SOFFT
 */

#ifndef LCD_H_
#define LCD_H_

#include "STD_TYPES.h"

//typedef unsigned char BYTE;
void LCD_cmd(BYTE cmd);
void LCD_init ();
void LCD_write_char(BYTE data);
void LCD_write(BYTE* data);
void LCD_startfrom(BYTE row , BYTE pos);
void LCD_set_time(BYTE time);


#endif /* LCD_H_ */

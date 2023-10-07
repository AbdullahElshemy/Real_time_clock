/*

* DIO.h
 *
 *  Created on: Sep 3, 2023
 *      Author: GAFFARY SOFFT
 */

#ifndef DIO_H_
#define DIO_H_


#include "STD_TYPES.h"


//typedef unsigned char BYTE;
#define INPUT 0
#define OUTPUT 1
#define HIGH 1
#define LOW 0

void pin_mode (char port , BYTE pin , BYTE mode);
void pin_write (char port , BYTE pin ,BYTE value);
void port_write (char port , BYTE value);
BYTE pin_read (char port , BYTE pin);
BYTE port_read(char port);

#endif /* DIO_H_ */

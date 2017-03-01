#ifndef KEYB_H
#define KEYB_H

#include "screen.h"
#include "system.h"
#include "types.h"

string readStr()
{
	char buff;
	string buffstr;
	uint8 i = 0;
	uint8 isReading = 1;

	while(isReading)
	{
		/* 0x64 Allows to check for the keyboard input */
		/* Goes through switch only when the key is pressed (The result of the inportb(0x64) must be a NON-ZERO) */
		if(inportb(0x64) & 0x1)	
		{
			/* The address in which the key code is read from */
			/* Each of the following codes is called SCAN CODE */
			/* We need to convert each code to it's ASCII representation */
			switch(inportb(0x60))
			{
			    case 2:
			            printch('1');
			            buffstr[i] = '1';
			            i++;
			            break;
			    case 3:
			            printch('2');
			            buffstr[i] = '2';
			            i++;
			            break;
			    case 4:
			            printch('3');
			            buffstr[i] = '3';
			            i++;
			            break;
			    case 5:
			            printch('4');
			            buffstr[i] = '4';
			            i++;
			            break;
			    case 6:
			            printch('5');
			            buffstr[i] = '5';
			            i++;
			            break;
			    case 7:
			            printch('6');
			            buffstr[i] = '6';
			            i++;
			            break;
			    case 8:
			            printch('7');
			            buffstr[i] = '7';
			            i++;
			            break;
			    case 9:
			            printch('8');
			            buffstr[i] = '8';
			            i++;
			            break;
			    case 10:
			            printch('9');
			            buffstr[i] = '9';
			            i++;
			            break;
			    case 11:
			            printch('0');
			            buffstr[i] = '0';
			            i++;
			            break;

			}
		}
	}
}
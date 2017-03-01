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
				case 1:


			}
		}
	}
}
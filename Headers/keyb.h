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
		if(inportb(0x64) & 0x1)
		{
			switch(inportb(0x60))
		}
	}
}
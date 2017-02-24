#ifndef SCREEN_H
#define SCREEN_H
#include "types.h"
#include "system.h"
#include "string.h"

int cursorX = 0, cursorY = 0;
const uint8 sw = 80, sh = 25, sd = 2;
void clearLine(uint8 line_s, uint8 line_e)
{
	uint16 i = sw * line_s * sd;
	string vidmem = (string)0xb8000;
	for(i;i<(sw*(line_e+1)*sd;i++)
	{
		vidmem[i] = 0x0;
	}
}


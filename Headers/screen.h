#ifndef SCREEN_H
#define SCREEN_H
#include "types.h"
#include "system.h"
#include "string.h"

int cursorX = 0, cursorY = 0;
const uint8 sw = 80, sh = 25, sd = 2;					//sw = screen width, height, depth, sd=2 => color,char
void clearLine(uint8 line_s, uint8 line_e)				//Delete lines from line_s to line_e
{
	uint16 i = sw * line_s * sd;			
	string vidmem = (string)0xb8000;
	for(i;i<(sw*(line_e+1)*sd;i++)
	{
		vidmem[i] = 0x0;
	}
}


void updateCursor()
{
	unsigned temp;
	temp = cursorY * sw + cursorX;					//Position = (Y*Width) + X
	
	outportb(0x3D4, 14);						//CRT Control Register
	outportb(0x3D5, temp >> 8);					//Send the high byte across the bus
	outportb(0x3D4, 15);						//CRT Control Register
	outportb(0x3D5, temp);						//Send the low byte of the cursor location
}


void clearScreen()
{
	clearLine(0,sh-1);
	cursorX = 0;
	cursorY = 0;
	updateCursor();
}



	

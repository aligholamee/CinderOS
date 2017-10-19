/* Cinder OS
# ========================================
# [] File Name : screen.c
#
# [] Creation Date : December 2016
#
# [] Created By : Ali Gholami (aligholami7596@gmail.com)
# ========================================
*/

#include "../headers/screen.h"

int cursorX = 0, cursorY = 0;
const uint8 sw = 80, sh = 25, sd = 2;							/* sw = screen width, height, depth, sd=2 => color,char */
int color = 0x0F;
void clearLine(uint8 line_s, uint8 line_e)						/* Delete lines from line_s to line_e */
{
	uint16 i = sw * line_s * sd;
	string vidmem = (string)0xb8000;
	for(i;i<(sw*(line_e+1)*sd);i++)
	{
		vidmem[i] = 0x0;
	}
}


void updateCursor()
{
	unsigned temp;
	temp = cursorY * sw + cursorX;							/* Position = (Y*Width) + X */

	outportb(0x3D4, 14);								/* CRT Control Register */
	outportb(0x3D5, temp >> 8);							/* Send the high byte across the bus */
	outportb(0x3D4, 15);								/* CRT Control Register */
	outportb(0x3D5, temp);								/* Send the low byte of the cursor location */
}


void clearScreen()
{
	clearLine(0,sh-1);
	cursorX = 0;
	cursorY = 0;
	updateCursor();
}


void scrollUp(uint8 lineNumber)
{
	string vidmem = (string)0xb8000;
	uint16 i = 0;

	for(i;i<sw*(sh-1)*sd;i++)
	{
		vidmem[i] = vidmem[i+sw+sd+lineNumber];
	}
	clearLine(sh-1-lineNumber,sh-1);
	if((cursorY - lineNumber) < 0)
	{
		cursorX = 0;
		cursorY = 0;
	}
	else
	{
		cursorY -= lineNumber;
	}
	updateCursor();
}


void checkNewLine()
{
	if(cursorY >= sh-1)
	{
		scrollUp(1);
	}
}

void printChar(char c)
{
	string vidmem = (string)0xb8000;

	switch(c)
	{
		case (0x08):								/* 0x08 = Backspace */
			if(cursorX > 0)
			{
				cursorX--;
				vidmem[(cursorY*sw + cursorX)*sd] = 0x00;		/* Everything in that positions is deleted */
			}
			break;
		case (0x09):								/* 0x09 = Tab */
			cursorX = (cursorX + 8) & ~(8 - 1);
			break;
		case ('\r'):							        /* Start the line from beginning */
			cursorX = 0;
			break;
		case('\n'):								/* Jump to the next line */
			cursorX = 0;
			cursorY++;
			break;
		default:
			vidmem [((cursorY * sw + cursorX)) * sd] = c;			/* Print charachter c to the first byte */
			vidmem [((cursorY * sw + cursorX)) * sd + 1] = 0x0F;	        /* 0x0F = White (Set character color to white) */
			cursorX++;
			break;
	}

	if(cursorX >= sw)								/* End of the screen width */
	{
		cursorX = 0;
		cursorY++;
	}

	checkNewLine();
	updateCursor();
}

void print(string ch)									/* Print an string */
{
	uint16 i = 0;
	uint8 length = strlength(ch)-1;
	for(i;i<length;i++)
	{
		printChar(ch[i]);							        /* Loop through string */
	}
}


void setScreenColor(int text_color,int bg_color)
{
	color =  (bg_color << 4) | text_color;;
}

void set_screen_color_from_color_code(int color_code)
{
	color = color_code;
}

void print_colored(string ch,int text_color,int bg_color)
{
	int current_color = color;
	setScreenColor(text_color,bg_color);
	print(ch);
	set_screen_color_from_color_code(current_color);
}

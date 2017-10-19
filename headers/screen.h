/* Cinder OS
# ========================================
# [] File Name : screen.h
#
# [] Creation Date : December 2016
#
# [] Created By : Ali Gholami (aligholami7596@gmail.com)
# ========================================
*/

#ifndef SCREEN_H
#define SCREEN_H
#include "types.h"
#include "system.h"
#include "string.h"
int cursorX , cursorY;
const uint8 sw ,sh ,sd ;

void clearLine(uint8 line_s, uint8 line_e);
void updateCursor();
void clearScreen();
void scrollUp(uint8 lineNumber);
void checkNewLine();
void printChar(char c);
void print(string ch);
void set_screen_color_from_color_code(int color_code);
void set_screen_color(int text_color,int bg_color);
void print_colored(string ch,int text_color,int bg_color);


#endif

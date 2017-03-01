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

#endif



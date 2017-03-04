#include "../Headers/keyb.h"

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
			            printChar('1');
			            buffstr[i] = '1';
			            i++;
			            break;
			    case 3:
			            printChar('2');
			            buffstr[i] = '2';
			            i++;
			            break;
			    case 4:
			            printChar('3');
			            buffstr[i] = '3';
			            i++;
			            break;
			    case 5:
			            printChar('4');
			            buffstr[i] = '4';
			            i++;
			            break;
			    case 6:
			            printChar('5');
			            buffstr[i] = '5';
			            i++;
			            break;
			    case 7:
			            printChar('6');
			            buffstr[i] = '6';
			            i++;
			            break;
			    case 8:
			            printChar('7');
			            buffstr[i] = '7';
			            i++;
			            break;
			    case 9:
			            printChar('8');
			            buffstr[i] = '8';
			            i++;
			            break;
			    case 10:
			            printChar('9');
			            buffstr[i] = '9';
			            i++;
			            break;
			    case 11:
			            printChar('0');
			            buffstr[i] = '0';
			            i++;
			            break;
			    case 12:
		                printChar('-');
		                buffstr[i] = '-';
		                i++;
		                break;
		        case 13:
		                printChar('=');
		                buffstr[i] = '=';
		                i++;
		                break;
		        case 14:
		                printChar('\b');
		                i--;
		                buffstr[i] = 0;
		                break;
		        case 15:
		                printChar('\t');         
		                buffstr[i] = '\t';
		                i++;
		                break;
		        case 16:
		                printChar('q');
		                buffstr[i] = 'q';
		                i++;
		                break;
		        case 17:
		                printChar('w');
		                buffstr[i] = 'w';
		                i++;
		                break;
		        case 18:
		                printChar('e');
		                buffstr[i] = 'e';
		                i++;
		                break;
		        case 19:
		                printChar('r');
		                buffstr[i] = 'r';
		                i++;
		                break;
		        case 20:
		                printChar('t');
		                buffstr[i] = 't';
		                i++;
		                break;
		        case 21:
		                printChar('y');
		                buffstr[i] = 'y';
		                i++;
		                break;
		        case 22:
		                printChar('u');
		                buffstr[i] = 'u';
		                i++;
		                break;
		        case 23:
		                printChar('i');
		                buffstr[i] = 'i';
		                i++;
		                break;
		        case 24:
		                printChar('o');
		                buffstr[i] = 'o';
		                i++;
		                break;
		        case 25:
		                printChar('p');
		                buffstr[i] = 'p';
		                i++;
		                break;
		        case 26:
		                printChar('[');
		                buffstr[i] = '[';
		                i++;
		                break;
		        case 27:
		                printChar(']');
		                buffstr[i] = ']';
		                i++;
		                break;
		        case 28:
		                printChar('\n');
		                buffstr[i] = '\n';
		                i++;
		                isReading = 0;
		                break;
		        case 29:
		                printChar('q');           		/* Left Control */
		                buffstr[i] = 'q';
		                i++;
		                break;
		        case 30:
		                printChar('a');
		                buffstr[i] = 'a';
		                i++;
		                break;
		        case 31:
		                printChar('s');
		                buffstr[i] = 's';
		                i++;
		                break;
		        case 32:
		                printChar('d');
		                buffstr[i] = 'd';
		                i++;
		                break;
		        case 33:
		                printChar('f');
		                buffstr[i] = 'f';
		                i++;
		                break;
		        case 34:
		                printChar('g');
		                buffstr[i] = 'g';
		                i++;
		                break;
		        case 35:
		                printChar('h');
		                buffstr[i] = 'h';
		                i++;
		                break;
		        case 36:
		                printChar('j');
		                buffstr[i] = 'j';
		                i++;
		                break;
		        case 37:
		                printChar('k');
		                buffstr[i] = 'k';
		                i++;
		                break;
		        case 38:
		                printChar('l');
		                buffstr[i] = 'l';
		                i++;
		                break;
		        case 39:
		                printChar(';');
		                buffstr[i] = ';';
		                i++;
		                break;
		        case 40:
		                printChar((char)44);               /*   Single quote (') */
		                buffstr[i] = (char)44;
		                i++;
		                break;
		        case 41:
		                printChar((char)44);               /* Back tick (`) */
		                buffstr[i] = (char)44;
		                i++;
		                break;
		        case 42:                                 /* Left shift */
		                printChar('q');
		                buffstr[i] = 'q';
		                i++;
		                break;
		        case 43:                                 /* (< for somekeyboards)   */
		                printChar((char)92);
		                buffstr[i] = 'q';
		                i++;
		                break;
		        case 44:
		                printChar('z');
		                buffstr[i] = 'z';
		                i++;
		                break;
		        case 45:
		                printChar('x');
		                buffstr[i] = 'x';
		                i++;
		                break;
		        case 46:
		                printChar('c');
		                buffstr[i] = 'c';
		                i++;
		                break;
		        case 47:
		                printChar('v');
		                buffstr[i] = 'v';
		                i++;
		                break;                
		        case 48:
		                printChar('b');
		                buffstr[i] = 'b';
		                i++;
		                break;               
		        case 49:
		                printChar('n');
		                buffstr[i] = 'n';
		                i++;
		                break;                
		        case 50:
		                printChar('m');
		                buffstr[i] = 'm';
		                i++;
		                break;               
		        case 51:
		                printChar(',');
		                buffstr[i] = ',';
		                i++;
		                break;                
		        case 52:
		                printChar('.');
		                buffstr[i] = '.';
		                i++;
		                break;            
		        case 53:
		                printChar('/');
		                buffstr[i] = '/';
		                i++;
		                break;            
		        case 54:
		                printChar('.');
		                buffstr[i] = '.';
		                i++;
		                break;            
		        case 55:
		                printChar('/');
		                buffstr[i] = '/';
		                i++;
		                break;            
		        case 56:
		                printChar(' ');          			 /* Right shift */
		                buffstr[i] = ' ';
		                i++;
		                break;           
		        case 57:
		                printChar(' ');
		                buffstr[i] = ' ';
		                i++;
		                break;

			}
		}
	}
}

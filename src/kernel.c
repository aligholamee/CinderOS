/* Cinder OS
# ========================================
# [] File Name : kernel.c
#
# [] Creation Date : December 2016
#
# [] Created By : Ali Gholami (aligholami7596@gmail.com)
# ========================================
*/

#include "../headers/screen.h"
#include "../headers/string.h"
#include "../headers/isr.h"
#include "../headers/idt.h"
#include "../headers/keyb.h"
#include "../headers/shell.h"

int cmain()
{
	isr_install();
	clearScreen();
	print("Cinder is up...\nWhat can i do?");
	start_shell(0);
}

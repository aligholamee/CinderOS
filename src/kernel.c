#include "../Headers/screen.h"
#include "../Headers/string.h"
#include "../Headers/isr.h"
#include "../Headers/idt.h"
#include "../Headers/keyb.h"
#include "../Headers/shell.h"

int cmain()
{
	isr_install();
	clearScreen();
	print("Cinder is up...\nWhat can i do?");
	start_shell(0);		
}

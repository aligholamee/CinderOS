#include "../Headers/screen.h"
#include "../Headers/string.h"
#include "../Headers/isr.h"
#include "../Headers/idt.h"
#include "../Headers/keyb.h"

cmain()
{
	isr_install();
	clearScreen();
	print("Cinder is up...\nWhat can i do?");
	while(1)
	{
		print("\nCINDER> ");

		string ch = readStr();

		if(strEql(ch,"cmd") || strEql(ch,"CMD"))
		{
			print("Cinder is up...\nWhat can i do?");
		}

		else if(strEql(ch,"clear") || strEql(ch,"CLEAR"))
		{
			clearScreen();
		}

		else
		{
			print("Wrong Command!\n");
		}

		print("\n");
	}
			
}

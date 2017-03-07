#include "../Headers/shell.h"

void start_shell(int n)
{
	/* Dynamic memory allocation :| */
	string ch = (string) malloc(200);
	/* Simple counter :| */
	int CNT = 0;
	do
	{
		print("CINDER (");
	 	print(intToString(n));
	 	print(")>");
	 	/* Get the input :| */
	 	ch = readStr();
	 	if(strEql(ch,"cmd"))
	 	{
	 		print("\nAlready in the CMD. A new shell is created.\n");
	 		start_shell(n+1);
	 	}
	 	else if(strEql(ch,"clear"))
	 		clearScreen();
	 	else if(strEql(ch,"sum"))
	 		sum();
	 	else if(strEql(ch,"exit"))
	 		print("\nGood Bye Cruel :D\n");
	 	else if(strEql(ch,"echo"))
	 		echo();
	 	else if(strEql(ch,"sort"))
	 		sort();
	 	else if(strEql(ch,"fibonacci")
	 		fibonacci();
	 	else if(strEql(ch,"gcd"))
	 		gcd();
	 	else if(strEql(ch,"help"))
	 		help();
	 	else if(strEql(ch,"color"))
	 		setColor();
	 	else
	 	{
	 		print("\nWTF?!\n");
	 		print("CINDER> ");
	 	}
	}while(!strEql(ch,"exit"));
}
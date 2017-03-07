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

/* Simply start the summation procedure */
void sum()
{
	print("\nHow many numbers: ");
	int n = stringToInt(readStr());
	int i = 0;
	print("\n");
	int arr[n];
	fill_array(arr,n);
	int s = sum_array(arr,n);
	print("Result: ");
	print(intToString(s));
	print("\n");
}

/* Simply fill the array with the user input :| */
void fill_array(int arr[],int n)
{
	int i = 0;
	for(i = 0;i < n;i++)
	{
		print("ARR[");
		print(intToString(i));
		print("]: ");
		arr[i] = stringToInt(readStr());
		print("\n");
	}
}

/* Simply find the summation of the array elements :| */ 
int sum_array(int arr[],int n)
{
	int i = 0;
	int sum = 0;

	for(i = 0;i < n;i++)
		sum += arr[i];
	return sum;
}

/* Simply print the user input to the user :| */
void echo()
{
	print("\n");
	string str = readStr();
	print("\n");
	print(str);
	print("\n");
}

void sort()
{
	int arr[100];
	print("\nArray size please: ");
	int n = stringToInt(readStr());
	print("\n");
	fill_array(arr,n);
	print("Before Sorting: \n");
	print_array(arr,n);

	print("\nWhat order you want to sort?(1 for increasing / 0 for decreasing): ");
	int order = stringToInt(readStr());
	insertion_sort(arr,n,order);

	print("\nAfter Sorting: \n");
	print_array(arr,n);
}
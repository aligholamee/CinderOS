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

/* Calling the insertion sort algorithm from here :| */
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

/* Simple insertion sort found on the web :| */
void insertion_sort(int arr[], int n, int order)
{
	int i = 0
	for( i =1; i < n;i++)
	{
		int aux = arr[i];
		int j = i;
		while((j > 0) && ((aux < arr[j-1]) && order))
		{
			arr[j] = arr[j-1];
			j = j - 1;
		}
		arr[j] = aux;
	}
}

void fibonacci()
{
	print("\nHow many Elements: ");
	int n = stringToInt(readStr());
	print("\n");
	int i = 0;
	for(i = 0;i < n;i++)
	{
		print("Fibo ");
		print(intToString(i));
		print(" : ");
		print(intToString(fibo(i)));
		print("\n");
	}
}

int fibo(int n)
{
	if(n<2)
		return 1;
	else
		return fibo(n-1) + fibo(n-2);
}

void gcd()
{
	print("\nHow many numbers: ");
	int n = stringToInt(readStr());
	int i =0;
	print("\n");
	int arr[n];
	int matrix[n][n];
	fill_array(arr,n);
	for (i = 0;i<n;i++)
	{
		matrix[0][i] = arr[i];
	}
	int j = 0;
	for (i =1;i<n;i++)
	{
		for (j=0;j<n-1;j++)
		{
			matrix[i][j] = gcd_couple(matrix[i-1][j] , matrix[i-1][j+1]);
		}
	}
	print("Result: ");
	print(intToString(matrix[n-1][0]));
	print("\n");
}


int gcd_couple(int a,int b)
{
	if(b == 0)
		return 1;
	if(a % b ==0) 
		return b;
	else 
		return gcd_couple(b,a % b);
}

/* Matrix printing function for debugging purposes */
void print_matrix(int matrix[][100],int rows,int cols)
{
	int i = 0;
	int j = 0;
	for(i = 0; i < rows;i++)
	{
		print(intToString(matrix[i][j]));
		print(" ");
	}
	print("\n");

}


void setBackgroundColor()
{
	print("\nColor codes : ");
	print("\n0 : black");

	/* Following function is defined in screen.h */
	print_colored("\n1 : blue",1,0);   
	print_colored("\n2 : green",2,0);
	print_colored("\n3 : cyan",3,0);
	print_colored("\n4 : red",4,0);
	print_colored("\n5 : purple",5,0);
	print_colored("\n6 : orange",6,0);
	print_colored("\n7 : grey",7,0);
	print_colored("\n8 : dark grey",8,0);
	print_colored("\n9 : blue light",9,0);
	print_colored("\n10 : green light",10,0);
	print_colored("\n11 : blue lighter",11,0);
	print_colored("\n12 : red light",12,0);
	print_colored("\n13 : rose",13,0);
	print_colored("\n14 : yellow",14,0);
	print_colored("\n15 : white",15,0);
	
	print("\n\n Text color ? : ");
	int text_color = stringToInt(readStr());
	print("\n\n Background color ? : ");
	int bg_color = stringToInt(readStr());
	/* Following function is defined in screen.h */
	setScreenColor(text_color,bg_color);
	clearScreen();

}

void help()
{
	print("\ncmd       : Launch a new recursive Shell");
	print("\nclear     : Clears the screen");
	print("\nsum       : Computes the sum of n numbers");
	print("\necho      : Reprint a given text");
	print("\nsort      : Sorts a given n numbers");
	print("\nfibonaci  : Prints the first n numbers of fibonaci");
	print("\ngcd       : Computes the grand common divider of n given numbers");
	print("\nexit      : Quits the current shell");
	print("\ncolor     : Changes the colors of the terminal");
	
	print("\n\n");
}
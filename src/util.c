#include "../Headers/util.h"

void memory_copy(char *source, char *dest, int nbytes)
{
	int i;
	for (i = 0; i < nbytes; i++)
	{
		/* dest[i] = soruce[i] */
		*(dest + i) = *(source + i);
	}
}

void memory_set(uint8 *dest, uint8 val, uint32 len)
{
	uint8 *temp = (uint8 *)dest;
	for ( ; len != 0; len--) 
		*temp++ = val;
}

void int_to_ascii(int n, char str[])
{
	int i, sign;
	if((sign = n) < 0) n = -n;

	i = 0;
	do 
	{
		/* Take out each digit and calculate it's ascii */
		str[i++] = n % 10 + '0';
	} while((n /= 10) > 0);

	/* Add negative sign */
	if (sign < 0) str[i++] = '-';

	/* Add null character */
	str[i] = '\0';

	/* Reverse str */
}


string intToString(int n)
{
	string ch = malloc(50);
	int_to_ascii(n,ch);
	int len = strlength(ch);
	int i = 0;
	int j = len - 1;
	while(i<(len/2 + len%2))
	{
		char tmp = ch[i];
		ch[i] = ch[j];
		ch[j] = tmp;
		i++;
		j--;
	}
	return ch;
}



void * malloc(int nbytes)
{
	char variable[nbytes];
	return &variable;
}

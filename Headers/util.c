#include "util.h"

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


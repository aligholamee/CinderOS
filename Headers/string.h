#ifndef STRING_H
#define STRING_H

#include "types.h"
uint16 strlength(string ch)
{
	uint16 i = 1;
	while(ch[i++]);
	return --i;
}

#endif

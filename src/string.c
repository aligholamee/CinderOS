/* Cinder OS
# ========================================
# [] File Name : string.c
#
# [] Creation Date : December 2016
#
# [] Created By : Ali Gholami (aligholami7596@gmail.com)
# ========================================
*/

#include "../headers/string.h"

uint16 strlength(string ch)
{
	uint16 i = 0;
	while(ch[i++]);
	return i-1;
}

uint8 strEql(string ch1,string ch2)
{
	uint8 result = 1;
	uint8 size = strlength(ch1);

	if(size != strlength(ch2))
		result = 0;
	else
	{
		uint8 i = 0;
		for(i;i<=size;i++)
		{
			if(ch1[i] != ch2[i])
				result = 0;

		}
	}
	return result;
}

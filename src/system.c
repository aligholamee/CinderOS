/* Cinder OS
# ========================================
# [] File Name : system.c
#
# [] Creation Date : December 2016
#
# [] Created By : Ali Gholami (aligholami7596@gmail.com)
# ========================================
*/

#include "../headers/system.h"
uint8 inportb(uint16 _port)
{
	uint8 rv;
	__asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
	return rv;
}

void outportb(uint16 _port, uint8 _data)
{
	__asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

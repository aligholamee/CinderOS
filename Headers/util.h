#ifndef UTIL_H
#define UTIL_H

#include "types.h"

/* Copying data in the memory */
void memory_copy(char *soruce, char *dest, int nbytes);

/* Assigning a value to an specific address in the memory for len times */
void memory_set(uint8 *dest, uint8 val, uint32 len);

/* Converting integer to string */
void int_to_ascii(int n, char str[]);

#endif
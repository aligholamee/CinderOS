/* Cinder OS
# ========================================
# [] File Name : util.h
#
# [] Creation Date : December 2016
#
# [] Created By : Ali Gholami (aligholami7596@gmail.com)
# ========================================
*/

#ifndef UTIL_H
#define UTIL_H

#include "types.h"

/* Copying data in the memory */
void memory_copy(char *soruce, char *dest, int nbytes);

/* Assigning a value to an specific address in the memory for len times */
void memory_set(uint8 *dest, uint8 val, uint32 len);

/* Converting integer to ascii */
void int_to_ascii(int n, char str[]);

/* Converting integer to string */
string intToString(int n);

/* Converting string to integer */
int stringToInt(string ch);

/* Memory allocation function */
void * malloc(int bytes);

#endif

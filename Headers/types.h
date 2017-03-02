#ifndef TYPES_H
#define TYPES_H

typedef signed char int8;
typedef unsigned char uint8;

typedef signed short int16;
typedef unsigned short uint16;

typedef signed int int32;
typedef unsigned int uint32;

typedef signed long long int64;
typedef unsigned long long uint64;

typedef char* string;

/* Simply AND the lower 16 bits with the 0xFFFF Mask */
#define low_16(address) (uint16)((address) & 0xFFFF)

/* Simply AND the higher 16 bits with the 0xFFFF Mask */
#define high_16(address) (uint16)((address) >> 16) & 0xFFFF 

#endif

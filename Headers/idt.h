#ifndef IDT_H
#define IDT_H

#include "types.h"

#define KERNEL_CS 0x08

/* Defines each element of the interrupt descriptor table (IDT) */
/* The following struct is going to be produced 256 times */
typedef struct 
{
	uint16 low_offset;
	uint16 sel;
	uint8 always0;
	uint8 flags;
	uint16 high_offset;
}__attribute__((packed)) idt_gate_t;

typedef struct 
{
	uint16 limit;
	uint32 base;
}__attribute__((packed)) idt_register_t;
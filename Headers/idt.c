#include "idt.h"
#include "util.h"

void set_idt_gate(int n, uint32 handler)
{
	idt[n].low_offset = low_16(handler);
	idt[n].sel = KERNEL_CS;
	idt[n].always0 = 0;
	idt[n].flags = 0x8E;
	idt.high_offset = high_16(handler);
}
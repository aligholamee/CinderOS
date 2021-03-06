/* Cinder OS
# ========================================
# [] File Name : idt.c
#
# [] Creation Date : December 2016
#
# [] Created By : Ali Gholami (aligholami7596@gmail.com)
# ========================================
*/

#include "../headers/idt.h"
#include "../headers/util.h"

void set_idt_gate(int n, uint32 handler)
{
	idt[n].low_offset = low_16(handler);
	idt[n].sel = KERNEL_CS;
	idt[n].always0 = 0;
	idt[n].flags = 0x8E;
	idt[n].high_offset = high_16(handler);
}

void set_idt()
{
	/* Assign the address of the idt to the base variable in idt_reg */
	idt_reg.base = (uint32) &idt;
	idt_reg.limit = IDT_ENTRIES * sizeof(idt_gate_t) - 1;
	__asm__ __volatile__("lidtl (%0)" : : "r" (&idt_reg));

}

#include "isr.h"
#include "idt.h"
#include "screen.h"
#include "util.h"

void isr_install()
{
	/* Fill IDT gates with the handler functions needed to handle the interrupts */
	set_idt_gate(0, (uint32)isr0);
	set_idt_gate(1, (uint32)isr1);
	set_idt_gate(2, (uint32)isr2);
	set_idt_gate(3, (uint32)isr3);
	set_idt_gate(4, (uint32)isr4);
	set_idt_gate(5, (uint32)isr5);
	set_idt_gate(6, (uint32)isr6);
	set_idt_gate(7, (uint32)isr7);
	set_idt_gate(8, (uint32)isr8);
	set_idt_gate(9, (uint32)isr9);
	set_idt_gate(10, (uint32)isr10);
	set_idt_gate(11, (uint32)isr11);
	set_idt_gate(12, (uint32)isr12);
	set_idt_gate(13, (uint32)isr13);
	set_idt_gate(14, (uint32)isr14);
	set_idt_gate(15, (uint32)isr15);
	set_idt_gate(16, (uint32)isr16);
	set_idt_gate(17, (uint32)isr17);
	set_idt_gate(18, (uint32)isr18);
	set_idt_gate(19, (uint32)isr19);
	set_idt_gate(20, (uint32)isr20);
	set_idt_gate(21, (uint32)isr21);
	set_idt_gate(22, (uint32)isr22);
	set_idt_gate(23, (uint32)isr23);
	set_idt_gate(24, (uint32)isr24);
	set_idt_gate(25, (uint32)isr25);
	set_idt_gate(26, (uint32)isr26);
	set_idt_gate(27, (uint32)isr27);
	set_idt_gate(28, (uint32)isr28);
	set_idt_gate(29, (uint32)isr29);
	set_idt_gate(30, (uint32)isr30);
	set_idt_gate(31, (uint32)isr31);
}
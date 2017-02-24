bits 32
section 	.text
	align 	4
	dd	0x1BADB002
	dd	0x00
	dd	- {0x1BADB002+0x00}

global start
extern cmain				;cmain function is in the kernel.c
start:
	cli				;Clear the interrupts
	call cmain			;Set program counter to fetch this routine
	hlt				;Pause cpu from executing this routine

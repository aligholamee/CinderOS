COMPILER = gcc
LINKER = ld
ASSEMBLER = nasm
CFLAGS = -m32 -c --ffreestanding
ASFLAGS = -f elf32
LDFLAGS = -m elf_i386 -T src/link.ld
EMUALATOR = qemu-system-i386
EMUALATOR_FLAGS = -kernel


SRCS = src/kernel.asm src/kernel.c src/idt.c src/isr.c src/screen.c src/string.c src/system.c src/util.c
OBJS = Objects/cinder.o Objects/cinderc.o Objects/idt.o Objects/isr.o Objects/screen.o Objects/string.o Objects/system.o Objects/util.o
OUTPUT = CinderOS/boot/kernel.bin

run:link
	$(EMUALATOR) $(EMUALATOR_FLAGS) $(OUTPUT)

link:compile $(OBJS)
	rm -r -f CinderOS/
	mkdir CinderOS/
	mkdir CinderOS/boot
	$(LINKER) $(LDFLAGS) -o $(OUTPUT) $(OBJS)

	

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

compile:$(SRCS)
	rm Objects/ -r -f
	mkdir Objects/

Objects/cinder.o:src/kernel.asm
	$(ASSEMBLER) $(ASFLAGS) -o Objects/cinder.o src/kernel.asm

Objects/cinderc.o:src/kernel.c
	$(COMPILER) $(CFLAGS) src/kernel.c -o Objects/cinderc.o 
	
Objects/idt.o:src/idt.c
	$(COMPILER) $(CFLAGS) src/idt.c -o Objects/idt.o 

Objects/kb.o:src/keyb.c
	$(COMPILER) $(CFLAGS) src/kb.c -o Objects/keyb.o

Objects/isr.o:src/isr.c
	$(COMPILER) $(CFLAGS) src/isr.c -o Objects/isr.o

Objects/screen.o:src/screen.c
	$(COMPILER) $(CFLAGS) src/screen.c -o Objects/screen.o

Objects/string.o:src/string.c
	$(COMPILER) $(CFLAGS) src/string.c -o Objects/string.o

Objects/system.o:src/system.c
	$(COMPILER) $(CFLAGS) src/system.c -o Objects/system.o

Objects/util.o:src/util.c
$(COMPILER) $(CFLAGS) src/util.c -o Objects/util.o


build:all
	rm CinderOS/boot/grub/ -r -f
	mkdir CinderOS/boot/grub/
	echo set default=0 >> CinderOS/boot/grub/grub.cfg
	echo set timeout=0 >> CinderOS/boot/grub/grub.cfg
	echo menuentry "CinderOS" { >> CinderOS/boot/grub/grub.cfg
	echo         set root='(hd96)' >> CinderOS/boot/grub/grub.cfg
	echo         multiboot /boot/kernel.bin >> CinderOS/boot/grub/grub.cfg
	echo } >> CinderOS/boot/grub/grub.cfg

grub-mkrescue -o CinderOS.iso CinderOS/

clear:
	rm -f obj/*.o
	rm -r -f CinderOS/
	
nasm -f elf32 kernel.asm -o cinder.o
gcc -m32 -c kernel.c -o cinderc.o -ffreestanding
gcc -m32 -c Headers/isr.c -o Objects/isr.o -ffreestanding
gcc -m32 -c Headers/idt.c -o Objects/idt.o -ffreestanding
gcc -m32 -c Headers/util.c -o Objects/util.o -ffreestanding
gcc -m32 -c Headers/system.c -o Objects/system.o -ffreestanding
gcc -m32 -c Headers/string.c -o Objects/string.o -ffreestanding  
gcc -m32 -c Headers/screen.c -o Objects/screen.o -ffreestanding                                                     
gcc -m32 -c Headers/keyb.c -o Objects/keyb.o -ffreestanding 
ld -m elf_i386 -T link.ld -o CinderOS/boot/kernel.bin cinder.o cinderc.o Objects/isr.o Objects/idt.o Objects/util.o Objects/system.o Objects/string.o Objects/screen.o Objects/keyb.o 
qemu-system-i386 -kernel CinderOS/boot/kernel.bin
grub-mkrescue -o CinderOS.iso CinderOS/

read a

nasm -f elf32 kernel.asm -o cinder.o
gcc -m32 -c kernel.c -o cinderc.o
ld -m elf_i386 -T link.ld -o kernel.bin cinder.o cinderc.o
qemu-system-i386 -kernel kernel.bin
grub-mkrescue -o CinderOS.iso CinderOS/

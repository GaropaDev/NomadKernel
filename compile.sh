nasm -f elf32 kernel.asm -o ./bin/kasm.o
gcc -m32 -c kernel.c -o ./bin/kc.o
gcc -m32 -c kScreen.c -o ./bin/ksc.o
gcc -m32 -c kStdLib.c -o ./bin/kst.o
cd bin
ld -m elf_i386 -T ../link.ld -o kernel-0 kasm.o kc.o kst.o ksc.o
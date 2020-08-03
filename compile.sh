#!/bin/bash

readonly NAME_KERNEL=Nomad_Kernel
readonly VERSION=1
readonly COMPILATION=0
readonly DIR_BUILD=build            # Resultado da compilacao, objetos
readonly DIR_BIN=bin                # Resultado da linkagen, kernel

echo "Compilando Kernel - $VERSION.$COMPILATION"

# Criando diretorio BUILD caso não exista
if ! [ -d $DIR_BUILD ]; then
    mkdir $DIR_BUILD
fi

# Criando diretorio BIN caso não exista
if ! [ -d $DIR_BIN ]; then
    mkdir $DIR_BIN
fi

# Compilando assembly
nasm -f elf32 kernel.asm -o ./$DIR_BUILD/kasm.o

# Compilando c
gcc -m32 -c kernel.c -o "./$DIR_BUILD/kc.o"

# Linkando
ld -m elf_i386 -T link.ld -o "./$DIR_BIN/$NAME_KERNEL-$VERSION" "./$DIR_BUILD/*.o"

# incrementando compilação
#sed -i "s/readonly COMPILATION=$COMPILATION/readonly COMPILATION=$(($COMPILATION+1))/" compile.sh
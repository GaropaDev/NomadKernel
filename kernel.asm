;;Projeto produzido por Thiago Jose Silveira
;;Tubarao - SC - Brazil
;;29/07/2020 - Em meio a pandemia
;;Tutorial seguido retirado de:
;;https://arjunsreedharan.org/post/82710718100/kernels-101-lets-write-a-kernel

;;kernel.asm
bits 32						;nasm directive - 32 bits
section .text
	;multiboot spec
	align 4
	dd 0x1BADB002	;magic
	dd 0x00			;flags
	dd - (0x1BADB002 + 0x00)

global start
extern kmain				;kmain is defined in the c file

start:
	cli						;block interrupts
	mov esp, stack_space 	;set stack pointer
	call kmain
	hlt						;halt the cpu

section .bss
resb 8192					;8KB for stack
stack_space:

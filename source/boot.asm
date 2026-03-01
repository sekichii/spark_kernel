; Multiboot constants
MAGIC    equ 0x1BADB002
MBFLAGS  equ 0x03
CHECKSUM equ -(MAGIC + MBFLAGS)

section .multiboot
align 4
    dd MAGIC
    dd MBFLAGS
    dd CHECKSUM

section .text
global _start
extern k_main

_start:
    mov esp, stack_top
    
    call k_main

    cli
.hang:
    hlt
    jmp .hang

section .bss
align 16
stack_bottom:
    resb 16384
stack_top:

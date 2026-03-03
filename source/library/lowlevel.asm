section .text

global load_gdt
global load_idt
global check_cpuid
global get_cpuid

load_gdt:
    mov eax, [esp + 4]  ; get the pointer to the GDT descriptor
    lgdt [eax]          ; load the GDT

    ret

load_idt:
    mov eax, [esp + 4]
    lidt [eax]

    ret

check_cpuid:
    pushfd
    pushfd
    xor dword [esp],0x00200000
    popfd
    pushfd
    pop eax
    xor eax,[esp]
    popfd
    and eax,0x00200000
    ret

get_cpuid:
    push ebp
    mov ebp, esp
    push ebx

    mov eax, [ebp + 8]
    cpuid

    mov edi, [ebp + 12]

    mov [edi + 0], eax
    mov [edi + 4], ebx
    mov [edi + 8], ecx
    mov [edi + 12], edx

    pop ebx
    mov esp, ebp
    pop ebp

    ret


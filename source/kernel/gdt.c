#include <stdint.h>

#include "kernel/gdt.h"

struct gdt_ptr gdt_ptr_struct;
struct gdt_entry gdt_entry_struct[6];
struct tss_entry tss_entry_struct;

struct gdt_entry encode_gdt_entry(uint32_t limit, uint32_t base, uint8_t access, uint8_t flags) {
    struct gdt_entry gdt_e;

    gdt_e.limit_low =   (uint16_t)(limit & 0xFF);
    gdt_e.base_low =    (uint16_t)(base & 0xFF);
    gdt_e.base_middle = (uint8_t)((base & 0xF00) >> 8);
    gdt_e.access =      access;
    gdt_e.limit_flags = (uint8_t)(((limit & 0xF00) >> 8) | ((flags & 0xF) << 4));
    gdt_e.base_high =   (uint8_t)((base & 0xF000) >> 12);

    return gdt_e;
}

void gdt_init() {
    gdt_ptr_struct.limit = (sizeof(struct gdt_entry) * 6) - 1;
    gdt_ptr_struct.base = (uint32_t)&gdt_entry_struct;

    gdt_entry_struct[0] = encode_gdt_entry(0, 0x00000, 0x00, 0x0); // Null Descriptor
    gdt_entry_struct[1] = encode_gdt_entry(0, 0xFFFFF, 0x9A, 0xC); // Kernel Mode Code Segment
    gdt_entry_struct[2] = encode_gdt_entry(0, 0xFFFFF, 0x92, 0xC); // Kernel Mode Data Segment
    gdt_entry_struct[3] = encode_gdt_entry(0, 0xFFFFF, 0xFA, 0xC); // User Mode Code Segment
    gdt_entry_struct[4] = encode_gdt_entry(0, 0xFFFFF, 0xF2, 0xC); // User Mode Data Segment
    
    tss_init(0x10, 0x00);
    load_gdt(&gdt_ptr_struct);
}

void tss_init(uint16_t ss0, uint32_t esp0) {
    uint32_t base = (uint32_t)&tss_entry_struct;
    uint32_t limit = base + sizeof(tss_entry_struct);

    tss_entry_struct.ss0 = ss0;
    tss_entry_struct.esp0 = esp0;

    gdt_entry_struct[5] = encode_gdt_entry(limit, base, 0x89, 0x0); // Task State Segment
}
#include "kernel/idt.h"

struct idt_entry_struct table[256];

struct idt_entry_struct encode_idt_entry(uint32_t offset, uint16_t selector, uint8_t reserved, uint8_t gate_type) {
    struct idt_entry_struct idt_entry;

    idt_entry.offset_low = (uint16_t)(offset & 0xFFFF);
    idt_entry.offset_high = (uint16_t)((offset >> 16) & 0xFFFF);

    idt_entry.selector = selector;
    idt_entry.reserved = 0x00;

    idt_entry.type_attr = (uint8_t)(0x80 | gate_type);

    return idt_entry;
}

void idt_init() {
    struct idt_descriptor_struct idt_descriptor;

    idt_descriptor.size = (sizeof(struct idt_entry_struct) * 256) - 1;
    idt_descriptor.offset = (uint32_t)&table;

    load_idt(&idt_descriptor);
}
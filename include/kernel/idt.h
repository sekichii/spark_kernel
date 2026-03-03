#ifndef IDT_H
#define IDT_H

#include <stdint.h>

enum idt_gate_type {
    IDT_GATE_TYPE__TASK_GATE = 0x5,
    IDT_GATE_TYPE__16_INTERRUPT_GATE = 0x6,
    IDT_GATE_TYPE__16_TRAP_GATE = 0x7,
    IDT_GATE_TYPE__32_INTERRUPT_GATE = 0xE,
    IDT_GATE_TYPE__32_TRAP_GATE = 0xF
};

struct idt_descriptor_struct {
    uint16_t size;
    uint32_t offset;
}__attribute__((packed));

struct idt_entry_struct {
    uint16_t offset_low;
    uint16_t selector;
    uint8_t reserved;
    uint8_t type_attr;
    uint16_t offset_high;
}__attribute__((packed));

extern void load_idt(struct idt_descriptor_struct* idt_descriptor);

struct idt_entry_struct encode_idt_entry(uint32_t offset, uint16_t selector, uint8_t reserved, uint8_t type_attr);
void idt_init();

#endif
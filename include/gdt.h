#include <stdint.h>

/** Because the 386 was designed with backwards compatibility for the 286, 
 * descriptors ended up with fragmented internal structure.
 * 
 * Base is a 32 bit value split between bits 16-39 and bits 56-63 of the descriptor.
 * Limit is a 20 bit value split between bits 0-15 and bits 48-51 of the descriptor.
 * Offset is a 32 bit values split between bits 0-15 and bits 48-63 of the descriptor.
 * Selector is a 16 bit value in bits 16-31 of the descriptor.
 * Attributes are a collection of values in bits 32-47 of a gate or in bits 40-47 plus 52-55 of a nongate.
 * 
 * http://www.osdever.net/tutorials/view/descriptor-tables-gdt-idt-ldt
 */

struct gdt_entry {
    uint16_t limit_low;     // bits 0 to 15
    uint16_t base_low;      // bits 16 to 31
    uint8_t base_middle;    // bits 32 to 39
    uint8_t access;         // bits 40 to 47 
    uint8_t limit_flags;    // bits 48 to 51 (limit) & 52 to 55 (flags)
    uint8_t base_high;      // bits 56 to 63
} __attribute__((packed));

struct gdt_ptr {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

struct tss_entry {
    uint32_t link;
    uint32_t esp0;
    uint32_t ss0;
    uint32_t esp1;
    uint32_t ss1;
    uint32_t esp2;
    uint32_t ss2;
    uint32_t cr3;
    uint32_t eip;
    uint32_t eflags;
    uint32_t eax;
    uint32_t ecx;
    uint32_t edx;
    uint32_t ebx;
    uint32_t esp;
    uint32_t ebp;
    uint32_t esi;
    uint32_t edi;
    uint32_t es;
    uint32_t cs;
    uint32_t ss;
    uint32_t ds;
    uint32_t fs;
    uint32_t gs;
    uint32_t ldtr;
    uint32_t iobp;
    uint32_t ssp;
} __attribute__((packed));

/**
 * @brief Encodes a tightly packed entry struct.
 * @param limit     A 20-bit value that tells the maximum addressable unit.
 * @param base      A 32-bit value containing the linear address where the segment begins.
 * @param access    An 8-bit value encoding different data about the segment.
 * @param flags     A 4-bit value encoding different flags about the segment.
 * @return          The encoded entry struct.
 */
struct gdt_entry encode_gdt_entry(uint32_t limit, uint32_t base, uint8_t access, uint8_t flags);

/**
 * @brief Sets the GDT table up for 32-bit Flat mode.
 */
void gdt_init();

void tss_init(uint16_t ss0, uint32_t esp0);
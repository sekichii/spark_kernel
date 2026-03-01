struct gdt_entry {
    unsigned short limit;
    unsigned short base_low;
    unsigned char base_middle;
    unsigned char access;
    unsigned char attributes;
    unsigned char base_high;
} __attribute__((packed));
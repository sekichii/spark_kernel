#ifndef CPU_H
#define CPU_H

#include <stdint.h>

struct cpuid_res_struct {
    uint32_t eax;
    uint32_t ebx;
    uint32_t ecx;
    uint32_t edx;
}__attribute__((packed));

// assembly
extern void get_cpuid(uint32_t leaf, struct cpu_res_struct* res);

void print_cpu_data(); 

#endif
#include "drivers/cpu.h"
#include "kernel/kstatus.h"

#include <stdint.h>

void print_cpu_data() {
    struct cpuid_res_struct vendor_res;
    get_cpuid(0x00, &vendor_res);

    // Turn those registers into a string
    char vendor_id[13];
    *(uint32_t *)(vendor_id + 0) = vendor_res.ebx;
    *(uint32_t *)(vendor_id + 4) = vendor_res.edx;
    *(uint32_t *)(vendor_id + 8) = vendor_res.ecx;
    vendor_id[12] = '\0';

    kstatus_debug("CPU Vendor ID is: %s", vendor_id);
}
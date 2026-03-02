#include <cpuid.h>

#include "drivers/terminal.h"

#include "kernel/kprint.h"
#include "kernel/kstatus.h"
#include "kernel/kpanic.h"

#include "gdt.h"

void k_main(void) {
	terminal_init();
	terminal_clear();

	kstatus_info("Spark Kernel");
	gdt_init();
	kstatus_debug("Successfully initialized GDT!");


	while(1);
}

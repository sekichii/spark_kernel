#include "drivers/terminal.h"
#include "drivers/cpu.h"

#include "kernel/kprint.h"
#include "kernel/kstatus.h"
#include "kernel/kpanic.h"

#include "kernel/gdt.h"
#include "kernel/idt.h"

void k_main(void) {
	terminal_init();
	terminal_clear();

	kstatus_info("Spark Kernel");

	print_cpu_data();

	gdt_init();
	kstatus_debug("Successfully initialized GDT!");

	idt_init();
	kstatus_debug("Successfully initialized IDT!");


	while(1);
}

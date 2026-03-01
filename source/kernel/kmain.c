#include <cpuid.h>

#include "terminal.h"
#include "kprint.h"

void k_main(void) {
	terminal_init();
	terminal_clear();

	kprintf("Hello, World!");

	while(1);
}

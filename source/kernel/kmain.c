#include <cpuid.h>

#include "terminal.h"
#include "kprint.h"

void k_main(void) {
	terminal_init();
	terminal_clear();

	// goals for tomorrow: actually read out data about the cpu via cpuid

	kprintf("Hello, World! %d", 69420);

	while(1);
}

#include "drivers/terminal.h"
#include "drivers/vga.h"
#include "kernel/kprint.h"

void kpanic(char* msg) {
    terminal_change_attribute(
        VGA_COLOR_RED, VGA_COLOR_WHITE
    );

    terminal_clear();

    kprintf("KERNEL PANIC\n");
    kprintf(msg);

    while(1);
}
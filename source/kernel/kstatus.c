#include <stdarg.h>

#include "drivers/terminal.h"
#include "drivers/vga.h"
#include "kernel/kprint.h"
#include "kernel/kstatus.h"

void kstatus_error(char* msg, ...) {
    terminal_change_attribute(
        VGA_COLOR_BLACK, VGA_COLOR_RED
    );

    kprintf("[ERROR] ");

    terminal_change_attribute(
        VGA_COLOR_BLACK, VGA_COLOR_WHITE
    );

    va_list args;
    va_start(args, msg);
    vkprintf(msg, args);
    va_end(args);

    kprintf("\n");
}

void kstatus_info(char* msg, ...) {
    terminal_change_attribute(
        VGA_COLOR_BLACK, VGA_COLOR_LIGHT_GRAY
    );

    kprintf("[INFO] ");

    terminal_change_attribute(
        VGA_COLOR_BLACK, VGA_COLOR_WHITE
    );

    va_list args;
    va_start(args, msg);
    vkprintf(msg, args);
    va_end(args);

    kprintf("\n");
}

void kstatus_debug(char* msg, ...) {
    terminal_change_attribute(
        VGA_COLOR_BLACK, VGA_COLOR_CYAN
    );

    kprintf("[DEBUG] ");

    terminal_change_attribute(
        VGA_COLOR_BLACK, VGA_COLOR_WHITE
    );

    va_list args;
    va_start(args, msg);
    vkprintf(msg, args);
    va_end(args);

    kprintf("\n");
}
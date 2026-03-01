#ifndef TERMINAL_H
#define TERMINAL_H

#include <stddef.h>
#include <stdint.h>

#include "vga.h"

extern size_t cursor_column;
extern size_t cursor_row;

extern uint8_t terminal_attribute;

void terminal_init();
void terminal_put_char(uint8_t character);
void terminal_put_string(char* str);
void terminal_clear();
void terminal_scroll();

#endif
#include "terminal.h"
#include "vga.h"

size_t cursor_column = 0;
size_t cursor_row = 0;
uint8_t terminal_attribute = 0;

void terminal_init() {
    terminal_attribute = vga_create_attribute(
        VGA_COLOR_GREEN, VGA_COLOR_BRIGHT_GREEN
    );
}



void terminal_put_char(uint8_t character) {
    if(character == '\n') {
        cursor_column = 0;
        cursor_row++;
    } else {
        uint16_t entry = vga_create_entry(
            character, terminal_attribute
        );

        vga_put_entry_at(
            entry,
            cursor_column,
            cursor_row
        );

        cursor_column++;

        if (cursor_column >= VGA_TEXT_WIDTH) {
            cursor_column = 0;
            cursor_row++;
        }
    }

    if(cursor_row >= VGA_TEXT_HEIGHT) {
        // terminal_scroll()
        
        // for now just clear terminal, since memcpy is not implemented yet
        terminal_clear(); 
        cursor_row = VGA_TEXT_HEIGHT - 1;
    }
}

void terminal_put_string(char* str) {
    while (*str != '\0') {
        terminal_put_char(*str);
        str++;
    }
}

void terminal_clear() {
    for (int y = 0; y < VGA_TEXT_HEIGHT; y++) {
        for (int x = 0; x < VGA_TEXT_WIDTH; x++) {
            terminal_put_char(' ');
        }
    }

    cursor_column = 0;
    cursor_row = 0;
}

void terminal_set_attribute(uint16_t attribute) {
    terminal_attribute = attribute;
}

void terminal_scroll() {

}
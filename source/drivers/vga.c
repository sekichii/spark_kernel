#include "vga.h"

void vga_put_entry_at(uint16_t entry, size_t x, size_t y) {
    volatile uint16_t* text_buffer = (volatile uint16_t*)VGA_TEXT_BUFFER;

    size_t index = y * VGA_TEXT_WIDTH + x;
    text_buffer[index] = entry;
}

uint16_t vga_get_entry_at(size_t x, size_t y) {
    volatile uint16_t* text_buffer = (volatile uint16_t*)VGA_TEXT_BUFFER;

    size_t index = y * VGA_TEXT_WIDTH + x;
    return text_buffer[index];
}

uint8_t vga_create_attribute(uint8_t background_color, uint8_t foreground_color) {
    return (uint8_t)((background_color << 4) | foreground_color);
}

uint16_t vga_create_entry(uint8_t character, uint8_t attribute) {
    return (uint16_t)((attribute << 8) | character);
}

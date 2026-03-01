#ifndef VGA_H
#define VGA_H

#define VGA_TEXT_WIDTH 80
#define VGA_TEXT_HEIGHT 25
#define VGA_TEXT_BUFFER 0xB8000

#include <stddef.h>
#include <stdint.h>

enum vga_color {
    VGA_COLOR_BLACK = 0,
    VGA_COLOR_BLUE = 1,
    VGA_COLOR_GREEN = 2,
    VGA_COLOR_AQUA = 3,
    VGA_COLOR_RED = 4,
    VGA_COLOR_MAGENTA = 5,
    VGA_COLOR_BROWN = 6,
    VGA_COLOR_LIGHT_GRAY = 7,
    VGA_COLOR_DARK_GRAY = 8,
    VGA_COLOR_BRIGHT_BLUE = 9,
    VGA_COLOR_BRIGHT_GREEN = 10,
    VGA_COLOR_CYAN = 11,
    VGA_COLOR_MAROON = 12,
    VGA_COLOR_PURPLE = 13,
    VGA_COLOR_YELLOW = 14,
    VGA_COLOR_WHITE = 15
};

/**
 * @brief Puts an entry in the correct memory address regarding the x and y coordinate.
 * @param entry     The entry to put in the VGA buffer.
 * @param x         The x coordinate.
 * @param y         The y coordinate.
 * @return void
 */
void vga_put_entry_at(uint16_t entry, size_t x, size_t y);

/**
 * @brief Gets an entry from the VGA buffer at a memory address based off of the x and y coordinate.
 * @param x     The x coordinate.
 * @param y     The y coordinate.
 */
uint16_t vga_get_entry_at(size_t x, size_t y);

/**
 * @brief Creates a VGA Text mode attribute using two colors from the EGA palette.
 * @param background_color  The color for the background of the attribute.
 * @param foreground_color  The color for the foreground of the attribute.
 * @return uint8_t          The created attribute.
 */
uint8_t vga_create_attribute(uint8_t background_color, uint8_t foreground_color);

/**
 * @brief Creates a VGA Text mode entry using an attribute and a character.
 * @param character     The character of the entry.
 * @param attribute     The attribute of the entry.
 * @return uint16_t     The created entry.
 */
uint16_t vga_create_entry(uint8_t character, uint8_t attribute);

#endif
#ifndef KPRINT_H
#define KPRINT_H

#include <stdarg.h>

void vkprintf(char *str, va_list args);

/**
 * @brief Kernel printing function with formatting support
 */
void kprintf(char* str, ...);

#endif
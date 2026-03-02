#include <stdarg.h>

#include "kernel/kprint.h"
#include "drivers/terminal.h"
#include "library/string.h"

void vkprintf(char *str, va_list args) {
    static char buffer[12]; 
    char* s_ptr;

    while (*str != '\0') {
        if (*str == '%') {
            str++;

            switch (*str) {
                case 'c': // - character
                    terminal_put_char((char)va_arg(args, int));
                    break;

                case 'd': // - signed integer
                    terminal_put_string(itoa(va_arg(args, int), buffer));
                    break;

                case 'p': // - pointer
                    break;

                case 's': // - string
                    s_ptr = va_arg(args, char*);
                    terminal_put_string(s_ptr ? s_ptr : "(null)");
                    break;

                case 'u': // - unsigned integer
                    terminal_put_string(itoa(va_arg(args, int), buffer));
                    // this is icky, will need to implement an utoa function
                    break;

                case 'x': // - hexadecimal
                    // i am tired for today
                    break;

                case '%': // - % character
                    terminal_put_char('%');
                    break;
            }
        } else {
            terminal_put_char(*str);
        }

        str++;
    }
}

void kprintf(char* str, ...) {
    va_list args;
    va_start(args, str);
    vkprintf(str, args);
    va_end(args);
}
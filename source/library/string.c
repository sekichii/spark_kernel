#include "string.h"

int atoi(char* str) {
    int n = 0;
    int sign = 1;

    if (*str == '-') {
        sign = -1;
        str++;
    }

    while (*str >= '0' && *str <= '9') {
        int val = (*str) - '0';
        n = (n * 10) + val;

        str++;
    }

    return n * sign;
}

char* itoa(int n, char* buffer) {
    int i = 10; 
    buffer[11] = '\0'; 

    if (n == 0) {
        buffer[10] = '0';
        return &buffer[10];
    }

    int is_negative = 0;
    if (n < 0) {
        is_negative = 1;
        n = -n; 
    }

    while (n > 0) {
        buffer[i--] = (n % 10) + '0';
        n /= 10;
    }

    if (is_negative) {
        buffer[i--] = '-';
    }

    return &buffer[i + 1];
}
#ifndef STRING_H
#define STRING_H

/**
 * @brief Converts an ASCII string to an integer.
 * @param str   The ASCII string is needs to be converted.
 * @return      The converted integer.
 */
int atoi(char* str);

/**
 * @brief Converts an integer to an ASCII string.
 * @param n     The integer that is to be converted.
 * @return      The converted string.
 */
char* itoa(int n, char* buffer);

#endif
#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _puts(char *str);
int print_number(int num);
int handle_format(va_list args, char specifier);

#endif /* MAIN_H */

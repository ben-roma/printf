#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int print_char(char c);
int print_str(char *str);
int print_number(int n);
int print_binary(unsigned int n);
int print_unsigned(unsigned int u);
int print_octal(unsigned int o);
int print_hex(unsigned int x, int uppercase);
int print_S(char *str);
int print_pointer(void *ptr);
const char *check_flags(const char *ptr, int *plus, int *space, int *hash);


#endif /* MAIN_H */

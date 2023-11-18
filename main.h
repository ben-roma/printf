#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int print_char(char c);
int print_str(char *str);
int print_number_with_width(int n, int width);
int print_binary_with_width(unsigned int n, int width);
int print_unsigned_with_width(unsigned int u, int width);
int print_octal_with_width(unsigned int o, int width);
int print_hex_with_width(unsigned int x, int uppercase, int width);
int print_S_with_width(char *str, int width);
int print_pointer_with_width(void *ptr, int width);
const char *check_flags(const char *ptr, int *plus, int *space, int *hash);
const char *get_width(const char *ptr, int *width);
int print_number_with_width(int num, int width);
int print_number(int num);


#endif /* MAIN_H */

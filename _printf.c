#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
/**
 * print_char - Print a character
 * @c: Character to print
 *
 * Return: Number of characters printed
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_str - Print a string
 * @str: String to print
 *
 * Return: Number of characters printed
 */
int print_str(char *str)
{
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		count += write(1, str, 1);
		str++;
	}
	return (count);
}
/**
 * print_number - Print a number (integer)
 * @n: Number to print
 *
 * Return: Number of characters printed
 */
int print_number(int n)
{
	char buffer[20];
	int count;

	sprintf(buffer, "%d", n);
	count = print_str(buffer);
	return (count);
}
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *ptr;
	char c;
	char *str;
	int num;

	va_start(args, format);

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%' && *(ptr + 1) != '\0')
		{
			ptr++;
			switch (*ptr)
			{
				case 'c':
					c = va_arg(args, int);
					count += print_char(c);
					break;
				case 's':
					str = va_arg(args, char *);
					if (str == NULL)
						str = "(null)";
					count += print_str(str);
					break;
				case 'd':
				case 'i':
					num = va_arg(args, int);
					count += print_number(num);
					break;
				case '%':
					count += write(1, "%", 1);
					break;
				default:
					count += write(1, "%%", 1);
					count += write(1, &(*ptr), 1);
					break;
			}
		}
		else
		{
			count += write(1, &(*ptr), 1);
		}
	}
	va_end(args);
	return (count);
}

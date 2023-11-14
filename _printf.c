#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 * @...: Variable number of arguments
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					break;
				case 's':
					count += _puts(va_arg(args, char *));
					break;
				case '%':
					count += _putchar('%');
					break;
				default:
					break;
			}
		}
		else
		{
			count += _putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}

/**
 * _putchar - Write a character to stdout
 * @c: Character to write
 *
 * Return: 1 on success, -1 on failure
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - Write a string to stdout
 * @str: String to write
 *
 * Return: Number of characters written
 */
int _puts(char *str)
{
	int count = 0;

	while (*str)
	{
		count += _putchar(*str);
		str++;
	}
	return (count);
}

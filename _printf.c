#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && (
					*(format + 1) == 'c' ||
					*(format + 1) == 's' ||
					*(format + 1) == '%'
					))
		{
			count += handle_format(args, *(format + 1));
			format += 2;
		}
		else
		{
			write(1, format++, 1);
			count++;
		}
	}

	va_end(args);

	return (count);
}

/**
 * handle_format - Handle conversion specifiers
 * @args: Variable arguments list
 * @specifier: Conversion specifier
 *
 * Return: Number of characters printed for the specifier
 */
int handle_format(va_list args, char specifier)
{
	int len = 0;

	if (specifier == 'c')
	{
		char c = va_arg(args, int);

		write(1, &c, 1);

		return (1);
	}
	else if (specifier == 's')
	{
		char *str = va_arg(args, char *);

		if (str == NULL)
			str = "(null)";

		while (str[len])
			len++;
		write(1, str, len);
		return (len);
	}
	else if (specifier == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function
 * @format: Format string containing conversion specifiers
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
					{
						char c = va_arg(args, int);

						write(1, &c, 1);
						count++;
					}
					break;
				case 's':
					{
						char *str = va_arg(args, char *);

						while (*str)
						{
							write(1, str, 1);
							str++;
							count++;
						}
					}
					break;
				case '%':
					write(1, "%", 1);
					count++;
					break;
				case 'd':
				case 'i':
					{
						int num = va_arg(args, int);
						int digits = 0;
						char buffer[20];

						if (num < 0)
						{
							write(1, "-", 1);
							count++;
							num = -num;
						}
						do {
							buffer[digits++] = num % 10 + '0';
							num /= 10;
						} while (num != 0);

						while (digits > 0)
						{
							write(1, &buffer[--digits], 1);
							count++;
						}
					}
					break;
				default:
					write(1, "%", 1);
					write(1, format, 1);
					count += 2;
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}

		format++;
	}

	va_end(args);

	return (count);
}

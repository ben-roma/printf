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
				case 'u':
					{
						unsigned int num = va_arg(args, unsigned int);
						int digits = 0;
						char buffer[20];

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
				case 'o':
					{
						unsigned int num = va_arg(args, unsigned int);
						int digits = 0;
						char buffer[20];

						do {
							buffer[digits++] = num % 8 + '0';
							num /= 8;
						} while (num != 0);

						while (digits > 0)
						{
							write(1, &buffer[--digits], 1);
							count++;
						}
					}
					break;
				case 'x':
					{
						unsigned int num = va_arg(args, unsigned int);
						int digits = 0;
						char buffer[20];

						do {
							int remainder = num % 16;
							buffer[digits++] = (remainder < 10) ? remainder + '0' : remainder - 10 + 'a';
							num /= 16;
						} while (num != 0);

						while (digits > 0)
						{
							write(1, &buffer[--digits], 1);
							count++;
						}
					}
					break;
				case 'X':
					{
						unsigned int num = va_arg(args, unsigned int);
						int digits = 0;
						char buffer[20];

						do {
							int remainder = num % 16;

							buffer[digits++] = (remainder < 10) ? remainder + '0' : remainder - 10 + 'A';
							num /= 16;
						} while (num != 0);

						while (digits > 0)
						{
							write(1, &buffer[--digits], 1);
							count++;
						}
					}
					break;
				case 'b':
					{
						unsigned int num = va_arg(args, unsigned int);
						int bits[32];
						int index = 0;

						while (num > 0)
						{
							bits[index++] = num % 2;
							num /= 2;
						}
						while (--index >= 0)
						{
							char bit = bits[index] + '0';
							write(1, &bit, 1);
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

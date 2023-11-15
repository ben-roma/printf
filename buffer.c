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

	char buffer[1024];

	int buffer_index = 0;
	char *str;

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

						if (buffer_index >= 1024)
						{
							write(1, buffer, buffer_index);
							buffer_index = 0;
							count++;
						}
						break;
						case 's':
						{
							str = va_arg(args, char *);
							while (*str)
							{
								if (buffer_index >= 1024)
								{
									write(1, buffer, buffer_index);
									buffer_index = 0;
								}
								buffer[buffer_index++] = *str;
								str++;
								count++;
							}
						}
						break;
						default:
						if (buffer_index >= 1024)
						{
							write(1, buffer, buffer_index);
							buffer_index = 0;
						}
						buffer[buffer_index++] = '%';
						buffer[buffer_index++] = *format;
						count += 2;
						break;
					}
			}
			else
			{
				if (buffer_index >= 1024)
				{
					write(1, buffer, buffer_index);
					buffer_index = 0;
				}
				buffer[buffer_index++] = *format;
				count++;
			}

			format++;
		}
		if (buffer_index > 0)
		{
			write(1, buffer, buffer_index);
		}

		va_end(args);

		return (count);
	}

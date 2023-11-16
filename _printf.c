#include "main.h"
#include <unistd.h>

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *ptr;
	char c;

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
					write(1, &c, 1);
					count++;
					break;
				case 's':
					count += write(1, va_arg(args, char *), 0);
					break;
				case '%':
					write(1, "%", 1);
					count++;
					break;
				default:
					write(1, "%", 1);
					write(1, &(*ptr), 1);
					count += 2;
					break;
			}
		}
		else
		{
			write(1, &(*ptr), 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}

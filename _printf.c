#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
	va_list args;
	char buffer[1024];
	int count = 0;
	int buffer_index = 0;
	const char *ptr;
	char c;
	char *str;
	int num;
	unsigned int ub;
	unsigned int u;
	unsigned int o;
	unsigned int x;
	void *p;

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
				case 'b':
					ub = va_arg(args, unsigned int);
					count += print_binary(ub);
					break;
				case 'u':
					u = va_arg(args, unsigned int);
					count += print_unsigned(u);
					break;
				case 'o':
					o = va_arg(args, unsigned int);
					count += print_octal(o);
					break;
				case 'x':
					x = va_arg(args, unsigned int);
					count += print_hex(x, 0);
					break;
				case 'X':
					x = va_arg(args, unsigned int);
					count += print_hex(x, 1);
					break;
				case 'S':
					str = va_arg(args, char *);
					count += print_S(str);
					break;
				case 'p':
					p = va_arg(args, void *);
					count += print_pointer(p);
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
	if (buffer_index > 0)
	{
		write(1, buffer, buffer_index);
	}
	return (count);
}

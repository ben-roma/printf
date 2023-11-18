#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <wchar.h>

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
	int plus = 0, space = 0, hash = 0;
	int long_modifier = 0;
	int short_modifier = 0;

	va_start(args, format);

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		plus  = 0;
		space = 0;
		hash = 0;
		long_modifier = 0;
		short_modifier = 0;

		if (*ptr == '%' && *(ptr + 1) != '\0')
		{
			ptr = check_flags(ptr, &plus, &space, &hash);
			ptr++;
			while (*ptr == 'l' || *ptr == 'h')
			{
				 if (*ptr == 'l')
					 long_modifier++;
				 else if (*ptr == 'h')
					 short_modifier++;
				 ptr++;
			}

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
					count += print_str(va_arg(args, char *));
					break;
				case 'd':
				case 'i':
					num = (long_modifier == 2) ? va_arg(args, long) :
						(long_modifier == 1) ? va_arg(args, long) :
						(short_modifier == 1) ? (short)va_arg(args, int) :
						va_arg(args, int);
					count += print_number(num);
					break;
				case 'b':
					ub = va_arg(args, unsigned int);
					count += print_binary(ub);
					break;
				case 'u':
					u = (long_modifier == 2) ? va_arg(args, unsigned long) :
						(long_modifier == 1) ? va_arg(args, unsigned long) :
						(short_modifier == 1) ? (unsigned short)va_arg(args, unsigned int) :
						va_arg(args, unsigned int);
					count += print_unsigned(u);
					break;
				case 'o':
					o = (long_modifier == 2) ? va_arg(args, unsigned long) :
						(long_modifier == 1) ? va_arg(args, unsigned long) :
						(short_modifier == 1) ? (unsigned short)va_arg(args, unsigned int) :
						va_arg(args, unsigned int);
					count += print_octal(o);
					break;
				case 'x':
					x = va_arg(args, unsigned int);
					count += print_hex(x, 0);
					break;
				case 'X':
					x = (long_modifier == 2) ? va_arg(args, unsigned long) :
						(long_modifier == 1) ? va_arg(args, unsigned long) :
						(short_modifier == 1) ? (unsigned short)va_arg(args, unsigned int) :
						va_arg(args, unsigned int);
					count += print_hex(x, 1);
					break;
				case 'S':
					if (long_modifier == 1)
					{
						wchar_t *wstr = va_arg(args, wchar_t *);
						count += write(1, &wstr[0], 1);
					}
					else if (short_modifier == 1)
					{
						int temp = va_arg(args, int);
						char c = (char)temp;
						count += write(1, &c, 1);
					}
					else
					{
						char *str = va_arg(args, char *);
						count += print_S(str);
					}
					break;
				case 'p':
					p = (void *)(va_arg(args, long));
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

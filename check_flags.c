#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

const char *check_flags(const char *ptr, int *plus, int *space, int *hash)
{
	while (*ptr)
	{
		if (*ptr == '+')
			*plus = 1;
		else if (*ptr == ' ')
			*space = 1;
		else if (*ptr == '#')
			*hash = 1;
		else
			break;
		ptr++;
	}
	return (ptr);
}

int print_number_with_width(int num, int width)
{
	int count = 0;
	count += write(1, " ", width - count);
	count += print_number(num);
	return (count);
}


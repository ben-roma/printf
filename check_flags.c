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

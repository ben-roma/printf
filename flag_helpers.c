#include "main.h"
#include <unistd.h>

void print_plus(int *count, int *plus)
{
	if (*plus)
	{
		*count += write(1, "+", 1);
		*plus = 0;
	}
}

void print_space(int *count, int *space)
{
	if (*space)
	{
		*count += write(1, " ", 1);
		*space = 0;
	}
}

void print_hash(int *count, int *hash)
{
	if (*hash)
	{
		*count += write(1, "#", 1);
		*hash = 0;
	}
}

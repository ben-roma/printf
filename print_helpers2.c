#include "main.h"
#include <stdio.h>
#include <unistd.h>

/**
 * print_octal - Print an octal number
 * @o: Octal number to print
 *
 * Return: Number of characters printed
 */
int print_octal(unsigned int o)
{
	char buffer[20];
	int count = 0;

	sprintf(buffer, "%o", o);
	count = print_str(buffer);
	return (count);
}

/**
 * print_hex - Print a hexadecimal number
 * @x: Hexadecimal number to print
 * @uppercase: Flag to print uppercase letters 1 for uppercase, 0 for lowercase
 *
 * Return: Number of characters printed
 */
int print_hex(unsigned int x, int uppercase)
{
	char buffer[20];
	int count;

	sprintf(buffer, uppercase ? "%X" : "%x", x);
	count = print_str(buffer);
	return (count);
}

int print_S(char *str)
{
	int count = 0;

	if (str == NULL)
		return (count);

	while (*str)
	{
		char hex[3];

		if (*str >= 32 && *str < 127)
		{
			count += write(1, str, 1);
		}
		else
		{
			count += write(1, "\\x", 2);
			sprintf(hex, "%02X", *str);
			count += write(1, hex, 2);
		}
		str++;
	}
	return (count);
}

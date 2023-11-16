#include "main.h"
#include <stdio.h>
#include <unistd.h>
/**
 * print_char - Print a character
 * @c: Character to print
 *
 * Return: Number of characters printed
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_str - Print a string
 * @str: String to print
 *
 * Return: Number of characters printed
 */
int print_str(char *str)
{
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		write(1, str, 1);
		str++;
		count++;
	}

	return (count);
}

/**
 * print_number - Print a number (integer)
 * @n: Number to print
 *
 * Return: Number of characters printed
 */
int print_number(int n)
{
	char buffer[20];
	int count;

	sprintf(buffer, "%d", n);
	count = print_str(buffer);
	return (count);
}
/**
 * print_binary - Print a number in binary
 * @n: Number to print
 *
 * Return: Number of characters printed
 */
int print_binary(unsigned int n)
{
	int count = 0;
	char binary[32];
	int i;

	if (n == 0)
	{
		count += print_char('0');
	}
	else
	{
		for (i = 0; n > 0; i++)
		{
			binary[i] = (n % 2) + '0';
			n /= 2;
		}
		for (i = i - 1; i >= 0; i--)
		{
			count += write(1, &binary[i], 1);
		}
	}
	return (count);
}
/**
 * print_unsigned - Print an unsigned number
 * @u: Unsigned number to print
 *
 * Return: Number of characters printed
 */
int print_unsigned(unsigned int u)
{
	char buffer[20];
	int count;

	sprintf(buffer, "%u", u);
	count = print_str(buffer);
	return (count);
}

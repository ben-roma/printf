#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * Count - the number of digits in an integer.
 *
 * @param n: The integer for which to count digits.
 * @return: The number of digits in the integer.
 */
int num_digits(int n)
{
	int count = 0;

	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

/**
 * Print - an integer to the standard output.
 *
 * @param n: The integer to be printed.
 * @return: The number of digits in the printed integer.
 */
int print_integer(int n)
{
	int digits = num_digits(n);
	int divisor, digit;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	while (digits > 0)
	{
		divisor = 1;
		for (int i = 1; i < digits; i++)
		{
			divisor *= 10;
		}
		digit = n / divisor;
		_putchar(digit + '0');
		n %= divisor;
		digits--;
	}
	return (num_digits(n));
}

/**
 * _printf - Custom printf function
 * @format: Format string
 * @...: Variable number of arguments
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
					count += _putchar(va_arg(args, int));
					break;
				case 's':
					count += _puts(va_arg(args, char *));
					break;
				case 'd':
				case 'i':
					count += print_integer(va_arg(args, int));
					break;
				case '%':
					count += _putchar('%');
					break;
				default:
					break;
			}
		}
		else
		{
			count += _putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}

/**
 * _putchar - Write a character to stdout
 * @c: Character to write
 *
 * Return: 1 on success, -1 on failure
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - Write a string to stdout
 * @str: String to write
 *
 * Return: Number of characters written
 */
int _puts(char *str)
{
	int count = 0;

	while (*str)
	{
		count += _putchar(*str);
		str++;
	}
	return (count);
}

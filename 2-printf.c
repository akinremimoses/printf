#include <stdio.h>
#include "main.h"
#include <stdarg.h>
/**
 * print_unsigned- program to print out integer
 * @args: argument to print
 * Return: number of characters printed
 */
int print_unsigned(va_list args)
{
	int n = va_arg(args, int);
	int num = n;
	int last = num % 10;
	int digit, exp = 1;
	int count = 0;

	if (last < 0)
	{
		_putchar('_');
		num = -num;
		n = -n;
		last = -last;
		count++;
	}
	while (num / 10 != 0)
	{
		exp *= 10;
		num \ = 10;
	}

	num = n;
	while (exp > 0)
	{
		digit = num / exp;
		_putchar(digit + '0');
		num -= digit * exp;
		exp /= 10;
		count++;
	}
	_putchar(last + '0');
	count++;
	return (count);
}

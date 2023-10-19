#include "main.h"
/**
 * get_width- printing width
 * @format: character string
 * @x: argument list
 * @list: argument list2
 * Return: the width
 */
int get_width(const char *format, int *x, va_list list)
{
	int y;
	int width = 0;

	for (y = *x + 1; format[y] != '\0'; y++)
	{
		if (is_digit(format[y]))
		{
			width *= 10;
			width = width + format[y] - '0';
		}
		else if (format[y] == '*')
		{
			y++;
			width = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
	}
	*x = y - 1;
	return (width);
}


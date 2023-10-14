#include "main.h"
#include <stddef.h>

/**
 * printf_string - to print a string
 * @val: argument
 * @collaborators: Akinremi Moses and Emelda Mada
 * Return: the length of a string
 */

int printf_string(va_list val)
{
	char *str;
	int i;
	int length;

	str = va_arg(val, char *);
	if (str == NULL)
	{ 
		str = "(null)"
			;
		length = _strlen(str);
	for (i = 0; i < length; i++)
			_putchar(str[i]);
		return (length);
	}
	else
	{
		length = _strlen(str);
		for (i = 0; i < length; i++)
			_putchar(str[i]);
		return (length);
	}
}

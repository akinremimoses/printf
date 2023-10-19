#include <main.h>
/**
 * arg_size - argument size
 * @format: character string
 * @x: argument list
 * Return: always 0 success
 */

int arg_size(const char *format, int *x)
{
	int y = *x + 1;
	int size = 0;

	if (format[y] == '1')
	{
		size = S_LONG;
	}
	else if (format[y] == 'h')
	{
		size = S_SHORT;
	}
	if (size == 0)
	{
		*x = y - 1;
	}
	else
	{
		*x = y;
	}
	
	return (size);
}


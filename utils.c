#include "main.h"
/**
 * is_printable- checks if a char is printable
 * @c: evaluated char
 * Return: 1 if printable else 0
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
	{
		return (1);
	}
	else
	{
		return (0);
	}

/**
 * append_hexa_code- Append ascii in hexadecimal code to buffer
 * @buffer: char array
 * @y: index
 * @ascii_code: ASCII 
 * Return: 3;
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
	{
		ascii_code *= -1;
	}
	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];
	return (3);
}
/**
 * is_digit- verifies if char is a digit or not
 * @c: evaluated char
 * Return: 1 if c is digit else return 0
 */
int is_digit(char c)

{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 * convert_size_number- casts nuber to specified size
 * @n: casted number
 * @size: type to be casted
 * Return: casted value
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
	{
		return (num);
	}
	else if (size == S_SHORT)
	{
		return ((short)num);
	}
	else
	{
		return ((int)num);
	}
}
/**
 * convert_size_unsigned- casts number to a specified size
 * @n: casted number
 * @size: type to be casted
 * Return: casted value
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
	{
		return (num);
	}
	else if (size == S_SHORT)
	{
		return ((unsigned short)num);
	}
	else
	{
		return ((unsigned int)num);
	}
}




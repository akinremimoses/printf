#include "main.h"
/**
 * handle_write_char - prints out string
 * @c: char type
 * @buffer: buffer array
 * @flags: active flags
 * @size: size specifier
 * @precision: precision specifier
 * @width: width
 * Return: number of printed chars
 */

int handle_write_char(char c, char buffer[],
		int flags, int width, int precision, int size)

{
	int x = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
	{
		padd = '0';
	}
	buffer[x++] = c;
	buffer[x] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (x = 0; x < width - 1; x++)
		{
			buffer[BUFF_SIZE - x - 2] = padd;
		}

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - x - 1], width -
1));
		else
		{
			return (write(1, &buffer[BUFF_SIZE - x - 1], width - 1) +
					write(1, &buffer[0], 1));
		}
		
		}
	}
	return (write(1, &buffer[0], 1));
}
/**
 * write_number - Prints out a string
 * @is_negative: argument list
 * @index: char types
 * @buffer: buffer array
 * @flags: active flags
 * @width: width
 * @precision: precision specifier
 * @size: Size specifier
 * Return: printed chars
 */
int write_number(int is_negative, int index, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
	{
		padd = '0';
	}
	if (is_negative)
	{
		extra_ch = '-';
	}
	else if (flags & F_PLUS)
	{
		extra_ch = '+';
	}
	else if (flags & F_SPACE)
	{
		extra_ch = ' ';
	}

	return (write_num(ind, buffer, flags, width, precision,
				length, padd, extra_ch));
}
/**
 * write_num - Write number using a bufffer
 * @index: index where number starts
 * @buffer: buffer array
 * @flags: active flag
 * @width: width
 * @prec: Precision specifier
 * @length: Numbe rof the length
 * @padd: Padding char
 * @extra_c: Extra char
 * Return: printed chars
 */

int write_num(int index, char buffer[],
		int flags, int width, int prec,
		int length, char padd, char extra_c)
{
	int x, padd_start = 1;

	if (prec == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0' && width
			== 0)
	{
		return (0);
	}
	if (prec == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
	{
		buffer[index] = padd = ' ';
	}
	if (prec > 0 && prec < length)
	{
		padd = ' ';
	}
	while (prec > length)
	{
		buffer[--index] = '0', length++;
	}
	if (extra_c != 0)
	{
		length++;
	}
	if (width > length)
	{
		for (x = 1; x < width - length + 1; x++)
		{
			buffer[x] = padd;
		}
		buffer[x] = '\0';
	}
	if (flags & F_MINUS && padd == ' ')
	{
		if (extra_c)
		{
			buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1,
	&buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
			{
				buffer[--index]= extra_c;
			}
			return (write(1, &buffer[1], i - 1) + write(1,
	&buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
			{
				buffer[--padd_start] = extra_c;
			}
			return (write(1, &buffer[padd_start], i - padd_start) +
					write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
	{
		buffer[--index] = extra_c;
	}

	return (write(1, &buffer[ind], length));
}
/**
 * write_unsigned - Writes unsigned number
 * @is_negative: Number indicating if the num is negative
 * @index: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of written chars.
 */

int write_unsgnd(int is_negative, int index,
		char buffer[],
		int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - index - 1, i = 0;
	char padd = ' ';
	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
	{
		return (0);
	}
	if (precision > 0 && precision < length)
	{
		padd = ' ';
	}
	while (precision > length)
	{
		buffer[--index] = '0';
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
	{
		padd = '0';
	}
	if (width > length)
	{
		for (i = 0; i < width - length; i++)
		{
			buffer[i] = padd;

		buffer[i] = '\0';
	if (flags & F_MINUS)
	{
		return (write(1, &buffer[index], length) + write(1,
					&buffer[0], i));
	else
	{
		return (write(1, &buffer[0], i) + write(1, &buffer[ind],
length));
	}
	
	}
		}
	}
	return (write(1, &buffer[ind], length));

}
/**
 * write_pointer - Write a memory address
 * @buffer: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Wwidth specifier
 * @flags: Flags specifier
 * * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start*
 * Return: Number of written chars.
 */
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int y;
	if (width > length)
	{
		for (y = 3; y < width - length + 3; y++)
		{
			buffer[y] = padd;
		}
		buffer[y] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
			{
				buffer[--ind] = extra_c;
			}
			return (write(1, &buffer[ind], length) + write(1,
&buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
			{
				buffer[--ind] = extra_c;
			}
			return (write(1, &buffer[3], i - 3) + write(1,
&buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
			{
				buffer[--padd_start] = extra_c;
			}
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
					write(1, &buffer[ind], length - (1 - padd_start) -
2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
	{
		buffer[--ind] = extra_c;
	}
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}












#include <stdio.h>
#include <inttypes.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf-function that produces output according to a format
 * @format: character string
 * Return: formatted output
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	char b[256];

	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			switch (*format)
			{
				case 'u':
					sprintf(b, "%#" PRIuMAX "\n", va_arg(args, uintmax_t));
					_putchar(b[format++]);
					break;
				case 'o':
					sprintf(b, "%#" PRIoMAX "\n", va_arg(args, uintmax_t));
					_putchar(b[format++]);
					break;
				case 'x':
					sprintf(b, "%#" PRIxMAX "\n", va_arg(args, uintmax_t));
					_putchar(b[format++]);
					break;
				case 'X':
					sprintf(b, "%#" PRIXMAX "\n", va_arg(args, uintmax_t));
					_putchar(b[format++]);
					break;
					default:
					_putchar(*format);
					break;
			}
		}
		else
		{
			_putchar(*format);
		}
		format++;
	}
	va_end(args);
}


#ifndef MAINgH
#define MAIN_H
#include <stdarg.h>
#define BUFF_SIZE 1024

/**
 * struct format - Struct op
 *
 * @format: The format.
 * @fn: The function associated.
 */
struct format
{
	char format;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct format format_t - Struct op
 *
 * @format: The format.
 * @fm_t: The function associated.
 */
typedef struct format format_t;

int _printf(const char *format, ...);
int handle_print(const char *format, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);



int _putchar(char c);
int _printf(const char *format, ...);
int printf_char(va_list val);
int printf_string(va_list val);
int _strlen(char *str);
int _strlenc(const char *str);
int print_37(void);
int print_int(va_list args);
int print_dec(va_list args);
int print_bin(va_list val);
int arg_size(const char *format, int *x);
long int convert_size_unsigned(unsigned long int n, int size);
int is_digit(char c);
int append_hexa_code(char ascii_code, char buffer[], int y);
int is_printable(char c);
int handle_print(const char *format, int *index, va_list list, char buffer[],
		int flags, int width, int precision, int size);
int get_width(const char *format, int *x, va_list list)
	int arg_size(const char *format, int *x);
int handle_write_char(char c, char buffer[],
		int flags, int width, int precision, int size);
int write_number(int is_negative, int index, char buffer[],
		int flags, int width, int precision, int size);
int write_num(int index, char buffer[]
		int flags, int width, int prec,
		int length, char padd, char extra_c);
int write_unsgnd(int is_negative, int index,
		char buffer[],
		int flags, int width, int precision, int size);
int write_pointer(char buffer[], int ind, int length,
		int width, int flags, char padd, char extra_c, int padd_start);
#endif


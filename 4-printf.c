#include <stdio.h>
#include <string.h>
#include "main.h"
/**
 * create_buffer- local buffer of 1024 chars in order
 * to call write as little as possible
 * @buffer: input
 * Return: always 0 success
 */
void create_buffer(char * buffer)
{
	buffer[0] = '\0';

	void write_buffered

#include "main.h"
/**
 * _strlen - Returns the length of a string
 * @str: string pointer
 * Return: i
 * @collaborators: Akinremi Moses and Emelda Mada
 */

int _strlen(char *str)
{
	int i;
	for (i = 0; str[i] != 0; i++)
		;
	return (i);
	
}

/**
 * _strlenc - strlen function but applied for constant char pointer str
 * @str: char pointer
 * Return: 1 
 */

int _strlllenc(const char *str)
{
	int i;
	for (i = 0; str[i] != 0; i++)
		;
	return (i); 

}

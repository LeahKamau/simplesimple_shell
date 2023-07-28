#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @str: string to count length
 *
 * Return: length of str
 */
int _strlen(char *str)
{
	int len = 0;

	if (!str)
		return (0);

	while (*str++)
		len++;

	return (len);
}

#include "shell.h"

/**
 * _puts - writes string to stdout
 * @str: pointer to string to write
 *
 * Return: number of bytes written to stdout
 */
int _puts(char *str)
{
	int len;

	len = _strlen(str);

	return (write(STDOUT_FILENO, str, len));
}

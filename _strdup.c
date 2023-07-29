#include "shell.h"

/**
 * _strdup - copies a string to new
 * dynamically allocated memory
 * @str: string to be copied
 *
 * Return: copy of string
 */
char *_strdup(const char *str)
{
	size_t i = 0, n = 0;
	char *new_str = NULL;

	while (str[n] != '\0')
		n++;

	new_str = malloc(sizeof(char) * (n + 1));

	if (new_str == NULL)
		return (NULL);

	for (i = 0; i <= n; i++)
		new_str[i] = str[i];

	return (new_str);
}

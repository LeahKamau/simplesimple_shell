#include "shell.h"

/**
 * _strchr - locates a character in a string
 * @str: string to be parsed
 * @c: character to look for
 *
 * Return:  a pointer to character memory
 */
char *_strchr(char *str, char c)
{
	do {
		if (*str == c)
			return (str);
	}

	while (*str++ != '\0')
		;

	return (NULL);
}

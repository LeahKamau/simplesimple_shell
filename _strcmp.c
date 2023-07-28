#include "shell.h"

/**
 * _strcmp - compares string 1 with string 2
 * @s1: first string
 * @s2:second string
 *
 * Return: 0 if equal
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);

		s1++;
		s2++;
	}

	return (0);
}

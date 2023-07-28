#include "shell.h"

/**
 * _strncmp - compares n characters of
 * string 1 with string 2
 * @s1: string 1
 * @s2: string 2
 * @n: bytes to compare
 *
 * Return: 0 if equal
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);

		if (*s1 == '\0' || *s2 == '\0')
			break;

		s1++;
		s2++;
		n--;
	}

	return (0);
}

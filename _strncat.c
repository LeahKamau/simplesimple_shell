#include "shell.h"

/**
 * _strncat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: no of bytes to concatenate
 *
 * Return: concatenated string
 */
char *_strncat(char *s1, char *s2, int n)
{
	int i = 0, j = 0;
	char *add = s1;

	while (s1[i] != '\0')
		i++;

	while (s2[j] != '\0' && j < n)
	{
		s1[i] = s2[j];
		i++;
		j++;
	}

	if (j < n)
		s1[i] = '\0';

	return (add);
}

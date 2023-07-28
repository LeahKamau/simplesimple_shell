#include "shell.h"

/**
 * _strncpy - copies string
 * @dest: where to copy string
 * @src: string to be copied
 * @n: number of characters to be copied
 *
 * Return: pointer to the destination string dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	char *add = dest;
	int i = 0, j;

	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}

	if (i < n)
	{
		j = i;

		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}

	return (add);
}

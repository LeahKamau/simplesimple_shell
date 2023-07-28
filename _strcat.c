#include "shell.h"

/**
 * _strcat - concatenate two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: concatenated string
 */
char *_strcat(char *s1, char *s2)
{
	char *cat_str = NULL;
	unsigned int len1 = 0, len2 = 0, i = 0;

	if (s1)
		len1 = _strlen(s1);
	if (s2)
		len2 = _strlen(s2);

	cat_str = malloc(sizeof(char) * (len1 + len2 + 1));

	if (!cat_str)
		return (NULL);

	for (i = 0; i < len1; i++)
		cat_str[i] = s1[i];

	for (i = 0; i < len2; i++)
		cat_str[len1 + i] = s2[i];

	cat_str[len1 + len2] = '\0';

	return (cat_str);
}

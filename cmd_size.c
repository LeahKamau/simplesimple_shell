#include "shell.h"

/**
 * cmd_size - count number of args
 * @str: pointer to args
 * @delim: delimeter
 *
 * Return: number of args
 */
int cmd_size(char *str, char delim)
{
	int i = 0, count = 0;

	if (str != NULL)
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			if (str[i] == delim)
				count++;
		}
		count++;
	}
	return (count);
}

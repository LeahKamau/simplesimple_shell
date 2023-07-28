#include "shell.h"

/**
 * line_getter - reads line from stdin
 *
 * Return: pointer to line read
 */
char *line_getter(void)
{
	char *command = NULL;
	size_t bufSize = 0;
	ssize_t chars_read = 0;

	chars_read = getline(&command, &bufSize, stdin);

	if (chars_read == -1)
	{
		perror("getline error\n");
		return (NULL);
	}

	if (command[chars_read - 1] == '\n')
		command[chars_read - 1] = '\0';

	return (command);
}

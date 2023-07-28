#include "shell.h"

/**
 * _cd - changed directory
 * @args: desired directory
 *
 * Return: always 1
 */
int _cd(char **args)
{
	int status;

	if (args[1] == NULL)
		_puts("provide directory");

	status = chdir(args[1]);
	free(args);

	if (status != 0)
	{
		perror("Error:");
		free(args);
	}

	return (1);
}

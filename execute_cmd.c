#include "shell.h"

/**
 * execute_cmd - executes commands
 * @args: argument string
 * @drs: path string
 *
 * Return: exit_sucess when completed
 */
int execute_cmd(char **args, char **drs)
{
	int i = 0;
	char *full_path = NULL;

	while (drs[i] != NULL)
	{
		full_path = malloc(sizeof(char) * (_strlen(drs[i]) + _strlen(args[0]) + 2));

		if (full_path == NULL)
		{
			perror("malloc error\n");
			return (1);
		}

		_strcpy(full_path, drs[i]);
		full_path = _strcat(full_path, "/");
		full_path = _strcat(full_path, args[0]);

		if (access(full_path, X_OK) == 0)
		{
			if (execve(full_path, args, NULL) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		free(full_path);
		i++;
	}
	if (drs[i] == NULL)
	{
		free(drs);
		if (access(args[0], X_OK) == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("execve error");
				exit(EXIT_FAILURE);
			}
		}
	}
	exit(EXIT_SUCCESS);
}

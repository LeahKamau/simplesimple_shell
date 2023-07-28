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
	int i = 0, j = 0;
	char *full_path = NULL;

	if (args[0] != NULL)
	{
		if (_strcmp(args[0], "help") == 0)
		{
			_puts("Help: command for more information\n");
			return (1);
		}
		else if (_strcmp(args[0], "cd") == 0)
		{
			if (args[1] != NULL)
			{
				if (chdir(args[1]) != 0)
					perror("cd");
			}
			else
				puts("cd missing operand\n");
			return (1);
		}

		else if (_strcmp(args[0], "exit") == 0)
			return (0);
	}

	while (drs[i] != NULL)
	{
		full_path = malloc(sizeof(char) * (_strlen(drs[i]) + _strlen(args[0]) + 2));

		if (full_path == NULL)
		{
			perror("malloc error\n");
			return (1);
		}

		_strcpy(full_path, drs[i]);
		printf("what is in %s\n", drs[i]);
		full_path = _strcat(full_path, "/");
		full_path = _strcat(full_path, args[0]);

		printf("Trying to execute: %s\n", full_path);

		if (access(full_path, X_OK) == 0)
		{
			pid_t pid = fork();

			if (pid == 0)
			{
				printf("Child process is executing %s\n", full_path);
				if (execve(full_path, args, NULL) == -1)
				{
					perror("execve");
					exit(EXIT_FAILURE);
				}
			}

			else if (pid < 0)
				perror("fork");

			else
				wait(NULL);

			free(full_path);
			return (1);
		}

		else if (access(args[0], X_OK) == 0)
		{
			pid_t pid = fork();
			if (pid == 0)
			{
				if (execve(args[0], args, NULL) == -1)
				{
					perror("execve");
					exit(EXIT_FAILURE);
				}
			}
			else if (pid < 0)
				perror("fork");
			else
				wait(NULL);
			return (1);
		}
		free(full_path);
		i++;
	}

	puts("command not found");

	for (j = 0; args[j] != NULL; j++)
	{
		free(args[j]);
		args[j] = NULL;
	}

	free(args);
	return (1);
}

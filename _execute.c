#include "shell.h"

/**
 * _execute - executes builtins and commands
 * @args: arguments to execute
 * @dirs: path string
 *
 * Return: 1 loop to continue
 * or 0 loop exits
 */
int _execute(char **args, char **dirs)
{
	int i = 0, status = 1;
	char *builtin_cmd[] = {"cd", "help", "exit", NULL};

	if (args[0] == NULL)
		return (1);

	for (i = 0; builtin_cmd[i]; i++)
	{
		if (_strcmp(builtin_cmd[i], args[0]) == 0)
			break;
	}

	switch (i)
	{
		case 0:
			status = _cd(args);
			break;
		case 1:
			status = _help();
			break;
		case 2:
			status  = execute_exit();
			break;
		default:
			status = run_fork(args, dirs);
			break;
	}

	return (status);
}

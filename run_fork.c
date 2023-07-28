#include "shell.h"

/**
 * run_fork - calls the fork process
 * to execute commands
 * @args: arguments string
 * @dirs: path string
 *
 * Return: 1 to continue with loop
 */
int run_fork(char **args, char **dirs)
{
	int status;
	pid_t pid;

	pid = fork();

	if (pid == 0)
		execute_cmd(args, dirs);

	if (pid < 0)
		perror("Error:");

	else
		wait(&status);

	return (1);
}

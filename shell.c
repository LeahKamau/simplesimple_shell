#include "shell.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * @envp: environment variables
 *
 * Return: 0 on success
 */
int main(int argc, char **argv, char **envp)
{
	char *cmd = NULL, **args = NULL;
	char **directories = NULL;
	int running = 1, is_interactive = 0;
	int i = 0;

	(void)argc;
	(void)argv;

	directories = extract_dirs(envp);
	is_interactive = (isatty(STDIN_FILENO));

	while (running)
	{
		if (is_interactive)
			_puts("($) ");
		else
			running = 0;

		signal(SIGINT, ctrlc_handler);
		cmd = line_getter();
		args = _tokenizer(cmd);
		running = _execute(args, directories);

		if (cmd)
			free(cmd);

		if (is_interactive == 0)
			free(directories);
	}
	for (i = 0; directories[i] != NULL; i++)
		free(directories[i]);


	free(directories);

	if (args)
		free(args);

	return (0);
}

#include "shell.h"

/**
 * extract_dirs - processes environment variables
 * & extracts relevant directories
 * @envp: environment variables
 *
 * Return: relevant directory
 */
char **extract_dirs(char **envp)
{
	char **directories = NULL;
	char *path_env = NULL;
	char *dir_token = NULL;
	const char delimiter[] = ":";
	int i, num_dirs = 0;

	for (i = 0; envp[i] != NULL; i++)
	{
		if (_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_env = envp[i] + 5;
			break;
		}
	}

	if (path_env == NULL)
	{
		perror("Error: PATH not found\n");
		return (NULL);
	}

	for (i = 0; path_env[i] != '\0'; i++)
	{
		if (path_env[i] == ':')
			num_dirs++;
	}
	num_dirs++;

	directories = (char **)malloc(sizeof(char *) * (num_dirs + 1));

	if (!directories)
	{
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	dir_token = strtok(path_env, delimiter);
	i = 0;

	while (dir_token != NULL)
	{
		directories[i] = _strdup(dir_token);
		/*printf("directories are %s\n", dir_token);*/
		dir_token = strtok(NULL, delimiter);
		i++;
	}

	directories[i] = NULL;

	return (directories);
}

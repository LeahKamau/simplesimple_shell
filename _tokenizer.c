#include "shell.h"

/**
 * _tokenizer - tokenizes string according to delimeter
 * @line: line from stdin
 *
 * Return: an array of tokens
 */
char **_tokenizer(char *line)
{
	char *token = NULL, **tokens = NULL;
	char *line_cpy = _strdup(line);
	const char *delim = " \t\n";
	int i = 0, n = 0;

	token = strtok(line, delim);
	while (token != NULL)
	{
		n++;
		token = strtok(NULL, delim);
	}

	tokens = (char **)malloc((n + 1) * sizeof(char *));

	if (tokens == NULL)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}

	token = strtok(line_cpy, delim);

	while (token)
	{
		tokens[i] = _strdup(token);
		printf("tokens are %s\n", token);
		token = strtok(NULL, delim);
		i++;
	}


	tokens[i] = NULL;

	free(line_cpy);

	return (tokens);
}

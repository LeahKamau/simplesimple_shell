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
	const char *delim = " \t\n\r\a";
	int i = 0, n = cmd_size(line, ' ');


	tokens = (char **)malloc((n + 1) * sizeof(char *));

	if (tokens == NULL)
	{
		free(tokens);
		perror("malloc error");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, delim);

	while (token)
	{
		tokens[i] = token;
		/*printf("tokens are %s\n", token);*/
		token = strtok(NULL, delim);
		i++;
	}


	tokens[i] = NULL;

	return (tokens);
}

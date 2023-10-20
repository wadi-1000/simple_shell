#include "main.h"

/**
 * tokenize_input - Function that tokenizes the user's input
 * @cmd: The user input string
 * Return: An array of tokens
 */
char **tokenize_input(char *cmd)
{
	char *buf = NULL, *bufp = NULL, *token = NULL, *delim = " :\t\r\n";
	char **tokens = NULL;
	int tokenize = 1;
	size_t index = 0, mode = 0;

	buf  = _strdup(cmd);

	if (!buf)
		return (NULL);
	bufp = buf;
	while (*bufp)
	{
		if (_strchr(delim, *bufp) != NULL && mode == 0)
		{
			tokenize++;
			mode = 1;
		}
		else if
			(_strchr(delim, *bufp) == NULL && mode == 1)
				mode = 0;
		bufp++;
	}
	tokens = malloc(sizeof(char *) * (tokenize + 1));
	token = strtok(buf, delim);
	while (token)
	{
		tokens[index] = _strdup(token);
		if (tokens[index] == NULL)
		{
			free(tokens);
			return (NULL);
		}
		token = strtok(NULL, delim);
		index++;
	}
	tokens[index] = '\0';
	free(buf);
	return (tokens);
}

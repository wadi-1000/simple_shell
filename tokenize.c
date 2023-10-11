#include "main.h"

/**
 * tokenize_input - Function that toenizes the user's input
 * @input: The user input string
 * Return: An array of tokens
 */
char **tokenize_input(char *input)
{
	char *token;
	char **array = malloc(1024 * sizeof(char *));
	int i = 0;

	token = strtok(input, " ");
	while (token)
	{
		array[i] = strdup(token);
		token = strtok(NULL, " ");
		i++;
	}
	array[i] = NULL;

	if (i == 0)
	{
		free(array);
		return (NULL);
	}
	return (array);
}

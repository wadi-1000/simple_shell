#include "main.h"

/**
 * tokenize_input - Function that tokenizes the user's input
 * @input: The user input string
 * Return: An array of tokens
 */
char **tokenize_input(char *input)
{
	char *token;
	char **array = malloc(1024 * sizeof(char *));
	int i = 0;

	if (array == NULL)
	{
		perror("Memory allocation failed.");
		return (NULL);
	}
	token = strtok(input, " ");
	while (token)
	{
		array[i] = _strdup(token);
		if (array[i] == NULL)
		{
			perror("Memory allocation failed.");
			free_tokens(array);
			return (NULL);
		}
		token = strtok(NULL, " ");
		i++;
	}
	array[i] = NULL;
	return (array);
}

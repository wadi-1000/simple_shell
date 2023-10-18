#include "main.h"

/**
 * tokenize_input - Function that tokenizes the user's input
 * @input: The user input string
 * Return: An array of tokens
 */
char **tokenize_input(char *input)
{
	char *token;
	char **array = NULL;
	int i = 0;
	int j;


	array = malloc(1024 * sizeof(char *));
	if (array == NULL)
	{
		perror("malloc");
		exit(1);
	}

	token = strtok(input, " ");
	while (token)
	{
		array[i] = strdup(token);
		if (array[i] == NULL)
		{
			perror("strdup");
			for (j = 0; j < i; j++)
			{
				free(array[j]);
				exit(1);
			}
			free(array);
			exit(1);
		}
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

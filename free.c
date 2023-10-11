#include "main.h"

/**
 * free_tokens - Function that fress the memory used by the array
 * @tokens: Array of tokens to free
 *
 * Return: Nothing
 */
void free_tokens(char **tokens)
{
	int i;
	
	for (i = 0; tokens[i]; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}


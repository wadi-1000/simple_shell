#include "main.h"

/**
 * my_strtok - separate a sentence
 * @str: pointer to the sentence
 * @delimiters: what separates the string
 *
 * Return: pointer to an array
 */

char *my_strtok(char *str, char *delimiters)
{
	static char *nextToken;
	char *token;

	if (str != NULL)
	{
		nextToken = str;
	}
	if (nextToken == NULL || *nextToken == '\0')
	{
		return (NULL);
	}
	while (*nextToken != '\0' && _strchr(delimiters, *nextToken) != NULL)
	{
		nextToken++;
	}
	if (*nextToken == '\0')
	{
		return (NULL);
	}

	token = nextToken;

	while (*nextToken != '\0' && _strchr(delimiters, *nextToken) == NULL)
	{
		nextToken++;
	}
	if (*nextToken != '\0')
	{
		*nextToken = '\0';
		nextToken++;
	}
	return (token);
}

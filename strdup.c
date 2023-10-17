#include "main.h"

/**
 * _strdup - duplicates a string
 * @s: pointer to the string to be duplicated
 *
 * Return: pointer to the duplicated string
 */

char *_strdup(const char *s)
{
	char *d = malloc(_strlen(s) + 1);

	if (d == NULL)
	{
		return (NULL);
	}
	_strcpy(d, s);
	return (d);
}

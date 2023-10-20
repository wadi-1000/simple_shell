#include "main.h"

/**
 * _strchr - Locate character in a string
 * @s: string
 * @c: character
 * Return: pointer to the first character
 */

char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (!c)
		return (s);
	return (NULL);
}

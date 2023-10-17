#include "main.h"

/**
 * _strlen - counts the length of a string
 * @s: pointer to the string whose length is to be determined
 *
 * Return: length of the string
 */

size_t _strlen(const char *s)
{
	size_t len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

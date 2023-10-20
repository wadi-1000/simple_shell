#include "main.h"

/**
 * _strlen - counts the length of a string
 * @s: pointer to the string whose length is to be determined
 *
 * Return: length of the string
 */

int _strlen(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);

}

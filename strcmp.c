#include "main.h"

/**
 * _strcmp - compares btwn two strings
 * @s1: One of the strings
 * @s2: The other string
 *
 * Return: 0 if strings are same, +ve integer if s1 is longer
 * than s2 and -ve interger if s1 is shoter than s2
 */

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}

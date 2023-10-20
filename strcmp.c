#include "main.h"

/**
 * _strngcmp - compares btwn two strings
 * @s1: One of the strings
 * @s2: The other string
 * @n: num of bytes
 *
 * Return: 0 if strings are same, +ve integer if s1 is longer
 * than s2 and -ve interger if s1 is shoter than s2
 */

int _strngcmp(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

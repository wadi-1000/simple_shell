#include "main.h"
/**
 * stricmp - compares two strings
 * @s1: char
 * @s2: char
 *
 * Return: integer
 */
int stricmp(char *s1, char *s2)
{
	int i = 0, output;

	while (*(s1 + i) == *(s2 + i) && *(s1 + 1) != '\0')
		i++;

	output = (*(s1 + i) - *(s2 + i));

	return (output);
}

/**
 * my_strcmp - compares two strings
 * @s1: pointer to one of the strings
 * @s2: pointer to the other string
 *
 * Return: +ve No if s1 > s2, -ve No if s1 < s2 otherwise 0
 */

int my_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}
/**
 * exec_exit - Exits shell
 * @cmd: tokenized input
 * @command: input read
 *
 * REturn: no return
 */
void exec_exit(char **cmd, char *command)
{
	free(command);
	free_buf(cmd);
	exit(0);
}

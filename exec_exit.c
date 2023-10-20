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

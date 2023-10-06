#include "main.h"

/**
 * prompt - displays prompt and waits for user to enter commands
 *
 * Return: Pointer to an array containning the commands
 */

void prompt(void)
{
	char *buffer = malloc(1024);
	size_t len = 1024;
	char *token;
	char *array = malloc(1024);
	int i = 0;

	while (1)
	{
		_putchar('$');
		_putchar(32);
		getline(&buffer, &len, stdin);

		token = strtok(buffer, " ");
		while (token)
		{
			array[i] = *token;
			token = strtok(NULL, " ");
			i++;
		}
	}
}

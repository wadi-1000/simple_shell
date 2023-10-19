#include "main.h"

/**
 * prompt - displays prompt and waits for user to enter commands
 * @env: poointer to the environment variables
 *
 * Return: Nothing
 */

void prompt(char **env)
{
	char *buffer = NULL;
	size_t len = 0;
	char **array = NULL;

	while (1)
	{
		if (_isatty(STDIN_FILENO))
		{
			_putchar('$');
			_putchar(32); }
		if (getline(&buffer, &len, stdin) == -1)
		{
			free(buffer);
			exit(1);
		}
		input_length = strlen(buffer);

		if (input_length > 0 && buffer[input_length - 1] == '\n')
		{
			buffer[input_length - 1] = '\0';
		}

		array = tokenize_input(buffer);

		if (array && array[0])
		{
			exec_input(array, env);
			free_tokens(array);
		}
	}
	free(buffer);
}

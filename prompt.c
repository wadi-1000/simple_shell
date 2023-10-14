#include "main.h"

/**
 * prompt - displays prompt and waits for user to enter commands
 *
 * Return: Nothing
 */

void prompt(void)
{
	char *buffer = NULL;
	size_t len = 0;
	char **array = NULL;

	while (1)
	{
		printf("$ Enter command: ");


		if (getline(&buffer, &len, stdin) == -1)
		{
			perror("No input");
			exit(1);
		}

		input_length = strlen(buffer);

		if (input_length > 0 && buffer[input_length - 1] == '\n')
		{
			buffer[input_length - 1] = '\0';
		}

		if (strlen(buffer) == 0)
		{
			fprintf(stderr, "Error: No input detected, re-enter command.\n");
			continue;
		}

		array = tokenize_input(buffer);

		if (array)
		{
			exec_input(array);
			free_tokens(array);
		}
	}
	free(buffer);
}

#include "main.h"

/**
 * display_prompt - displays prompt and waits for user to enter commands
 *
 * Return: Nothing
 */

void display_prompt(void)
{
	_putchar('$');
	_putchar(32);
}
/**
 * get_user_input - Read and return a line of user input
 *
 * Return: string with user input.
 */
char *get_user_input()
{
	char *buffer = NULL;
	size_t len = 0;

	if (getline(&buffer, &len, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(buffer);
			printf("\n");
			exit(0);
		}
		else
		{
			perror("No input");
			free(buffer);
			exit(1);
		}
	}
		input_length = strlen(buffer);

		if (input_length > 0 && buffer[input_length - 1] == '\n')
		{
			buffer[input_length - 1] = '\0';
		}
	if (strlen(buffer) == 0)
	{
		fprintf(stderr, "Error: no input detected, re-enter command. \n");
			return (NULL);

	}
	return (buffer);
}

/**
 * process_user_input - Processes user input
 * @input: user input
 *
 * Return: Nothing
 */

void process_user_input(char *input)
{
	char **array;

	if (input == NULL)
	{
		fprintf(stderr, "Error: No input detected, re-enter command. \n");
		return;
	}

	array = tokenize_input(input);

	if (array)
	{
		exec_input(array);
		free_tokens(array);
	}
}
/**
 * prompt - Processes prompt.
 *
 * Return: Nothing
 */

void prompt(void)
{
	char *input;

	while (1)
	{
		display_prompt();
		input = get_user_input();

		if (input)
		{
			process_user_input(input);
			free(input);
		}
	}
}



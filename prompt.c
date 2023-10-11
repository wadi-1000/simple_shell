#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

/**
 * prompt - displays prompt and waits for user to enter commands
 *
 */
char **tokenize_input(char *input);
void free_tokens(char **tokens);
void exec_input(char *argv[]);
size_t input_length;

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


/**
 * tokenize_input - Function that toenizes the user's input
 * @input: The user input string
 * Return: An array of tokens
 */
char **tokenize_input(char *input)
{
	char *token;
	char **array = malloc(1024 * sizeof(char *));
	int i = 0;

	token = strtok(input, " ");
	while (token)
	{
		array[i] = strdup(token);
		token = strtok(NULL, " ");
		i++;
	}
	array[i] = NULL;

	if (i == 0)
	{
		free(array);
		return (NULL);
	}
	return (array);
}

/**
 * free_tokens - Function that fress the memory used by the array
 * @tokens: Array of tokens to free
 */
void free_tokens(char **tokens)
{
	int i;

	for (i = 0; tokens[i]; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}

/*
 * exec_input - Execute the command entered by the user.
 * @argv: Array of command arguments.
 *
 * Description: It forks a new process to execute a command with
 * the arguments given by the user.
 *
 * Return: exits the process upon success or failure.
 */
void exec_input(char *argv[])
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid < 0)
	{
		perror("Fork failed.");
		exit(1);
	}

	if (pid == 0)
	{
		if (execvp(argv[0], argv) < 0)
		{
			fprintf(stderr,"Execution failed. Incorrect command or no such file/directory.\n");
			return;
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	exit(0);
}

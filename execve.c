#include "main.h"

/**
 * exec_input - Execute the command entered by the user.
 * @argv: Array of command arguments.
 * @envp: gets the environment from where the command originates
 *
 * Return: exits the process upon success or failure.
 */
void exec_input(char *argv[], char *envp[])
{
	pid_t pid;
	int status;
	/*
	 * unsigned int i;
	 * char *newline = "\n";
	 * char *equal = "=";
	 */

	pid = fork();

	if (_strcmp(argv[0], "exit") == 0)
		exit(0);
	/*
	 * if (_strcmp(argv[0], "env") == 0)
	 * {
	 * while (envp[i] != NULL)
	 * {
	 * write(1, envp[i], _strlen(envp[i]));
	 * write(1, equal, 1);
	 * write(1, envp[i] + _strlen(envp[i]) + 1,
	 * _strlen(envp[i] + _strlen(envp[i]) + 1));
	 * write(1, newline, 1);
	 * i++;
	 * }}
	 */
	if (argv == NULL || envp == NULL)
		exit(1);
	if (pid < 0)
	{
		perror("Fork failed.");
		exit(1);
	}
	if (pid == 0)
	{
		if (execve(argv[0], argv, envp) == -1)
		{
			perror("./hsh");
			exit(0); }}
	else
		waitpid(pid, &status, 0); }

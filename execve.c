#include "main.h"

/**
 * exec_input - Execute the command entered by the user.
 * @argv: Array of command arguments.
 *
 *
 * Return: exits the process upon success or failure.
 */
void exec_input(char *argv[], char *env[])
{
	pid_t pid;
	int status;
	pid = fork();

	if (strcmp(argv[0], "exit") == 0)
		exit(0);
	if (pid < 0)
	{
		perror("Fork failed.");
		exit(1);
	}
	if (pid == 0)
	{
		if (execve(argv[0], argv, env) == -1)
		{
			perror("./hsh");
			exit(0);
		}
	}
	else
		waitpid(pid, &status, 0);
	return;
}


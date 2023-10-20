#include "main.h"

/**
 * exec_input - Execute the command entered by the user.
 * @cmd: command entered
 * @cp: user input
 *
 * Return: exits the process upon success or failure.
 */
void exec_input(char *cp, char **cmd)
{
	pid_t child_pid;
	int status;
	char **env = environ;

	child_pid = fork();
	if (child_pid < 0)
		perror(cp);
	if (child_pid == 0)
	{
		execve(cp, cmd, env);
		perror(cp);
		exit(98);
	}
	else
		wait(&status);
}


#include "main.h"

/**
 * exec_input - Execute the command entered by the user.
 * @argv: Array of command arguments.
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
		if (strcmp(argv[0], "env") == 0)
		{
			exec_env(environ);
			exit(0);
		}
		else if (strcmp(argv[0], "exit") == 0)
		{
			exec_exit(argv);
			exit(0);
		}
		else if (execvp(argv[0], argv) < 0)
		{
			fprintf(stderr,
					"Execution failed. \n"
					"Incorrect command or no such file/directory. \n"
					"Re-enter command. \n");
			return;
		}
	}
	else
		waitpid(pid, &status, 0);
	exit(0);
}


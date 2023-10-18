#include "main.h"

/**
 * exec_exit - Exits shell when user enters exit command.
 *
 * @argv: Array of arguments.
 */
void exec_exit(char *argv[])
{
	if (strcmp(argv[0], "env") == 0)
	{
		exec_env(argv);
		return;
	}
	else if (strcmp(argv[0], "exit") == 0)
	{
		exec_exit(argv);
	}
}

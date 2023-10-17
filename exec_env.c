#include "main.h"

/**
 * exec_env - Prints env variables when users enters env.
 *
 * @argv: Array of arguments.
 */
extern char **environ;

void exec_env(char *argv[])
{
	if (strcmp(argv[0], "env") == 0)
	{
		char **env = environ;

		while (*env)
		{
			printf("%s\n", *env);
			env++;
		}
		return;
	}
}

#include "main.h"

/**
 * exec_env - Prints env variables when users enters env.
 *
 * @environ: Array of environment variables.
 */


void exec_env(char **environ)
{
	if (environ != NULL)
	{
		int i;

		for (i = 0; environ[i] != NULL; i++)
		{
			printf("%s\n", environ[i]);
		}
	}
}

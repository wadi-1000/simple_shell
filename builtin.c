#include "main.h"

/**
 * handle_builtins - execute builtin commands
 * @cmd: user's tokenized input
 * @command: input from the user
 * Return: 1 (successful) 0 (failed)
 */
int handle_builtins(char **cmd, char *command)
{
	struct builtins builtins = {"env", "exit"};

	if (stricmp(*cmd, builtins.env) == 0)
	{
		exec_env();
		return (1);
	}
	else if (stricmp(*cmd, builtins.exit) == 0)
	{
		exec_exit(cmd, command);
		return (1);
	}
	return (0);
}

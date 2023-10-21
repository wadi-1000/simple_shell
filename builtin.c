#include "main.h"

/**
 * handle_builtins - execute builtin commands
 * @cmd: user's tokenized input
 * @command: input from the user
 * Return: 1 (successful) 0 (failed)
 */
int handle_builtins(char **cmd, char *command)
{
	struct builtins builtins = {"env", "exit", "setenv", "cd", "unsetenv"};

	if (my_strcmp(*cmd, builtins.env) == 0)
	{
		exec_env();
		return (1);
	}
	else if (my_strcmp(*cmd, builtins.exit) == 0)
	{
		exec_exit(cmd, command);
		return (1);
	}
	else if (my_strcmp(*cmd, builtins.setenv) == 0)
	{
		exec_setenv(cmd, command);
		return (1);
	}
	else if (my_strcmp(*cmd, builtins.unsetenv) == 0)
	{
		exec_unsetenv(cmd, command);
		return (1);
	}
	return (0);
}

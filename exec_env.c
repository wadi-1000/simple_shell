#include "main.h"

/**
 * exec_env - Prints out environment variables.
 *
 * Return: Nothing
 */
void exec_env(void)
{
	int i = 0;
	char **env = environ;

	while (env[i])
	{
		write(STDOUT_FILENO, (const void *)env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 * exec_setenv - sets new environment variable
 * @cmd: command given by user
 * @command: to be handed to free
 *
 * Return: Nothing
 */

void exec_setenv(char **cmd, char *command)
{
	if (cmd[1] != NULL && cmd[2] != NULL)
	{
		if (_setenv(cmd[1], cmd[2], 1) != 0)
		{
			_fprintf(stderr, "setenv: Failed to set the environment variable\n");
		}
	}
	else
	{
		_fprintf(stderr, "Usage: %s VARIABLE VALUE\n", command);
	}
	free_buf(cmd);
	free(command);
}

/**
 * exec_unsetenv - unsets the environment
 * @cmd: commands given by the user
 * @command: to be handed to free
 *
 * Return: Nothing
 */

void exec_unsetenv(char **cmd, char *command)
{
	int i, j;

	if (cmd[1] != NULL)
	{
		i = 0;
		while (environ[i] != NULL)
		{
			if (_strcmp(environ[i], cmd[1]) == 0 && environ[i][_strlen(cmd[1])] == '=')
			{
				j = i;
				while (environ[j] != NULL)
				{
					environ[j] = environ[j + 1];
					j++;
				}
				break;
			}
			i++;
		}
	}
	else
	{
		_fprintf(stderr, "Usage: %s VARIABLE\n", command);
	}
	free_buf(cmd);
	free(command);
}

/**
 * exec_cd - executes the cd commad in terminal
 * @cmd: the commands given by user
 * @command: to be freed
 *
 * Return: Nothing
 */

void exec_cd(char **cmd, char *command)
{
	if (cmd[1] != NULL)
	{
		if (chdir(cmd[1]) != 0)
		{
			_fprintf(stderr, "cd: %s: No such file or directory\n", cmd[1]);
		}
		else
		{
			char cwd[1024];

			if (getcwd(cwd, sizeof(cwd)) != NULL)
			{
				_setenv("PWD", cwd, 1);
			}
			else
			{
				_fprintf(stderr, "cd: Failed to update PWD environment variable\n");
			}
		}
	}
	else
	{
		char *home = _getenv("HOME");

		if (home != NULL)
		{
			if (chdir(home) != 0)
			{
				_fprintf(stderr, "cd: %s: No such file or directory\n", home);
			}
			else
			{
				_setenv("PWD", home, 1); }}
		else
		{
			_fprintf(stderr, "cd: HOME not set\n"); }}
	free_buf(cmd);
	free(command); }


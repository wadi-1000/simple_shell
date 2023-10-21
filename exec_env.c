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
		if (setenv(cmd[1], cmd[2], 1) != 0)
		{
			fprintf(stderr, "setenv: Failed to set the environment variable\n");
		}
	}
	else
	{
		fprintf(stderr, "Usage: %s VARIABLE VALUE\n", command);
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
	if (cmd[1] != NULL)
	{
		if (unsetenv(cmd[1]) != 0)
		{
			fprintf(stderr, "unsetenv: Failed to unset the environment variable\n");
		}
	}
	else
	{
		fprintf(stderr, "Usage: %s VARIABLE\n", command);
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
			fprintf(stderr, "cd: %s: No such file or directory\n", cmd[1]);
		}
		else
		{
			char cwd[1024];

			if (getcwd(cwd, sizeof(cwd)) != NULL)
			{
				setenv("PWD", cwd, 1);
			}
			else
			{
				fprintf(stderr, "cd: Failed to update PWD environment variable\n");
			}
		}
	}
	else
	{
		char *home = getenv("HOME");

		if (home != NULL)
		{
			if (chdir(home) != 0)
			{
				fprintf(stderr, "cd: %s: No such file or directory\n", home);
			}
			else
			{
				setenv("PWD", home, 1); }}
		else
		{
			fprintf(stderr, "cd: HOME not set\n"); }}
	free_buf(cmd);
	free(command); }


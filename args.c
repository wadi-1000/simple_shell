#include "main.h"

/**
 *  **parse_args - Parsing Arguments
 *  @cmd: char
 *  Return: char
 */

char **parse_args(char *cmd)
{
	char **args = malloc(sizeof(char *) * 10);
	char *tokentmp = NULL;
	int argc = 0;

	if (args == NULL)
	{
		perror("malloc");
		exit(1);
	}

	tokentmp = strtok(cmd, " ");
	while (tokentmp != NULL && argc < 10)
	{
		args[argc++] = tokentmp;
		tokentmp = strtok(NULL, " ");
	}
	args[argc] = NULL;
	return (args);
}

/**
 * get_path - gets path
 * Return: NULL
 */
char *get_path(void)
{
	int i;
	char **env = environ, *path = NULL;

	while (*env)
	{
		if (_strngcmp(*env, "PATH=", 5) == 0)
		{
			path = *env;
			while (*path && i < 5)
			{
				path++;
				i++;
			}
			return (path);
		}
		env++;
	}
	return (NULL);
}


/**
 * ad_p - adds path to command
 * @path: path of command entered by the user
 * @command: user's input
 * Return: buffer with command
 */
char *ad_p(char *path, char *command)
{
	char *buf;
	size_t i = 0, j = 0;

	if (command == 0)
		command  = "";
	if (path == 0)
		path = "";
	buf = malloc(sizeof(char) * (_strlen(path) + _strlen(command) + 2));
	if (!buf)
		return (NULL);

	while (path[i])
	{
		buf[i] = path[i];
		i++;
	}

	if (path[i - 1] != '/')
	{
		buf[i] = '/';
		i++;
	}
	while (command[j])
	{
		buf[i + j] = command[j];
		j++;
	}
	buf[i + j] = '\0';
	return (buf);
}
/**
 * check_path - checks path
 * @path: tokenized path
 * @cmd: user input
 * Return: NULL
 */
char *check_path(char **path, char *cmd)
{
	int i = 0;
	char *output;

	while (path[i])
	{
		output = ad_p(path[i], cmd);
		if (access(output, F_OK | X_OK) == 0)
			return (output);
		free(output);
		i++;
	}
	return (NULL);
}

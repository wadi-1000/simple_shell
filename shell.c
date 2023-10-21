#include "main.h"

/**
 * main - calls prompt to intiate the process
 * @ac: No of commandline arguments
 * @av: pointer to array of strings holding command line argumenta
 * @envp: pointer to environment variables
 *
 * Return: Always 0
 */

int main(int ac, char **av, char *envp[])
{
	char *cmd = NULL, *path = NULL, *patharg = NULL;
	size_t buffsize = 0;
	ssize_t linesize = 0;
	char **args = NULL, **paths = NULL;
	(void)envp, (void)av;

	if (ac < 1)
		return (-1);
	signal(SIGINT, mode_handler);

	while (1)
	{
		free_buf(paths);
		free_buf(args);
		free(patharg);
		prompt();
		linesize = _getline(&cmd, &buffsize, stdin);
		if (linesize < 0)
			break;
		cond.count++;
		if (cmd[linesize - 1] == '\n')
			cmd[linesize - 1] = '\0';
		args = tokenize_input(cmd);
		if (args == NULL || *args == NULL || **args == '\0')
			continue;
		if (cmd_check(args, cmd))
		continue;
		path = get_path();
		paths = tokenize_input(path);
		patharg = check_path(paths, args[0]);
		if (!patharg)
			perror(av[0]);
		else
			exec_input(patharg, args);
	}
	if (linesize < 0 && m_handler.active)
		write(STDERR_FILENO, "\n", 1);
	free(cmd);
	return (0);
}

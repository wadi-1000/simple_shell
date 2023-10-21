#include "main.h"

extern __sighandler_t signal(int __sig, __sighandler_t __handler);
/**
 * mode_handler - tracks shell mode
 * @s: signal numeral
 *
 * Return: nothing
 */


void mode_handler(int s)
{
	(void)s;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}


/**
 * cmd_check - checks for builtins
 * @cmd: input
 * @buf: buffer
 *
 * Return: 1 (succesful) 0 (failed)
 */
int cmd_check(char **cmd, char *buf)
{
	if (handle_builtins(cmd, buf))
		return (1);
	else if (**cmd == '/')
	{
		exec_input(cmd[0], cmd);
		return (1);
	}
	else if (**cmd == '.')
	{
		exec_input(cmd[0], cmd);
		return (1);
	}
	return (0);
}

/**
 * ctrl_d - exits shell when user presses ctrl d
 * @signa: parameter
 */

void ctrl_d(int signa)
{
	(void)signa;
	_putchar('\n');
	exit(EXIT_SUCCESS);
}

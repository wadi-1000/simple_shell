#include "main.h"

/**
 * prompt - displays prompt and waits for user to enter commands
 *
 * Return: Nothing
 */

void prompt(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		m_handler.active = 1;
	if (m_handler.active)
		write(STDERR_FILENO, "$ ", 2);
}

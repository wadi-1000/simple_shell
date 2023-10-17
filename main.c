#include "main.h"

/**
 * main - holds prompt function for the user
 *
 * Return: 0 (Successful)
 */

int main(void)
{
	extern char **environ;

	prompt();

	exec_env(environ);

	return (0);
}

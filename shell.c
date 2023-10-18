#include "main.h"

/**
 * main - calls prompt to intiate the process
 * @ac: No of commandline arguments
 * @av: pointer to array of strings holding command line argumenta
 * @env: pointer to environment variables
 *
 * Return: Always 0
 */

int shell(int ac, char **av)
{
	(void)ac;
	(void)av;

	prompt();
	return (0);
}

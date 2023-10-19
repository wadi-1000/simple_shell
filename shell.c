#include "main.h"

/**
 * main - calls prompt to intiate the process
 * @ac: No of commandline arguments
 * @av: pointer to array of strings holding command line argumenta
 * @env: pointer to environment variables
 *
 * Return: Always 0
 */

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	prompt(env);
	return (0);
}
